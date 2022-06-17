#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef FKSIAZ_H
#define FKSIAZ_H

class fksiaz
{
public:
	void KsiazkiLista();
	void KsiazkiDodawanie();
	void KsiazkiMenu();
	void KsiazkiUsuwanie();

};

class Ksiazka
{
public:
	Ksiazka(std::string Tytul, std::string Pisarz, std::string RokWydania, std::string Wydawca, std::string Gatunek, std::string Seria, std::string LiczbaStron, std::string Status);
	std::string Tytul;
	std::string Pisarz;
	std::string RokWydania;
	std::string Wydawca;
	std::string Gatunek;
	std::string Seria;
	std::string LiczbaStron;
	std::string Status;

};

#endif FKSIAZ_H 