
#include<iostream>
#include "TVector.h"

template <class T>

class TMatrix
{
protected:
	int size;
	T* data;
public:
	TMatrix(const TMatrix<T>& p); 
	TMatrix(const TMatrix<T>&& p);//перемещение матрицы
	TMatrix(int,int);//конструктор по умолчанию
	~TMatrix();
	TMatrix<T>&operator+(const TMatrix<T>&);
	TMatrix<T>&operator-(const TMatrix<T>&);
	TMatrix<T>&operator*(const TMatrix<T>&);
	TMatrix<T>&operator*(double p);

	TMatrix<T>& operator=(const TMatrix<T>&);
	TMatrix<T>& operator==(const TMatrix<T>&);
	void Resize(int, int);




};
