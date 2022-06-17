#include "fksiaz.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector < Ksiazka > ksiazki;

void fksiaz::KsiazkiLista()
{
	std::cout << "\n\n\nLista ksiazek:\n";
	for (int i = 0; i < ksiazki.size(); i++)
	{
		std::cout << "Tytul: " << ksiazki[i].Tytul << std::endl;
		std::cout << "Pisarz: " << ksiazki[i].Pisarz << std::endl;
		std::cout << "Rok Wydania: " << ksiazki[i].RokWydania << std::endl;
		std::cout << "Wydawca: " << ksiazki[i].Wydawca << std::endl;
		std::cout << "Gatunek: " << ksiazki[i].Gatunek << std::endl;
		std::cout << "Seria: " << ksiazki[i].Seria << std::endl;
		std::cout << "Liczba Stron: " << ksiazki[i].LiczbaStron << std::endl;
		std::cout << "Status: " << ksiazki[i].Status << std::endl;
	};
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fksiaz::KsiazkiDodawanie()
{
	std::cout << "\n\n\n|----DODAWANIE_KSIAZEK-----|";
	std::cout << "\nPodaj Tytul: ";
	std::string Tytul;
	std::cin >> Tytul;
	std::cout << "Pisarz: ";
	std::string Pisarz;
	std::cin >> Pisarz;
	std::cout << "Rok Wydania: ";
	std::string RokWydania;
	std::cin >> RokWydania;
	std::cout << "Wydawca: ";
	std::string Wydawca;
	std::cin >> Wydawca;
	std::cout << "Gatunek: ";
	std::string Gatunek;
	std::cin >> Gatunek;
	std::cout << "Seria: ";
	std::string Seria;
	std::cin >> Seria;
	std::cout << "Liczba Stron: ";
	std::string LiczbaStron;
	std::cin >> LiczbaStron;
	std::cout << "Status: ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < ksiazki.size(); i++) {
		if (Tytul == ksiazki[i].Tytul && Pisarz == ksiazki[i].Pisarz && RokWydania == ksiazki[i].RokWydania && Wydawca == ksiazki[i].Wydawca && Gatunek == ksiazki[i].Gatunek && Seria == ksiazki[i].Seria && LiczbaStron == ksiazki[i].LiczbaStron)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}
	}

	ksiazki.push_back(Ksiazka(Tytul, Pisarz, RokWydania, Wydawca, Gatunek, Seria, LiczbaStron, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fksiaz::KsiazkiMenu()
{
	char odp;
	do
	{
		std::cout << "\nWybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza ksiazek\n1.Lista ksiazek\n2.Dodaj kiazek\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;
		odp = _getch();
		switch (odp)
		{
		case '1':
			fksiaz w;
			w.KsiazkiLista();
			break;
		case '2':
			fksiaz cap;
			cap.KsiazkiDodawanie();
			break;
		case '3':
			fksiaz tr;
			tr.KsiazkiUsuwanie();
			break;
		}
	} while (odp != '4');
}

void fksiaz::KsiazkiUsuwanie()
{
	std::string name;
	std::string second;
	std::cout << "\nPodaj tytul ksiazki chcesz usunac:" << std::endl;
	std::cin >> name;
	std::cout << "\nPodaj rok produkcji ksiazki chcesz usunac:" << std::endl;
	std::cin >> second;

	for (int i = 0; i < ksiazki.size(); i++) {
		if (ksiazki[i].Tytul == name && ksiazki[i].RokWydania == second) {
			ksiazki.erase(ksiazki.begin() + i);
		}
	}
}

Ksiazka::Ksiazka(std::string Tytul, std::string Pisarz, std::string RokWydania, std::string Wydawca, std::string Gatunek, std::string Seria, std::string LiczbaStron, std::string Status) :
	Tytul(Tytul),
	Pisarz(Pisarz),
	RokWydania(RokWydania),
	Wydawca(Wydawca),
	Gatunek(Gatunek),
	Seria(Seria),
	LiczbaStron(LiczbaStron),
	Status(Status)
{
};