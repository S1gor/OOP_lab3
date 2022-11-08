#pragma once

template <typename T> class List
{
private:
	struct Element
	{
		int data;
		Element* next = nullptr;
		Element* prev = nullptr;
	};

	Element* head = nullptr;
	Element* tail = nullptr;
	int size;

public:

	Element* findElement(int pos)
	{
		Element* current = head;
		for (int i = 1; i <= pos; i++)
			current = current->next;
		return current;
	}

	void pushList(int pos, int data)
	{
		Element* tmp = new Element;
		tmp->data = data;

		if (pos >= size)
		{
			tail = tmp;
			tmp->next = nullptr;
		}
		else
		{
			tmp->next = findElement(pos);
			tmp->next->prev = tmp;
		}

		if (pos == 0)
		{
			tmp->prev = nullptr;
			head = tmp;
		}
		else if (size != 0)
		{
			tmp->prev = findElement(pos - 1);
			tmp->prev->next = tmp;
		}
		size++;
	}

	void pushList(int data)
	{
		pushList(size, data);
	}

	void print()
	{
		if (head == nullptr)
			return;

		for (Element* cur = head; cur != nullptr; cur = cur->next)
			printf("%d ", cur->data);
	}

};