#include <iostream>
#include <cublas.h>
#include <inspect.hpp>

int main(){
    int m = 2, n = 3;

    float a[] = {1, 2, 3, 4, 5, 6};

    float *d_a;

    // alloc device memory
    cublasAlloc(m * n, sizeof(float), (void**)&d_a);

    // host to device
    cublasSetMatrix(m, n, sizeof(float), a, m, d_a, m);

    // a + b
    cublasSscal(m * n, 2, d_a, 1);

    // device to host
    cublasGetMatrix(m, n, sizeof(float), d_a, m, a, m);

    // free device memory
    cublasFree(d_a);

    inspect<float>(m, n, a);

    return 0;
}