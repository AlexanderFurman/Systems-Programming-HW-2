#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->player = Player(playerName); // The other things are set automatically right?
    this->cards = new Card[numOfCards];
    this->currentIndex = 0;

}

Mtmchkin::~Mtmchkin(){
    delete[] this->cards;
}

void Mtmchkin::playNextCard(){
    // Check if we have reached the end of the array - if so we go back to first index - else, increment by 1
    if(this->currentIndex == sizeof(this->cards - 1)){
        this->currentIndex = 0;
    }
    else{
            this->currentIndex++;
    }
    Card& currentCard = this->cards[currentIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(this->player);
    printPlayerInfo(this->player.getName(), this->player.getLevel(), this->player.getForce(), this->player.getHP(), this->player.getCoins());
}

bool Mtmchkin::isOver() const{
    return (this->getGameStatus() != GameStatus::MidGame);
}



