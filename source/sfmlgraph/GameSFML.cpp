//
// Created by lander on 12/21/18.
//

#include "GameSFML.h"
#include "../Logic/Transformation.h"

/*
 * TODO
 * make title screen:
 * input area for name, selector for level (level 1, ...)
 *
 * pause screen:
 * black screen, progress on level, restart, quit (to home screen)
 *
 * cars change scaling
 *
 * redo moving logic
 *
 * boss level
 *
 * exception class (std::exception as base)
 *
 * create logic control
 *
 * each entity keeps own distance
 *
 * game -> gameSFML
 */
void GameSFML::draw_screen()
{
        window->clear();

        // do something
        std::unique_ptr<sf::Event> event = std::make_unique<sf::Event>();
        while (window->pollEvent(*event)) {
                if (event->type == sf::Event::Closed ||
                    (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Escape)) {
                        h.save(world->getScore());
                        window->close();
                }
        }
        // Check keyboard input
        world->handleInput();
        world->run();
        world->draw();
        window->display();
}
void GameSFML::init_game()
{
        unsigned int x = config.getWidth();
        unsigned int y = config.getHeight();

        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(x, y), "Racing GameSFML");
        //    window->setVerticalSyncEnabled(false);
        roadfighter::Transformation::Instance()->setSize(window->getSize().x, window->getSize().y);

        world = std::make_shared<WorldSFML>(window);
        score = std::make_shared<roadfighter::ScoreObserver>(world);
        world->attach(score);
}
