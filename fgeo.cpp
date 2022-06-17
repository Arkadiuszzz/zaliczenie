#include "fgeo.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
//#include <algorithm>
//#include <iterator>

std::vector < Geografia > miejsce;

void fgeo::GeografiaLista()
{
	std::cout << "\n|----Lista miejsc:-----|\n";
	for (int i = 0; i < miejsce.size(); i++)
	{
		std::cout << "Kontynent: " << miejsce[i].Kontynent << std::endl;
		std::cout << "Kraj: " << miejsce[i].Kraj << std::endl;
		std::cout << "Region: " << miejsce[i].Region << std::endl;
		std::cout << "Miejscowosc: " << miejsce[i].Miejscowosc << std::endl;
		std::cout << "Typ: " << miejsce[i].Typ << std::endl;
		std::cout << "Obiekt: " << miejsce[i].Obiekt << std::endl;
		std::cout << "Owiedzone: " << miejsce[i].Status << std::endl;
		std::cout << "\n";
	};

	/*std::fstream plik;
	plik.open("Tekst.txt", std::ios::in);
	while (!plik.eof())
	{
		std::string liczba;
		plik.read((char*)&liczba, sizeof(int));
		std::cout << liczba << std::endl;
	} //while
	plik.close();*/


	std::ifstream ifs("Tekst1.txt", std::ios::binary);

	unsigned size = miejsce.size();
	ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

	std::vector<Geografia> miejsce;
	ifs.read(reinterpret_cast<char*>(miejsce.data()), sizeof(Geografia) * size);

	std::cout << "\nFrom file\n";
	for (size_t i = 0; i < miejsce.size(); i++)
	{
		std::cout << miejsce[i].Kontynent << "\t" << miejsce[i].Kraj << miejsce[i].Region << "\t" << miejsce[i].Miejscowosc << "\t" << miejsce[i].Typ << "\t" << miejsce[i].Obiekt << "\t" << miejsce[i].Status << '\n';
	}


}

void fgeo::GeografiaDodawanie()
{
	std::cout << "\n|----DODAWANIE MIEJSC-----|";
	std::cout << "\nPodaj Kontynent: ";
	std::string Kontynent;
	std::cin >> Kontynent;
	std::cout << "Kraj: ";
	std::string Kraj;
	std::cin >> Kraj;
	std::cout << "Region: ";
	std::string Region;
	std::cin >> Region;
	std::cout << "Miejscowosc: ";
	std::string Miejscowosc;
	std::cin >> Miejscowosc;
	std::cout << "Typ: ";
	std::string Typ;
	std::cin >> Typ;
	std::cout << "Obiekt: ";
	std::string Obiekt;
	std::cin >> Obiekt;
	std::cout << "Status(odwiedzone - tak/nie): ";
	std::string Status;
	std::cin >> Status;

	for (int i = 0; i < miejsce.size(); i++) {
		if (Kontynent == miejsce[i].Kontynent && Kraj == miejsce[i].Kraj && Region == miejsce[i].Region && Miejscowosc == miejsce[i].Miejscowosc && Typ == miejsce[i].Typ && Obiekt == miejsce[i].Obiekt)
		{
			std::cout << "Obiekt juz dodany" << std::endl;
			return;
		}

	};

	miejsce.push_back(Geografia(Kontynent, Kraj, Region, Miejscowosc, Typ, Obiekt, Status));
	std::cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << std::endl;
	std::cout << "\n";

	
	/*std::fstream plik;
	plik.open("Tekst.txt", std::ios::out);
	plik.write((char*)&miejsce[0], miejsce.size() * sizeof(int));
	plik.close();
	
	std::ofstream file;
	file.open("Tekst.txt");
	for (int i = 0; i < miejsce.size(); ++i) {
		file << miejsce[i] << std::endl;
	}
	file.close();*/
	//std::fstream file;
	//file.open("Tekst.txt", std::ios_base::out);

	//std::vector<Geografia>::iterator itr;
	//std::ostream_iterator<Geografia> out_itr(file, "\n");
	//copy(miejsce.begin(), miejsce.end(), out_itr);

	//for (itr = miejsce.begin(); itr != miejsce.end(); itr++)
	//{
		//file << *itr << std::endl;
	//}

	//file.close();

	/*for (auto content : miejsce)
	{
		file << content << std::endl;
	}

	file.close();*/

	std::ofstream ofs("Tekst1.txt", std::ios::binary);
	unsigned size = miejsce.size();

	ofs.write(reinterpret_cast<char*>(&size), sizeof(size));
	ofs.write(reinterpret_cast<char*>(miejsce.data()), sizeof(Geografia) * size);

	std::cout << "\nTo file\n";
	for (size_t i = 0; i < miejsce.size(); i++)
	{
		std::cout << miejsce[i].Kontynent << "\t" << miejsce[i].Kraj << miejsce[i].Region << "\t" << miejsce[i].Miejscowosc << "\t" << miejsce[i].Typ << "\t" << miejsce[i].Obiekt << "\t" << miejsce[i].Status << '\n';
	}



}

void fgeo::geolicznik()
{
	std::string typ = "tak";
	int b = 0;
	int c = 0;

	for (int i = 0; i < miejsce.size(); i++) {
		if (miejsce[i].Status == typ) {
			c = b + 1;
		}
		b = b + 1;
	};
	std::cout <<"odwiedziles " << c << " na " << miejsce.size() <<" miejsc" << std::endl;
}

void fgeo::GeografiaMenu()
{
	char odp;
	do
	{
		std::cout << "Wybierz odpowiedni tryb" << std::endl;
		std::cout << "Baza Miejsc\n1.Lista miejsc\n2.Dodaj miejsce\n3.Usuwanie obiektu\n4.Powrot do glownego menu" << std::endl;
		std::cout << "Twoj postep: ";
		fgeo tl;
		tl.geolicznik();
		odp = _getch();
		switch (odp)
		{
		case '1':
			fgeo w;
			w.GeografiaLista();
			break;
		case '2':
			fgeo cap;
			cap.GeografiaDodawanie();
			break;
		case '3':
			fgeo tr;
			tr.GeografiaUsuwanie();
			break;
		} 
	}while (odp != '4');
}

void fgeo::GeografiaUsuwanie()
{
	std::string name;
	std::cout << "\nPodaj jakiego obiektu chcesz usunac:" << std::endl;
	std::cin >> name;
	for (int i = 0; i < miejsce.size(); i++) {
		if (miejsce[i].Obiekt == name) {
			miejsce.erase(miejsce.begin() + i);
		}
	}
	std::cout << "\n";
}

Geografia::Geografia(std::string Kontynent, std::string Kraj, std::string Region, std::string Miejscowosc, std::string Typ, std::string Obiekt, std::string Status) :
	Kontynent(Kontynent),
	Kraj(Kraj),
	Region(Region),
	Miejscowosc(Miejscowosc),
	Typ(Typ),
	Obiekt(Obiekt),
	Status(Status) 
{
};

/*void write(std::ostream& o, const std::vector <Geografia>& miejsce) {
	for (auto s : miejsce) {
		o << s* Kontynent << ';' << s->Kraj << ';'<< s->Region << ';' << s->Miejscowosc << ';' << s->Typ << ';' <<  s->Obiekt << ';' << s->Status <<'\n';
	}
}
void writeStudents(std::ostream&& o, const std::vector<Geografia>& miejsce) {
	writeStudents(o, miejsce);
}*/
