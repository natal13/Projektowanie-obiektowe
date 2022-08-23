#ifndef MATRIX_H
#define MATRIX_H



class Matrix
{
public:
  // constructor
  Matrix()
  {
    p = NULL;
    rows = 0;
    cols = 0;
  }

    //konstr - uwaga wrocic
  Matrix(const int row_count, const int column_count)
  {

    p = NULL;

    if (row_count > 0 && column_count > 0)
    {
      rows = row_count;
      cols = column_count;

      p = new double*[rows];
      for (int r = 0; r < rows; r++)
      {
        p[r] = new double[cols];

        for (int c = 0; c < cols; c++)
        {
          p[r][c] = 0;
        }
      }
    }

    public:
  // destructor
  ~Matrix()
  {
    // clean up allocated memory
    for (int r = 0; r < rows; r++)
    {
      delete p[r];
    }
    delete p;
    p = NULL;
  }

private:
  int rows;
  int cols;
  double** p;     // pointer to a matrix with doubles
};



  }

  // assignment operator
  Matrix(const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;
    p = new double*[a.rows];
    for (int r = 0; r < a.rows; r++)
    {
      p[r] = new double[a.cols];

      // copy the values from the matrix a
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
      throw Exception("Subscript out of range");
    }
  }



  double get(const int r, const int c) const
  {
    if (p != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
    {
      return p[r-1][c-1];
    }
    else
    {
      throw Exception("Subscript out of range");
    }
  }

  Matrix& operator= (const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;
    p = new double*[a.rows];
    for (int r = 0; r < a.rows; r++)
    {
      p[r] = new double[a.cols];

    //kopiowanie wart
      for (int c = 0; c < a.cols; c++)
      {
        p[r][c] = a.p[r][c];
      }
    }
    return *this;
  }




