#include <iostream>
#include <cublas.h>
#include <inspect.hpp>

int main(){
    int m = 2, n = 3;

    float a[] = {1, 2, 3, 4, 5, 6};
    float b[] = {7, 8, 9, 10, 11, 12};

    float *d_a, *d_b;

    // alloc device memory
    cublasAlloc(m * n, sizeof(float), (void**)&d_a);
    cublasAlloc(m * n, sizeof(float), (void**)&d_b);

    // host to device
    cublasSetMatrix(m, n, sizeof(float), a, m, d_a, m);
    cublasSetMatrix(m, n, sizeof(float), b, m, d_b, m);

    // a + b
    cublasSaxpy(m * n, 1, d_b, 1, d_a, 1);

    // device to host
    cublasGetMatrix(m, n, sizeof(float), d_a, m, a, m);

    // free device memory
    cublasFree(d_a);
    cublasFree(d_b);

    inspect<float>(m, n, a);

    return 0;
}
