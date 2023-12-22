#pragma once
#include <iostream>


template <class T>

class TVector
{
protected:
	int size;
	T* data;
public:
	TVector(const TVector<T>&);
	TVector(const TVector<T>&&);
	TVector(int _size = 3);
	~TVector();
	int GetSize();
	T* GetData();
	void Resize(int);
	TVector<T>&operator+(const TVector<T>& p);
	TVector<T>&operator-(const TVector<T>& p);
	TVector<T>&operator*(const TVector<T>& p);
	TVector<T>&operator*(double p);
	TVector<T>& operator=(const TVector<T>& p);
	TVector<T>& AddVec(int _size, T* d);
	friend std::ostream& operator<<(std::ostream& os, const TVector& p);
	friend std::istream& operator>>(std::istream& is, TVector& p);
	void Vvod();
};


template <class T>
TVector<T>::TVector(int _size) //создание вектора по умолчанию
{
	if (_size <= 0)
		throw "” вектора не может быть отрицательной размерности";
	size = _size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

template <class T>
TVector<T>::TVector(const TVector<T>& p) //копирование вектора
{
	size = p.size;
	if (data != nullptr)
		delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>
TVector<T>::TVector(const TVector<T>&& p) //перемещение вектора
{
	size = p.size;
	data = p.data;
	p.size = 0;
	p.data = nullptr;
}


template <class T>
TVector<T>::~TVector() //деструктор вектора
{
	if (data != nullptr)
		delete[]data;
	data = nullptr;
	size = 0;
}
template <class T>
int TVector<T>::GetSize()  //получение размерности вектора
{
	return size;
}

//ћетоды:

template <class T>
void TVector<T>::Resize(int newsize) // изменение размерности вектора
{
	if (newsize <= 0)
		throw "invalid size";
	T* newdata = new T[newsize];
	for (int i = 0; i < newsize; i++)
	{
		newdata[i] = data[i];
		delete[] data;
		data = newdata;
	}
}

template <class T>
T* TVector<T>::GetData() // получение значений вектора
{
	T* res = new T;
	for (int i = 0; i < size; i++)
	{
		res[i] = data[i];
	}
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator+ (const TVector <T>& p) //сложение векторов
{
	TVector<T> res(size);
	if (size == p.size) //проверка совпадени€ размерности 
	{
		for (int i = 0; i < size; i++)
		{
			res.data[i] = data[i] + p.data[i];
		}
		std::cout << "tested " << res << std::endl;
	}
	else
	{
		std::cerr << "–азмерность векторов не совпадает";
	}
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator- (const TVector <T>& p) //сложение векторов
{
	if (size == p.size) //проверка совпадени€ размерности 
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = data[i] - p.data[i];
		}
		return *this;
	}
	else
	{
		std::cerr << "–азмерность векторов не совпадает";
	}
}
/*
template <class T>
TVector<T>& TVector<T>::operator* (const TVector <T>& p)
{

}
*/
template <class T>
TVector<T>& TVector<T>::operator* (double chislo) //умножение вектора на число
{
	TVector<T> res = *this;
	for (int i = 0; i < size; i++)
		res.data[i] *= chislo;
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& p) //присвоение вектора
{
	if (this == &p)
		return *this;
	if (data != nullptr)
		delete[] data;
	data = new T[size];
	this->AddVec(size, data);
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
	return *this;

}

template <class T>
TVector<T>& TVector<T>::AddVec(int _size, T* d) //функци€ конвертирует входные данные в TVector
{
	if (_size != size)// по какой то вдруг причине размерности выделенной под вектор пам€ти и пришедша€ не совпадают
	{
		delete[] data;
		data = new T [_size];
		if (size < _size) //≈сли пришедший более размерный чем выделенный
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = d[i];
			}
			for (int i = size; i < _size; i++)
			{
				data[i] = 0;
			}
			size = _size;
			return *this;
		}
		if (size > _size)// если пришедший менее размерный чем выделенный
		{
			for (int i = 0; i < _size; i++)
			{
				data[i] = d[i];
			}
			size = _size;
			return *this;
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = d[i];
		}
		return *this;
	}
}


std::ostream& operator<<(std::ostream& os, const TVector<double> &p)
{
	os << "–азмерность вектора : " << p.size << std::endl;
	os << "¬ектор: (";
	for (int i = 0; i < p.size; i++)
	{
		os << p.data[i];
		if (i < p.size-1)
			os << ",";
	}
	os << ")" << std::endl;
	return os;
}

template <class T>
void TVector<T>::Vvod() // ‘ункци€ ввода данных с клавиатуры
{
	std::cout << "¬ведите размерность вектора" << std::endl;
	std::cin >> size;
	data = new T[size];
	std::cout << "¬ведите числа вектора" << std::endl;
	for (int i = 0; i < size; i++)
		std::cin >> data[i];
	this->AddVec(size, data); //отправка на конвертацию с проверкой (избавл€ет от ошибок, без нее в дате будет вс€кий бред)
}

