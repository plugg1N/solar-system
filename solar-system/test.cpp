#include <SFML/Graphics.hpp>
#include "EllipseMovement.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Elliptical Movement");

    EllipseMovement ellipse(100.0f, 50.0f, 0.2f, 0.01f);  // Example parameters, adjust as needed

    sf::CircleShape planetShape(10.0f);  // Planet radius, adjust as needed
    planetShape.setFillColor(sf::Color::Yellow);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f newPosition = ellipse.updatePosition();
        planetShape.setPosition(newPosition + sf::Vector2f(400.0f, 300.0f));  // Centered at (400, 300)

        window.clear();
        window.draw(planetShape);
        window.display();
    }

    return 0;
}
