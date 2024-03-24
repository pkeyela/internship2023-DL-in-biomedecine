#!/bin/sh
#SBATCH -p tut
#SBATCH -n 4
#SBATCH -t 1
module add intel/v2021.1
mpirun ./a.out

