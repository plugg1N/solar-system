#include <SFML/Graphics.hpp>
#include "celectialConstants.h"
#include <iostream>
#include <string>
#include <cmath>



class Planet {
public:
    std::string name;
    static const double sun_collision_radius;
    double x, y, radius, mass, distance_to_sun;
    bool sun;
    double x_vel, y_vel;
    sf::Color color;

    std::vector<sf::Vector2f> orbit;

    Planet(const std::string& planetName, double x, double y, double radius, sf::Color color, double mass)
        : name(planetName), x(x), y(y), radius(radius), color(color), mass(mass), sun(false), distance_to_sun(0), x_vel(0), y_vel(0) {}

    void draw(sf::RenderWindow& win) {
        double screen_x = x * SCALE + win.getSize().x / 2;
        double screen_y = y * SCALE + win.getSize().y / 2;


        // Draw the line from Sun to the planet
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(win.getSize().x / 2, win.getSize().y / 2);  // Sun position
        line[0].color = sf::Color::Red;
        line[1].position = sf::Vector2f(screen_x, screen_y);  // Planet position
        line[1].color = color;

        win.draw(line);


        if (orbit.size() > 2) {
            std::vector<sf::Vector2f> updated_points;
            for (const auto& point : orbit) {
                double x = point.x * SCALE + win.getSize().x / 2;
                double y = point.y * SCALE + win.getSize().y / 2;
                updated_points.emplace_back(x, y);
            }


            sf::VertexArray lines(sf::LineStrip, updated_points.size());
            for (size_t i = 0; i < updated_points.size(); ++i) {
                lines[i].position = updated_points[i];
                lines[i].color = sf::Color::White;
            }
            win.draw(lines);
        }

        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setPosition(screen_x - radius, screen_y - radius);
        win.draw(circle);

        if (!sun) {
            sf::Font font;
            font.loadFromFile("arial.ttf");

            sf::Text name_text;
            name_text.setFont(font);
            name_text.setString(name);
            name_text.setCharacterSize(16);
            name_text.setFillColor(sf::Color::Green);
            name_text.setPosition(screen_x - radius / 2 - 30.f, screen_y - radius / 2 - 30.f);
            win.draw(name_text);

            sf::Text distance_text;
            distance_text.setFont(font);
            distance_text.setString(std::to_string(static_cast<int>(distance_to_sun / 1000000)) + "M km");
            distance_text.setCharacterSize(16);
            distance_text.setFillColor(sf::Color::Green);
            distance_text.setPosition(screen_x - radius / 2 - 30.f, screen_y - radius / 2 + 20.f);
            win.draw(distance_text);
        }
    }

    sf::Vector2f attraction(const Planet& other) {
        double distance_x = other.x - x;
        double distance_y = other.y - y;
        double distance = std::sqrt(distance_x * distance_x + distance_y * distance_y);

        if (other.sun) {
            distance_to_sun = distance;
        }


        double force = G * mass * other.mass / (distance * distance) * 0.09f;
        double theta = std::atan2(distance_y, distance_x);
        double force_x = std::cos(theta) * force;
        double force_y = std::sin(theta) * force;
        return sf::Vector2f(force_x, force_y);
    }

    void update_position(const std::vector<Planet>& planets) {
        double total_fx = 0, total_fy = 0;
        for (const auto& planet : planets) {
            if (this == &planet) {
                continue;
            }

            sf::Vector2f force = attraction(planet);
            total_fx += force.x;
            total_fy += force.y;
        }

        x_vel += total_fx / mass * TIMESTEP;
        y_vel += total_fy / mass * TIMESTEP;

        x += x_vel * TIMESTEP;
        y += y_vel * TIMESTEP;
        orbit.emplace_back(x, y);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1700, 900), "Planet Simulation");
    window.setFramerateLimit(89);

    std::vector<Planet> planets;




    Planet sun("Sun", 0, 50, 40, sf::Color::Yellow, 1.98892 * 10e30);
    sun.sun = true;

    Planet earth("Earth", 1 * AU, 600, 12, sf::Color(100, 149, 237), 5.9742 * 10e24);
    earth.y_vel = 29.783 * 1000;

    Planet mars("Mars", 1.524 * AU, 700, 8, sf::Color(188, 39, 50), 6.39 * 10e23);
    mars.y_vel = 24.077 * 1000;

    Planet mercury("Mercury", 0.387 * AU, 800, 4, sf::Color(80, 78, 81), 3.30 * 10e23);
    mercury.y_vel = 47.4 * 1000;

    Planet venus("Venus", 0.723 * AU, 900, 10, sf::Color::White, 4.8685 * 10e24);
    venus.y_vel = 35.02 * 1000;



    planets = { sun, earth, mars, mercury, venus };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (auto& planet : planets) {
            planet.update_position(planets);
            planet.draw(window);
        }


        sf::Font font;
        font.loadFromFile("arial.ttf");

        sf::Text info_time_step;
        info_time_step.setFont(font);
        info_time_step.setString("Time Step: " + std::to_string(static_cast<int>(TIMESTEP/86000)));
        info_time_step.setCharacterSize(22);
        info_time_step.setFillColor(sf::Color::White);
        info_time_step.setPosition(14.f, 14.f);


        window.draw(info_time_step);
        window.display();
    }

    return 0;
}
