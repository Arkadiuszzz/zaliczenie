#include "fmuz.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector < Muzyka > music;
void fmuz::MuzykaLista()
{
	std::cout << "\n\n\nLista Muzyki:\n";
	for (int i = 0; i < music.size(); i++)
	{
		std::cout << "Artysta: " << music[i].Artysta << std::endl;
		std::cout << "Album/Singiel(tytul): " << music[i].AlbumSingiel << std::endl;
		std::cout << "Rok Wydania: " << music[i].RokWydania << std::endl;
		std::cout << "Dlugosc: " << music[i].Dlugosc << std::endl;
		std::cout << "Gatunek: " << music[i].Gatunek << std::endl;
		std::cout << "Wytwornia: " << music[i].Wytwornia << std::endl;
		std::cout << "Status: " << music[i].Status << std::endl;
	};
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fmuz::MuzykaDodawanie()
{
	std::cout << "\n\n\n|----DODAWANIE_MUZYKI-----|";
	std::cout << "\nPodaj Artysta: ";
	std::string Artysta;
	std::cin >> Artysta;
	std::cout << "Album/Singiel(tytul): ";
	std::string AlbumSingiel;
	std::cin >> AlbumSingiel;
	std::cout << "Rok Wydania: ";
	std::string RokWydania;
	std::cin >> RokWydania;
	std::cout << "Dlugosc: ";
	std::string Dlugosc;
	std::cin >> Dlugosc;
	std::cout << "Gatunek: ";
	std::string Gatunek;
	std::cin >> Gatunek;
	std::cout << "Wytwornia: ";
	std::string Wytwornia;
	std::cin >> Wytwornia;
	std::cout << "Status: ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < music.size(); i++) {
		if (Artysta == music[i].Artysta && AlbumSingiel == music[i].AlbumSingiel && RokWydania == music[i].RokWydania && Dlugosc == music[i].Dlugosc && Gatunek == music[i].Gatunek && Wytwornia == music[i].Wytwornia)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}
	}

	music.push_back(Muzyka(Artysta, AlbumSingiel, RokWydania, Dlugosc, Gatunek, Wytwornia, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
	std::cout << "Wcisnij enter aby przejsc do menu" << std::endl;
}

void fmuz::MuzykaMenu()
{
	char odp;
	do
	{
		std::cout << "\nWybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza muzyki\n1.Lista muzyki\n2.Dodaj muzyke\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;
		odp = _getch();
		switch (odp)
		{
		case '1':
			fmuz w;
			w.MuzykaLista();
			break;
		case '2':
			fmuz cap;
			cap.MuzykaDodawanie();
			break;
		case '3':
			fmuz tr;
			tr.MuzykaUsuwanie();
			break;
		}
	} while (odp != '4');
}

void fmuz::MuzykaUsuwanie()
{
	std::string name;
	std::string second;
	std::cout << "\nPodaj tytul albumu badz singla ktorego chcesz usunac:" << std::endl;
	std::cin >> name;
	std::cout << "\nPodaj artyste albumu badz singla, ktorego chcesz usunac:" << std::endl;
	std::cin >> second;

	for (int i = 0; i < music.size(); i++) {
		if (music[i].AlbumSingiel == name && music[i].Artysta == second) {
			music.erase(music.begin() + i);
		}
	}
}

Muzyka::Muzyka(std::string Artysta, std::string AlbumSingiel, std::string RokWydania, std::string Dlugosc, std::string Gatunek, std::string Wytwornia, std::string Status) :
	Artysta(Artysta),
	AlbumSingiel(AlbumSingiel),
	RokWydania(RokWydania),
	Dlugosc(Dlugosc),
	Gatunek(Gatunek),
	Wytwornia(Wytwornia),
	Status(Status)
{
};