// Stacheman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y),
        "Stacheman", Style::Fullscreen);

    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    Text startText;
    startText.setFont(font);
    startText.setString("Press Enter to start!");
    startText.setCharacterSize(75);
    startText.setFillColor(Color::White);

    FloatRect startTextRect = startText.getLocalBounds();
    startText.setOrigin(startTextRect.left +
        startTextRect.width / 2.0f,
        startTextRect.top +
        startTextRect.height / 2.0f);
    startText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

    bool paused = true;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            paused = false;
        }

        window.clear();
        window.draw(spriteBackground);
        if (paused) {
            window.draw(startText);
        }
        window.display();
    }

    return 0;
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
