#include "node.hpp"

Node::Node(int _id,
           const std::string& _name,
           const std::string& _last,
           char _gender,
           int _age,
           int _boss,
           bool dead,
           bool jail,
           bool was,
           bool isb) {

    id = _id;
    name = _name;
    last_name = _last;
    gender = _gender;
    age = _age;
    id_boss = _boss;

    is_dead = dead;
    in_jail = jail;
    was_boss = was;
    is_boss = isb;

    left = right = parent = nullptr;
}