#include "stdafx.h"
#include "Profile.h"


Profile::Profile()
{
}

Profile::Profile(const Profile & profile)
{
	this->label = profile.label;
	this->firstName = profile.firstName;
	this->lastName = profile.lastName;
	this->age = profile.age;
	this->categories = profile.categories;
}

Profile::Profile(string label, string firstName, string lastName, int age)
{
	this->label = label;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}


Profile::~Profile()
{
	
}

string Profile::getLabel()
{
	return this->label;
}

string Profile::getFirstName()
{
	return this->firstName;
}

string Profile::getLastName()
{
	return this->lastName;
}

int Profile::getAge()
{
	return this->age;
}

SinglyLinkedList<Category*> Profile::getCategories()
{
	return this->categories;
}

void Profile::addCategories(SinglyLinkedList<Category*> * categories)
{
	//cout << categories->getSize() << "   szzz ok\n";
	int categoriesCount = categories->getSize();
	for (int i = 0; i < categoriesCount; i++) {
		int moviesCount = categories->get(i)->getNumberOfMovies();
		for (int j = 0; j < moviesCount; j++) {
			this->addMovieToQueue(&(categories->get(i)->movies.get(j)));
		}
	}
}

void Profile::displayMovieQueue(int option)
{
	if (option == 1) {

	}
	else if (option == 2) {

	}
	else if (option == 3) {

	}
	else if (option == 4) {

	}
	else if (option == 5) {

	}
	else if (option == 6) {

	}

	/*for (int i = 0; i < this->categories.getSize(); i++) {
		cout << "\n---------\n" << this->categories.get(i)->getName() << " " << this->categories.get(i)->getNumberOfMovies() << "\n---------\n";
		this->categories.get(i)->displayMovieQueue(option);
	}*/
}

void Profile::addMovieToQueue(Movie * movie)
{
	cout << movie->getName() << " : " << movie->getYear() << endl;
	string category = movie->getCategory();
	int categoryIndex = this->findCategory(category);
	if (categoryIndex > -1) {
		this->categories.get(categoryIndex)->addMovieToQueue(*movie);
	}
	else {
		Category * newCategory = new Category(category);
		this->categories.add(newCategory);
		this->categories.get(this->categories.getSize()-1)->addMovieToQueue(*movie);
	}
}

void Profile::editMovieInQueue(pair<int, int> pos, Movie * movie)
{
	this->removeMovieFromQueue(pos); // remove the old one
	this->addMovieToQueue(movie); // put the new one
}

void Profile::removeMovieFromQueue(pair<int, int> pos)
{
	this->categories.get(pos.first)->movies.remove(pos.second);
	if (this->categories.get(pos.first)->movies.getSize() == 0) {
		this->categories.remove(pos.first);
	}
}

pair<int, int> Profile::searchForMovieInQueue(string name, int year)
{
	for (int i = 0; i < this->categories.getSize(); i++) {
		for (int j = 0; j < this->categories.get(i)->getNumberOfMovies(); j++) {
			if (this->categories.get(i)->movies.get(j).getName() == name
				&& this->categories.get(i)->movies.get(j).getYear() == year) {

				return pair<int, int>(i,j);
			}
		}
	}
	return pair<int, int>(-1,-1);
}

int Profile::findCategory(string categoryName)
{
	int catesCount = this->categories.getSize();
	for (int i = 0; i < catesCount; i++) {
		if (categoryName == this->categories.get(i)->getName())
			return i;
	}
	return -1;
}
