#include "ffilm.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector < Film > filmy;

void ffilm::FilmyLista()
{
	std::cout << "\n\n\nLista filmow:\n";
	for (int i = 0; i < filmy.size(); i++)
	{
		std::cout << "Tytul: " << filmy[i].Tytul << std::endl;
		std::cout << "Rezyser: " << filmy[i].Rezyser << std::endl;
		std::cout << "Rok Produkcji: " << filmy[i].RokProdukcji << std::endl;
		std::cout << "Produkcja: " << filmy[i].Produkcja << std::endl;
		std::cout << "Gatunek: " << filmy[i].Gatunek << std::endl;
		std::cout << "Seria: " << filmy[i].Seria << std::endl;
		std::cout << "Status: " << filmy[i].Status << std::endl;
	};
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void ffilm::FilmyDodawanie()
{
	std::cout << "\n\n\n|----DODAWANIE_FILMOW-----|";
	std::cout << "\nPodaj Tytul: ";
	std::string Tytul;
	std::cin >> Tytul;
	std::cout << "Rezyser: ";
	std::string Rezyser;
	std::cin >> Rezyser;
	std::cout << "Rok Produkcji: ";
	std::string RokProdukcji;
	std::cin >> RokProdukcji;
	std::cout << "Produkcja: ";
	std::string Produkcja;
	std::cin >> Produkcja;
	std::cout << "Gatunek: ";
	std::string Gatunek;
	std::cin >> Gatunek;
	std::cout << "Seria: ";
	std::string Seria;
	std::cin >> Seria;
	std::cout << "Status: ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < filmy.size(); i++) {
		if (Tytul == filmy[i].Tytul && Rezyser == filmy[i].Rezyser && RokProdukcji == filmy[i].RokProdukcji && Produkcja == filmy[i].Produkcja && Gatunek == filmy[i].Gatunek && Seria == filmy[i].Seria)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}
	}

	filmy.push_back(Film(Tytul, Rezyser, RokProdukcji, Produkcja, Gatunek, Seria, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void ffilm::FilmyMenu()
{
	char odp;
	do
	{
		std::cout << "\nWybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza filmow\n1.Lista filmow\n2.Dodaj film\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;

		odp = _getch();
		switch (odp)
		{
		case '1':
			ffilm w;
			w.FilmyLista();
			break;
		case '2':
			ffilm cap;
			cap.FilmyDodawanie();
			break;
		case '3':
			ffilm tr;
			tr.FilmyUsuwanie();
		}
	} while (odp != '4');
}

void ffilm::FilmyUsuwanie()
{
	std::string name;
	std::string second;
	std::cout << "\nPodaj tytul filmu chcesz usunac:" << std::endl;
	std::cin >> name;
	std::cout << "\nPodaj rok produkcji filmu chcesz usunac:" << std::endl;
	std::cin >> second;

	for (int i = 0; i < filmy.size(); i++) {
		if (filmy[i].Tytul == name && filmy[i].RokProdukcji == second) {
			filmy.erase(filmy.begin() + i);
		}
	}
}

Film::Film(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Produkcja, std::string Gatunek, std::string Seria, std::string Status) :
	Tytul(Tytul),
	Rezyser(Rezyser),
	RokProdukcji(RokProdukcji),
	Produkcja(Produkcja),
	Gatunek(Gatunek),
	Seria(Seria),
	Status(Status)
{
};