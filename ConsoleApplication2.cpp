#include "stdafx.h"
#include "Matrix_.h"


int main(int argc, char **argv)
{
	int n, m;
	std::cout << " ������� ������ �������" << std::endl;
	std::cin >> n >> m;
	Matrix_ m1(n ,m);
	std::cout << " ������� �������" << std::endl;
	std::cin >> m1;
	std::cout << m1;
	Matrix_ m2(m1);
	std::cout << (m1 + m2);
	m1 += m2;
	std::cout << m1;
	std::cout << (m1 - m2);
	Matrix_ m3 = m2;
	if (m3 == m2)
		std::cout << "������� myMatrix3 � myMatrix2 �����!\n" << std::endl;
	std::cout << m3;
	std::cout << (m1 * m2);
	m3 *= m2;
	std::cout << m3.getTransp();
    return 0;
}

