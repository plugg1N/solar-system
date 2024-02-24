#ifndef ELLIPSE_MOVEMENT_H
#define ELLIPSE_MOVEMENT_H

#include <SFML/Graphics.hpp>

class EllipseMovement {
public:
    EllipseMovement(float semiMajorAxis, float semiMinorAxis, float rotation, float speed);

    sf::Vector2f updatePosition();

private:
    float semiMajorAxis;
    float semiMinorAxis;
    float rotation;
    float speed;
    float angle;
};

#endif // ELLIPSE_MOVEMENT_H
