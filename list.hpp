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

public:
	LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList()
{
}
