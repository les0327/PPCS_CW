//
// Created by Foresstt on 28-Oct-17.
//

#ifndef PARALLELANDDISTRIBUTEDCOMPUTINGLAB4_FUNCTIONS_H
#define PARALLELANDDISTRIBUTEDCOMPUTINGLAB4_FUNCTIONS_H

void printVector(int *A, int n);

void fillVector(int num, int *A, int n);
void fillMatrix(int num, int *A, int n);

void vectorSort(int *A, int from, int to);
void merge(int *A, int leftIndex, int rightIndex, int size);

void F(int *A, int e, int *Z, int d, int *S, int *MO, int *MH, int from, int to, int n);

#endif //PARALLELANDDISTRIBUTEDCOMPUTINGLAB4_FUNCTIONS_H
