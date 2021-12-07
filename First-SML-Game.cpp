// First-SML-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

void Update(CircleShape &triangle, CircleShape &circle, RectangleShape &rect, ConvexShape &convex);
void Draw(RenderWindow &window, CircleShape &triangle, CircleShape &circle, RectangleShape &rect, ConvexShape &convex);

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML works!", Style::Default);

    //window.
    window.setFramerateLimit(60); // limit framerate to 60

    CircleShape triangle;
    triangle.setRadius(50.f);
    triangle.setPointCount(3);
    triangle.setFillColor(Color(200, 200, 50, 150));
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(Color(250, 250, 100, 200));
    triangle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    
    CircleShape circle(50.f);
    circle.setFillColor(Color(100, 200, 100, 100));
    circle.setPosition(Vector2f(150.f, 300.f));

    RectangleShape rect(Vector2f(50.f,100.f));
    rect.setFillColor(Color(100,200,100,200));
    rect.setPosition(Vector2f(400.f, 200.f));

    Vertex line[] = { Vertex(Vector2f(100.f, 250.f)), Vertex(Vector2f(100.f, 250.f)) };
    ConvexShape convex;
    convex.setPosition(Vector2f(150.f, 150.f));

    convex.setPointCount(5);

    convex.setPoint(0, Vector2f(0, 50));
    convex.setPoint(1, Vector2f(150, 10));
    convex.setPoint(2, Vector2f(120, 90));
    convex.setPoint(3, Vector2f(30, 100));
    convex.setPoint(4, Vector2f(0, 50));

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        /*
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        if (Mouse::isButtonPressed(Mouse::Left))
            window.close();
        */
        
        Update(triangle, circle, rect, convex);
        Draw(window, triangle, circle, rect, convex);
    }

    return 0;
}

void Update(CircleShape &triangle, CircleShape &circle, RectangleShape &rect, ConvexShape &convex) {
    circle.move(0.3f, 0.3f);
    circle.rotate(1.2f);
    rect.move(-0.5f, -0.2f);
    rect.rotate(-0.5f);
}

void Draw(RenderWindow &window, CircleShape &triangle, CircleShape &circle, RectangleShape &rect, ConvexShape &convex);
    window.clear(Color::Black);

    window.draw(triangle);
    window.draw(circle);
    window.draw(rect);
    window.draw(convex);

    window.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
