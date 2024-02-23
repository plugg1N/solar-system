#include <iostream>
#include "shapes.h"

void drawEllipseOutline(sf::RenderWindow& window, float x, float y, float radiusX, float radiusY, const sf::Color& outlineColor, float outlineThickness) {
    sf::CircleShape ellipse;
    ellipse.setPosition(x, y);
    ellipse.setPointCount(100);
    ellipse.setRadius(radiusX);  // Set the radius along the x-axis
    ellipse.setScale(1.0f, radiusY / radiusX);  // Scale along the y-axis to achieve an elliptical shape
    ellipse.setFillColor(sf::Color::Transparent);
    ellipse.setOutlineColor(outlineColor);
    ellipse.setOutlineThickness(outlineThickness);

    window.draw(ellipse);
}