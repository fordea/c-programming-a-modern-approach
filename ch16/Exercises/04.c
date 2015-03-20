#include <stdio.h>

typedef struct {
    double real;
    double imaginary;
} Complex;

Complex make_complex(double real, double imaginary)
{
    Complex newcomplex;
    newcomplex.real = real;
    newcomplex.imaginary = imaginary;

    return newcomplex;
}

Complex add_complex(Complex s1, Complex s2)
{
    Complex newcomplex;
    newcomplex.real = s1.real + s2.real;
    newcomplex.imaginary = s1.imaginary + s2.imaginary;

    return newcomplex;
}

int main(void)
{
    Complex c1, c2, c3;
}


