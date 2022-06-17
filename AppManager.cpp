#include "AppManager.h"

AppManager::AppManager(int width, int height)
{
    this->width = width;
    this->height = height;

    window = new sf::RenderWindow(sf::VideoMode(width, height), "Progresssja");
    //window->setPosition({ sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 });

    windowState = main_menu;

    if (!nFont.loadFromFile("Komoda.otf"))
        exit(0);

    MenuButton_SideWindowOpen = new Button(0, 0, 50, 40, "Menu", nFont);
    MenuButton_Exit = new Button(950, 0, 50, 40, "Exit", nFont);
    TopButton_Geography = new Button(60, 0, 160, 40, "Miejsca", nFont);
    TopButton_Films = new Button(240, 0, 160, 40, "Filmy%Seriale", nFont);
    TopButton_Games = new Button(420, 0, 160, 40, "Gry", nFont);
    TopButton_Books = new Button(600, 0, 160, 40, "Ksiazki", nFont);
    TopButton_Music = new Button(780, 0, 160, 40, "Muzyka", nFont);
}

AppManager::~AppManager()
{
    delete window;
}


void AppManager::update()
{
    switch (windowState) {
    case(main_menu):

        if (MenuButton_SideWindowOpen->getButtonState() == 2) {
            windowState = side_window;
            break;
        }

        if (MenuButton_Exit->getButtonState() == 2) {
            exit(0);
        }

    case(top):

        if (TopButton_Geography->getButtonState() == 2) {
            windowState = side_window;
            //czy tu powinno byæ to z maina, to z wyswietlaniem i wpisywaniem vectora?
            break;
        }

        if (TopButton_Films->getButtonState() == 2) {
            windowState = side_window;
            break;
        }

        if (TopButton_Games->getButtonState() == 2) {
            windowState = side_window;
            break;
        }

        if (TopButton_Books->getButtonState() == 2) {
            windowState = side_window;
            break;
        }

        if (TopButton_Music->getButtonState() == 2) {
            windowState = side_window;
            break;
        }
    case(side_window):
        break;
    }
}

void AppManager::render()
{
    MenuButton_SideWindowOpen->render(*window);
    MenuButton_Exit->render(*window);
    TopButton_Geography->render(*window);
    TopButton_Films->render(*window);
    TopButton_Games->render(*window);
    TopButton_Books->render(*window);
    TopButton_Music->render(*window);
}

void AppManager::mainLoop()
{
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }

        // Clear screen
        window->clear();

        update();
        render();

        // Update the window
        window->display();
    }
}
