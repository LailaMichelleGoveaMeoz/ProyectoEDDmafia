#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include "node.hpp"

class Tree {
private:
    Node* root;

    Node* find(Node* node, int id);
    Node* findSuccessorInSubtree(Node* start, bool allowJailed);
    Node* findSuccessorFromOtherChildOfParent(Node* boss, bool allowJailed);
    Node* findInPreviousBossCompanion(Node* boss, bool allowJailed);
    Node* findNearestBossWithTwoFreeSuccessors(bool allowJailed);
    Node* findGlobalSuccessor(bool allowJailed);
    Node* findCurrentBoss();
    bool hasChildren(Node* n);

public:
    Tree();

    Node* getRoot();
    Node* findById(int id);
    void clear();

    bool insert(Node* newNode);
    void showSuccession(Node* node);
    void modify(int id);
    void updateBoss();

    void loadFromCSV(const std::string& filename);
};

#endif