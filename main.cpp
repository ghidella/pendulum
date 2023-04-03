#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pendulum");

    // set up variables
    const float gravity = 9.81f; // m/s^2
    const float length = 400.f;  // length of the pendulum in pixels
    const float radius = 50.f;   // radius of the circle in pixels
    float angle = 45.f;          // initial angle of the pendulum in degrees
    float angularVelocity = 0.f; // initial angular velocity of the pendulum
    float timeStep = 1.f / 60.f; // time step in seconds

    // define the line segment
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(400.f, 0.f); // x, y coordinates
    line[1].position = sf::Vector2f(400.f, length);

    // create the circle
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin(radius, radius); // set the origin to the center of the circle

    // main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // calculate the angular acceleration
        float angularAcceleration = -gravity / length * std::sin(angle * M_PI / 180.f);

        // update the angular velocity and angle
        angularVelocity += angularAcceleration * timeStep;
        angle += angularVelocity * timeStep;

        // update the position of the circle
        float x = length * std::sin(angle * M_PI / 180.f);
        float y = length * std::cos(angle * M_PI / 180.f);
        circle.setPosition(line[0].position.x + x, line[0].position.y + y);

        // update the position of the second vertex of the line
        line[1].position = sf::Vector2f(line[0].position.x + x, line[0].position.y + y);

        // clear the window
        window.clear(sf::Color::White);

        // draw the line
        window.draw(line);

        // draw the circle
        window.draw(circle);

        // draw a line from the top of the line segment to the position of the circle
        sf::Vertex connector[] =
            {
                sf::Vertex(line[0].position),
                sf::Vertex(circle.getPosition())

            };
        // set the color of the connector
        sf::Color connectorColor = sf::Color::Black;
        connector[0].color = connectorColor;
        connector[1].color = connectorColor;
        window.draw(connector, 2, sf::Lines);

        // display the window
        window.display();
    }

    return 0;
}
