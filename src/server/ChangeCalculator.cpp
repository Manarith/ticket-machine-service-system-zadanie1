#include "ChangeCalculator.hpp"
#include "CashRegister.hpp"

std::map<double, int> ChangeCalculator::calculate(double amount, std::map<double, int, std::greater<>>& cash) {
    CashRegister temp;
    for (auto& [v, c] : cash) temp.add(v, c);

    if (!temp.canProvide(amount))
        return {};

    return temp.withdrawChange(amount);
}