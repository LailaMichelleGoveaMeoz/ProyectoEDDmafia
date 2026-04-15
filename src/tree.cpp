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