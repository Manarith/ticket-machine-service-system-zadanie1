#include "CashRegister.hpp"
#include <cmath>

CashRegister::CashRegister() {
    // przykładowy stan początkowy
    coins[2.0] = 10;
    coins[1.0] = 5;
    coins[0.5] = 2;
    coins[0.2] = 0;
    coins[0.1] = 0;
}

void CashRegister::add(double value, int count) {
    std::lock_guard<std::mutex> lock(mtx);
    coins[value] += count;
}

void CashRegister::remove(double value, int count) {
    std::lock_guard<std::mutex> lock(mtx);
    coins[value] -= count;
}

std::map<double, int, std::greater<>> CashRegister::getState() {
    std::lock_guard<std::mutex> lock(mtx);
    return coins;
}

bool CashRegister::canProvide(double amount) {
    std::lock_guard<std::mutex> lock(mtx);

    double remaining = amount;

    for (auto& [coin, count] : coins) {
        int use = std::min(count, (int)std::floor(remaining / coin));
        remaining -= use * coin;
    }

    return std::fabs(remaining) < 1e-9;
}

std::map<double, int> CashRegister::withdrawChange(double amount) {
    std::lock_guard<std::mutex> lock(mtx);

    double remaining = amount;
    std::map<double, int> used;

    //od największych nominałów
    for (auto& [coin, count] : coins) {

        int use = std::min(count, (int)std::floor(remaining / coin));

        if (use > 0) {
            used[coin] = use;
            remaining -= use * coin;
        }
    }

    // jeśli nie udało się dokładnie wydać reszty => FAIL
    if (std::fabs(remaining) > 1e-9) {
        return {}; // brak rozwiązania
    }

    // zatwierdzamy transakcję (odejmujemy monety)
    for (auto& [coin, count] : used) {
        coins[coin] -= count;
    }

    return used;
}