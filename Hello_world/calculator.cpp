#include "calculator.h"
#include <iostream>
#include "..\calc\framework.h"

void Calculator::Potenz()
{
	int u;
	int i;
	int result;
	std::cout << "Geben Sie eine Zahl ein: \n";
	std::cin >> u;
	std::cout << "Geben Sie eine weitere Zahl ein\n";
	std::cin >> i;
	result = PotenzBerechnen(u, i);
	
	if (erweiterteAusgabe)
		std::cout << u << "^" << i << " = " << result << std::endl;
	else 
		std::cout << result << std::endl;
}
void Calculator::Fakultaet()
{
	int u;
	std::cout << "Bitte geben Sie eine Zahl ein: \n";
	std::cin >> u;
	if (erweiterteAusgabe)
		std::cout << u << "!" << " = " << FakultaetBerechnen(u) << std::endl;
	else
		std::cout << FakultaetBerechnen(u) << std::endl;
}
void Calculator::Log()
{
	double u;
	double i;
	double result;
	std::cout << "Geben Sie eine Zahl ein: \n";
	std::cin >> u;
	std::cout << "Geben Sie eine weitere Zahl ein\n";
	std::cin >> i;
	result = LogBerechnen(u, i);
	std::cout << "log" << u << "(" << i << ")" << "=" << result << std::endl;
}