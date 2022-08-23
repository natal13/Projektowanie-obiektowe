#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::istream;
using std::ostream;

class Complex
{

        friend istream & operator>>(istream &in, Complex & c); // operator wejscia
        friend ostream & operator<<(ostream &out, const Complex & c); //a tu wyjscia

	public:

		Complex(double re=0, double im=0);  //konstruktor domyœlny
		//Complex(double, double); //konstruktor
		Complex(const Complex & c); //konstruktor kopiujacy

        ~Complex();//destruktor

        //dodawanie dwoch liczb zespolonych
		Complex add(const Complex &) const;
        Complex operator+(const Complex &) const ;

        //dodawanie l rzeczywistej i zesp
        Complex operator+(double) const;

        //dodawanie dwoch l zespolonych
        void operator+=(Complex &);

        //odejmowanie dwoch l zespolonych
		Complex subtract(const Complex &) const;
        Complex operator-(const Complex &) const;

        //'kopiowanie' l zespolonej
        void copy(const Complex &);
        void operator=(const Complex &);
        void operator=(const double);

        //porownywanie 2 l zesp
        bool operator==(Complex &) const;

		void print();

		double getRe() const; //gettery
		double getIm() const;

		void setRe(double);  //settery
		void setIm(double);

        void setCoplex(double re, double im);

	private:

		double re;
		double im;

};

    inline void Complex::setComplex(double re, double im)
    {
        setRe(re);
        setIm(im);
    }

    inline double Complex::getRe() const
    {
        return Re;
    }

    inline double Complex::getIm() const
    {
        return Im;
    }

    inline void Complex::setIm(double im)
    {

        Im = im;
    }

Complex operator+(double realNumber, Complex & right) ;


#endif
