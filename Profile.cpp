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

DoublyLinkedList<Category> Profile::getCategories()
{
	return this->categories;
}

void Profile::addCategories(DoublyLinkedList<Category> categories)
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
	cout << this->categories.getSize() << endl;
	for (int i = 0; i < this->categories.getSize(); i++) {
		cout << this->categories.get(i).getName() << " " << this->categories.get(i).getNumberOfMovies() << "\n---------\n";
		for (int j = 0; j < this->categories.get(i).getNumberOfMovies(); j++) {
			cout << this->categories.get(i).getMovies().get(i).getName() << endl;
		}
		cout << "************************\n";
	}
}

void Profile::addMovieToQueue(Movie movie)
{
	Movie newMovie(movie.getName(), movie.getYear(), movie.getCategory(), movie.getRating(), movie.getRanking());
	cout << newMovie.getName() << " : " << newMovie.getYear() << endl;
	string category = movie.getCategory();
	int categoryIndex = this->findCategory(category);
	cout << "index: " << categoryIndex << endl;
	if (categoryIndex > -1) {
		cout << "here!!!!\n";
		this->categories.get(categoryIndex).addMovieToQueue(newMovie);
	}
	else {
		Category newCategory = Category(category);
		//cout << "ok " << newCategory.getMovies().get(0).getName() << endl;
		cout << "ok\n";
		cout << "cat sz: " << this->categories.getSize() << endl;
		this->categories.add(newCategory);
		cout << "add ok\n";
		cout << "size: " << this->categories.getSize() << endl;
		cout << this->categories.get(this->categories.getSize() - 1).getName() << endl;
		//cout << this->categories.get(this->categories.getSize() - 1).getMovies().getSize() << endl;
		//this->categories.get(this->categories.getSize() - 1).getMovies().add(Movie(movie.getName(), movie.getYear(), movie.getCategory(), movie.getRating(), movie.getRanking()));

		this->categories.get(this->categories.getSize()-1).addMovieToQueue(newMovie);
		cout << this->categories.get(0).getName() << " ok2" << endl;
	}
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

int Profile::findCategory(string categoryName)
{
	int catesCount = this->categories.getSize();
	for (int i = 0; i < catesCount; i++) {
		if (categoryName == this->categories.get(i).getName())
			return i;
	}
	return -1;
}
