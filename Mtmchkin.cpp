#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this.player = Player(playerName) // The other things are set automatically right?
    this.cards = new Card[numOfCards]
    this.currentIndex = 0;

}

Mtmchkin::~Mtmchkin(){
    delete[] this.cards
}

Mtmchkin::playNextCard(){
    this.currentIndex ++;
    Card& currentCard = this.cards[currentIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(this.player)
    printPlayerInfo(this.player.m_name, this.player.m_level, this.player.m_force, this.player.m_hp, this.player.coin)
}

Mtmchkin::isOver(){
    return (this.getGameStatus() != GameStatus::MidGame)
}



