NVCC = nvcc
 CXX = /usr/bin/g++
  CC = /usr/bin/gcc
 OPT = -ccbin $(CC) -std=c++11 -O3 \
	-gencode arch=compute_52,code=sm_52 \
	-gencode arch=compute_60,code=sm_60 \
	-gencode arch=compute_61,code=sm_61 \
	-gencode arch=compute_70,code=sm_70 \
	-gencode arch=compute_75,code=sm_75

gemm: gemm.cpp inspect.o
	$(NVCC) $(OPT) --compiler-options -Wall --compiler-options -Wextra -lcublas -I. -o $@ $^

inspect: inspect.cpp
	$(CXX) -c $^