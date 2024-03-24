import os, csv, PIL
import pandas as pd
import torchvision.transforms as transforms

def build_annotation_dataframe(image_location, annot_location, output_csv_name):
    class_lst = os.listdir(
        image_location)  # returns a LIST containing the names of the entries (folder names in this case) in the directory.
    class_lst.sort()  # IMPORTANT
    with open(os.path.join(annot_location, output_csv_name), 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        writer.writerow(['file_name', 'file_path', 'class_name',
                        'class_index'])  # create column names
        for class_name in class_lst:
            # concatenates various path components with exactly one directory separator (‘/’) except the last path component.
            class_path = os.path.join(image_location, class_name)
            # get list of files in class folder
            file_list = os.listdir(class_path)
            for file_name in file_list:
                # concatenate class folder dir, class name and file name
                file_path = os.path.join(image_location, class_name, file_name)
                # write the file path and class name to the csv file
                writer.writerow(
                    [file_name, file_path, class_name, class_lst.index(class_name)-1])
    return pd.read_csv(os.path.join(annot_location, output_csv_name))


def check_annot_dataframe(annot_df):
    class_zip = zip(annot_df['class_index'], annot_df['class_name'])
    my_list = list(class_zip)
    return list(set(my_list))


def transform_bilinear(output_img_width, output_img_height):
    # sourcery skip: inline-immediately-returned-variable
    image_transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5]),
        transforms.Resize((output_img_width, output_img_height),
                          interpolation=transforms.InterpolationMode.BILINEAR )
    ])
    return image_transform