#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef FILMY_H
#define FILMY_H

class ffilm
{
public:
	void FilmyLista();
	void FilmyDodawanie();
	void FilmyMenu();
	void FilmyUsuwanie();
};


class Film
{
public:
	Film(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Produkcja, std::string Gatunek, std::string Seria, std::string Status);
	std::string Tytul;
	std::string Rezyser;
	std::string RokProdukcji;
	std::string Produkcja;
	std::string Gatunek;
	std::string Seria;
	std::string Status;

};

#endif FILMY_H