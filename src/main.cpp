// About DC https://www.instructables.com/Dragon-Curve-Using-Python/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include "graphics.h"
#include "bundle.h"

namespace fs = std::filesystem;

void line(sf::RenderWindow* window, sf::Vector2f p1, sf::Vector2f p2) {
    sf::Vertex line[] = {
        sf::Vertex(p1, sf::Color::Cyan),
        sf::Vertex(p2, sf::Color::Cyan)
    };
    window->draw(line, 2, sf::Lines);
}

void unfoldCurve(sf::RenderWindow* window, int maxIteration, int iteration, float x1, float y1, float x2, float y2, int offsetX, int offsetY, float shapeX, float shapeY) {
    if (iteration >= maxIteration) {
        line(window, sf::Vector2f(x1+offsetX, y1+offsetY), sf::Vector2f(x2+offsetX, y2+offsetY));
    } else {
        float x = (x1 + x2)/2.0 + (y2 - y1)/2.0/shapeX;
        float y = (y1 + y2)/2.0 - (x2 - x1)/2.0/shapeY;
        unfoldCurve(window, maxIteration, iteration+1, x1, y1, x, y, offsetX, offsetY, shapeX, shapeY);
        unfoldCurve(window, maxIteration, iteration+1, x2, y2, x, y, offsetX, offsetY, shapeX, shapeY);
    }
}

void drawText(sf::RenderWindow* window, std::string text, int size, sf::Color color, sf::Vector2f position) {
    sf::Text textProxy;
    sf::Font font;
    if (!font.loadFromFile("./DejaVuSans.ttf")) {
        // sf::err() << "Couldn't load font\n";
    }
    textProxy.setFont(font);
    textProxy.setString(text);
    textProxy.setCharacterSize(size);
    textProxy.setFillColor(color);
    textProxy.setPosition(position);
    window->draw(textProxy);
}

int main(int argc, char *argv[]) {
    // create the window
    Bundle bundle = Bundle(argv[0]);
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800*2, 600*2), "Dragon Curve v0.2.5", sf::Style::Default, settings);
    int i = 0;
    float compression = 1.0f;
    int maxIterations = 15;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (i > 0) {
                    i -= 1;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (i < maxIterations) {
                    i += 1;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (compression < 2.0) {
                    compression += 0.01;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (compression > 1.0) {
                    compression -= 0.01;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                compression = 1.0f;
                i = 0;
            }
        }

        // std::cout << "Path: " << bundle.getBundleRoot() << std::endl;
        // std::cout << "Path: " << bundle.getBundleAsset("DejaVuSans.ttf") << std::endl;

        // clear the window with black color
        window.clear(sf::Color(25, 25, 25, 255));

        // Dragon curve
        // https://github.com/kurinurm/dragon-curve/blob/master/dragon%20curve%20with%20pygame.py
        unfoldCurve(&window, i, 0, 0, 0, 800, 0, 450, 650, compression, compression);

        drawText(&window, "Iteration " + std::to_string(i), 52, sf::Color(255, 255, 255, 255), sf::Vector2f(200.0, 1050.0));
        drawText(&window, "Compression " + std::to_string(int(compression*100)-100), 52, sf::Color(255, 255, 255, 255), sf::Vector2f(1000.0, 1050.0));

        GraphicsManager gm = GraphicsManager(&window);
        gm.drawLine(sf::Vector2f(100, 100), sf::Vector2f(300, 400), sf::Color(255, 255, 0, 255));
        
        gm.drawText(sf::Vector2f(200, 200), sf::Color(255, 255, 255, 255), 52, "Sample Example", bundle.getBundleAsset("DejaVuSans.ttf"));
        drawText(&window, bundle.getBundleRoot(), 52, sf::Color(255, 255, 255, 255), sf::Vector2f(100.0, 100.0));
        // std::cout << bundle.getBundleAsset("DejaVuSans.ttf") << std::endl;

        // end the current frame
        window.display();
    }
    return 0;
}