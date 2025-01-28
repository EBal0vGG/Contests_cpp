#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> adjacent_swap(const std::vector<int> &vec) {
    std::vector<int> new_vec;
    for (int i = 1; i < vec.size(); i += 2) {
        new_vec.push_back(vec[i]);
        new_vec.push_back(vec[i - 1]);
    }
    return new_vec;
}

int *adjacent_swap(const int *begin, size_t size) {
    int *new_arr = new int[size];
    for (int i = 0; i < size; i += 2) {
        new_arr[i] = begin[i + 1];
        new_arr[i + 1] = begin[i];
    }
    return new_arr;
}

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5, 6};
//     std::vector<int> new_vec = adjacent_swap(vec);
//     for (int &num : new_vec) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     int *arr = new int[6];
//     for (int i = 0; i < 6; i++) {
//         arr[i] = i + 1;
//     }
//     int *new_arr = adjacent_swap(arr, 6);
//     for (int i = 0; i < 6; i++) {
//         std::cout << new_arr[i] << " ";
//     }
//     std::cout << std::endl;


//     return 0;
// }