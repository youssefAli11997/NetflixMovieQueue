#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;
	Node<T> * prev;
	Node<T> * next;
};

template <class T>
class DoublyLinkedList
{

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList &list);
	DoublyLinkedList& operator=(const DoublyLinkedList& list);
	~DoublyLinkedList();
	void add(T data);
	T get(int index);
	T operator[](int index);
	void remove(int index);
	int search(T data);
	int getSize();
	void printAll();
	void printAllReversed();
	void clear();

private:
	Node<T> * first;
	Node<T> * last;
	const int NOT_FOUND = -1;
	int size;
};


// definitions

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList & list)
{
	Node<T> * current = list->first;
	while (current != nullptr) {
		this->add(current->data);
		current = current->next;
	}
}

template<class T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator=(const DoublyLinkedList & list)
{
	if (this == &list)
		return *this;

	DoublyLinkedList<T> * tempList = new DoublyLinkedList<T>();
	Node<T> * current = list.first;
	while (current != nullptr) {
		DoublyLinkedList<T> * tempList = new DoublyLinkedList<T>();
		tempList->add(current->data);
	}
	return *tempList;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

template <class T>
void DoublyLinkedList<T>::clear() {
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template <class T>
void DoublyLinkedList<T>::add(T data)
{
	if (!this->first) {
		// empty list so far
		this->first = new Node<T>;
		this->first->data = data;
		this->first->prev = nullptr;
		this->first->next = nullptr;
		this->last = this->first;
		this->size++;
	}
	else {
		// non empty list
		if (this->last == this->first) {
			// has only one element
			this->last = new Node<T>;
			this->last->data = data;
			this->last->next = nullptr;
			this->last->prev = this->first;
			this->first->next = this->last;
			this->size++;
		}
		else {
			// has more than one element
			Node<T> * node = new Node<T>();
			node->data = data;
			node->prev = this->last;
			node->next = nullptr;
			this->last->next = node;
			this->last = node;
			this->size++;
		}
	}
}

template <class T>
T DoublyLinkedList<T>::get(int index)
{
	Node<T> * current = this->first;
	for (int i = 0; i < index; i++) {
		if (!current)
			break;
		current = current->next;
	}
	return current->data;
}

template <class T>
T DoublyLinkedList<T>::operator[](int index)
{
	return get(index);
}

template <class T>
void DoublyLinkedList<T>::remove(int index)
{
	if (!this->first) {
		return;
	}
	else if(index == 0) {
		// remove the first element
		if (this->first == this->last) {
			// has only one element
			this->first = nullptr;
			this->last = nullptr;
			this->size--;
		}
		else {
			// has more than one element
			this->first = this->first->next;
			this->first->prev = nullptr;
			this->size--;
		}
	}
	else {
		//index to be removed > 0
		Node<T> * current = this->first;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		if (current->next == this->last) {
			current->next = nullptr;
			this->last = current;
			this->size--;
		}
		else {
			current->next = current->next->next;
			current->next->prev = current;
			this->size--;
		}
	}
}

template <class T>
int DoublyLinkedList<T>::search(T data)
{
	int i = 0;
	Node<T> * current = this->first;
	while (current != nullptr) {
		if (current->data == data) {
			return i;
		}
		i++;
		current = current->next;
	}
	return this->NOT_FOUND;
}

template<class T>
inline int DoublyLinkedList<T>::getSize()
{
	return this->size;
}

template <class T>
void DoublyLinkedList<T>::printAll()
{
	Node<T> * current = this->first;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
	cout << "-----------\n";
}

template <class T>
void DoublyLinkedList<T>::printAllReversed()
{
	Node<T> * current = this->last;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->prev;
	}
	cout << "-----------\n";
}