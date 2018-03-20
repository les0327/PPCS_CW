#include <iostream>
#include <omp.h>
#include "functions.h"

using std::cout;
using std::cin;

int p, n, h;
int num = 1;

int e;
int *A, *B, *C;
int *MX, *MZ;

void init() {
    A = (int *) malloc(static_cast<size_t>(n * 4));
    B = (int *) malloc(static_cast<size_t>(n * 4));
    C = (int *) malloc(static_cast<size_t>(n * 4));
    MX = (int *) malloc(static_cast<size_t>(n * n * 4));
    MZ = (int *) malloc(static_cast<size_t>(n * n * 4));
}

void finish() {
    free(A);
    free(B);
    free(C);
    free(MX);
    free(MZ);
}

int main() {
    cout << "Enter p:\n";
    cin >> p;
    cout << "Enter n:\n";
    cin >> n;

    h = n / p;

    init();

    omp_set_num_threads(p);
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();

        if (tid == 0) {
            e = num;
            fillVector(num, C, n);
            fillMatrix(num, MX, n);
        }

        if (tid == p - 1) {
            fillVector(num, B, n);
            fillMatrix(num, MZ, n);
            B[0] = 20;
        }
    };


    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        vectorSort(B, h * tid, h * (tid + 1));

        if (tid == p - 1) {
            cout << "B = ";
            printVector(B, n);
        }
    };

    finish();
    return 0;
}