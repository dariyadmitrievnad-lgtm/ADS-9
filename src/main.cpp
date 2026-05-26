// Copyright 2022 NNTU-CS
#include "tree.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<char> in = {'1', '2', '3'};

    PMTree tree(in);

    std::vector<std::vector<char>> perms = getAllPerms(tree);

    std::cout << "All permutations:\n";

    for (const auto& perm : perms) {
        for (char c : perm)
            std::cout << c;
        std::cout << '\n';
    }

    std::vector<char> p1 = getPerm1(tree, 1);

    std::cout << "\ngetPerm1(1): ";

    for (char c : p1)
        std::cout << c;

    std::cout << '\n';

    std::vector<char> p2 = getPerm2(tree, 2);

    std::cout << "getPerm2(2): ";

    for (char c : p2)
        std::cout << c;

    std::cout << '\n';

    return 0;
}
