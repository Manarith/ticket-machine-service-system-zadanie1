#include "TicketService.hpp"

TicketService::TicketService() {
    tickets.push_back({ 1, 3.50 });
    tickets.push_back({ 2, 1.70 });
    tickets.push_back({ 3, 5.00 });
}

std::optional<Ticket> TicketService::reserveTicket(int id) {
    std::lock_guard<std::mutex> lock(mtx);

    for (auto& t : tickets) {
        if (t.id == id && !t.reserved && !t.sold) {
            t.reserved = true;
            return t;
        }
    }
    return std::nullopt;
}

void TicketService::releaseTicket(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& t : tickets)
        if (t.id == id) t.reserved = false;
}

void TicketService::sellTicket(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& t : tickets)
        if (t.id == id) {
            t.sold = true;
            t.reserved = false;
        }
}

std::optional<Ticket> TicketService::getTicket(int id) {
    for (auto& t : tickets)
        if (t.id == id) return t;
    return std::nullopt;
}