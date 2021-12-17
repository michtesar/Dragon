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
#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "bundle.h"
#include "fractal.h"
#include "version.h"
#include "config.h"
#include "keyboard.h"
#include "events.h"

int main(int argc, char *argv[]) {
    // Initialize bundle and fonts before opening window
    Bundle bundle = Bundle(argv[0]);
    Font fontDejaVuSans = Font(bundle.getBundleAsset(FONT_DEJAVU_SANS));
    
    // Create a main window with settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTIALIASING;
    std::string version = "v" + 
        std::to_string(DRAGON_VERSION_MAJOR) + "." + 
        std::to_string(DRAGON_VERSION_MINOR) + "." + 
        std::to_string(DRAGON_VERSION_PATCH);
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), 
        "Dragon Curve " + version, 
        sf::Style::Default, 
        settings
    );

    // Create a graphics manager for drawing on window    
    GraphicsManager gm = GraphicsManager(&window);

    // Initialize the fractal engine
    int iteration = 0;
    float compression = 1.0f;
    Fractal fractal = Fractal(&gm, 15, 450, 650);
    
    // Inititalize and process keyboard and events
    KeyboardProcessor keyboardProcessor;
    EventProcessor eventsProcessor;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            keyboardProcessor.process(
                &iteration, 
                &compression, 
                &fractal.compressionStep,
                &fractal.maxIteration, 
                &window
            );
            eventsProcessor.process(&event, &window);
        }

        // Clear buffer with dark grey color
        window.clear(sf::Color(25, 25, 25, 255));

        // Unfold corresponding iteration of the dragon curve
        fractal.unfoldIteration(15-iteration, 0, 0, 800, 0, compression, compression);

        // Show informative text to use about iteration
        gm.drawText(
            sf::Vector2f(200, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Iteration " + std::to_string(iteration),
            &fontDejaVuSans.font
        );

        // Show informative text to use about compression
        gm.drawText(
            sf::Vector2f(1000, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Compression " + std::to_string(int(compression*100)-100),
            &fontDejaVuSans.font
        );

        // Swap buffers
        window.display();
    }

    return 0;
}