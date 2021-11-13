#include <iostream>
#include <cublas.h>
#include <inspect.hpp>

int main(){
    int m = 10000, n = 20000, k = 30000;

    float *a = (float*)malloc(sizeof(float) * m * k);
    float *b = (float*)malloc(sizeof(float) * k * n);
    float *c = (float*)malloc(sizeof(float) * m * n);

    float *d_a, *d_b, *d_c;

    // alloc device memory
    cublasAlloc(m * k, sizeof(float), (void**)&d_a);
    cublasAlloc(k * n, sizeof(float), (void**)&d_b);
    cublasAlloc(m * n, sizeof(float), (void**)&d_c);

    // host to device
    cublasSetMatrix(m, k, sizeof(float), a, m, d_a, m);
    cublasSetMatrix(k, n, sizeof(float), b, k, d_b, k);

    // a dot b
    cublasSgemm('N', 'N', n, m, k, 1, d_b, n, d_a, k, 0, d_c, n);

    // device to host
    cublasGetMatrix(m, n, sizeof(float), d_c, m, c, m);

    // free device memory
    cublasFree(d_a);
    cublasFree(d_b);
    cublasFree(d_c);

    // inspect<float>(m, n, c);

    free(a);
    free(b);
    free(c);

    return 0;
}
