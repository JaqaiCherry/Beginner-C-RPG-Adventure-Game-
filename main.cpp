#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Enemy.hpp"

// Function to handle combat logic
bool startCombat(Player &hero) {
    // Seed random number generator based on current time
    srand(time(0));

    Enemy goblin("Dungeon Goblin", 50, 20);
    std::cout << "\nA wild Dungeon Goblin blocks your path!\n";

    while (hero.isAlive() && goblin.isAlive()) {
        hero.displayStatus();
        goblin.displayStatus();

        int choice;
        std::cout << "\nChoose action:\n1. Attack\n2. Try to Run\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            // --- PLAYER TURN ---
            // Random number between 1 and 100. Needs to be > 50 to land.
            int playerHitRoll = (rand() % 100) + 1;
            std::cout << "\nYou swing your weapon! (Roll: " << playerHitRoll << "/100)\n";

            if (playerHitRoll > 50) {
                std::cout << "Your attack hits the goblin!\n";
                goblin.takeDamage(hero.getAttackPower());
            } else {
                std::cout << "You missed!\n";
            }

            // Check if enemy survived player's attack
            if (!goblin.isAlive()) {
                std::cout << "\nYou defeated the goblin!\n";
                return true; // Player wins combat
            }

            // --- ENEMY TURN ---
            // Enemy has a 50/50 chance (Roll > 50) to attack or defend/miss
            int enemyHitRoll = (rand() % 100) + 1;
            std::cout << "\nThe goblin lunges at you! (Roll: " << enemyHitRoll << "/100)\n";

            if (enemyHitRoll > 50) {
                std::cout << "The goblin's attack lands!\n";
                hero.takeDamage(enemyHitRoll); // using enemy attack power or hit roll
            } else {
                std::cout << "The goblin trips and misses its attack!\n";
            }

            if (!hero.isAlive()) {
                return false; // Player lost combat
            }

        } else {
            std::cout << "\nYou tried to run away, but the goblin blocked your exit!\n";
        }
    }
    return hero.isAlive();
}

int main() {
    std::string name;
    std::cout << "=== DUNGEON ESCAPE ===\n";
    std::cout << "Enter player name: ";
    std::cin >> name;

    Player hero(name);
    int choice = 0;

    while (hero.isAlive() && choice != 3) {
        hero.displayStatus();
        std::cout << "\n1. Open door (Enter Combat Room)\n2. Search room\n3. Quit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            // Start the combat sequence
            bool victory = startCombat(hero);
            
            if (victory) {
                std::cout << "\nYou step past the defeated foe and escape the dungeon! YOU WIN!\n";
                break;
            } else {
                std::cout << "\nYou were slain by the enemy...\n";
                break; // Triggers restart / game over loop logic
            }
        } else if (choice == 2) {
            std::cout << "\nYou found a hidden trap and took 10 damage!\n";
            hero.takeDamage(10);
        }
    }

    if (!hero.isAlive()) {
        std::cout << "\nGAME OVER. You must restart from the beginning.\n";
    }

    return 0;
}