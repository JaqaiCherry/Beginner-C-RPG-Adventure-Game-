#include "Player.hpp"
#include <iostream>

Player::Player(std::string playerName) {
    name = playerName;
    health = 100;
    attackPower = 25; // Default player damage
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

bool Player::isAlive() {
    return health > 0;
}

void Player::displayStatus() {
    std::cout << "\n[" << name << " | HP: " << health << "]\n";
}

int Player::getAttackPower() {
    return attackPower;
}