#include "stdafx.h"
#include "Matrix_.h"


Matrix_::Matrix_() : rows(0), cols(0)
{
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];
}

Matrix_::Matrix_(int x, int y) : rows(x), cols(y)
{
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];
}

Matrix_::Matrix_(Matrix_ &matr) : rows(matr.rows), cols(matr.cols)
{
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	for (int i =0; i < rows; i++)
		for (int j = 0; j < cols; j++) 
			matrix[i][j] = matr.matrix[i][j];
}

Matrix_::Matrix_(Matrix_ &&tmp) : rows(tmp.rows), cols(tmp.cols)
{
	matrix = tmp.matrix;
	tmp.matrix = nullptr;
}

//Matrix_ &Matrix_::operator=(Matrix_&& tmp)
//{
//	for (int i = 0; i < rows; i++)
//		delete[] matrix[i];
//	delete[] matrix;
//	rows = tmp.rows;
//	cols = tmp.cols;
//	for (int i = 0; i < rows; i++)
//		matrix[i] = tmp.matrix[i];
//	matrix = tmp.matrix;
//	tmp.matrix = nullptr;
//	return *this;
//}

int &Matrix_::operator() (int row, int col)
{
	if ((row > rows) || (col > cols))
	{
		std::cerr << "\n Ошибка индекса: " << row << " " << col << std::endl;
		exit(1); 
	}
	return (matrix[row][col]);
}

const Matrix_ &Matrix_::operator= (const Matrix_ &right)
{
	if (&right != this)
	{
		if (rows != right.rows || cols != right.cols)
		{
			for (int i = 0; i < rows; i++)
				delete[] matrix[i];
			delete[] matrix;
			matrix = new int*[rows];
			for (int i = 0; i < rows; i++)
				matrix[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = right.matrix[i][j];
	}

	return *this;
}

Matrix_ &Matrix_::operator+ (const Matrix_ &right)
{
	if (rows != right.rows || cols != right.cols)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	Matrix_ result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
	return result;
}

Matrix_ &Matrix_::operator+= (const Matrix_ &right)
{
	if (rows != right.rows || cols != right.cols)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = matrix[i][j] + right.matrix[i][j];
	return *this;
}

Matrix_ &Matrix_::operator- (const Matrix_ &right)
{
	if (rows != right.rows || cols != right.cols)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	Matrix_ result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j] - right.matrix[i][j];
	return result;
}

Matrix_ &Matrix_::operator-= (const Matrix_ &right)
{
	if (rows != right.rows || cols != right.cols)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = matrix[i][j] - right.matrix[i][j];
	return *this;
}

Matrix_ &Matrix_::operator* (const Matrix_ &right)
{
	if (cols != right.rows)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	Matrix_ result(rows, right.cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < right.cols; j++) {
			int s = 0;
			for (int r = 0; r < cols; r++) {
				s += matrix[i][r] * right.matrix[r][j];
			}
			result.matrix[i][j] = s;
		}
	}
	return result;
}

Matrix_ &Matrix_::operator*= (const Matrix_ &right)
{
	if (cols != right.rows || right.rows != right.cols)
	{
		std::cout << "Массивы разного размера!\n" << std::endl;
		exit(1);
	}

	Matrix_ result(rows, right.cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < right.cols; j++) {
			int s = 0;
			for (int r = 0; r < cols; r++) {
				s += matrix[i][r] * right.matrix[r][j];
			}
			result.matrix[i][j] = s;
		}
	}
	*this = result;
	return *this;
}

Matrix_ Matrix_::getTransp()
{
	Matrix_ result(rows, cols);
	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
		{
			result.matrix[i][j] = matrix[j][i];
		}
	return result;
}

bool Matrix_::operator== (const Matrix_ &right) const
{
	if (rows != right.rows || cols != right.cols)
		return false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] != right.matrix[i][j])
				return false;
	return true;
}

std::ostream & operator <<(std::ostream&ostr, const Matrix_&m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			ostr << m.matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	ostr << std::endl; // перенос маркера на новую строку

	return ostr;
}

std::istream &operator >> (std::istream&istr, Matrix_&m)
{
	for (int i = 0; i < m.rows; i++)
		for (int j = 0; j < m.cols; j++)
			istr >> m.matrix[i][j];
	return istr;
}

Matrix_::~Matrix_()
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

