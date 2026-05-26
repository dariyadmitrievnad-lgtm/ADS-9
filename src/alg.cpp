// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <vector>

#include "tree.h"

namespace {

int64_t factorial(int n) {
    int64_t result = 1;

    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}

void dfsAll(PMNode* node,
            std::vector<char>* current,
            std::vector<std::vector<char>>* result) {
    if (node->value != '\0')
        current->push_back(node->value);

    if (node->children.empty()) {
        if (!current->empty())
            result->push_back(*current);
    } else {
        for (auto child : node->children)
            dfsAll(child, current, result);
    }

    if (node->value != '\0')
        current->pop_back();
}

}  // namespace

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<std::vector<char>> result;
    std::vector<char> current;

    dfsAll(tree.getRoot(), &current, &result);

    return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    std::vector<std::vector<char>> perms = getAllPerms(tree);

    if (num < 1 || num > static_cast<int>(perms.size()))
        return {};

    return perms[num - 1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    int64_t total = factorial(tree.getSize());

    if (num < 1 || num > total)
        return {};

    std::vector<char> result;

    PMNode* current = tree.getRoot();

    int remain = tree.getSize();
    int64_t index = num - 1;

    while (!current->children.empty()) {
        int64_t block = factorial(remain - 1);

        int childIndex = static_cast<int>(index / block);

        index %= block;

        current = current->children[childIndex];

        result.push_back(current->value);

        --remain;
    }

    return result;
}
    int64_t result = 1;

    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}

void dfsAll(PMNode* node,
            std::vector<char>* current,
            std::vector<std::vector<char>>* result) {
    if (node->value != '\0')
        current->push_back(node->value);

    if (node->children.empty()) {
        if (!current->empty())
            result->push_back(*current);
    } else {
        for (auto child : node->children)
            dfsAll(child, current, result);
    }

    if (node->value != '\0')
        current->pop_back();
}

}  // namespace

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<std::vector<char>> result;
    std::vector<char> current;

    dfsAll(tree.getRoot(), &current, &result);

    return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    std::vector<std::vector<char>> perms = getAllPerms(tree);

    if (num < 1 || num > static_cast<int>(perms.size()))
        return {};

    return perms[num - 1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    int64_t total = factorial(tree.getSize());

    if (num < 1 || num > total)
        return {};

    std::vector<char> result;

    PMNode* current = tree.getRoot();

    int remain = tree.getSize();
    int64_t index = num - 1;

    while (!current->children.empty()) {
        int64_t block = factorial(remain - 1);

        int childIndex = static_cast<int>(index / block);

        index %= block;

        current = current->children[childIndex];

        result.push_back(current->value);

        --remain;
    }

    return result;
}
