#include <iostream>
#include <omp.h>
#include "functions.h"

using std::cout;
using std::cin;

int p, n;
float h;
int num = 1;

int e;
int *A, *B, *C;
int *MX, *MZ;

void init_memory() {
    A = (int *) malloc((size_t)(n * 4));
    B = (int *) malloc((size_t)(n * 4));
    C = (int *) malloc((size_t)(n * 4));
    MX = (int *) malloc((size_t)(n * n * 4));
    MZ = (int *) malloc((size_t)(n * n * 4));
}

void free_memory() {
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

    h = (float) n / p;

    cout << "h = " << h << "\n";

    init_memory();

    omp_set_num_threads(p);
    #pragma omp parallel
    {
        int tid = omp_get_thread_num(); // get thread id

        // local variables for
        int e_local;
        int *C_local;
        int *MX_local;

        cout << "Thread " << tid << " start\n";

        if (tid == 0) {
            e = num;
            fillVector(num, C, n);
            fillMatrix(num, MX, n);
        }

        if (tid == p - 1) {
            fillVector(num, B, n);
            fillMatrix(num, MZ, n);
            //B[0] = 20;
        }

        #pragma omp barrier // wait until finish enter data


        #pragma omp critical
        {
            e_local = e;
            C_local = C;
            MX_local = MX;
        };


        vectorSort(B, int(h * tid), (int)(h * (tid + 1)));

        #pragma omp barrier // wait until sorting and merging finish
        F(A, B, e_local, C_local, MX_local, MZ, (int) h * tid, int(h * (tid + 1)), n);


        #pragma omp barrier // wait until computing finish
        if (tid == p - 1) {
            cout << "A = ";
            printVector(A, n);
        }

        cout << "T" << tid << " finish\n";
    };

    free_memory();
    return 0;
}