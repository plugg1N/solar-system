#include "EllipseMovement.h"
#include <cmath>

EllipseMovement::EllipseMovement(float semiMajorAxis, float semiMinorAxis, float rotation, float speed)
    : semiMajorAxis(semiMajorAxis), semiMinorAxis(semiMinorAxis), rotation(rotation), speed(speed), angle(0.0f) {}

sf::Vector2f EllipseMovement::updatePosition() {
    float x = semiMajorAxis * std::cos(angle);
    float y = semiMinorAxis * std::sin(angle);

    // Rotate the position based on the specified rotation angle
    float rotatedX = x * std::cos(rotation) - y * std::sin(rotation);
    float rotatedY = x * std::sin(rotation) + y * std::cos(rotation);

    angle += speed;  // Update the angle for the next frame

    return sf::Vector2f(rotatedX, rotatedY);
}
