#include <iostream>

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
	size_t size() const;
	bool empty() const;
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
