#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(float x, float y, float width, float height, std::string words, sf::Font nFont);
    virtual ~Button();
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mousePosition);
    int getButtonState();


protected:

private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    std::string words;

    enum button_state { button_idle, button_hover, button_pressed };
    int buttonState;

};

#endif // BUTTON_H