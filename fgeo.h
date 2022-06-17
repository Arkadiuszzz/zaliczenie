#include <iostream>
#include <vector>
#include <string>
#pragma once
#ifndef FGEO_H
#define FGEO_H

class fgeo
{
public:
	void GeografiaLista();
	void GeografiaDodawanie();
	void GeografiaMenu();
	void GeografiaUsuwanie();
	void geolicznik();
	void write();
	//friend std::ostream& operator<< (std::ostream& stream, const std::&);
};

class Geografia
{
public:
	std::string Kontynent;
	std::string Kraj;
	std::string Region;
	std::string Miejscowosc;
	std::string Typ;
	std::string Obiekt;
	std::string Status;
	Geografia(std::string Kontynent, std::string Kraj, std::string Region, std::string Miejscowosc, std::string Typ, std::string Obiekt, std::string Status);
};

#endif FGEO_H