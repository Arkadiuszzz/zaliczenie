#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef FGRY_H
#define FGRY_H
class fgry
{
public:
	void GryLista();
	void GryDodawanie();
	void GryMenu();
	void GryUsuwanie();
};

class Gra
{
public:
	Gra(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Studio, std::string Gatunek, std::string Seria, std::string Status);
	std::string Tytul;
	std::string Rezyser;
	std::string RokProdukcji;
	std::string Studio;
	std::string Gatunek;
	std::string Seria;
	std::string Status;

};
#endif FGRY_H
