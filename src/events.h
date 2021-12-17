#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>

class EventProcessor {
    public:
        void process(sf::Event* event, sf::RenderWindow* window);
};

void EventProcessor::process(sf::Event* event, sf::RenderWindow* window) {
    if (event->type == sf::Event::Closed) {
        window->close();
    }
}

#endif