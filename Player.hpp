#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Player(std::string playerName);
    void takeDamage(int amount);
    bool isAlive();
    void displayStatus();
    int getAttackPower();
};

#endif