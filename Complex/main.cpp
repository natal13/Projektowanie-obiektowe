#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() //klasa complex
{
     setRe(0); //cz rzeczywista
     setIm(0); //cz urojona
}

Complex::Complex(double re, double im)
{
	setRe(re);
	setIm(im);
}


Complex::~Complex()//destruktor
{
    //TU JESZCZE SPOJRZEC
}

//gettery i settery
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

//dodawanie dwoch liczb zespolonych -> zwracana suma
Complex Complex::add(const Complex & right) const
{
        Complex sum(getRe() + right.getRe(),
        getIm() + right.getIm());

	return sum;
}

Complex Complex::operator+(const Complex & right) const
{
    cout<<"Complex::operator+(const Complex & right) const is called"<<endl;
    Complex sum(getRe() + right.getRe(),
    getIm() + right.getIm());

	return sum;
}

Complex Complex::operator+(double realNumber) const
{
    cout<<"Complex::operator+(double realNumber) const is called"<<endl;

    Complex sum(getRe() + realNumber, getIm());

	return sum;
}

//funkcja globalna
Complex operator+(double realNumber, Complex & right)
{

     cout<<"operator+(double realNumber, const Complex & right) is called"<<endl;
     Complex sum(realNumber+right.getRe(), right.getIm());

     return sum;
}


//przeciazenie +=
void Complex::operator+=(Complex & right)
{
    cout<<"Complex::operator+=(const Complex & right) is called"<<endl;
    setRe(getRe( )+right.getRe());
    setIm(getIm()+right.getIm());
}


//odejmowanie dwoch liczb zespolonych -> zwracana roznica
Complex Complex::subtract(const Complex & right) const
{
	return Complex (getRe() - right.getRe(),getIm() - right.getIm());

}

Complex Complex::operator-(const Complex & right) const
{
        cout<<"Complex::operator-(const Complex & right) const is called"<<endl;

	return Complex (getRe() - right.getRe(), getIm() - right.getIm());

}

//kopiowanie liczby zespolonej; wynik
void Complex::copy(const Complex & right)
{
     setRe(right.getRe());
     setIm(right.getIm());
}

void Complex::operator=(const Complex & right)
{
   cout<<"Complex::operator=(const Complex & right) is called"<<endl;
    setRe(right.getRe());
    setIm(right.getIm());
}

void Complex::operator=(const double h)
{
   setRe(h);
   setIm(0);
}

//porownanie dwoch liczb zespolonch
bool Complex::operator==(Complex & right) const
{
   cout<<"Complex::operator==(const Complex & right) const is called"<<endl;

    if (getRe() == right.getRe()  && getIm() == right.getIm())
        return true;
    else
        return false;
}

// wypisywanie liczby zespolonej
void Complex::print()
{
	cout << "(" << getRe() << ", " << getIm() << ")" << endl;
}

//Przeci¹zenie operatora strumienia wejsciowego
istream& operator>>(istream & input, Complex & cNumber)
{
   double re, im;

   input.ignore(256, '(');

   input>>re;  //wczytywanie cz rzeczywistej

   input.ignore(256,','); //ignorownie tzw white spaces

   input>>im;  //wczytywanie cz urojonej

   input.ignore(256,')');  //ignorowanie tzw white spaces

   if (input.good())
   {
       cNumber.re = re;
       cNumber.im = im;
   }

   return input;
}

//Przeci¹zenie operatora strumienia wyjsciowego
ostream& operator<<(ostream & output, const Complex & cNumber)
{
    output<<"(" <<cNumber.re<<", "<<cNumber.im<<")";

    return output;
}
