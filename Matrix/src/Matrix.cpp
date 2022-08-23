#include "Matrix.h"


// constructor
  Matrix(const int row_count, const int column_count)
  {
    // tworzenie macierzy
    p = NULL;

    if (row_count > 0 && column_count > 0)
    {
      rows = row_count;
      cols = column_count;

      p = new double*[rows]; //dynamiczna alokacja
      for (int r = 0; r < rows; r++)
      {
        p[r] = new double[cols];

        // uzupelnienie zerami
        for (int c = 0; c < cols; c++)
        {
          p[r][c] = 0;
        }
      }
    }
  }

  // operator przypisania
  Matrix(const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;

    p = new double*[a.rows]; // dynamiczna alokacja

    for (int r = 0; r < a.rows; r++)
    {
      p[r] = new double[a.cols];

     //kopiowanie wart z mac a
      for (int c = 0; c < a.cols; c++)
      {
        p[r][c] = a.p[r][c];
      }
    }
  }


  double& operator()(const int r, const int c)
  {
    if (p != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
    {
      return p[r-1][c-1];
    }
    else
    {
      throw Exception("Subscript out of range"); //Wyjatek
    }
  }

 //do indeksow
  double get(const int r, const int c) const
  {
    if (p != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
    {
      return p[r-1][c-1];
    }
    else
    {
      throw Exception("Subscript out of range"); //Wyjatek
    }
  }

 //operator przypisania
  Matrix& operator= (const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;
    p = new double*[a.rows];

    for (int r = 0; r < a.rows; r++)
    {
      p[r] = new double[a.cols];

      for (int c = 0; c < a.cols; c++)
      {
        p[r][c] = a.p[r][c];
      }
    }
    return *this;
  }

  // dodawanie wart
  Matrix& Add(const double v)
  {
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        p[r][c] += v;
      }
    }
     return *this;
  }

  // odejmowanie
  Matrix& Subtract(const double v)
  {
    return Add(-v);
  }

  // mnozenie
  Matrix& Multiply(const double v)
  {
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        p[r][c] *= v;
      }
    }
     return *this;
  }

  // dzielenie
  Matrix& Divide(const double v)
  {
     return Multiply(1/v);
  }


  friend Matrix operator+(const Matrix& a, const Matrix& b)
  {
    // sprawdzanie wymiarow
    if (a.rows == b.rows && a.cols == b.cols)
    {
      Matrix res(a.rows, a.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c = 0; c < a.cols; c++)
        {
          res.p[r][c] = a.p[r][c] + b.p[r][c];
        }
      }
      return res;
    }
    else
    {
      throw Exception("Dimensions does not match"); //Blad
    }

    // 'na wszelki wypadek' zwracamy pusta macierz
    return Matrix();
  }

    //dodawanie
  friend Matrix operator+ (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Add(b);
    return res;
  }
    //dodawanie
  friend Matrix operator+ (const double b, const Matrix& a)
  {
    Matrix res = a;
    res.Add(b);
    return res;
  }

  // odejmowanie
  friend Matrix operator- (const Matrix& a, const Matrix& b)
  {
    // czy sa takie same
    if (a.rows == b.rows && a.cols == b.cols)
    {
      Matrix res(a.rows, a.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c = 0; c < a.cols; c++)
        {
          res.p[r][c] = a.p[r][c] - b.p[r][c];
        }
      }
      return res;
    }
    else
    {
      throw Exception("Dimensions does not match"); //blad
    }
    //ponownie to co u gory
    return Matrix();
  }

  // odejmowanie
  friend Matrix operator- (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Subtract(b);
    return res;
  }
  // odejmowanie
  friend Matrix operator- (const double b, const Matrix& a)
  {
    Matrix res = -a;
    res.Add(b);
    return res;
  }

  // operator -
  friend Matrix operator- (const Matrix& a)
  {
    Matrix res(a.rows, a.cols);

    for (int r = 0; r < a.rows; r++)
    {
      for (int c = 0; c < a.cols; c++)
      {
        res.p[r][c] = -a.p[r][c];
      }
    }

    return res;
  }

  // operator mnozenia
  friend Matrix operator* (const Matrix& a, const Matrix& b)
  {
    // czy sa takie same
    if (a.cols == b.rows)
    {
      Matrix res(a.rows, b.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c_res = 0; c_res < b.cols; c_res++)
        {
          for (int c = 0; c < a.cols; c++)
          {
            res.p[r][c_res] += a.p[r][c] * b.p[c][c_res];
          }
        }
      }
      return res;
    }
    else
    {

      throw Exception("Dimensions does not match");
    }
    return Matrix();
  }

  friend Matrix operator* (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Multiply(b);
    return res;
  }

  friend Matrix operator* (const double b, const Matrix& a)
  {
    Matrix res = a;
    res.Multiply(b);
    return res;
  }


  friend Matrix operator/ (const Matrix& a, const Matrix& b)
  {
    if (a.rows == a.cols && a.rows == a.cols && b.rows == b.cols)
    {
      Matrix res(a.rows, a.cols);

      res = a * Inv(b);

      return res;
    }
    else
    {
      throw Exception("Dimensions does not match");
    }


    return Matrix();
  }

  friend Matrix operator/ (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Divide(b);
    return res;
  }

  friend Matrix operator/ (const double b, const Matrix& a)
  {
    Matrix b_matrix(1, 1);
    b_matrix(1,1) = b;

    Matrix res = b_matrix / a;
    return res;
  }

   //zwracanie minorow
  Matrix Minor(const int row, const int col) const
  {
    Matrix res;
    if (row > 0 && row <= rows && col > 0 && col <= cols)
    {
      res = Matrix(rows - 1, cols - 1);

      for (int r = 1; r <= (rows - (row >= rows)); r++)
      {
        for (int c = 1; c <= (cols - (col >= cols)); c++)
        {
          res(r - (r > row), c - (c > col)) = p[r-1][c-1];
        }
      }
    }
    else
    {
      throw Exception("Index for minor out of range");
    }

    return res;
  }

  //zwraca l wiersz
  int GetRows() const
  {
    return rows;
  }

  // kolumn
  int GetCols() const
  {
    return cols;
  }

  void Print() const
  {
    if (p != NULL)
    {
      printf("[");
      for (int r = 0; r < rows; r++)
      {
        if (r > 0)
        {
          printf(" ");
        }
        for (int c = 0; c < cols-1; c++)
        {
          printf("%.2f, ", p[r][c]);
        }
        if (r < rows-1)
        {
          printf("%.2f;\n", p[r][cols-1]);
        }
        else
        {
          printf("%.2f]\n", p[r][cols-1]);
        }
      }
    }
    else
    {
      // macierz jest pusta
      printf("[ ]\n");
    }
  }

  //###

  int Size(const Matrix& a, const int i)
{
  return a.Size(i);
}


Matrix Ones(const int rows, const int cols)
{
  Matrix res = Matrix(rows, cols);

  for (int r = 1; r <= rows; r++)
  {
    for (int c = 1; c <= cols; c++)
    {
      res(r, c) = 1;
    }
  }
  return res;
}

//same zera
Matrix Zeros(const int rows, const int cols)
{
  return Matrix(rows, cols);
}

//diagonalna
Matrix Diag(const int n)
{
  Matrix res = Matrix(n, n);
  for (int i = 1; i <= n; i++)
  {
    res(i, i) = 1;
  }
  return res;
}


Matrix Diag(const Matrix& v)
{
  Matrix res;
  if (v.GetCols() == 1)
  {
    // wktor n x 1
    int rows = v.GetRows();
    res = Matrix(rows, rows);

    // kopiowanie wart wektora do macierzy
    for (int r=1; r <= rows; r++)
    {
      res(r, r) = v.get(r, 1);
    }
  }
  else if (v.GetRows() == 1)
  {
    //  macierz - wector 1 x n
    int cols = v.GetCols();
    res = Matrix(cols, cols);


    for (int c=1; c <= cols; c++)
    {
      res(c, c) = v.get(1, c);
    }
  }
  else
  {
    throw Exception("Parameter for diag must be a vector");
  }
  return res;
}

//wyznacznik macierzy
double Det(const Matrix& a)
{
  double d = 0;    // wartosc wyzn
  int rows = a.GetRows();
  int cols = a.GetRows();

  if (rows == cols)
  {
    // macierz kwadratowa
    if (rows == 1)
    {
      // macierz 1 x 1
      d = a.get(1, 1);
    }
    else if (rows == 2)
    {
      //  2 x 2
      //  [a11,a12;a21,a22] det = a11*a22-a21*a12
      d = a.get(1, 1) * a.get(2, 2) - a.get(2, 1) * a.get(1, 2);
    }
    else
    {
      //  3 x 3
      for (int c = 1; c <= cols; c++)
      {
        Matrix M = a.Minor(1, c);
        //d += pow(-1, 1+c) * a(1, c) * Det(M);
        d += (c%2 + c%2 - 1) * a.get(1, c) * Det(M);
      }
    }
  }
  else
  {
    throw Exception("Matrix must be square");
  }
  return d;
}

// wymiana 2 wart
void Swap(double& a, double& b)
{
  double temp = a;
  a = b;
  b = temp;
}

//odwrotnosc macierzy
Matrix Inv(const Matrix& a)
{
  Matrix res;
  double d = 0;
  int rows = a.GetRows();
  int cols = a.GetRows();

  d = Det(a);
  if (rows == cols && d != 0)
  {
    // macierz kwadratowa
    if (rows == 1)
    {
      // 1 x 1
      res = Matrix(rows, cols);
      res(1, 1) = 1 / a.get(1, 1);
    }
    else if (rows == 2)
    {
      //  2 x 2
      res = Matrix(rows, cols);
      res(1, 1) = a.get(2, 2);
      res(1, 2) = -a.get(1, 2);
      res(2, 1) = -a.get(2, 1);
      res(2, 2) = a.get(1, 1);
      res = (1/d) * res;
    }
    else
    {
      // 3 x 3 albo wieksza
      //  gauss-jordan

      res = Diag(rows);   //macierz diagonalna
      Matrix ai = a;    // kopia mac a

      for (int c = 1; c <= cols; c++)
      {

        int r;
        for (r = c; r <= rows && ai(r, c) == 0; r++)
        {
        }
        if (r != c)
        {
          // swap wiersze
          for (int s = 1; s <= cols; s++)
          {
            Swap(ai(c, s), ai(r, s));
            Swap(res(c, s), res(r, s));
          }
        }

        // eliminacja niezerowych wart
        for (int r = 1; r <= rows; r++)
        {
          if(r != c)
          {
            // eliminacja wart z kolumny c i wiersza r
            if (ai(r, c) != 0)
            {
              double f = - ai(r, c) / ai(c, c);

              //  dodat=nie (f * row c) do wiersza wyrzuconej wart
              for (int s = 1; s <= cols; s++)
              {
                ai(r, s) += f * ai(c, s);
                res(r, s) += f * res(c, s);
              }
            }
          }
          else
          {
            // obliczanie wart
            // podzielenie kazdej wart w rzedzie r wart at

            double f = ai(c, c);
            for (int s = 1; s <= cols; s++)
            {
              ai(r, s) /= f;
              res(r, s) /= f;
            }
          }
        }
      }
    }
  }
  else
  {
    if (rows == cols)
    {
      throw Exception("Matrix must be square");
    }
    else
    {
      throw Exception("Determinant of matrix is zero");
    }
  }
  return res;
}


