#include <iostream>

int Potenz_berechnen(int Zahl, int Potenz)
{
    int result;
    result = 1;
    while (Potenz > 0)
    {
        result = result * Zahl;
        Potenz = Potenz - 1;
    }
    return result;
}
int Fakultaet_berechnen(int u)
{
    int i;
    i = u;
    while (i > 2)
    {
        u = ((i - 1) * u);
        i = i - 1;
    }
    return u;
}