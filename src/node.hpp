#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node {
    int id;
    std::string name;
    std::string last_name;
    char gender;
    int age;
    int id_boss;
    bool is_dead;
    bool in_jail;
    bool was_boss;
    bool is_boss;

    Node* left;
    Node* right;

    Node() : id(0), gender('H'), age(0), id_boss(0),
             is_dead(false), in_jail(false),
             was_boss(false), is_boss(false),
             left(nullptr), right(nullptr) {}
};

#endif
