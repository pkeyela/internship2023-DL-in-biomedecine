import torch
from torchsummary import summary
import torch.nn as nn
import torch.optim as optim
from src.config.data_config import *

def default_loss():
    return nn.CrossEntropyLoss()

def default_optimizer(model, learning_rate = 0.001):
    return optim.Adam(model.parameters(), lr = learning_rate)

def get_default_device():
    """Picking GPU if available or else CPU"""
    if torch.cuda.is_available():
        return torch.device('cuda')
    else:
        return torch.device('cpu')

def model_prep_and_summary(model, device):
    """ Move model to GPU and print model summary
    """
    # Define the model and move it to GPU:
    model = model
    model = model.to(device)
    print(f'Current device: {str(device)}')
    print(f'Is Model on CUDA: {str(next(model.parameters()).is_cuda)}')
    # Display model summary:
    summary(model, (INPUT_CHANNEL, INPUT_WIDTH, INPUT_HEIGHT))
