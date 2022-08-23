#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() //klasa complex
{
    Re = 0;
    Im = 0;

}

Complex::Complex(double re)
{
    Re = re;
    Im = 0;
}

Complex::Complex(double re, double im)
{
    Re = re;
    Im = im;
	
}


Complex::~Complex()//destruktor
{
}

double Complex::getRe() const
{
	return re;
}

double Complex::getIm() const
{
	return im;
}

void Complex::setRe(double re)
{
	this->re = re;
}

void Complex::setIm(double im)
{
	this->im = im;
}

void Complex::set(double re, double im)
{
    Re = re;
    Im = im;
}
//###

Complex operator+(const Complex& z1, const Complex& z2) {
    return Complex(z1.Re + z2.Re,
        z1.Im + z2.Im);
}


Complex operator-(const Complex& z1, const Complex& z2) {
    return Complex(z1.Re - z2.Re,
        z1.Im - z2.Im);
}

Complex operator*(const Complex& z1, const Complex& z2) {
    return Complex(z1.Re * z2.Re - z1.Im * z2.Im,
        z1.Im * z2.Re + z1.Re * z2.Im);
}

Complex operator/(const Complex& z1, const Complex& z2) {
    double abs_sq = z1.Re * z2.Re + z1.Im * z2.Im;
    return Complex((z1.Re * z2.Re + z1.Im * z2.Im) / abs_sq,
        (z1.Im * z2.Re - z1.Re * z2.Im) / abs_sq);
}

bool operator==(const Complex& z1, const Complex& z2) {
    return (z1.Re == z2.Re && z1.Im == z2.Im);
}

bool operator!=(const Complex& z1, const Complex& z2) {
    return !(z1.Re == z2.Re && z2.Im == z1.Im);
}


istream& operator>>(istream& in, Complex& z) {
    return in >> z.Re >> z.Re;
}

ostream& operator<<(ostream& out, const Complex& z) {
    return out << z.Re << " + " << z.Im << "i\n";

    if (z.Im == 0)
      return (out << z.Re);		// brak cz urojonej

    if (z.Re == 0)
      return (out << z.Im << 'i');	// brak cz rzeczyw

    out << z.Re;			// obie
    if (z.Im > 0)
     out << " + " << z.Im << 'i';
   else
      out << " - " << -z.Im << 'i';

   return out;
    

}




void Complex::operator+=(const Complex& z)
{
    Re += z.re;
    Im += z.im;
}

void Complex::operator-=(const Complex& z)
{
    Re -= z.re;
    Im -= z.im;
}

void Complex::operator*=(const Complex& z)
{
    double a = re;
    double b = im;
    double c = z.re;
    double d = z.im;

    Re = a * c - b * d;
    Im = a * d + b * c;
}

void Complex::operator*=(double r)
{
    Re *= r;
    Im *= r;
}

void Complex::operator/=(double r)
{
    Re /= r;
    Im /= r;
}

void Complex::operator/=(const Complex& z)
{
    *this *= z.inv();
}




//###

Complex& Complex::operator++()	
{
    Re = Re + 1;		
    return *this;		
}

Complex Complex::operator++(int)	
{
    Complex temp = *this;	
    Re = Re + 1;		
    return temp;			
}

Complex& Complex::operator--()	
{
    Re = Re - 1;		
    return *this;		
}

Complex Complex::operator--(int)
{
    Complex temp = *this;	
    Re = Re - 1;		
    return temp;			
}

//-------
