#include "Server.hpp"
#include "ChangeCalculator.hpp"
#include <iostream>

bool Server::selectTicket(const std::string& session, int id) {
    auto t = tickets.reserveTicket(id);
    if (!t) return false;

    sessions.setTicket(session, id);
    return true;
}

bool Server::cancel(const std::string& session) {
    int id = sessions.getTicket(session);
    if (id != -1) tickets.releaseTicket(id);
    return true;
}

bool Server::pay(const std::string& session, double money, std::string user) {
    int id = sessions.getTicket(session);

    auto ticket = tickets.getTicket(id);
    if (!ticket) return false;

    double change = money - ticket->price;

    auto coins = cash.getState();
    auto result = ChangeCalculator::calculate(change, coins);

    if (change > 0 && result.empty()) {
        tickets.releaseTicket(id);
        return false;
    }

    tickets.sellTicket(id);

    std::cout << "Bilet sprzedany dla " << user
        << " ID: " << id
        << " reszta: " << change << "\n";

    return true;
}