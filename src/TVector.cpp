

#include "TVector.h"
#include <iostream>


template <class T>

TVector<T>::TVector(int _size)
{
	if (_size <= 0)
		throw "size less"
	size = _size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

template <class T>
TVector<T>::TVector(const TVector<T>&p)
{
	size = p.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>
TVector<T>::TVector(const TVector<T>&&p)
{
	size = p.size;
	data = p.data;
	p.size = 0;
	p.data = nullptr;
}


template <class T>
inline TVector<T>::~TVector()
{
	if (data != nullptr)
		delete[]data;
	data = nullptr;
	size = 0;
}
template <class T>
int TVector<T>::GetSize()
{
	return size;
}

template <class T>
void TVector<T>::Resize(int newsize)
{
	if (newsize <= 0)
		throw "invalid size"
		newdata = new T[newsize];
	for (int i = 0; i < newsize; i++)
	{
		newdata[i] = data[i];
		delete[] data;
		data = newdata;
	}
}

template <class T>
T* TVector<T>::GetData()
{
	T* res = new T;
	for (int i = 0; i < size; i++)
	{
		res[i] = data[i];
	}
	return res;
}
template <class T>
TVector<T>& TVector<T>::operator+ (const TVector <T>& p)
{

}
template <class T>
TVector<T>& TVector<T>::operator- (const TVector <T>& p)
{

}
template <class T>
TVector<T>& TVector<T>::operator* (const TVector <T>& p)
{

}

template <class T>

TVector<T>& TVector<T>::operator* (double n)
{
	TVector<T> res = *this;
	for (int i = 0; i < size; i++)
		res.data[i] *= n;
}