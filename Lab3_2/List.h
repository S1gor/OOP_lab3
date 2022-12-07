#pragma once

template <typename T> class List
{
private:
	struct Element
	{
		T data;
		Element* next = nullptr;
		Element* prev = nullptr;
	};

	Element* head, * tail;
	int size;

public:
	List() : head(nullptr), tail(nullptr), size(NULL) {}
	~List()
	{
		DelList();
	}

	int GetSize()
	{
		return size;
	}

	T GetElement(int pos)
	{
		if (pos < 1 || pos > size)
			return 0;

		Element* tmp = head;
		for (int i = 1; i < pos; i++)
			tmp = tmp->next;

		return tmp->data;
	}

	friend std::ostream& operator<<(std::ostream& out, List const& list)
	{
		if (list.head == nullptr)
			return out;

		out << "List:";
		for (Element* cur = list.head; cur != nullptr; cur = cur->next)
			out << " " << cur->data;
		out << std::endl;
		return out;
	}

	void PrintElem(int pos)
	{
		if (pos < 1 || pos > size)
			return;

		Element* tmp;
		if (pos <= size / 2)
		{
			tmp = head;
			for (int i = 1; i < pos; i++)
				tmp = tmp->next;
		}
		else
		{
			tmp = tail;
			for (int i = 1; i <= size - pos; i++)
				tmp = tmp->prev;
		}
		std::cout << "Position " << pos << " - " << tmp->data << std::endl;
	}

	void PushHead(T data)
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

	void PushTail(T data)
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

	void PushPos(T data, int pos)
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
		for (int i = 1; i < pos; i++)
			current = current->next;

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
		for (int i = 1; i < pos; i++)
			tmp = tmp->next;

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