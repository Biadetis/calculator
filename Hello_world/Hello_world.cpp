// Hello_world.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Berechnen.h"
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
		int pos;
		pos = Zeile.find(",");
		std::string cmd = Zeile.substr(0, pos);
		int result;
		if (cmd == "Potenz")
		{
			std::string cmd_p_1 = Zeile.substr(pos + 1);
			int cmd_p_2;
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




//int main()
//{
//	char str[7];
//	str[0] = 'h';
//	str[1] = 'e';
//	str[2] = 'l';
//	str[3] = 'l';
//	str[4] = 'o';
//	str[5] = 0;
//	std::cout << str;
//	strcpy_s(str, " world");
//	std::cout << str;
//	int zahl;
//	std::cin >> zahl;
//	std::cout << " zahl " << zahl;
//}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
//// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcdeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
