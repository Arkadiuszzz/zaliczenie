#include "fgry.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector < Gra > gry;

void fgry::GryLista()
{
	std::cout << "\n\n\nLista gier:\n";
	for (int i = 0; i < gry.size(); i++)
	{
		std::cout << "Tytul: " << gry[i].Tytul << std::endl;
		std::cout << "Rezyser: " << gry[i].Rezyser << std::endl;
		std::cout << "Rok Produkcji: " << gry[i].RokProdukcji << std::endl;
		std::cout << "Studio: " << gry[i].Studio << std::endl;
		std::cout << "Gatunek: " << gry[i].Gatunek << std::endl;
		std::cout << "Seria: " << gry[i].Seria << std::endl;
		std::cout << "Status: " << gry[i].Status << std::endl;
	};
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fgry::GryDodawanie()
{
	std::cout << "\n\n\n|----DODAWANIE_GIER-----|";
	std::cout << "\nPodaj Tytul: ";
	std::string Tytul;
	std::cin >> Tytul;
	std::cout << "Rezyser: ";
	std::string Rezyser;
	std::cin >> Rezyser;
	std::cout << "Rok Produkcji: ";
	std::string RokProdukcji;
	std::cin >> RokProdukcji;
	std::cout << "Studio: ";
	std::string Studio;
	std::cin >> Studio;
	std::cout << "Gatunek: ";
	std::string Gatunek;
	std::cin >> Gatunek;
	std::cout << "Seria: ";
	std::string Seria;
	std::cin >> Seria;
	std::cout << "Status: ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < gry.size(); i++) {
		if (Tytul == gry[i].Tytul && Rezyser == gry[i].Rezyser && RokProdukcji == gry[i].RokProdukcji && Studio == gry[i].Studio && Gatunek == gry[i].Gatunek && Seria == gry[i].Seria)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}
	}

	gry.push_back(Gra(Tytul, Rezyser, RokProdukcji, Studio, Gatunek, Seria, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
}

void fgry::GryMenu()
{
	char odp;
	do
	{
		std::cout << "\nWybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza gier\n1.Lista gier\n2.Dodaj gier\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;
		odp = _getch();

		switch (odp)
		{
		case '1':
			fgry w;
			w.GryLista();
			break;
		case '2':
			fgry cap;
			cap.GryDodawanie();
			break;
		case '3':
			fgry tr;
			tr.GryUsuwanie();
			break;
		}
	} while (odp != '4');
}

void fgry::GryUsuwanie()
{
	std::string name;
	std::string second;
	std::cout << "\nPodaj tytul gry chcesz usunac:" << std::endl;
	std::cin >> name;
	std::cout << "\nPodaj rok produkcji gry chcesz usunac:" << std::endl;
	std::cin >> second;

	for (int i = 0; i < gry.size(); i++) {
		if (gry[i].Tytul == name && gry[i].RokProdukcji == second) {
			gry.erase(gry.begin() + i);
		}
	}
}

Gra::Gra(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Studio, std::string Gatunek, std::string Seria, std::string Status) :
	Tytul(Tytul),
	Rezyser(Rezyser),
	RokProdukcji(RokProdukcji),
	Studio(Studio),
	Gatunek(Gatunek),
	Seria(Seria),
	Status(Status)
{
};