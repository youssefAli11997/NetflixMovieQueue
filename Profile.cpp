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

/*Profile & Profile::operator=(const Profile & profile)
{
	if (this == &profile) // self assignment
		return *this;

	Profile tempProfile(profile.label, profile.firstName, profile.lastName, profile.age);
	tempProfile->label = profile.label;
	tempProfile->firstName = profile.firstName;
	tempProfile->lastName = profile.lastName;
	tempProfile->age = profile.age;
	tempProfile->categories = profile.categories;

	cout << "assigning!\n";
	cout << tempProfile.label << " " << tempProfile.firstName << " " << tempProfile.lastName << " " << tempProfile.age << endl;

	return tempProfile;
}*/

Profile::Profile(string label, string firstName, string lastName, int age)
{
	this->label = label;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}


Profile::~Profile()
{
	this->categories.clear();
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

SinglyLinkedList<Category> Profile::getCategories()
{
	return this->categories;
}

void Profile::addCategories(SinglyLinkedList<Category> categories)
{
	int categoriesCount = categories.getSize();
	for (int i = 0; i < categoriesCount; i++) {
		int moviesCount = categories.get(i).getNumberOfMovies();
		for (int j = 0; j < moviesCount; j++) {
			this->addMovieToQueue(categories.get(i).getMovies().get(j));
		}
	}
}

void Profile::displayMovieQueue(int option)
{

}

void Profile::addMovieToQueue(Movie movie)
{
}

void Profile::editMovieInQueue(string name, int year)
{
}

string Profile::removeMovieFromQueue(string name, int year)
{
	return string();
}

string Profile::searchForMovieInQueue(string name, int year)
{
	return string();
}
