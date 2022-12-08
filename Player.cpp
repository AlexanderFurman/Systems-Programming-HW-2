//
// Created by Omer Meushar on 06/12/2022.
//

#include "Player.h"
#include "utilities.h" ///for printing player info



/*** constructor ***/
///should it be string& or by value?
Player::Player(const std::string& name, const int maxHP, const int force) :
    m_name(name), m_level(1), m_force(force),
    m_maxHP(maxHP), m_HP(maxHP), m_coins(0)
   {
        if (maxHP<=0) {
            m_maxHP = NEW_PLAYER_MAXHP;
            m_HP = NEW_PLAYER_MAXHP;
        }
        if (force<0) {
            m_force = NEW_PLAYER_FORCE;
        }
   }

/*** getters and setters ***/
int Player::getAttackStrength() const // return force+level  // required
{
    return m_force+m_level;
}

const std::string& Player::getName() const 
{
    return m_name; // This should return *char instead of std__string, in oredr to match with the method printPlayerInfo
}

PlayerLevel Player::getLevel() const // required
{
    return m_level;
}

int Player::getForce() const
{
    return m_force;
}

//int Player::getMaxHP() const
//{
//    return m_maxHP;
//}

int Player::getHP() const
{
    return m_HP;
}

int Player::getCoins() const
{
    return m_coins;
}


/*** required methods ***/

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level < PLAYER_MAX_LEVEL) {
        m_level++;
    }
}

void Player::buff(int forceIncrease)
{
    if(forceIncrease > 0) {
        m_force += forceIncrease;
    }
}

void Player::heal(int addedHP)
{
    if(addedHP<=0) {
        return;
    }
    m_HP = (m_HP+addedHP>=m_maxHP) ? m_maxHP : m_HP+addedHP;
}

void Player::damage(int deductedHP)
{
    if(deductedHP<=0) {
        return;
    }
    m_HP = (m_HP-deductedHP<0) ? 0 : m_HP-deductedHP;
}

bool Player::isKnockedOut() const
{
    return (m_HP==0);
}

void Player::addCoins(int addedCoins)
{
    m_coins += (addedCoins<=0) ? 0 : addedCoins;
}

bool Player::pay(int deductedCoins)
{
    if(deductedCoins<=0) { //piazza @205
        return true;
    }
    if(m_coins-deductedCoins<0) { // doesn't have enough coins
        return false;
    }
    m_coins = m_coins-deductedCoins; // has enough coins
    return true;
}

bool Player::won() const{
    return getLevel() == PLAYER_MAX_LEVEL;
}
