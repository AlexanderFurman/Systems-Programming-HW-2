//
// Created by Omer Meushar on 06/12/2022.
//

#ifndef HW2_CLION_PLAYER_H
#define HW2_CLION_PLAYER_H

#include <string>

typedef int PlayerLevel; /// natural number between 1 to 10

class Player {
public:

    Player(const std::string& name, const int maxHP=100, const int force=5);
    ~Player() = default;
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;

    /*** setters and getters: ***/
    PlayerLevel getLevel() const;
    int getAttackStrength() const; /// return force+level

    /*** other required methods ***/
    /// if methods get neg/wrong value treat as got 0
    void printInfo() const;
    void levelUp();
    void buff(int forceIncrease);
    void heal(int addedHP); ///increase HP by addedHP with. total max value of maxHP.
    void damage(int deductedHP);
    bool isKnockedOut() const;
    void addCoins(int addedCoins);
    bool pay(int deductedCoins); ///if false - not committing payment.


private:
    std::string m_name; ///english letters (Aa), no spaces.
    PlayerLevel m_level; /// int in range 1..10
    int m_force; /// int >= 0
    int m_maxHP; /// int > 0
    int m_hp; /// int in range 0..maxHP
    int coins; /// int >= 0

};

#endif //HW2_CLION_PLAYER_H
