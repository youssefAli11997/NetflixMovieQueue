#pragma once
#include "Movie.h"

class Category
{
public:
	Category();
	Category(string name);
	~Category();
	Category& operator++();       // Prefix increment operator.  
	Category operator++(int);     // Postfix increment operator.  
	Category& operator--();       // Prefix decrement operator.  
	Category operator--(int);     // Postfix decrement operator.  
	string getName();
	int getNumberOfMovies();
	SinglyLinkedList<Movie> getMovies();
	SinglyLinkedList<Movie> movies = SinglyLinkedList<Movie>();

private:
	string name;
	int numberOfMovies = 0;
};

