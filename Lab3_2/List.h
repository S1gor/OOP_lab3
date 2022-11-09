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
		for (int i = 0; i < pos; i++)
			current = current->next;
		return current;
	}

	int getSize()
	{
		return size;
	}

	void print()
	{
		if (head == nullptr)
			return;

		for (Element* cur = head; cur != nullptr; cur = cur->next)
			printf("%d ", cur->data);
		printf("\n");
	}

	void pushList(int pos, int data)
	{
		Element* tmp = new Element;
		tmp->data = data;

		if (pos > size || pos < 0)
			return;

		if (pos == size)
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
		else
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

	Element* popList(int pos)
	{
		if (pos < 0 || pos > size)
			return 0;




	}

	

};