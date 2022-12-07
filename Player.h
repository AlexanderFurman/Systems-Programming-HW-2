//
// Created by Omer Meushar on 06/12/2022.
//

#ifndef HW2_CLION_PLAYER_H
#define HW2_CLION_PLAYER_H

#include <string>

typedef int PlayerLevel; /// natural number between 1 to 10

class Player {
public:

    static const int NEW_PLAYER_FORCE = 5;
    static const int NEW_PLAYER_MAXHP = 100;
    static const int PLAYER_MAX_LEVEL = 10;



    explicit Player(const std::string& name, int maxHP=100, int force=5); ///should it be string& or by value?
    ~Player() = default;
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;

    /*** setters and getters: ***/

    int getAttackStrength() const; /// return force+level
    const std::string& getName() const;
    PlayerLevel getLevel() const;
    int getForce() const;
    int getMaxHP() const;
    int getHP() const;
    int getCoins() const;

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
    int m_HP; /// int in range 0..maxHP
    int m_coins; /// int >= 0

};

#endif //HW2_CLION_PLAYER_H
