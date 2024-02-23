#include <SFML/Graphics.hpp>
#include "celectialConstants.h"
#include "shapes.h"
#include <string>
#include <cmath>
#include <iostream>
#include <vector>


struct CelectialBody {
    sf::CircleShape shape;
    sf::Vector2f position;
    float radius;
};


int main()
{

    std::vector<sf::Vector2f> initPositions{};


    // Create initPositions for each planet
    for (int i = 0; i < planetDist.size(); ++i) {
        if (planetDist[i] != dSUN) {
            initPositions.push_back(
                {
                    (SCR_WIDTH / 2) + R_SUN + planetRadii[i] + (planetDist[i] * AU), (SCR_HEIGHT / 2) - planetRadii[i]
                });
        }

        else {
            initPositions.push_back(
                {
                    (SCR_WIDTH / 2) - R_SUN + (planetDist[i] * AU), (SCR_HEIGHT / 2) - planetRadii[i]
                });

        }
    }
    
    // Create objects of bodies
    std::vector<CelectialBody> cBodies(planetRadii.size());




    // Initialize shapes, colors, and positions for each body
    for (int i = 0; i < planetDist.size(); ++i) {
        // If SUN
        if (planetRadii[i] == R_SUN)
            cBodies[i].shape = sf::CircleShape(planetRadii[i] - OFFSET);

        else
            cBodies[i].shape = sf::CircleShape(planetRadii[i] + OFFSET);

        cBodies[i].shape.setFillColor(planetColors[i]);
        cBodies[i].position = initPositions[i];
        cBodies[i].shape.setPosition(cBodies[i].position);
    }




    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Solar system", sf::Style::Close);




    // MAIN LOOP
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw all planets
        for (const auto& planet : cBodies) {
            window.draw(planet.shape);
        }

        drawEllipseOutline(window, SCR_WIDTH/2-400.f, SCR_HEIGHT/2-150.f, 400.f, 150.f, sf::Color::White, 2.0f);

        window.display();
    }

    return 0;
}