#pragma once
#include <iostream>

template <typename T> class Vector
{
	T* data = nullptr;
	int size = 0;

public:
	Vector()
	{}
	Vector(int size) : size(size)
	{
		if (size <= 0)	std::cout << "Invalid vector size: " << size << std::endl;
		data = new T[size];
	}
	Vector(T x, T y) : size(2)
	{
		data = new T[2];
		data[0] = x;
		data[1] = y;
	}
	Vector(T x, T y, T z) :size(3)
	{
		data = new T[3];
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}
	Vector(Vector& vector) : size(vector.size)
	{
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = vector[i];
	}
	~Vector()
	{
		if (data)
			delete[] data;
	}

	int setSize()
	{
		if (data) delete[] data;

		std::cout << "Enter the size of the vector (1 - 100): ";
		do {
			std::cin >> size;
		} while (size < 1 || size > 100);
		data = new T[size];
		return size;
	}
	int getSize()
	{
		return size;
	}

	void setElem(int index, T d)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index" << std::endl;
			return;
		}
		data[index] = d;
	}
	T getElem(int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index" << std::endl;
			return 0;
		}
		return data[index];
	}

	T getLen()
	{
		T sum = 0;
		for (int i = 0; i < getSize(); i++)
			sum += data[i] * data[i];
		return sqrt(sum);
	}

	void inputRandomly()
	{
		if (size <= 0)	return;

		for (int i = 0; i < size; i++)
			data[i] = (rand() % 2001 - 1000.0) / 10;
	}
	void input()
	{
		if (size <= 0)	return;

		for (int i = 0; i < size; i++)
		{
			std::cout << "Enter vector[" << i + 1 << "] = ";
			std::cin >> data[i];
		}
		std::cout << std::endl;
	}

	float& peek(int index) const
	{
		if (index < 0 || index >= size)
			std::cout << "Invalid index" << std::endl;
		return data[index];
	}
	void print()
	{
		if (data == nullptr)	return;

		std::cout << "Vector:" << std::endl;
		for (int i = 0; i < size; i++)
			std::cout << " " << data[i] << " ";
	}
	void clear()
	{
		if (!size)	return;
		delete[] data;
		size = 0;
		data = nullptr;
	}

	void add(Vector const& vector)
	{
		if (size != vector.size)	return;

		for (int i = 0; i < size; i++)
			data[i] += vector.data[i];
	}
	void multiply(T d)
	{
		for (int i = 0; i < size; i++)
			data[i] *= d;
	}

	float& operator[](int index) const
	{
		return peek(index);
	}

	Vector operator+(Vector const& vector) const
	{
		if (size != vector.size)	return 0;

		Vector tmp(size);
		for (int i = 0; i < size; i++)
			tmp[i] = data[i] + vector[i];
		return tmp;
	}
	friend Vector operator+(Vector const& vector, T val)
	{
		Vector tmp(vector.size);
		for (int i = 0; i < vector.size; i++)
			tmp[i] = vector[i] + val;
		return tmp;
	}
	friend Vector operator+(T val, Vector const& vector)
	{
		Vector tmp(vector.size);
		for (int i = 0; i < vector.size; i++)
			tmp[i] = vector[i] + val;
		return tmp;
	}

	Vector const& operator=(Vector const& vector)
	{
		if (data) delete[] data;

		size = vector.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = vector[i];
		return *this;
	}
	bool operator==(Vector& vector)
	{
		return getLen() == vector.getLen();
	}
	bool operator!=(Vector& vector)
	{
		return getLen() != vector.getLen();
	}
	friend bool operator<(T val, Vector& vector)
	{
		return val < vector.getLen();
	}

	friend std::ostream& operator<<(std::ostream& out, Vector const& vector)
	{
		std::cout << "Vector:" << std::endl;
		for (int i = 0; i < vector.size; i++)
			out << " " << vector[i] << " ";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Vector& vector)
	{
		for (int i = 0; i < vector.size; i++)
		{
			std::cout << "Enter vector[" << i + 1 << "] = ";
			in >> vector[i];
		}
		return in;
	}
};