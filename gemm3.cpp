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
    cublasAlloc(k * m, sizeof(float), (void**)&d_a);
    cublasAlloc(k * n, sizeof(float), (void**)&d_b);
    cublasAlloc(m * n, sizeof(float), (void**)&d_c);

    // host to device
    cublasSetMatrix(k, m, sizeof(float), a, k, d_a, k);
    cublasSetMatrix(k, n, sizeof(float), b, k, d_b, k);

    // a.T dot b
    cublasSgemm('N', 'T', n, m, k, 1, d_b, n, d_a, m, 0, d_c, n);

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
