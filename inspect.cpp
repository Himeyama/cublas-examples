#include <iostream>

template <typename T>
void inspect(int m, int n, T *data){
    std::string str = "[";
    for(std::int64_t i = 0; i < m; i++){
        str += "[";
        for(std::int64_t j = 0; j < n; j++){
            str += std::to_string(data[i * n + j]) + (j == n - 1 ? "" : ", ");
        }
        str += (i == m - 1 ? "]" : "], ");
    }
    str += "]";
    std::cout << str << std::endl;
}

template void inspect(int, int, float*);
template void inspect(int, int, double*);
