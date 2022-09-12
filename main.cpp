#include <SFML/Graphics.hpp>

#include <memory>
#include <ctime>
#include <iostream>

#include "FloorMap.h"
#include "Game.h"

int main() {
    // initialize the randomic number generator
    srand(time(nullptr));

    // load window in fullscreen mode
    sf::RenderWindow window(sf::VideoMode(), "A Crab's Journey", sf::Style::Fullscreen);

    // load window in windowed mode
    // sf::RenderWindow window(sf::VideoMode(1366, 768), "A Crab's Journey");
    // sf::RenderWindow window(sf::VideoMode(1440, 900), "A Crab's Journey");
    // sf::RenderWindow window(sf::VideoMode(1280, 1024), "A Crab's Journey");

    // creation of the event
    sf::Event event;

    // create the game
    auto game = Game::getInstance({window.getSize().x, window.getSize().y});
    game->prepareFirstState();

    bool clicked;

    // Game loop
    while (window.isOpen()) {
        int deltaTime = game->clock.restart().asMicroseconds();

        clicked = false;

        while (window.pollEvent(event)) {
            // closing the window and ending the game
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                        clicked = true;
            }
            // handles the event of the current state, like changing state or other actions
            game->eventHandling(event, window);
        }

        // Clearing the old frame and preparing for drawing the new one
        window.clear(sf::Color::White);

        // game update and draw
        game->update(deltaTime, clicked, window);
        game->draw(window);

        // Bring to screen and display the new frame just drawn
        window.display();
    }

    // clean
    delete game;

    // End of the Game
    return 0;
}