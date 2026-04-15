#include "tree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// =========================
// COLA SIMPLE PARA BFS
// =========================
class QueueNode {
public:
    Node* data;
    QueueNode* next;

    QueueNode(Node* d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(Node* n) {
        QueueNode* temp = new QueueNode(n);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    Node* dequeue() {
        if (isEmpty()) return nullptr;
        QueueNode* temp = front;
        Node* d = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return d;
    }
};


// Tree implementación


Tree::Tree() {
    root = nullptr;
}

Node* Tree::getRoot() {
    return root;
}

void Tree::clear() {
    root = nullptr;
}

Node* Tree::find(Node* node, int id) {
    if (!node) return nullptr;
    if (node->id == id) return node;

    Node* res = find(node->left, id);
    if (res) return res;
    return find(node->right, id);
}

Node* Tree::findById(int id) {
    return find(root, id);
}

bool Tree::hasChildren(Node* n) {
    return n && (n->left || n->right);
}


// Insertar respetando id_boss

bool Tree::insert(Node* newNode) {
    if (newNode->id_boss == 0) {
        if (!root) {
            root = newNode;
            return true;
        }
        return false;
    }

    Node* boss = find(root, newNode->id_boss);
    if (!boss) return false;

    if (!boss->left) {
        boss->left = newNode;
        newNode->parent = boss;
        return true;
    }
    if (!boss->right) {
        boss->right = newNode;
        newNode->parent = boss;
        return true;
    }

    return false;
}