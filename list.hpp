#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
	template <typename A>
	class Node
	{
		public:
			Node<T>* next;
			T data;
	};

	size_t list_size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

public:
	LinkedList();
	~LinkedList();
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	size_t size() const;
	bool empty() const;
	T& at(size_t pos) const;
	LinkedList& operator = (const LinkedList& other);
	void operator()(size_t pos);
};

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
size_t LinkedList<T>::size() const
{
	return list_size;
}

template <typename T>
bool LinkedList<T>::empty() const
{
	return list_size == 0 ? true : false;
}

template <typename T>
void LinkedList<T>::push_back(T data)
{
	Node<T>* new_node = new Node<T>();
	head->next = new_node;
	new_node->data = data;
	head = new_node;

	if (list_size == 0)
		tail = new_node;

	list_size++;
}

template <typename T>
T& LinkedList<T>::at(size_t pos) const
{
	if (list_size > pos)
	{
		Node<T>* tmp = tail;
		for (size_t i = 0; i < pos; i++)
			tmp = tmp->next;
		return tmp->data;
	}

	throw std::out_of_range("Out of range");
}

template <typename T>
void LinkedList<T>::pop_back()
{
	if (list_size == 0)
		return;
	else if (list_size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T>* tmp = tail;
		while (tmp->next != head)
			tmp = tmp->next;

		tmp->next = nullptr;
		delete head;
		head = tmp;
	}
	list_size--;
}

template <typename T>
void LinkedList<T>::push_front(T data)
{
	Node<T>* new_node = new Node<T>();
	new_node->next = tail;
	new_node->data = data;
	tail = new_node;

	if (list_size == 0)
		head = new_node;

	list_size++;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while (list_size)
		pop_back();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& other)
{
	  if (this != &other)
		{
			Node<T>* tmp = head;

			while (tmp->next)
			{
				head = head -> next;
				delete tmp;
				tmp = head;
      }

			tmp = other->head;

			while (tmp) 
			{
					push_back(tmp);
					tmp = tmp->next;
			}
		}
		return *this;
}

template <typename T>
void LinkedList<T>::operator()(size_t pos)
{
	if (pos < 0 || pos >= list_size)
		return;

	Node<T>* tmp = tail;
	for (size_t i = 0; i < pos; i++)
		tmp = tmp->next;

	tmp->next = tmp->next->next;
	tmp->data = tmp->next->data;
	tmp = tmp->next;
	delete tmp;
}
