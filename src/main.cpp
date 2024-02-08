#include <iostream>
#include "../include/Matrix.h"
int main()
{
	Matrix mat1(2,2);
	std::cout<<mat1;
	mat1.transpose();
	std::cout<<mat1;
	return 0;
}
