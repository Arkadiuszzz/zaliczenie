#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef FSER_H
#define FSER_H

class fser
{
public:
	void SerialeLista();
	void SerialeDodawanie();
	void SerialeMenu();
	void SerialeUsuwanie();
};

class Serial
{
public:
	Serial(std::string Tytul, std::string Rezyser, std::string RokProdukcji, std::string Produkcja, std::string Gatunek, std::string LiczbaSezonow, std::string Status);
	std::string Tytul;
	std::string Rezyser;
	std::string RokProdukcji;
	std::string Produkcja;
	std::string Gatunek;
	std::string LiczbaSezonow;
	std::string Status;

};
#endif FSER_H