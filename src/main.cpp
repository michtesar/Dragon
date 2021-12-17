// About DC https://www.instructables.com/Dragon-Curve-Using-Python/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphics.h"
#include "bundle.h"
#include "fractal.h"

int main(int argc, char *argv[]) {
    // create the window
    Bundle bundle = Bundle(argv[0]);
    Font fontDejaVuSans = Font(bundle.getBundleAsset("DejaVuSans.ttf"));
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800*2, 600*2), "Dragon Curve v0.2.5", sf::Style::Default, settings);
    int iteration = 0;
    float compression = 1.0f;    
    GraphicsManager gm = GraphicsManager(&window);
    Fractal fractal = Fractal(&gm, 15, 450, 650);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (iteration > 0) {
                    iteration -= 1;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (iteration < fractal.maxIteration) {
                    iteration += 1;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (compression < 2.0) {
                    compression += fractal.compressionStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (compression > 1.0) {
                    compression -= fractal.compressionStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                compression = 1.0f;
                iteration = 0;
            }
        }

        window.clear(sf::Color(25, 25, 25, 255));

        // https://github.com/kurinurm/dragon-curve/blob/master/dragon%20curve%20with%20pygame.py
        fractal.unfoldIteration(15-iteration, 0, 0, 800, 0, compression, compression);

        gm.drawText(
            sf::Vector2f(200, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Iteration " + std::to_string(iteration),
            &fontDejaVuSans.font
        );
        gm.drawText(
            sf::Vector2f(1000, 1050),
            sf::Color(255, 255, 255, 255),
            52,
            "Compression " + std::to_string(int(compression*100)-100),
            &fontDejaVuSans.font
        );
        window.display();
    }
    return 0;
}