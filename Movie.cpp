#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
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

bool Movie::operator==(Movie * movie)
{
	return this->name == movie->getName() && this->year == movie->getYear();
}

bool Movie::operator!=(Movie * movie)
{
	return !(this->name == movie->getName() && this->year == movie->getYear());
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

void Movie::edit(string name, int year, string category, string rating, int ranking)
{
	this->name = name;
	this->year = year;
	this->category = category;
	this->rating = rating;
	this->ranking = ranking;
}

int Movie::getYear()
{
	return this->year;
}

int Movie::getRanking()
{
	return this->ranking;
}

