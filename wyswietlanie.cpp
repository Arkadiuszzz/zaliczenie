#include "wyswietlanie.h"
#include <iostream>
#include <conio.h>
#include "fgeo.h"
#include "ffilm.h"
#include "fgry.h"
#include "fksiaz.h"
#include "fmuz.h"
#include "fser.h"

void wyswietlanie::GlowneMenu()
{
	std::cout << "Witaj uzytkowniku" << std::endl;
	char odp;
	do
	{
		std::cout << "\nWybierz sekcje, do ktorej chcesz przejsc" << std::endl;
		std::cout << "1.Geografia\n2.Filmy\n3.Gry\n4.Ksiazka\n5.Muzyka\n6.Serial\n7.Wyjscie z programu\n" << std::endl;
		odp = _getch();
		switch (odp)
		{
		case '1':
			fgeo a;
			a.GeografiaMenu();
			break;
		case '2':
			ffilm b;
			b.FilmyMenu();
			break;
		case '3':
			fgry c;
			c.GryMenu();
			break;
		case '4':
			fksiaz d;
			d.KsiazkiMenu();
			break;
		case '5':
			fmuz e;
			e.MuzykaMenu();
			break;
		case '6':
			fser f;
			f.SerialeMenu();
			break;
		}
		
	} while (odp != '7');
}