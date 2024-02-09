#pragma once

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
	TMatrix(int);//конструктор по умолчанию
	~TMatrix();
	TMatrix<T>&operator+(const TMatrix<T>&);
	TMatrix<T>&operator-(const TMatrix<T>&);
	TMatrix<T>&operator*(const TMatrix<T>&);
	TMatrix<T>&operator*(double p);

	TMatrix<T>& operator=(const TMatrix<T>&);
	bool operator==(const TMatrix<T>&);
	void Resize(int, int);




};
/*
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& p) //копирование матрицы
{
	size = p.size;
	if (data != nullptr)
		delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>

TMatrix<T>::TMatrix(int row)
{

}*/