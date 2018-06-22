#pragma once
#include "Movie.h"

class Category
{
public:
	Category();
	Category(string name);
	~Category();
	string getName();
	int getNumberOfMovies();
	SinglyLinkedList<Movie> getMovies();
	void displayMovieQueue(int option);
	void addMovieToQueue(Movie movie);
	void editMovieInQueue(string name, int year);
	string removeMovieFromQueue(string name, int year);
	string searchForMovieInQueue(string name, int year); // TODO: make sure of inputs
	SinglyLinkedList<Movie> movies = SinglyLinkedList<Movie>();

private:
	string name;
	int numberOfMovies;
};

