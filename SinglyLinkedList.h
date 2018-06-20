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
	~SinglyLinkedList();
	void add(T data);
	T get(int index);
	T operator[](int index);
	void remove(int index);
	int search(T data);
	void printAll();

private:
	Node<T> * first;
	Node<T> * last;
	const int NOT_FOUND = -1;
};


// definitions

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
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
	}
	else {
		if (this->last == this->first) {
			// has only one element
			this->last = new Node<T>;
			this->last->data = data;
			this->last->next = nullptr;
			this->first->next = this->last;
		}
		else {
			// has more than one element
			Node<T> * node = new Node<T>();
			node->data = data;
			node->next = nullptr;
			this->last->next = node;
			this->last = node;
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
		}
		else {
			// has more than one element
			this->first = this->first->next;
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
		}
		else {
			current->next = current->next->next;
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