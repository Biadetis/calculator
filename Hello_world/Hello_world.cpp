// Hello_world.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "..\calc\framework.h"
#include <fstream>
#include <string>

void Fakultaet()
{
	int u;
	std::cout << "Bitte geben Sie eine Zahl ein: \n";
	std::cin >> u;
	std::cout << Fakultaet_berechnen(u) << std::endl;
}

void Potenz()
{
	int u;
	int i;
	int result;
	std::cout << "Geben Sie eine Zahl ein: \n";
	std::cin >> u;
	std::cout << "Geben Sie eine weitere Zahl ein\n";
	std::cin >> i;
	result = Potenz_berechnen(u, i);
	std::cout << result << std::endl;
}

int main()
{
	char r[10];
	std::cout << "(P)otenz oder (F)akultaet?\n";
	std::cin >> r;
	if (strcmp(r, "P") == 0 || strcmp(r, "p") == 0)
		Potenz();
	else
		if (strcmp(r, "F") == 0 || strcmp(r, "f") == 0)
			Fakultaet();
		else std::cout << "Fehler!\n";
	std::ifstream file;
	std::string Zeile;
	file.open("C:\\temp\\Berechnungen.txt");
	std::ofstream log;
	log.open("C:\\temp\\log.txt");
	while (std::getline(file, Zeile))
	{
		std::cout << Zeile << std::endl;
		size_t pos;
		pos = Zeile.find(",");
		std::string cmd = Zeile.substr(0, pos);
		int result = -1;
		if (cmd == "Potenz")
		{
			std::string cmd_p_1 = Zeile.substr(pos + 1);
			pos = cmd_p_1.find(",");
			std::string Zahl_1 = cmd_p_1.substr(0, pos);
			std::string Zahl_2 = cmd_p_1.substr(pos + 1);
			int z1 = atoi(Zahl_1.c_str());
			int z2 = atoi(Zahl_2.c_str());
			result = Potenz_berechnen(z1, z2);

		}
		if (cmd == "Fakultaet")
		{
			std::string cmd_f_1 = Zeile.substr(pos + 1);
			int z1 = atoi(cmd_f_1.c_str());
			result = Fakultaet_berechnen(z1);
		}
		log << result << std::endl;
	}
	log.close();

}