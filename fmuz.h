#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef FMUZ_H
#define FMUZ_H

class fmuz
{
public:
	void MuzykaLista();
	void MuzykaDodawanie();
	void MuzykaMenu();
	void MuzykaUsuwanie();
};

class Muzyka
{
public:
	Muzyka(std::string Artysta, std::string AlbumSingiel, std::string RokWydania, std::string Dlugosc, std::string Gatunek, std::string Wytwornia, std::string Status);
	std::string Artysta;
	std::string AlbumSingiel;
	std::string RokWydania;
	std::string Dlugosc;
	std::string Gatunek;
	std::string Wytwornia;
	std::string Status;

};
#endif FMUZ_H
