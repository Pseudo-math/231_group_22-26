#include <iostream>
#include <string>
using namespace std;
struct Polynomial
{
    int deg;
    float* coeficents;
    Polynomial()
    {
        
        deg = 0;
        coeficents = new float[1];
        coeficents[0] = 0;
    }
    Polynomial(int n, float arr[])
    {
        deg = n;
        coeficents = new float[n + 1];
        for (int i = 0; i <= deg; ++i) coeficents[i] = arr[i];
    }
    float & coef(int i)
    {
        return &coeficents[i];
    }
    double Value(double point)
    {
        double s = coeficents[deg];
        for (int i = 1; i <= deg; ++i)
        {
            s *= point; 
            s += coeficents[deg - i];
        }
        return s;
    }
    
};
