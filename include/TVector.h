
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
	TVector(int);//Конструктор по умолчанию
	~TVector();//Деструктор вектора
	int GetSize();//Функция возвращает размерность вектора
	T* GetData;
	void Resize(int);
	TVector<T>operator+(const TVector<T>& p);
	TVector<T>operator-(const TVector<T>& p);
	TVector<T>operator*(const TVector<T>& p);

	TVector<T>operator*(double p);

	TVector<T>& operator=(const TVector<T>& p);


};