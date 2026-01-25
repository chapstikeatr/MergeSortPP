#!/bin/bash
#SBATCH --job-name=mergesort_bench
#SBATCH --output=mergesort_%j.out
#SBATCH --error=mergesort_%j.err
#SBATCH --time=05:00:00
#SBATCH --partition=Centaurus
#SBATCH --mem=30G

srun $HOME/MergeSortPP/MergeSortPP/mergeSort 10
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 100
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 1000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 10000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 100000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 1000000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 10000000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 100000000
srun $HOME/MergeSortPP/MergeSortPP/mergeSort 1000000000

