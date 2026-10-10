#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::cout << std::endl << "== Uno Turn Order Scene ==" << std::endl;
    std::unique_ptr<List<Player>> table = makeList<Player>();
    table->addBack(new Player(1, "John"));
    table->addBack(new Player(2, "Manju"));
    table->addBack(new Player(3, "Jesus"));
    std::cout << "Starting table: ";
    table->print();

    table->addAnywhere(2, new Player(4, "LLoyd"));
    std::cout << "LLoyd joins the table at position 2: ";
    table->print();
    std::cout << std::endl;

    table->reverse();
    std::cout << "After a reverse card is played: ";
    table->print();
    std::cout << std::endl;

    table->deleteAnywhere(1);
    std::cout << "After the player in position 1 runs out of cards: ";
    table->print();
    std::cout << std::endl;

    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addBack(new Player(5, "Mufasa"));
    table2->addBack(new Player(6, "Simba"));
    table2->addBack(new Player(7, "Scar"));
    std::cout << "Second table before performing concat: ";
    table2->print();
    std::cout << std::endl;

    table->concat(table2.get());
    std::cout << "First table after concat: ";
    table->print();
    std::cout << "Second table after concat: ";
    table2->print();

    return 0;
}

// upload