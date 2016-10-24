#pragma once
#include <iostream>
class Matrix_
{
private:
	int rows;
	int cols;
	int **matrix;
public:
	Matrix_();
	Matrix_(int, int);
	Matrix_(Matrix_ &matr);
	Matrix_(Matrix_&& tmp);
	~Matrix_();

	friend void swap(Matrix_ &set1, Matrix_ &set2) throw();
	int &operator() (int, int);
	Matrix_ &operator+ (const Matrix_ &right);
	Matrix_ &operator+= (const Matrix_ &right);
	Matrix_ &operator- (const Matrix_ &right);
	Matrix_ &operator-= (const Matrix_ &right);
	Matrix_ &operator * (const Matrix_ &right);
	Matrix_ &operator *= (const Matrix_ &right);
	Matrix_ &operator= (const Matrix_ right);
	bool operator== (const Matrix_ &right) const;
	//Matrix_& operator=(Matrix_&& tmp);

	int getRows() const { return rows; }
	int getCols() const { return cols; }
	Matrix_ getTransp();
	double Determinat();
	friend std::ostream & operator<< (std::ostream&ostr, const Matrix_ &);
	friend std::istream & operator>> (std::istream&istr, Matrix_ &);
};

