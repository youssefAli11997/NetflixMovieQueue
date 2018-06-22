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
	//cout << this->movies.getSize() << " constructor ok" << endl;
}

Category::~Category()
{
	this->movies.clear();
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

void Category::displayMovieQueue(int option)
{
	for (int j = 0; j < this->getNumberOfMovies(); j++) {
		cout << this->movies.get(j).getName() << endl;
	}
	cout << "************************\n";
}

void Category::addMovieToQueue(Movie movie)
{
	this->movies.add(movie);
	this->numberOfMovies++;
}

void Category::editMovieInQueue(string name, int year)
{
}

string Category::removeMovieFromQueue(string name, int year)
{
	return string();
}

string Category::searchForMovieInQueue(string name, int year)
{
	return string();
}
