#include "pch.h"
#include "framework.h"
#include <math.h>

int PotenzBerechnen(int Zahl, int Potenz)
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
int FakultaetBerechnen(int u)
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
double LogBerechnen(double u, double i)
{
    double result;
    result = log2(u) / log2(i);
    return result;
}