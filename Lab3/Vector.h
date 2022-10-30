#pragma once
#include <iostream>

template <typename T, typename V> class Vector
{
	T* data = nullptr;
	V size = 0;

public:
	Vector();
	Vector(V size);
	Vector(T x, T y);
	Vector(T x, T y, T z);
	Vector(Vector& vector);
	~Vector();

	V setSize();
	V getSize();

	void setElem(V index, T d);
	T getElem(V index);

	T getLen();

	void inputRandomly();
	void input();

	float& peek(V index) const;
	void print();
	void clear();

	void add(Vector const& vector);
	void multiply(T d);

	float& operator[](V index) const;

	Vector operator+(Vector const& vector) const;
	friend Vector operator+(Vector const& vector, T val);
	friend Vector operator+(T val, Vector const& vector);

	Vector const& operator=(Vector const& vector);
	bool operator==(Vector& vector);
	bool operator!=(Vector& vector);
	friend bool operator<(T value, Vector& vector);

	friend std::ostream& operator<<(std::ostream& out, Vector const& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector);
};