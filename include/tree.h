// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct PMNode {
    char value;
    std::vector<PMNode*> children;

    explicit PMNode(char val = '\0') : value(val) {}
};

class PMTree {
 public:
    explicit PMTree(const std::vector<char>& data);
    ~PMTree();

    PMNode* getRoot() const;
    int getSize() const;

 private:
    PMNode* root_;
    int size_;

    void buildTree(PMNode* node,
                   const std::vector<char>& available);

    void deleteTree(PMNode* node);
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);

std::vector<char> getPerm1(PMTree& tree, int num);

std::vector<char> getPerm2(PMTree& tree, int num);

long long factorial(int n);

#endif  // INCLUDE_TREE_H_
