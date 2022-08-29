//
// Created by longo on 26/07/2022.
//

#ifndef ACRABSJOURNEY_STATEPEARLSHOP_H
#define ACRABSJOURNEY_STATEPEARLSHOP_H

#include "../Game.h"
#include "../Button.h"
#include "State.h"

class StatePearlShop : public State {
public:
    explicit StatePearlShop(Game* game);
    ~StatePearlShop() override = default;

    void eventHandling(sf::Event event, sf::RenderWindow &window) override;

    void update(int deltaTime, bool clicked) override {}

    void draw(sf::RenderWindow &window) override;

private:
    void reloadCharactersTextures();
    void loadStats();

    sf::Texture texture;
    sf::Sprite backgroundSprite = { texture, sf::IntRect(0, 0, 1920, 1080) };

    // characters
    int currCharacter = 0;
    std::vector<sf::Texture> crabsTextures;
    Button currCharacterBtn = { "Game States/Pearl Shop/Brown Crab.png", 0.21, 630, 510, false };
    Button nextCharacterBtn = { "Game States/Pearl Shop/Fiddler Crab.png", 0.15, 1050, 510, false };
    Button prevCharacterBtn = { "Game States/Pearl Shop/Asian Great Paddle.png", 0.15, 210, 510, false };
    Button currCharacterLocked = { "Game States/Pearl Shop/Locked Character.png", 0.21, 630, 510, false };
    Button nextCharacterLocked = { "Game States/Pearl Shop/Locked Character.png", 0.15, 1050, 510, false };
    Button prevCharacterLocked = { "Game States/Pearl Shop/Locked Character.png", 0.15, 210, 510, false };

    // upgrade bars
    sf::Texture upgradeUnit;
    std::vector<sf::Sprite> upgradesBars;
    Button healthIcon = { "GameCharacter/Player/Stats Icons/Health.png", 0.05, 90, 840, false };
    Button speedIcon = { "GameCharacter/Player/Stats Icons/Speed.png", 0.05, 690, 840, false };
    Button armorIcon = { "GameCharacter/Player/Stats Icons/Armor.png", 0.05, 90, 960, false };
    Button strengthIcon = { "GameCharacter/Player/Stats Icons/Strength.png", 0.05, 690, 960, false };

    // habitats
    Button currHabitatBtn = { "GameCharacter/Player/BrownCrab/Brown Crab.png", 0, 1000, 450, false };
    Button nextHabitatBtn = { "GameCharacter/Player/BrownCrab/Brown Crab.png", 0, 1000, 200, false };
    Button prevHabitatBtn = { "GameCharacter/Player/BrownCrab/Brown Crab.png", 0, 1000, 600, false };
};


#endif //ACRABSJOURNEY_STATEPEARLSHOP_H