#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>

/**
 * @brief `sf::Event` processor.
 * 
 * Process the the main events from the
 * control loop.
 */
class EventProcessor {
    public:
        void process(sf::Event* event, sf::RenderWindow* window);
};

/**
 * @brief Process the event loop.
 * 
 * @param event event to process.
 * @param window window that is affected by event.
 */
void EventProcessor::process(sf::Event* event, sf::RenderWindow* window) {
    if (event->type == sf::Event::Closed) {
        window->close();
    }
}

#endif