#pragma once

#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "Button.h"

class AppManager
{
public:
    AppManager(int width, int height);
    virtual ~AppManager();
    void update();
    void render();
    void mainLoop();


protected:

private:
    Button* MenuButton_SideWindowOpen;
    Button* MenuButton_Exit;
    Button* SideMenuButton_MenuWindowOpen;
    Button* TopButton_Geography;
    Button* TopButton_Films;
    Button* TopButton_Games;
    Button* TopButton_Books;
    Button* TopButton_Music;

    sf::RenderWindow* window;

    sf::Font nFont;

    int width;
    int height;
    sf::Event event;

    enum window_state { main_menu, top, side_window };
    int windowState;

};

#endif // APPMANAGER_H
