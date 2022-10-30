#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T, typename V> Vector<T, V>::Vector()
{}

template <typename T, typename V> Vector<T, V>::Vector(V size) : size(size)
{
	if (size <= 0)	cout << "Invalid vector size: " << size << endl;
	data = new T[size];
}

template <typename T, typename V> Vector<T, V>::Vector(T x, T y) : size(2)
{
	T = new T[2];
	data[1] = y;
	data[0] = x;
}

template <typename T, typename V> Vector<T, V>::Vector(T x, T y, T z) : size(3)
{
	data = new T[3];
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

template <typename T, typename V> Vector<T, V>::Vector(Vector& vector) : size(vector.size)
{
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = vector[i];
}

template <typename T, typename V> Vector<T, V>::~Vector()
{
	if (data)
		delete[] data;
}

template <typename T, typename V> V Vector<T, V>::setSize()
{
	if (data) delete[] data;

	cout << "Enter the size of the vector (1 - 100): ";
	do {
		cin >> size;
	} while (size < 1 || size > 100);
	data = new T[size];
	return size;
}

template <typename T, typename V> V Vector<T, V>::getSize()
{
	return size;
}

template <typename T, typename V> void Vector<T, V>::setElem(V index, T d)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index" << endl;
		return;
	}
	data[index] = d;
}

template <typename T, typename V> T Vector<T, V>::getElem(V index)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index" << endl;
		return 0;
	}
	return data[index];
}

template <typename T, typename V> T Vector<T, V>::getLen()
{
	T sum = 0;
	for (int i = 0; i < getSize(); i++)
		sum += data[i] * data[i];
	return sqrt(sum);
}

template <typename T, typename V> void Vector<T, V>::inputRandomly()
{
	if (size <= 0)	return;

	for (int i = 0; i < size; i++)
		data[i] = (rand() % 2001 - 1000.0) / 10;
}

template <typename T, typename V> void Vector<T, V>::input()
{
	if (size <= 0)	return;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter vector[" << i + 1 << "] = ";
		cin >> data[i];
	}
	cout << endl;
}

template <typename T, typename V> float& Vector<T, V>::peek(V index) const
{
	if (index < 0 || index >= size)
		cout << "Invalid index" << endl;
	return data[index];
}

template <typename T, typename V> void Vector<T, V>::print()
{
	if (data == nullptr)	return;

	cout << "Vector:" << endl;
	for (int i = 0; i < size; i++)
		cout << " " << data[i] << " ";
}

template <typename T, typename V> void Vector<T, V>::clear()
{
	if (!size)	return;
	delete[] data;
	size = 0;
	data = nullptr;
}

template <typename T, typename V> void Vector<T, V>::add(Vector const& vector)
{
	if (size != vector.size)	return;

	for (int i = 0; i < size; i++)
		data[i] += vector.data[i];
}

template <typename T, typename V> void Vector<T, V>::multiply(T d)
{
	for (int i = 0; i < size; i++)
		data[i] *= d;
}

template <typename T, typename V> float& Vector<T, V>::operator[](V index) const
{
	return peek(index);
}

template <typename T, typename V> Vector<T, V> Vector<T, V>::operator+(Vector const& vector) const
{
	if (size != vector.size)	return 0;

	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp[i] = data[i] + vector[i];
	return tmp;
}

template <typename T, typename V> Vector<T, V> operator+(Vector<T, V> const& vector, T val)
{
	Vector tmp(vector.size);
	for (int i = 0; i < vector.size; i++)
		tmp[i] = vector[i] + val;
	return tmp;
}

	template <typename T, typename V> Vector<T, V> operator+(T val, Vector <T, V> const& vector)
{
	Vector tmp(vector.size);
	for (int i = 0; i < vector.size; i++)
		tmp[i] = vector[i] + val;
	return tmp;
}

	template <typename T, typename V> Vector<T, V> const& Vector<T, V>::operator=(Vector const& vector)
{
	if (data) delete[] data;

	size = vector.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = vector[i];
	return *this;
}

template <typename T, typename V> bool Vector<T, V>::operator==(Vector& vector)
{
	return getLen() == vector.getLen();
}

template <typename T, typename V> bool Vector<T, V>::operator!=(Vector& vector)
{
	return getLen() != vector.getLen();
}

template <typename T, typename V> bool operator<(T a, Vector<T, V>& vector)
{
	return a < vector.getLen();
}

template <typename T, typename V> std::ostream& operator<<(std::ostream& out, Vector<T, V> const& vector)
{
	cout << "Vector:" << endl;
	for (int i = 0; i < vector.size; i++)
		out << " " << vector[i] << " ";
	return out;
}

template <typename T, typename V> std::istream& operator>>(std::istream& in, Vector<T, V>& vector)
{
	for (int i = 0; i < vector.size; i++)
	{
		cout << "Enter vector[" << i + 1 << "] = ";
		in >> vector[i];
	}
	return in;
}