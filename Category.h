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
	void displayMovieQueue(int option);
	void addMovieToQueue(Movie movie);
	void editMovieInQueue(); // TODO: determine inputs
	string removeMovieFromQueue(string name, int year);
	string searchForMovieInQueue(string name, int year); // TODO: make sure of inputs

private:
	string name;
	int numberOfMovies;
	SinglyLinkedList<Movie> movies;
};

