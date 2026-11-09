#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Enemy(std::string enemyName, int hp, int power);
    void takeDamage(int amount);
    bool isAlive();
    void displayStatus();
    int getAttackPower();
};

#endif