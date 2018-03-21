//
// Created by Foresstt on 20-Mar-18.
//

#ifndef PPCS_CW_FUNCTIONS_H
#define PPCS_CW_FUNCTIONS_H

void printVector(int *A, int n);

void fillVector(int num, int *A, int n);
void fillMatrix(int num, int *A, int n);

void vectorSort(int *A, int from, int to);
void merge(int *A, int leftIndex, int rightIndex, int leftSize, int rightSize, int n);

void F(int *A, const int *B, int e, int *C, int *MX, int *MZ, int from, int to, int n);

#endif //PPCS_CW_FUNCTIONS_H
