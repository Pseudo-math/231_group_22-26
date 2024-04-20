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
        return coeficents[i];
    }
    double Value(double point) const
    {
        double s = coeficents[deg];
        for (int i = 1; i <= deg; ++i)
        {
            s *= point; 
            s += coeficents[deg - i];
        }
        return s;
    }
    ~Polynomial()
    {
        delete[] coeficents;
    }
    Polynomial(Polynomial&& other) : deg(other.deg), coeficents(other.coeficents) 
    {
        other.deg = 0;
        other.coeficents = nullptr; // "Обнуляем" перемещаемый объект
    }
    Polynomial & operator=(Polynomial&& other)
    {
        if (this != &other) {
            delete[] coeficents;
            degree = other.deg;
            coeficents = other.coeficents;
            other.deg = 0;
            other.coeficents = nullptr; 
        }
        return *this;
    }
    double operator()(double x) const 
    {
        double result = 0;
        for (int i = deg; i >= 0; --i) {
            result = result * x + coeficents[i];
        }
        return result;
    }
};

Polynomial operator+ (const Polynomial & f, const Polynomial & g)
{
    int maxDeg = std::max(f.deg, g.deg);
    int newDeg;
    float* resultCoeficents = new float[maxDeg + 1]{0};
    for (int i = 0; i <= maxDeg; ++i)
    {
        if (f.deg <= i) resultCoeficents[i] += f.coeficents[i];
        if (g.deg <= i) resultCoeficents[i] += g.coeficents[i];
        if (resultCoeficents[i] != 0) newDeg = i;
    }
    return Polynomial(newDeg, resultCoeficents);
}
Polynomial operator- (Polynomial f, Polynomial g)
{
    int maxDeg = std::max(f.deg, g.deg);
    int newDeg;
    float* resultCoeficents = new float[maxDeg + 1]{0};
    for (int i = 0; i <= maxDeg; ++i)
    {
        if (f.deg <= i) resultCoeficents[i] += f.coeficents[i];
        if (g.deg <= i) resultCoeficents[i] -= g.coeficents[i];
        if (resultCoeficents[i] != 0) newDeg = i;
    }
    return Polynomial(newDeg, resultCoeficents);
}
Polynomial operator* (Polynomial f, Polynomial g)
{
    int newDeg = f.deg + g.deg;
    float* resultCoeficents = new float[newDeg + 1]{0};
    for (int i = 0; i <= f.deg; ++i) 
    {
        for (int j = 0; j <= g.deg; ++j) {
            resultCoeficents[i + j] += f.coeficents[i] * g.coeficents[j];
        }
    }
    return Polynomial(newDeg, resultCoeficents);
}


