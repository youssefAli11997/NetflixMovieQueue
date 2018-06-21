#include "stdafx.h"
#include "Category.h"


Category::Category()
{
}

Category::Category(string name)
{
	this->name = name;
	this->numberOfMovies = 0;
	this->movies.clear();
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

}

void Category::addMovieToQueue(Movie movie)
{
}

void Category::editMovieInQueue()
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
