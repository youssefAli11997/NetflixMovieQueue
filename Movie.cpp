#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
}

Movie::Movie(const Movie & movie)
{
	this->name = movie.name;
	this->year = movie.year;
	//cout << "yr: " << &(movie).year << " " << movie.year << endl;
	this->category = movie.category;
	this->rating = movie.rating;
	this->ranking = movie.ranking;
}

Movie::Movie(string name, int year, string category, string rating, int ranking) {
	this->name = name;
	this->year = year;
	this->category = category;
	this->rating = rating;
	this->ranking = ranking;
}

Movie::~Movie()
{
}

string Movie::getName()
{
	return this->name;
}

string Movie::getRating()
{
	return this->rating;
}

string Movie::getCategory()
{
	return this->category;
}

int Movie::getYear()
{
	return this->year;
}

int Movie::getRanking()
{
	return this->ranking;
}

