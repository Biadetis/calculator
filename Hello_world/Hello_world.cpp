
#include <iostream>
#include "..\calc\framework.h"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <math.h>
#include "calculator.h"


int main()
{
	Calculator calc;
	char r;
	int Entscheidung;
	std::cout << "In Eingabeaufforderung berechnen?(1) oder Aus Datei lesen?(2)\n";
	std::cin >> Entscheidung;
	if (Entscheidung == 1)
	{
		std::cout << "(P)otenz, (L)og oder (F)akultaet?\n";
		std::cin >> r;
		r = std::tolower(r);
		switch (r)
		{
		case 'p':
			calc.Potenz(); break;
		case 'f':
			calc.Fakultaet(); break;
		case 'l':
			calc.Log(); break;
		default:
			std::cerr << "Fehler!\n";
		}
	}
	else
	{
		std::ifstream file;
		std::string Zeile;
		std::string Eingabedatei;
		std::string Ausgabedatei;
		std::cout << "Gib bitte die Eingabedatei an:\n";
		std::cin >> Eingabedatei;
		file.open(Eingabedatei);
		std::ofstream log;
		std::cout << "Gib bitte die Ausgabedatei an:\n";
		std::cin >> Ausgabedatei;
		log.open(Ausgabedatei);
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
				result = PotenzBerechnen(z1, z2);
				log << z1 << "^" << z2 << " = " << result << std::endl;
			}

			if (cmd == "Fakultaet")
			{
				std::string cmd_f_1 = Zeile.substr(pos + 1);
				int z1 = atoi(cmd_f_1.c_str());
				result = FakultaetBerechnen(z1);
				log << z1 << "!" << " = " << FakultaetBerechnen(z1) << std::endl;
			}

			if (cmd == "Log")
			{
				std::string cmd_p_1 = Zeile.substr(pos + 1);
				pos = cmd_p_1.find(",");
				std::string Zahl_1 = cmd_p_1.substr(0, pos);
				std::string Zahl_2 = cmd_p_1.substr(pos + 1);
				double z1 = atof(Zahl_1.c_str());
				double z2 = atof(Zahl_2.c_str());
				result = LogBerechnen(z1, z2);
				log << "log" << z1 << "(" << z2 << ")" << "=" << result << std::endl;
			}
			
		}
		log.close();

	}
}