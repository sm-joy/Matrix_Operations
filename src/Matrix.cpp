#include "../include/Matrix.h"


Matrix::Matrix(int p_row, int p_col, bool empty)
{
	dim.row = p_row;
	dim.col = p_col;
	rewrite(empty);
}

Matrix::~Matrix() { delete[] mat; }

Matrix::Matrix(const Matrix& mat2) : dim{mat2.dim.row, mat2.dim.col} 
{
	mat = new int*[dim.row];
    for (int i = 0; i < dim.row; ++i) 
	{
        mat[i] = new int[dim.col];
        for (int j = 0; j < dim.col; ++j) 
            mat[i][j] = mat2.mat[i][j];
    }
}


void Matrix::rewrite(bool empty)
{
	if(mat == nullptr)
	{
		mat = new int*[dim.row];
		for(int i = 0; i < dim.row; i++)
		{
			mat[i] = new int[dim.col];
		}
	}
	
	if(!empty)
	{
		int temp = 0;
		for(int i = 0; i < dim.row; i++)
		{
			for(int j = 0; j < dim.col; j++)
			{
				std::cout<<"\nEnter Value At ("<<i+1<<", "<<j+1<<") : ";std::cin>>temp; 
				mat[i][j] = temp;
				temp = 0;
			}
		}
	}
	else
	{
		for(int i = 0; i < dim.row; i++)
		{
			for(int j = 0; j < dim.col; j++)
				mat[i][j] = 0;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat1)
{
     for (int i = 0; i < mat1.dim.row; i++) 
	 {
		 os<<"\n[";
        for (int j = 0; j < mat1.dim.col; j++) 
		{
            if (j == mat1.dim.col - 1)
                os << mat1.mat[i][j];
            else
                os << mat1.mat[i][j] << " ";
        }
		os<<"]";
	 }
	 os<<"\n";
    return os;
}

void Matrix::print() const
{
	std::cout<< (*this);
}

int Matrix::trace() const
{
	int traceSum = 0;
	if(dim.col == dim.row)
	{
		for(int i = 0; i < dim.row; i++)
			traceSum += mat[i][i];
	}
	else
		std::cout<<"\nThis Matrix is not a Square Matrix.";

	return traceSum;
}

void Matrix::clear()
{
	for(int i = 0; i < dim.row; i++)
	{
		for(int j = 0; j < dim.col;j++)
		{
			mat[i][j] = 0;
		}
	}

}

const DIMENSION* Matrix::getDim() const { return &dim; }



Matrix Matrix::operator+(const Matrix& mat2) const
{
	Matrix res(dim.row, dim.col, true);
	if(mat2.dim.row == dim.row && mat2.dim.col == dim.col)
	{
		for(int i = 0; i < dim.row; i++)
		{
			for(int j = 0; j < dim.col; j++)
			{
				res.mat[i][j] = mat[i][j] + mat2.mat[i][j];
			}
		}
	}
	else
		std::cout<<"\nDimension Error!";
	return res;
}

Matrix Matrix::operator-(const Matrix& mat2) const
{
	Matrix res(dim.row, dim.col, true);
	if(mat2.dim.row == dim.row && mat2.dim.col == dim.col)
	{
		for(int i = 0; i < dim.row; i++)
		{
			for(int j = 0; j < dim.col; j++)
			{
				res.mat[i][j] = mat[i][j] - mat2.mat[i][j];
			}
		}
	}
	else
		std::cout<<"\nDimension Error!";
	return res;
}

Matrix Matrix::operator*(const Matrix& mat2) const
{
	Matrix res(dim.row, mat2.dim.col, true);
	if(mat2.dim.row == dim.col)
	{
		for(int i = 0; i < res.dim.row; i++)
		{
			for(int j = 0; j < res.dim.col; j++)
			{
				for(int k = 0; k < dim.col; k++)
					res.mat[i][j] += mat[i][k] * mat2.mat[k][j];
			}
		}
	}
	else
		std::cout<<"\nDimension Error!";
	return res;
}

Matrix Matrix::operator*(int m)
{
	Matrix res(dim.row, dim.col, true);
	for(int i = 0; i < res.dim.row; i++)
	{
		for(int j = 0; j < res.dim.col; j++)
		{
			res.mat[i][j] = mat[i][j] * m;
		}
	}	
	return res;
}

Matrix operator*(int m, const Matrix& mat1)
{
	Matrix res(mat1.dim.row, mat1.dim.col, true);
	for(int i = 0; i < res.dim.row; i++)
	{
		for(int j = 0; j < res.dim.col; j++)
		{
			res.mat[i][j] = mat1.mat[i][j] * m;
		}
	}	
	return res;
}

void Matrix::transpose()
{
	int temp = 0;
	for(int i = 0; i < dim.row; i++)
	{
		for(int j = i+1; j < dim.col; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;

		}
	}
}
