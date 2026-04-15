#include <iostream>
#include "tree.hpp"

using namespace std;

int main() {
    Tree tree;
    tree.loadFromCSV("data.csv");

    cout << "\nÁrbol cargado:\n";
    tree.showSuccession(tree.getRoot());

    int op;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Mostrar linea de sucesion\n";
        cout << "2. Actualizar jefe\n";
        cout << "3. Modificar nodo\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
        case 1:
            tree.showSuccession(tree.getRoot());
            break;

        case 2:
            tree.updateBoss();
            break;

        case 3: {
            int id;
            cout << "Ingrese ID: ";
            cin >> id;
            tree.modify(id);
            break;
        }
        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }
