/* 
 * This file is part of the Dragon Curve distribution.
 * Copyright (c) 2021-2022 Michael Tesar.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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