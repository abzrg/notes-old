"""
Strategy Design Pattern (Object oriented approach)
--------------------------------------------------

A method tries to do many choices of algorithms (if elif elif ...)
==>
An interface base class along with multiple subclasses with different strategy
implemented with that very method's name


SOURCE: [The strategy pattern: write BETTER PYTHON CODE Part 3](https://youtu.be/WQ8bNdxREHU)
"""

import random
import string
from abc import ABC, abstractmethod
from typing import List


def generate_id(length=8):
    """Helper function for generating an id"""
    return "".join(random.choices(string.ascii_uppercase, k=length))


class SupportTicket:
    id: str
    customer: str  # Name of the customer
    issue: str  # Description of the issue

    def __init__(self, customer, issue):
        self.id = generate_id()
        self.customer = customer
        self.issue = issue


class TicketOrideringStrategy(ABC):
    @abstractmethod
    def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
        pass


class FIFOOrderingStrategy(TicketOrideringStrategy):
    def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
        return list.copy()


class FILOOrderingStrategy(TicketOrideringStrategy):
    def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
        list_copy = list.copy()
        list_copy.reverse()
        return list_copy


class RandomOrderingStrategy(TicketOrideringStrategy):
    def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
        list_copy = list.copy()
        random.shuffle(list_copy)
        return list_copy


class BlackHoleOrderingStrategy(TicketOrideringStrategy):
    def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
        return []


class CustomerSupport:
    """Maintains a list of tickets"""

    tickets: List[SupportTicket] = []

    def create_ticket(self, customer, issue):
        self.tickets.append(SupportTicket(customer, issue))

    # This doesn't know anything about the ticket ordering strategy
    def process_tickets(self, processing_strategy: TicketOrideringStrategy):
        # Create the ordered list
        ticket_list = processing_strategy.create_ordering(self.tickets)

        # if it's empty, don't do anything
        if len(self.tickets) == 0:
            print("There are no tickets to process. Well done!")
            return

        for ticket in ticket_list:
            self.process_ticket(ticket)

    def process_ticket(self, ticket: SupportTicket):
        print("==================================")
        print(f"Processing ticket id: {ticket.id}")
        print(f"Customer: {ticket.customer}")
        print(f"Issue: {ticket.issue}")
        print("==================================")


def main() -> int:
    # Create the application
    app = CustomerSupport()

    # register a few tickets
    app.create_ticket("John Smith", "My computer makes strange sounds!")
    app.create_ticket("Linus Sebastian", "I can't upload any videos, please help.")
    app.create_ticket("Arjan Egges", "VSCode doesn't automatically solve my bugs.")

    # process the tickets
    app.process_tickets(RandomOrderingStrategy())

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
