#include <iostream>
#include <cublas.h>
#include <inspect.hpp>

int main(){
    int m = 3, n = 4, k = 2;

    float a[] = {9, 10, 11, 12, 13, 14};
    float b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    float *c = (float*)malloc(sizeof(float) * m * n);

    float *d_a, *d_b, *d_c;

    // alloc device memory
    cublasAlloc(m * k, sizeof(float), (void**)&d_a);
    cublasAlloc(n * k, sizeof(float), (void**)&d_b);
    cublasAlloc(m * n, sizeof(float), (void**)&d_c);

    // host to device
    cublasSetMatrix(m, k, sizeof(float), a, m, d_a, m);
    cublasSetMatrix(n, k, sizeof(float), b, n, d_b, n);

    // a dot b.T
    cublasSgemm('T', 'N', n, m, k, 1, d_b, k, d_a, k, 0, d_c, n);

    // device to host
    cublasGetMatrix(m, n, sizeof(float), d_c, m, c, m);

    // free device memory
    cublasFree(d_a);
    cublasFree(d_b);
    cublasFree(d_c);

    inspect<float>(m, n, c);

    free(c);

    return 0;
}
