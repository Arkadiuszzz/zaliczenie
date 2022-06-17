#include "Button.h"
#include "AppManager.h"
#include <iostream>
#include <fstream>
#include "wyswietlanie.h"

int main()
{
    //AppManager window(1000, 800);
    //window.mainLoop();

    /*std::fstream plik;
    plik.open("Dane.txt", ios::in);
    if (plik.good())
    {
        std::string napis;
        std::cout << "Zawartosc pliku:" << std::endl;
        while (!plik.eof())
        {
            getline(plik, napis);
            std::cout << napis << std::endl;
        }
        plik.close();
    }
    else std::cout << "Error! Nie udalo otworzyc sie pliku!" << std::endl;*/
 
        wyswietlanie z;
        z.GlowneMenu();
        




        return 0;
}