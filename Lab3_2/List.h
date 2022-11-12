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
	int GetSize()
	{
		return size;
	}

	int GetElement(int pos)
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

	void PrintList()
	{
		if (head == nullptr)
			return;

		std::cout << "List:" << std::endl;
		for (Element* cur = head; cur != nullptr; cur = cur->next)
			printf("%d ", cur->data);
		printf("\n");
	}

	void PrintElem(int pos)
	{
		if (pos < 1 || pos > size)
			return;

		Element* tmp;
		if (pos <= size / 2)
		{
			tmp = head;
			int i = 1;	
			while (i < pos)
			{
				tmp = tmp->next;
				i++;
			}
		}
		else
		{
			tmp = tail;
			int i = 1;
			while (i <= size - pos)
			{
				tmp = tmp->prev;
				i++;
			}
		}
		std::cout << "Position " << pos << " - " << tmp->data << std::endl;
	}

	void PushHead(int data)
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

	void PushTail(int data)
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

	void PushPos(int data, int pos)
	{
		if (pos > size + 1 || pos < 1)
			return;
		else if (pos == size + 1)
		{
			PushTail(data);
			return;
		}
		else if (pos == 1)
		{
			PushHead(data);
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

	void DelElem(int pos)
	{
		if (pos < 1 || pos > size)
			return;

		Element* tmp = head;
		int i = 1;
		while (i < pos)
		{
			tmp = tmp->next;
			i++;
		}

		Element* tmp_prev = tmp->prev;
		Element* tmp_next = tmp->next;

		if (tmp_prev != NULL && size != 1)
			tmp_prev->next = tmp_next;
		if (tmp_next != NULL && size != 1)
			tmp_next->prev = tmp_prev;

		if (pos == 1)
			head = tmp_next;
		if (pos == size)
			tail = tmp_prev;

		delete tmp;
		size--;
	}

	void DelList()
	{
		while (size != NULL)
			DelElem(1);
	}

};