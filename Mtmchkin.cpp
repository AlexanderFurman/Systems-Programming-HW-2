#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->player = Player(playerName); // The other things are set automatically right?
    this->cards = new Card[numOfCards];
    this->currentIndex = 0;

}

Mtmchkin::~Mtmchkin(){
    delete[] this->cards;
}

// Copy constructor
Mtmchkin::Mtmchkin(const Mtmchkin& existingGame){
    this->player = existingGame.player;
    // Deepcopy of array
    for(int i = 0; i < sizeof(existingGame.cards); i++){
        this->cards[i] = existingGame.cards[i];
    }
    this->currentIndex = existingGame.currentIndex; // Is this allowed?? accessing attributes of another object but of same class
}

//Assignment operator
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& existingGame){
    this->player = existingGame.player;
    this->cards = existingGame.cards;
    // Deepcopy of array
    for(int i = 0; i < sizeof(existingGame.cards); i++){
        this->cards[i] = existingGame.cards[i];
    }

    this->currentIndex = existingGame.currentIndex; // Is this allowed?? accessing attributes of another object but of same class
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

GameStatus Mtmchkin::getGameStatus() const{
    return this->status;
}

bool Mtmchkin::isOver() const{
    return (this->getGameStatus() != GameStatus::MidGame);
}



