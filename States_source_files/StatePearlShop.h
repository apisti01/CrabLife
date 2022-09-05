//
// Created by longo on 26/07/2022.
//

#ifndef ACRABSJOURNEY_STATEPEARLSHOP_H
#define ACRABSJOURNEY_STATEPEARLSHOP_H

#include "State.h"
#include "../Game.h"

class StatePearlShop : public State {
public:
    explicit StatePearlShop(Game *game);

    ~StatePearlShop() override = default;

    void eventHandling(sf::Event event, sf::RenderWindow &window) override;

    void update(int deltaTime, bool clicked, sf::RenderWindow &window) override;

    void draw(sf::RenderWindow &window) override;

private:
    void reloadCharactersTextures();
    void loadStats();

    sf::Texture texture;
    sf::Sprite backgroundSprite = {texture, sf::IntRect(0, 0, 1920, 1080)};

    TextButton titleText = {"Pearl Shop", game->font, 180, {1920 / 2, 150}, false};

    TextButton pearlsText = {to_string(game->globalProgress.pearls), game->font, 80, {1920 / 2, 300}, false};
    SpriteButton pearlsIcon = {"Game States/Pearl.png", 0.035, {1920 / 2, 300}, false};

    // characters
    int currCharacter = 0;
    std::vector<sf::Texture> crabsTextures;
    SpriteButton currCharacterBtn = {"Game States/Pearl Shop/Brown Crab.png", 0.21, {630, 570}};
    SpriteButton currCharacterLocked = {"Game States/Pearl Shop/Locked Character.png", 0.21, {630, 570}};
    SpriteButton currCharacterPearl = {"Game States/Pearl.png", 0.15, {630, 570}};
    TextButton currCharacterPrice = {to_string(game->globalProgress.characters[currCharacter].price), game->font, 120, {630, 570}};

    SpriteButton nextCharacterBtn = {"Game States/Pearl Shop/Fiddler Crab.png", 0.15, {1050, 570}};
    SpriteButton nextCharacterLocked = {"Game States/Pearl Shop/Locked Character.png", 0.15, {1050, 570}};

    SpriteButton prevCharacterBtn = {"Game States/Pearl Shop/Asian Great Paddle.png", 0.15, {210, 570}};
    SpriteButton prevCharacterLocked = {"Game States/Pearl Shop/Locked Character.png", 0.15, {210, 570}};

    // upgrade bars and stats icons
    sf::Texture statsUnitTexture, statsHalfUnitTexture;
    std::vector<SpriteButton> units;

    SpriteButton healthBar = {"Game States/Pearl Shop/Upgrade Bar.png", 1, {350, 870}};
    SpriteButton healthIcon = {"GameCharacter/Player/Stats Icons/Health.png", 0.05, {90, 870}};
    SpriteButton healthUp = {"Game States/Pearl Shop/Upgrade Up.png", 0.035, {560, 870}};
    SpriteButton healthPearl = {"Game States/Pearl.png", 0.05, {90, 870}};
    TextButton healthPrice = {to_string(25), game->font, 50, {90, 870}};

    SpriteButton speedBar = {"Game States/Pearl Shop/Upgrade Bar.png", 1, {950, 870}};
    SpriteButton speedIcon = {"GameCharacter/Player/Stats Icons/Speed.png", 0.05, {690, 870}};
    SpriteButton speedUp = {"Game States/Pearl Shop/Upgrade Up.png", 0.035, {1160, 870}};
    SpriteButton speedPearl = {"Game States/Pearl.png", 0.05, {690, 870}};
    TextButton speedPrice = {to_string(25), game->font, 50, {690, 870}};

    SpriteButton armorBar = {"Game States/Pearl Shop/Upgrade Bar.png", 1, {350, 990}};
    SpriteButton armorIcon = {"GameCharacter/Player/Stats Icons/Armor.png", 0.05, {90, 990}};
    SpriteButton armorUp = {"Game States/Pearl Shop/Upgrade Up.png", 0.035, {560, 990}};
    SpriteButton armorPearl = {"Game States/Pearl.png", 0.05, {90, 990}};
    TextButton armorPrice = {to_string(25), game->font, 50, {90, 990}};

    SpriteButton strengthBar = {"Game States/Pearl Shop/Upgrade Bar.png", 1, {950, 990}};
    SpriteButton strengthIcon = {"GameCharacter/Player/Stats Icons/Strength.png", 0.05, {690, 990}};
    SpriteButton strengthUp = {"Game States/Pearl Shop/Upgrade Up.png", 0.035, {1160, 990}};
    SpriteButton strengthPearl = {"Game States/Pearl.png", 0.05, {690, 990}};
    TextButton strengthPrice = {to_string(25), game->font, 50, {690, 990}};

    // habitats
    SpriteButton currHabitatBtn = {"Game States/Pearl Shop/Brown Crab.png", 0, {1000, 450}};
    SpriteButton nextHabitatBtn = {"Game States/Pearl Shop/Brown Crab.png", 0, {1000, 200}};
    SpriteButton prevHabitatBtn = {"Game States/Pearl Shop/Brown Crab.png", 0, {1000, 600}};

    SpriteButton backBtn = {"Game States/Back Icon.png", 0.2, {150, 150}, true};
};


#endif //ACRABSJOURNEY_STATEPEARLSHOP_H