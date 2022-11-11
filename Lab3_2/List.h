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
	int getSize()
	{
		return size;
	}

	int getElement(int pos)
	{
		if (pos < 1 || pos > size)
			return 0;

		Element* tmp = head;
		int i = 1;
		while (i < pos)
		{
			tmp = tmp->next;
			i++;
		}
		int d = tmp->data;
		return d;
	}

	void print()
	{
		if (head == nullptr)
			return;

		for (Element* cur = head; cur != nullptr; cur = cur->next)
			printf("%d ", cur->data);
		printf("\n");
	}

	void pushHead(int data)
	{
		Element* tmp = new Element;
		tmp->prev = nullptr;
		tmp->next = head;
		tmp->data = data;

		if (head == nullptr)
			head = tail = tmp;
		else
		{
			head->prev = tmp;
			head = tmp;
		}
		size++;
	}

	void pushTail(int data)
	{
		Element* tmp = new Element;
		tmp->next = nullptr;
		tmp->prev = tail;
		tmp->data = data;

		if (head == nullptr)
			head = tail = tmp;
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;
	}

	void pushPos(int data, int pos)
	{
		if (pos > size + 1 || pos < 1)
			return;
		else if (pos == size + 1)
		{
			pushTail(data);
			return;
		}
		else if (pos == 1)
		{
			pushHead(data);
			return;
		}

		Element* current = head;
		int i = 1;
		while (i < pos)
		{
			current = current->next;
			i++;
		}

		Element* prv = current->prev;
		Element* tmp = new Element;
		tmp->data = data;

		if (prv != 0 && size != 1)
			prv->next = tmp;

		tmp->next = current;
		tmp->prev = prv;
		current->prev = tmp;

		size++;
	}

	void pull(int pos)
	{
		if (pos < 1 || pos > size)
			return;
	}

};