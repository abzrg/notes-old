"""
In the following code we don't use the strategy pattern, and simply check for
each strategy in one single long method


SOURCE: [The strategy pattern: write BETTER PYTHON CODE Part 3](https://youtu.be/WQ8bNdxREHU)
"""

import random
import string
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


class CustomerSupport:
    """Maintains a list of tickets"""

    tickets: List[SupportTicket] = []

    def create_ticket(self, customer, issue):
        self.tickets.append(SupportTicket(customer, issue))

    def process_tickets(self, processing_strategy: str = "fifo"):
        # if it's empty, don't do anything
        if len(self.tickets) == 0:
            print("There are no tickets to process. Well done!")
            return

        # Implementing everything here
        if processing_strategy == "fifo":
            for ticket in self.tickets:
                self.process_ticket(ticket)
        elif processing_strategy == "filo":
            for ticket in reversed(self.tickets):
                self.process_ticket(ticket)
        elif processing_strategy == "random":
            list_copy = self.tickets.copy()
            random.shuffle(list_copy)
            for ticket in list_copy:
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
    app.process_tickets("filo")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
