#include "Card.h"

Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats){}


void Card::applyEncounter(Player& player) const{
    switch(this->m_effect){
        case CardType::Battle:{
            const bool wonFight = (this->m_stats.force <= player.getAttackStrength());
            if(!wonFight){
                player.damage(this->m_stats.hpLossOnDefeat);
            }
            else{
                player.levelUp();
                player.addCoins(this->m_stats.loot);
            }
            printBattleResult(wonFight);
            break;
        }
            

        case CardType::Buff:{
            if(player.pay(this->m_stats.cost)){
                player.buff(this->m_stats.buff);
            }
            break;
        }
            

        case CardType::Heal:{
            if(player.pay(this->m_stats.cost)){
                player.heal(this->m_stats.heal);
            }
            break;
        }
            

        case CardType::Treasure:{
            player.addCoins(this->m_stats.loot);
            break;
        }
            
    }
}


void Card::printInfo() const{
    switch(this->m_effect){
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
    }
}


