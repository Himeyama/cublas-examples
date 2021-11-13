# CuBLAS examples
CuBLAS の関数の使い方例

## 行列 (ベクトル) のスカラー倍 `cublas<T>scal`
以下の行列 A があるとき、

![A](images/A_mn.svg)


## 行列 (ベクトル) の定数倍
> A <- k * A

**A の要素が A * k の要素になり、元の値は破壊される。**

```cpp
//  m: 行数
//  n: 列数
//  2: k
// da: A
cublasSscal(m * n, 2, d_a, 1);
```

- [scal.cpp](scal.cpp)

## 行列 (ベクトル) の和 `cublas<T>axpy`
以下の行列 A、B があるとき、

![A](images/A_mn.svg) ![B](images/B_mn.svg)

> 例1: A <- A + B

**A の要素が A + B の要素になり、元の値は破壊される。**

```cpp
//   m: 行数
//   n: 列数
// d_a: A
// d_b: B
cublasSaxpy(m * n, 1, d_b, 1, d_a, 1);
```

- [axpy.cpp](axpy.cpp)

## 行列の積 `cublas<T>gemm`
以下の行列 A、B があるとき、

![A](images/A.svg) ![B](images/B.svg)

> 例1: C = A B
```cpp
// d_c: C (m, n)
// d_a: A (m, k)
// d_b: B (k, n)
cublasSgemm('N', 'N', n, m, k, 1, d_b, n, d_a, k, 0, d_c, n);
```

- [gemm.cpy](gemm.cpy)

> 例2: C = A B^T
```cpp
// d_c: C (m, n)
// d_a: A (m, k)
// d_b: B (n, k)
cublasSgemm('T', 'N', n, m, k, 1, d_b, k, d_a, k, 0, d_c, n);
```

- [gemm2.cpy](gemm2.cpy)

> 例3: C = A^T B
```cpp
// d_c: C (m, n)
// d_a: A (k, m)
// d_b: B (k, n)
cublasSgemm('N', 'T', n, m, k, 1, d_b, n, d_a, m, 0, d_c, n);
```

- [gemm3.cpy](gemm3.cpy)