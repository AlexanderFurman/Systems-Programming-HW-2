#include "Mtmchkin.h"

/// omer 8/12: think we need to create an array or cards and copy the cards from the cards given;
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards): 
    m_player(Player(playerName)), m_currentIndex(0), m_status(GameStatus::MidGame), m_numCards(numOfCards)
    {
        m_cards = copyCardArray(cardsArray,numOfCards);
    }

Mtmchkin::~Mtmchkin(){
    delete[] this->m_cards;
}

// Copy constructor
Mtmchkin::Mtmchkin(const Mtmchkin& existingGame) : m_player(existingGame.m_player), m_numCards(existingGame.m_numCards),
    m_currentIndex(existingGame.m_currentIndex), m_status(existingGame.m_status)
{
    m_cards = copyCardArray(existingGame.m_cards,existingGame.m_numCards);
}


//Assignment operator
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& existingGame)
{
    if(this == &existingGame) {
        return *this;
    }

    Card* tmpCards = copyCardArray(existingGame.m_cards, existingGame.m_numCards);

    m_player = existingGame.m_player;
    m_numCards = existingGame.m_numCards;
    m_currentIndex = existingGame.m_currentIndex; // Is this allowed?? accessing attributes of another object but of same class
    m_status = existingGame.m_status;

    delete[] m_cards;
    m_cards = tmpCards;
}

void Mtmchkin::playNextCard()
{
    Card& currentCard = m_cards[m_currentIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
    if(m_player.isKnockedOut()) {
        m_status = GameStatus::Loss;
    }
    else if (m_player.won()){
        m_status = GameStatus::Win;
    }
    printPlayerInfo(m_player.getName().c_str(), m_player.getLevel(), m_player.getForce(), m_player.getHP(), m_player.getCoins());

    // Check if we have reached the end of the array - if so we go back to first index - else, increment by 1
    if(m_currentIndex == m_numCards-1){
        m_currentIndex = 0;
    }
    else{
        m_currentIndex++;
    }
}

GameStatus Mtmchkin::getGameStatus() const{
    return m_status;
}

bool Mtmchkin::isOver() const {
    return (getGameStatus() != GameStatus::MidGame);
}

Card* Mtmchkin::copyCardArray(const Card* sourceCards ,int numOfCards)
{
    Card* cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i)
    {
        cards[i] = sourceCards[i];
    }
    return cards;
}



