#include "stdafx.h"
#include "Category.h"


Category::Category()
{
}

Category::Category(const Category & category)
{
	//cout << "copy categsssssssss\n";
	this->name = category.name;
	this->numberOfMovies = category.numberOfMovies;
	//this->movies = category.movies;
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
	//cout << newMovie.getName() << " " << newMovie.getCategory() << endl;
	//cout << "nm : " << this->name << endl;
	//cout << "movs sz: " << this->movies.getSize() << endl;
	//this->movies.add(Movie(movie.getName(), movie.getYear(), movie.getCategory(), movie.getRating(), movie.getRanking()));
	this->movies.add(movie);
	this->numberOfMovies++;
	//cout << this->movies.get(0).getName() << " ok" << endl;
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
