#ifndef TICKETSERVICE_HPP
#define TICKETSERVICE_HPP

#include "common/Models.hpp"
#include <vector>
#include <mutex>
#include <optional>

class TicketService {
    std::vector<Ticket> tickets;
    std::mutex mtx;

public:
    TicketService();

    std::optional<Ticket> reserveTicket(int id);
    void releaseTicket(int id);
    void sellTicket(int id);
    std::optional<Ticket> getTicket(int id);
};

#endif