#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(std::string enemyName, int hp, int power) {
    name = enemyName;
    health = hp;
    attackPower = power;
}

void Enemy::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

bool Enemy::isAlive() {
    return health > 0;
}

void Enemy::displayStatus() {
    std::cout << "[Enemy: " << name << " | HP: " << health << "]\n";
}

int Enemy::getAttackPower() {
    return attackPower;
}