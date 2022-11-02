#pragma once

class List
{
private:
	int data;
	List* next = nullptr;
	List* prev = nullptr;

public:
	List();
	~List();

	void pushList(List& l, int data);

};