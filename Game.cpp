//
// Created by apisti01 on 18/07/22.
//

#include "Game.h"
#include "StateTitleScreen.h"
#include "StateMainMenu.h"
#include "StatePearlShop.h"
#include "StatePlay.h"
#include "StateDisplayMap.h"
#include "StateManageInventory.h"
#include "StateShop.h"
#include "StatePause.h"
#include "StateSettings.h"

#include <iostream>

Game* Game::gameInstance = nullptr;

Game *Game::getInstance() {
    if (gameInstance == nullptr)
        gameInstance = new Game();
    return gameInstance;
}

Game::Game() : currentState(make_unique<StateTitleScreen>(this)) {
    // load font
    sf::Font Rancho;
    if (!Rancho.loadFromFile("Font/Arial/Arial.ttf")) {
        cout << "font non caricato" << endl;
        system("pause");
    }
    font = Rancho;
}

void Game::changeState(StateType type) {
    std::unique_ptr<State> tmp;

    // FIXME to complete
    // based on the enum it creates a new instance of a derived state class
    switch (type) {
        case StateType::MainMenu:
            tmp = std::make_unique<StateMainMenu>(this);
            break;
        case StateType::PearlShop:
            tmp = std::make_unique<StatePearlShop>(this);
            break;
        case StateType::Play:
            tmp = std::make_unique<StatePlay>(this);
            break;
        case StateType::DisplayMap:
            tmp = std::make_unique<StateDisplayMap>(this);
            break;
        case StateType::ManageInventory:
            tmp = std::make_unique<StateManageInventory>(this);
            break;
        case StateType::Shop:
            tmp = std::make_unique<StateShop>(this);
            break;
        case StateType::Pause:
            tmp = std::make_unique<StatePause>(this);
            break;
        case StateType::Settings:
            tmp = std::make_unique<StateSettings>(this);
            break;
    }
    // the current state became the one just created, deleting the old one
    currentState = std::move(tmp);
}
