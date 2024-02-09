#pragma once
#include <iostream>

struct DIMENSION
{
	int row = 0;
	int col = 0;
};

class Matrix
{
public:
	Matrix(int p_row, int p_col, bool empty = false);
	~Matrix();
	Matrix(const Matrix& mat2);
	void clear();
	void rewrite(bool empty = false);
	int det(); //incomplete
	void transpose(); 
	void inverse(); //incomplete
	int trace() const; 
	const DIMENSION* getDim() const; 
	void print() const; // print function
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat1); //print operator
	Matrix operator+(const Matrix& mat2) const; //addition
	Matrix operator-(const Matrix& mat2) const; //substraction
	Matrix operator*(const Matrix& mat2) const; // matrix, matrix multiplication
	Matrix operator*(int m); //scaler multiplication
	friend Matrix operator*(int m, const Matrix& mat1); //prefix scaler multiplication
private:
	int det3x3();
	int det2x2();
	DIMENSION dim;
	int** mat = nullptr;
};

