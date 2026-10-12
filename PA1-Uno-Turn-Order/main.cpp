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




    Card redSeven("Red", "7");
    Card blueSeven("Blue", "7");
    std::cout << "- John plays a " << redSeven << "." << std::endl;
    std::cout << "- Manju plays a " << blueSeven << "." << std::endl;
    std::cout << std::endl;

    std::cout << "== New Player Joins (addAnywhere) ==" << std::endl;
    table->addAnywhere(2, new Player(4, "LLoyd"));
    std::cout << "- LLoyd arrives late and sits at position 2 in the table." << std::endl;
    std::cout << "Updated Table Order: ";
    table->print();
    std::cout << std::endl;

    std::cout << "== Table Reversing (reverse) ==" << std::endl;
    Card reverseCard("Green", "Reverse");
    std::cout << "- Jesus plays a " << reverseCard << "! The order reverses." << std::endl;
    table->reverse();
    std::cout << "Reversed Table Order: ";
    table->print();
    std::cout << std::endl;

    std::cout << "== Player Winning (deleteAnywhere) ==" << std::endl;
    std::cout << "- The player at position 1 plays their last card and screams 'I won!'" << std::endl;
    table->deleteAnywhere(1);
    std::cout << "Table Order after the winner leaves: ";
    table->print();
    std::cout << std::endl;

    // Setting up a second table of players for a table merge (concat)
    std::cout << "== Merging Tables (Concat) ==" << std::endl;
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addBack(new Player(5, "Mufasa"));
    table2->addBack(new Player(6, "Simba"));
    table2->addBack(new Player(7, "Scar"));

    std::cout << "Second table waiting to join: ";
    table2->print();
    std::cout << std::endl;

    // Merge the second table into the first table
    table->concat(table2.get());
    std::cout << "First table after concatenating the second table: ";
    table->print();
    std::cout << "Second table after concat: ";
    table2->print();




    return 0;
}

// upload