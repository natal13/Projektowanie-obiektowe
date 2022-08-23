#include "String.h"

CString::CString()
{
    length = 0;
    data = new char[0];
}

CString::CString(char c)
{
    length = 1;
    data = new char(c);
}

CString::CString(const char* c)
{
    if (c)
    {
        unsigned n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data = new char[n];
        for (unsigned j = 0; j < n; j++)
            data[j] = c[j];
    }
    else
    {
        length = 0;
        data = new char[0];
    }
}

CString::CString(const CString& s)
{
    length = s.len();
    data = new char[length];
    for (unsigned j = 0; j < length; j++)
        data[j] = s[j];
}



CString::~CString()
{
    delete[] data;
}



unsigned CString::len() const
{
    return length;
}

int CString::index(char c) const
{
    for (unsigned j = 0; j < length; j++)
        if (data[j] == c) return (int)j;
    return -1;
}



void CString::upcase(unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j = first; j < last; j++)
        if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}

void CString::downcase(unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j = first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
}

void CString::togglecase(unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j = first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
        else if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}



std::ostream& operator<< (std::ostream& os, const CString& s)
{
    if (s.len() > 0)
    {
        for (unsigned j = 0; j < s.len(); j++)
            os << s[j];
    }
    else os << "";

    return os;
}

std::istream& operator>> (std::istream& is, CString& s)
{
    char* c = new char[1000];
    is >> c;
    s = CString(c);
    delete[] c;

    return is;
}



char CString::operator[] (unsigned j) const
{
    if (j >= length) throw 1;
    return data[j];
}

char& CString::operator[] (unsigned j)
{
    if (j >= length) throw 1;
    return data[j];
}



CString& CString::operator= (const CString& s)
{
    if (this == &s) return *this;

    delete data;
    length = s.len();
    data = new char[length];
    for (unsigned j = 0; j < length; j++)
        data[j] = s[j];
    return *this;
}



CString& CString::operator+= (const CString& s)
{
    unsigned len = length + s.len();
    char* str = new char[len];

    for (unsigned j = 0; j < length; j++)
        str[j] = data[j];

    for (unsigned i = 0; i < s.len(); i++)
        str[length + i] = s[i];

    delete data;
    length = len;
    data = str;
    return *this;
}



CString operator+ (const CString& lhs, const CString& rhs)
{
    return CString(lhs) += rhs;
}

CString operator+ (const CString& lhs, char rhs)
{
    return CString(lhs) += CString(rhs);
}

CString operator+ (const CString& lhs, const char* rhs)
{
    return CString(lhs) += CString(rhs);
}

CString operator+ (char lhs, const CString& rhs)
{
    return CString(lhs) += rhs;
}
CString operator+ (const char* lhs, const CString& rhs)
{
    return CString(lhs) += rhs;
}



bool operator== (const CString& lhs, const CString& rhs)
{
    if (lhs.len() != rhs.len()) return false;

    unsigned cap = lhs.len();
    unsigned   n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    return (n == cap);
}

bool operator== (const CString& lhs, char rhs)
{
    return (lhs == CString(rhs));
}

bool operator== (const CString& lhs, const char* rhs)
{
    return (lhs == CString(rhs));
}

bool operator== (char lhs, const CString& rhs)
{
    return (CString(lhs) == rhs);
}

bool operator== (const char* lhs, const CString& rhs)
{
    return (CString(lhs) == rhs);
}



bool operator> (const CString& lhs, const CString& rhs)
{
    unsigned cap = (lhs.len() < rhs.len()) ? lhs.len() : rhs.len();
    unsigned n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    if (n == cap) return (lhs.len() > rhs.len());

    if ((('A' <= lhs[n] && lhs[n] <= 'Z') || ('a' <= lhs[n] && lhs[n] <= 'z')) &&
        (('A' <= rhs[n] && rhs[n] <= 'Z') || ('a' <= rhs[n] && rhs[n] <= 'z')))
    {
        char A = (lhs[n] & ~32);
        char B = (rhs[n] & ~32);
        if (A != B) return (A > B);
    }
    return lhs[n] > rhs[n];
}

bool operator> (const CString& lhs, char rhs)
{
    return (lhs > CString(rhs));
}

bool operator> (const CString& lhs, const char* rhs)
{
    return (lhs > CString(rhs));
}

bool operator> (char lhs, const CString& rhs)
{
    return (CString(lhs) > rhs);
}

bool operator> (const char* lhs, const CString& rhs)
{
    return (CString(lhs) > rhs);
}



bool operator!= (const CString& lhs, const CString& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const CString& lhs, char rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const CString& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator!= (char lhs, const CString& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const char* lhs, const CString& rhs)
{
    return !(lhs == rhs);
}



bool operator< (const CString& lhs, const CString& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const CString& lhs, char rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const CString& lhs, const char* rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (char lhs, const CString& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const CString& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}



bool operator<= (const CString& lhs, const CString& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const CString& lhs, char rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const CString& lhs, const char* rhs)
{
    return !(lhs > rhs);
}

bool operator<= (char lhs, const CString& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const char* lhs, const CString& rhs)
{
    return !(lhs > rhs);
}



bool operator>= (const CString& lhs, const CString& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const CString& lhs, char rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const CString& lhs, const char* rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (char lhs, const CString& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const CString& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}