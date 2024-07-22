
#include <iostream>
#include "..\calc\framework.h"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <math.h>

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
void Log()
{
	double u;
	double i;
	double result;
	std::cout << "Geben Sie eine Zahl ein: \n";
	std::cin >> u;
	std::cout << "Geben Sie eine weitere Zahl ein\n";
	std::cin >> i;
	result = Log_berechnen(u, i);
	std::cout << "log" << u << "(" << i << ")" <<"=" << result << std::endl;
}

int main()
{
	char r;
	std::cout << "(P)otenz, (L)og oder (F)akultaet?\n";
	std::cin >> r;
	r = std::tolower(r);
	switch (r)
	{
	case 'p':
		Potenz(); break;
	case 'f':
		Fakultaet(); break;
	case 'l':
		Log(); break;
	default:
		std::cerr << "Fehler!\n";
	}

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
		double result = -1;
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
		if (cmd == "Log")
		{
			std::string cmd_p_1 = Zeile.substr(pos + 1);
			pos = cmd_p_1.find(",");
			std::string Zahl_1 = cmd_p_1.substr(0, pos);
			std::string Zahl_2 = cmd_p_1.substr(pos + 1);
			double z1 = atof(Zahl_1.c_str());
			double z2 = atof(Zahl_2.c_str());
			result = Log_berechnen(z1, z2);
		}
		log << result << std::endl;
	}
	log.close();

}