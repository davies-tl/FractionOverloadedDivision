/*
Program name: FractionOverloadedDivision.cpp
Programmer: Tyler Davies
Date: 10-9-21
Version: 2.0
Description: This program contains a class called Fraction, which has members for the numerator
             and denominator of a fraction. It overrides the division, multiplication, comparison,
             extraction, and insertion operators. The main function instantiates three Fraction
             objects, and tests all five of the overriden operators.
*/

#include<iostream>

using namespace std;

//This class contains private variables for a numerator and denominator of a fraction. It has friend
//functions which override the division, multiplication, comparison, extraction, and insertion operators.
class Fraction
{
private:
    double numerator, denominator;
public:
    Fraction()
    {
        numerator = 0.0;
        denominator = 1.0;    //Denominator should not be zero.
    }
    Fraction(double num, double denom)
    {
        numerator = num;
        denominator = denom;
    }
    friend Fraction operator/(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend bool operator==(Fraction, Fraction);
    friend istream& operator>>(istream&, Fraction&);
    friend ostream& operator<<(ostream&, const Fraction&);
    ~Fraction() {}
};

//This function, which is a friend of Fraction class, overrides the division operator. 
Fraction operator/(Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.numerator = f1.numerator * f2.denominator;
    temp.denominator = f1.denominator * f2.numerator;
    return temp;
}

//This function, which is a friend of Fraction class, overrides the multiplication operator. 
Fraction operator*(Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.numerator = f1.numerator * f2.numerator;
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

//This function, which is a friend of Fraction class, overrides the comparison operator. 
bool operator==(Fraction f1, Fraction f2)
{
    if (f1.numerator == f2.numerator && f1.denominator == f2.denominator)
        return true;
    else
        return false;
}

//This function, which is a friend of Fraction class, overrides the extraction operator. 
istream& operator>>(istream& in, Fraction& f)
{
    char slash;    //Reads '/'
    in >> f.numerator >> slash >> f.denominator;
    return in;
}

//This function, which is a friend of Fraction class, overrides the insertion operator. 
ostream& operator<<(ostream& out, const Fraction& f)
{
    out << f.numerator << " / " << f.denominator;
    return out;
}

//The main function instantiates three Fraction objects, and tests all five of the overriden operators.
int main()
{
    Fraction f1(1.0, 5.0), f2(2.0, 3.0), f3;

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    cout << "Fraction 1 divided by Fraction 2 equals: " << f1 / f2 << endl;
    cout << "Fraction 1 times Fraction 2 equals: " << f1 * f2 << endl;
    if (f1 == f2)
        cout << "Fraction 1 and Fraction 2 are the same." << endl;
    else
        cout << "Fraction 1 and Fraction 2 are different." << endl;
    cout << "Enter a fraction (numerator / denominator): " << endl;
    cin >> f3;
    cout << "You entered: " << f3;

    exit(0);
}