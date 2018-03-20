//
// Created by Foresstt on 28-Oct-17.
//

#include <cstdio>
#include <cstdlib>

#include "functions.h"


void printVector(int *A, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


void fillVector(int num, int *A, int n) {
    for (int i = 0; i < n; i++)
        A[i] = num;
}

void fillMatrix(int num, int *A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i*n + j] = num;
}

/**
 * Multiplication matrix A and B
 * @param A - matrix
 * @param B - matrix
 * @param C=A*B - matrix
 */
void matrixMultiplication(const int *A, const int *B, int *C, int from, int to, int n) {
    int buf;
    for (int i = 0; i < n; i++ ) {
        for (int j = from; j < to; j++) {
            buf = 0;
            for (int k = 0; k < n; k++) {
                buf += A[i*n + k] * B[k*n + j];
            }
            C[i*n + j] = buf;
        }
    }
}

/**
 * Multiplication vector A with matrix B
 * @param A - vector
 * @param B - matrix
 * @param C=A*B - vector
 */
void vectorMatrixMultiplication(const int *A, const int *B, int *C, int from, int to, int n) {
    int buf;
    for (int i = from; i < to; i++ ) {
        buf = 0;
        for (int j = 0; j < n; j++) {
            buf += A[j] * B[j*n + i];
        }
        C[i] = buf;
    }
}

/**
* Selection sort of arr from to
*/
void vectorSort(int *A, int from, int to) {
	int index;
	int min;
	for (int i = from; i < to; i++) {
		index = i;
		min = A[i];
		for (int j = i + 1; j < to; j++) {
			if (A[j] < min) {
				index = j;
				min = A[j];
			}
		}

		if (index != i) {
			A[index] = A[i];
			A[i] = min;
		}
	}
}

void merge(int *A, int leftIndex, int rightIndex, int size) {
	int index = leftIndex;
	int leftSize = leftIndex + size;
	int rightSize = rightIndex + size;

    auto *buf = (int *)malloc(static_cast<size_t>(size * 2 * 4));

	int i;
	for (i = 0 ; leftIndex < leftSize && rightIndex < rightSize; i++) {
		if (A[leftIndex] < A[rightIndex]) {
			buf[i] = A[leftIndex];
			leftIndex++;
		}
		else {
			buf[i] = A[rightIndex];
			rightIndex++;
		}
	}

	while (leftIndex < leftSize) {
		buf[i++] = A[leftIndex++];
	}

	while (rightIndex < rightSize) {
		buf[i++] = A[rightIndex++];
	}

	for (i = 0; i < size * 2; i++)
		A[index++] = buf[i];

	free(buf);
}
void F(int *A, const int *B, int e, int *C, int *MX, int *MZ, int from, int to, int n) {
    auto MBuf = (int *) malloc(static_cast<size_t>(n * n * 4));

    matrixMultiplication(MX, MZ, MBuf, from, to, n);
    vectorMatrixMultiplication(C, MBuf, A, from, to, n);

    for (int i = from; i < to; i++) {
        A[i] = A[i] + B[i] * e;
    }

    free(MBuf);
}