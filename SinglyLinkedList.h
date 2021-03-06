#pragma once
#include <iostream>

using namespace std;

template <class T>
struct SingleNode {
	T data;
	Node<T> * next;
};

template <class T>
class SinglyLinkedList
{

public:
	SinglyLinkedList();
	//SinglyLinkedList(const SinglyLinkedList &list);
	SinglyLinkedList& operator=(const SinglyLinkedList<T>& list);
	~SinglyLinkedList();
	void add(T data);
	T get(int index);
	T operator[](int index);
	void remove(int index);
	void insert(T data, int index);
	int search(T data);
	int getSize();
	void printAll();
	void clear();

private:
	Node<T> * first;
	Node<T> * last;
	const int NOT_FOUND = -1;
	int size;
};


// definitions

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

/*template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> & list)
{
	cout << "copying\n";
	cout << list.getSize() << endl;
	Node<T> * current = list.first;
	while (current != nullptr) {
		this->add(current->data);
		current = current->next;
	}
	cout << "End copying!\n";
}*/

template<class T>
SinglyLinkedList<T> & SinglyLinkedList<T>::operator=(const SinglyLinkedList & list)
{
	if (this == &list)
		return *this;

	SinglyLinkedList<T> * tempList = new SinglyLinkedList<T>();
	Node<T> * current = list.first;
	while (current != nullptr) {
		SinglyLinkedList<T> * tempList = new SinglyLinkedList<T>();
		tempList->add(current->data);
	}
	return *tempList;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

template <class T>
void SinglyLinkedList<T>::clear() {
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template <class T>
void SinglyLinkedList<T>::add(T data)
{
	if (!this->first) {
		// empty list so far
		this->first = new Node<T>;
		this->first->data = data;
		this->first->next = nullptr;
		this->last = this->first;
		this->size++;
	}
	else {
		if (this->last == this->first) {
			// has only one element
			this->last = new Node<T>;
			this->last->data = data;
			this->last->next = nullptr;
			this->first->next = this->last;
			this->size++;
		}
		else {
			// has more than one element
			Node<T> * node = new Node<T>();
			node->data = data;
			node->next = nullptr;
			this->last->next = node;
			this->last = node;
			this->size++;
		}
	}
}

template<class T>
inline void SinglyLinkedList<T>::insert(T data, int index)
{
	if (index > this->size || index < 0) {
		return;
	}
	else if (index == this->size) {
		this->add(data);
	}
	else if (index < this->size) {
		if (index == 0) {
			// insert at first
			Node<T> * node = new Node<T>();
			node->data = data;
			node->next = this->first;
			this->first = node;
			this->size++;
		}
		else {
			Node<T> * current = this->first;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node<T> * node = new Node<T>();
			node->data = data;
			node->next = current->next;
			current->next = node;
			this->size++;
		}
	}
}

template <class T>
T SinglyLinkedList<T>::get(int index)
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
T SinglyLinkedList<T>::operator[](int index)
{
	return get(index);
}

template <class T>
void SinglyLinkedList<T>::remove(int index)
{
	if (!this->first) {
		return;
	}
	else if (index == 0) {
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
			this->size--;
		}
	}
}

template <class T>
int SinglyLinkedList<T>::search(T data)
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
inline int SinglyLinkedList<T>::getSize()
{
	return this->size;
}

template <class T>
void SinglyLinkedList<T>::printAll()
{
	Node<T> * current = this->first;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
	cout << "-----------\n";
}