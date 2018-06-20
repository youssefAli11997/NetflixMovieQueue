#pragma once
template <class T>
class DynamicLinkedList
{
	template <class T>
	struct Node {
		T data;
		Node * pPreviousNode, pNextNode;
	};

public:
	DynamicLinkedList();
	~DynamicLinkedList();
	void add();
	T get(int index);
	T operator[](int index);
	void delete(int index);

private:
	Node<T> * first;
	Node<T> * last;
};

