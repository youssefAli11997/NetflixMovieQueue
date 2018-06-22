#include "stdafx.h"
#include "Category.h"


Category::Category()
{
}

Category::Category(string name)
{
	this->name = name;
	this->numberOfMovies = 0;
	//this->movies = DoublyLinkedList<Movie*>();
}

Category::~Category()
{
	this->movies.clear();
}

Category& Category::operator++()
{
	this->numberOfMovies++;
	return *this;
}

Category Category::operator++(int)
{
	Category temp = *this;
	++*this;
	return temp;
}

Category& Category::operator--()
{
	this->numberOfMovies--;
	return *this;
}

Category Category::operator--(int)
{
	Category temp = *this;
	--*this;
	return temp;
}

string Category::getName()
{
	return this->name;
}

int Category::getNumberOfMovies()
{
	return this->numberOfMovies;
}

SinglyLinkedList<Movie> Category::getMovies()
{
	return this->movies;
}