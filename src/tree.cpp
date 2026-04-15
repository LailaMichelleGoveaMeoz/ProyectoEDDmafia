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


//1. Insertar respetando id_boss

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

// 2.función que me deja mostrar línea de sucesión
void Tree::showSuccession(Node* node) {
    if (!node) return;

    bool alive = !node->is_dead;
    bool free_ = !node->in_jail;

    if (alive && free_) {
        cout << node->name << " " << node->last_name;
        if (node->is_boss) cout << " (JEFE)";
        cout << endl;
    }

    showSuccession(node->left);
    showSuccession(node->right);
}

//=====-==--==--==--=---====--==-=--=--
// 3. función que me deja modificar nodo
//-=--===--===--=====--======-==--==--=
void Tree::modify(int id) {
    Node* node = find(root, id);
    if (!node) {
        cout << "No encontrado\n";
        return;
    }

    cout << "Nuevo nombre: ";
    cin >> node->name;

    cout << "Nuevo apellido: ";
    cin >> node->last_name;

    cout << "Nueva edad: ";
    cin >> node->age;

    cout << "Genero (H/M): ";
    cin >> node->gender;

    cout << "Muerto (1/0): ";
    cin >> node->is_dead;

    cout << "En carcel (1/0): ";
    cin >> node->in_jail;

    cout << "Fue jefe antes (1/0): ";
    cin >> node->was_boss;

    cout << "Es jefe actual (1/0): ";
    cin >> node->is_boss;
}