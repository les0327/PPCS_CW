#include <iostream>
#include <omp.h>
#include "functions.h"

using std::cout;
using std::cin;

int main() {
    omp_set_num_threads(2);
    #pragma omp parallel
    {
      cout << "Hello world!\n";
    };
    return 0;
}