#pragma once
#include <ostream>
#include <string>
#include "Stack.h"
#include "Card.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name), hand_(new Stack<Card>()) {}

    ~Player() {
        delete hand_;
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    Stack<Card>* getHand() {
        return hand_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    Stack<Card>* hand_;
    std::string name_;
};

// upload