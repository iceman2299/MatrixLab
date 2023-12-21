
#include "TMatrix.h"
#include "TVector.h"
#include <iostream>

template <class T>

TMatrix<T>::TMatrix(int n, int m)
{
	if (n <= 0 || m <= 0)
	throw "invalid size"
	size = n;
	data = new TVector<T> [size]
	for (int i = 0; i < size; i++)
	{
		data[i].Resize(m);
	}
}

template <class T>

TMatrix<T>::TMatrix(const TMatrix<T>& p) 
{
	size = p.size;
	data = new TVector<T>[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>

TMatrix<T>::TMatrix(const TMatrix<T>&& p)
{
	size = p.size;
	data = p.data;
	p.size = 0;
	p.data = nullptr;
}

template <class T>

TMatrix<T>& TMatrix<T>::operator+ (const TMatrix<T>& p)
{
	TMatrix<T> res = *this;
	for (int i = 0; i < size: i++)
	{
		res[i] = data[i] + p.data[i];
	}
	return res;
}

TMatrix<T>& TMatrix<T>::operator- (const TMatrix<T>& p)
{
	TMatrix<T> res = *this;
	for (int i = 0; i < size: i++)
	{
		res[i] = data[i] - p.data[i];
	}
	return res;
}

TMatrix<T>& TMatrix<T>::operator* (const TMatrix<T> &p)
{
	TMatrix<T> res(*this);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < p.size; j++)
		{
			res[i][j] = 0;
			for (int n = 0; n < size; n++)
			{
				res[i][j] += data[i][j] * p.data[i][j];
			}
		}
	}
	return res;
}

TMatrix<T>& TMatrix<T>::operator= (const TMatrix<T>& p)
{
	if (*this == &p)
		return *this;
	delete[] data;
	size = p.size;
	data = new TVector<T>[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = p.data[i];
	}
	return *this;
}

TMatrix<T>& TMatrix<T>::operator* (double n)
{
	TMatrix<T> res = *this;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i][j] *= n;
		}
	}
	return res;
}

TMatrix<T>::~TMatrix<T>()
{
	size = 0;
	data = nullptr;
}


bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
	if (size != p.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if data[i][j] != p.data[i][j]
				return false;
		}
		return true;
	}
}


void TMatrix<T>::Resize(int n, int m)
{
	if (n < 0 || m < 0)
		throw "invalid size"
		TVector<T>*res = new TVector[n];
	for (int i = 0; i < min(n,size); i++)
	{
		res[i].Resize(m);
		for (int j = 0; j < min(m, data[i].size); j++)
		{
			res[i][j] = data[i][j];
		}
	}
}





