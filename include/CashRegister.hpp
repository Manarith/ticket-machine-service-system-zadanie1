#ifndef CASHREGISTER_HPP
#define CASHREGISTER_HPP

#include <map>
#include <mutex>

class CashRegister {
private:
    std::map<double, int, std::greater<>> coins;
    std::mutex mtx;

public:
    CashRegister();

    void add(double value, int count);
    void remove(double value, int count);

    std::map<double, int, std::greater<>> getState();

    bool canProvide(double amount);
    std::map<double, int> withdrawChange(double amount);
};

#endif