#include "fser.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector < Serial > seriale;

void fser::SerialeLista()
{
	std::cout << "\n\n\nLista seriali:\n";
	for (int i = 0; i < seriale.size(); i++)
	{
		std::cout << "Tytul: " << seriale[i].Tytul << std::endl;
		std::cout << "Rezyser: " << seriale[i].Rezyser << std::endl;
		std::cout << "Rok Produkcji: " << seriale[i].RokProdukcji << std::endl;
		std::cout << "Produkcja: " << seriale[i].Produkcja << std::endl;
		std::cout << "Gatunek: " << seriale[i].Gatunek << std::endl;
		std::cout << "Liczba Sezonow: " << seriale[i].LiczbaSezonow << std::endl;
		std::cout << "Status: " << seriale[i].Status << std::endl;
	};
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fser::SerialeDodawanie()
{
	std::cout << "\n\n\n|----DODAWANIE_SERIALI-----|";
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
	std::cout << "Liczba Sezonow: ";
	std::string LiczbaSezonow;
	std::cin >> LiczbaSezonow;
	std::cout << "Status: ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < seriale.size(); i++) {
		if (Tytul == seriale[i].Tytul && Rezyser == seriale[i].Rezyser && RokProdukcji == seriale[i].RokProdukcji && Produkcja == seriale[i].Produkcja && Gatunek == seriale[i].Gatunek && LiczbaSezonow == seriale[i].LiczbaSezonow)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}
	}

	seriale.push_back(Serial(Tytul, Rezyser, RokProdukcji, Produkcja, Gatunek, LiczbaSezonow, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fser::SerialeMenu()
{
	char odp;
	do
	{
		std::cout << "\nWybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza seriali\n1.Lista serial\n2.Dodaj serial\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;

		odp = _getch();
		switch (odp)
		{
		case '1':
			fser w;
			w.SerialeLista();
			break;
		case '2':
			fser cap;
			cap.SerialeDodawanie();
			break;
		case '3':
			fser tr;
			tr.SerialeUsuwanie();
			break;
		}
	} while (odp != '4');
}

void fser::SerialeUsuwanie()
{
	std::string name;
	std::string second;
	std::cout << "\nPodaj tytul serialu ktorego chcesz usunac:" << std::endl;
	std::cin >> name;
	std::cout << "\nPodaj rok produkcji serialu, ktorego chcesz usunac:" << std::endl;
	std::cin >> second;

	for (int i = 0; i < seriale.size(); i++) {
		if (seriale[i].Tytul == name && seriale[i].RokProdukcji == second) {
			seriale.erase(seriale.begin() + i);
		}
	}
}

Serial::Serial(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Produkcja, std::string Gatunek, std::string LiczbaSezonow, std::string Status) :
	Tytul(Tytul),
	Rezyser(Rezyser),
	RokProdukcji(RokProdukcji),
	Produkcja(Produkcja),
	Gatunek(Gatunek),
	LiczbaSezonow(LiczbaSezonow),
	Status(Status)
{
};