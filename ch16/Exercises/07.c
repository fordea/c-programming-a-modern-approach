#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

struct fraction reduce_fraction(struct fraction f);
struct fraction add_fractions(struct fraction f1, struct fraction f2);
struct fraction subtract_fractions(struct fraction f1, struct fraction f2);
struct fraction multiply_fractions(struct fraction f1, struct fraction f2);
struct fraction divide_fractions(struct fraction f1, struct fraction f2);
int find_gcd(int n1, int n2);

int main(void)
{

    struct fraction f = {21, 3};
    struct fraction f1 = {8, 64};
    struct fraction f2 = {9, 711};
    
    struct fraction reducedf = reduce_fraction(f);
    printf("%d/%d reduced to simplest terms: %d/%d\n", f.numerator, 
            f.denominator, reducedf.numerator, reducedf.denominator);

    struct fraction addedf = add_fractions(f1, f2);
    printf("%d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator,
            f2.numerator, f2.denominator, addedf.numerator, addedf.denominator);

    struct fraction subtractedf = subtract_fractions(f1, f2);
    printf("%d/%d - %d/%d = %d/%d\n", f1.numerator, f1.denominator,
            f2.numerator, f2.denominator, subtractedf.numerator,
            subtractedf.denominator);

    struct fraction multipliedf = multiply_fractions(f1, f2);
    printf("%d/%d * %d/%d = %d/%d\n", f1.numerator, f1.denominator,
            f2.numerator, f2.denominator, multipliedf.numerator,
            multipliedf.denominator);

    struct fraction dividedf = divide_fractions(f1, f2);
    printf("%d/%d / %d/%d = %d/%d\n", f1.numerator, f1.denominator,
            f2.numerator, f2.denominator, dividedf.numerator, 
            dividedf.denominator);
    return 0;
}

int find_gcd(int n1, int n2) 
{
    int temp;

    while (n1 != 0) {
        temp = n2 % n1;
        n2 = n1;
        n1 = temp;
    }

    return n2;
}

struct fraction reduce_fraction(struct fraction f)
{
    int gcd = find_gcd(f.numerator, f.denominator);
    f.numerator /= gcd;
    f.denominator /= gcd;
    return f;
}

struct fraction add_fractions(struct fraction f1, struct fraction f2)
{
    f1.numerator *= f2.denominator;
    f2.numerator *= f1.denominator;

    struct fraction result = {
        f1.numerator + f2.numerator,
        f1.denominator * f2.denominator
    };
    result = reduce_fraction(result);

    return result;
}

struct fraction subtract_fractions(struct fraction f1, struct fraction f2)
{
    f1.numerator *= f2.denominator;
    f2.numerator *= f1.denominator;

    struct fraction result = {
        f1.numerator - f2.numerator,
        f1.denominator * f2.denominator
    };
    result = reduce_fraction(result);

    return result;
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result = {
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    };
    result = reduce_fraction(result);

    return result;
}
struct fraction divide_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result = {
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    };
    result = reduce_fraction(result);

    return result;
}
