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
    Node* parent;

    Node(int _id,
         const std::string& _name,
         const std::string& _last,
         char _gender,
         int _age,
         int _boss,
         bool dead,
         bool jail,
         bool was,
         bool isb);
    };

#endif
