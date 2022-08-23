#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::istream;
using std::ostream;

//wyjatki
#define VERROR				0x00
#define ZERODIVIDING        0x01
typedef unsigned short USHORT;
class Comple#define VERROR				0x00
#define ZERODIVIDING        0x01
typedef unsigned short USHORT;

class ComplexExeption
{
public:
	ComplexExeption(USHORT errCode = VERROR) { m_Err = errCode; }
	const char* ShowReason();
private:
	USHORT m_Err;
};

inline const char* ComplexExeption::ShowReason()
{
	switch (m_Err)
	{
	case ZERODIVIDING: return "You can't divide by zero!\n";
	default: return "Other stack error";
	}
}
{
public:
    ComplexExeption(USHORT errCode = VERROR) { m_Err = errCode; }
    const char* ShowReason();
private:
    USHORT m_Err;
};

inline const char* ComplexExeption::ShowReason()
{
    switch (m_Err)
    {
    case ZERODIVIDING: return "You can't divide by zero!\n";
    default: return "Other stack error";
    }
}


class Complex
{

    Complex(double re = 0, double im = 0);
    Complex(const Complex& z);
    Complex& operator = (const Complex& z);
    ~Complex();

    double getRe() const; //gettery
    double getIm() const;

    void setRe(double);  //settery
    void setIm(double);

    void setCoplex(double re, double im);


    friend bool operator ==(const Complex& z1, const Complex& z2);
    friend bool operator !=(const Complex& z1, const Complex& z2);

    friend istream& operator >> (istream& in, Complex& z);
    friend ostream& operator << (ostream& out, const Complex& z);

    friend const Complex operator + (const Complex& z1, const Complex& z2);
    friend const Complex operator - (const Complex& z1, const Complex& z2);
    friend const Complex operator * (const Complex& z1, const Complex& z2);
    friend const Complex operator / (const Complex& z1, const Complex& z2);



    Complex& operator +=(const Complex& z);
    Complex& operator -=(const Complex& z);
    Complex& operator *=(const Complex& z);
    Complex& operator /=(const Complex& z);

//----------------
    Complex& Complex::operator-=(const Complex& z);
    Complex& Complex::operator-=(double z);

    Complex& Complex::operator*=(const complex& z);
    Complex& Complex::operator*=(double z);

    Complex& Complex::operator/=(const complex& z);
    Complex& Complex::operator/=(double z);

  
    void Complex::operator/=(const Complex& z);
    void Complex::operator/=(double r);
    void Complex::operator*=(double r);
    void Complex::operator*=(const Complex& z);
    void Complex::operator-=(const Complex& z);
    void Complex::operator+=(const Complex& z);

private:
    double Im;
    double Re;

};


