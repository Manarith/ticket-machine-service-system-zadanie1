#ifndef CHANGECALCULATOR_HPP
#define CHANGECALCULATOR_HPP

#include <map>

class ChangeCalculator {
public:
    static std::map<double, int> calculate(double amount, std::map<double, int, std::greater<>>& cash);
};

#endif