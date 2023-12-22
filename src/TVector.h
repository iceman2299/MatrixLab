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
TVector<T>::TVector(int _size) //�������� ������� �� ���������
{
	if (_size <= 0)
		throw "� ������� �� ����� ���� ������������� �����������";
	size = _size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

template <class T>
TVector<T>::TVector(const TVector<T>& p) //����������� �������
{
	size = p.size;
	if (data != nullptr)
		delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>
TVector<T>::TVector(const TVector<T>&& p) //����������� �������
{
	size = p.size;
	data = p.data;
	p.size = 0;
	p.data = nullptr;
}


template <class T>
TVector<T>::~TVector() //���������� �������
{
	if (data != nullptr)
		delete[]data;
	data = nullptr;
	size = 0;
}
template <class T>
int TVector<T>::GetSize()  //��������� ����������� �������
{
	return size;
}

//������:

template <class T>
void TVector<T>::Resize(int newsize) // ��������� ����������� �������
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
T* TVector<T>::GetData() // ��������� �������� �������
{
	T* res = new T;
	for (int i = 0; i < size; i++)
	{
		res[i] = data[i];
	}
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator+ (const TVector <T>& p) //�������� ��������
{
	TVector<T> res(size);
	if (size == p.size) //�������� ���������� ����������� 
	{
		for (int i = 0; i < size; i++)
		{
			res.data[i] = data[i] + p.data[i];
		}
		std::cout << "tested " << res << std::endl;
	}
	else
	{
		std::cerr << "����������� �������� �� ���������";
	}
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator- (const TVector <T>& p) //�������� ��������
{
	if (size == p.size) //�������� ���������� ����������� 
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = data[i] - p.data[i];
		}
		return *this;
	}
	else
	{
		std::cerr << "����������� �������� �� ���������";
	}
}
/*
template <class T>
TVector<T>& TVector<T>::operator* (const TVector <T>& p)
{

}
*/
template <class T>
TVector<T>& TVector<T>::operator* (double chislo) //��������� ������� �� �����
{
	TVector<T> res = *this;
	for (int i = 0; i < size; i++)
		res.data[i] *= chislo;
	return res;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& p) //���������� �������
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
TVector<T>& TVector<T>::AddVec(int _size, T* d) //������� ������������ ������� ������ � TVector
{
	if (_size != size)// �� ����� �� ����� ������� ����������� ���������� ��� ������ ������ � ��������� �� ���������
	{
		delete[] data;
		data = new T [_size];
		if (size < _size) //���� ��������� ����� ��������� ��� ����������
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
		if (size > _size)// ���� ��������� ����� ��������� ��� ����������
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
	os << "����������� ������� : " << p.size << std::endl;
	os << "������: (";
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
void TVector<T>::Vvod() // ������� ����� ������ � ����������
{
	std::cout << "������� ����������� �������" << std::endl;
	std::cin >> size;
	data = new T[size];
	std::cout << "������� ����� �������" << std::endl;
	for (int i = 0; i < size; i++)
		std::cin >> data[i];
	this->AddVec(size, data); //�������� �� ����������� � ��������� (��������� �� ������, ��� ��� � ���� ����� ������ ����)
}

