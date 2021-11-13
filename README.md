# CuBLAS examples
CuBLAS の関数の使い方例

## 行列の積 `cublas<T>gemm`
行列 A、B が以下であるとき、

![A](images/A.svg) ![B](images/B.svg)

> 例1: C = A B
```cpp
// d_c: C (m, n)
// d_a: A (m, k)
// d_b: B (k, n)
cublasSgemm('N', 'N', n, m, k, 1, d_b, n, d_a, k, 0, d_c, n);
```

> 例2: C = A B^T
```cpp
// d_c: C (m, n)
// d_a: A (m, k)
// d_b: B (n, k)
cublasSgemm('T', 'N', n, m, k, 1, d_b, k, d_a, k, 0, d_c, n);
```

> 例3: C = A^T B
```cpp
// d_c: C (m, n)
// d_a: A (k, m)
// d_b: B (k, n)
cublasSgemm('N', 'T', n, m, k, 1, d_b, n, d_a, m, 0, d_c, n);
```