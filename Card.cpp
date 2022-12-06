#include "Card.h"


Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats = stats;
}


Card::applyEncounter(Player& player){
    swtich(this->m_effect){
        case Battle:
            if this->stats->force > player.getAttackStrength(){
                player.damage(this->m_stats->hpLossOnDefeat)
            }
            else{
                player.levelUp();
                player.addCoins(this->m_stats->loot)
            }
            printBattleResult(NEED TO PUT IF WIN HERE BOOL)
            break;

        case Buff:
            if(player.pay(this->m_stats->cost)){
                player.buff(this->m_stats->buff)
            }
            break;

        case Heal:
            if(player.pay(this->m_stats->cost)){
                player.heal(this->m_stats->heal)
            }
            break;

        case Treasure:
            player.addCoins(this->m_stats->loot)
            break;
    }
}


Card::printInfo(){
    swtich(this->m_effect){
        case Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case Heal:
            printHealCardInfo(this->m_stats);
            break;
        case Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
    }
}


