#ifndef MODELS_HPP
#define MODELS_HPP

#include <string>

struct Ticket {
    int id;
    double price;
    bool reserved = false;
    bool sold = false;
};

struct UserData {
    std::string name;
};

#endif