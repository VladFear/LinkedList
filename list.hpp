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
	void push_back(T data);
	size_t size() const;
	bool empty() const;
	T& at(size_t pos) const;
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
