#include "bintree.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

void print_values(const char *str, const std::vector<int> *values) {
    std::cout << str << std::endl;
    for (int v : *values) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: ./main <n> <m>\n";
        std::cout << "\t<n> number of random elements of the tree\n";
        std::cout << "\t<m> maximum value for the random elements\n";
        return 0;
    }

    int key;
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k1 = atoi(argv[3]);
    int k2 = atoi(argv[4]);
    BSTree mytree;

    // use current time as seed
    std::srand(std::time(0));

    // insert n random numbers
    for (int i = 0 ; i < n ; i ++) {
        key = std::rand() % m + 1;
        mytree.insert(key);
    }

    // print inorder traversal
    std::vector<int> values;
    mytree.traversal(INORDER, &values);
    print_values("Inorder: ", &values);

    // print range query
    mytree.range_query(k1, k2, &values);
    print_values("Range [k1) +" " +std::to_string(k2) +]: ", &values);

    return 0;
}