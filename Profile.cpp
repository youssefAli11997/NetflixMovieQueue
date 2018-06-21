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

SinglyLinkedList<Category*> Profile::getCategories()
{
	return this->categories;
}

void Profile::addCategories(SinglyLinkedList<Category*> categories)
{
	int categoriesCount = categories.getSize();
	for (int i = 0; i < categoriesCount; i++) {
		int moviesCount = categories.get(i)->getNumberOfMovies();
		for (int j = 0; j < moviesCount; j++) {
			this->addMovieToQueue(&(categories.get(i)->getMovies().get(j)));
		}
	}
}

void Profile::displayMovieQueue(int option)
{
	cout << "siz shit: " << this->categories.getSize() << endl;
	for (int i = 0; i < this->categories.getSize(); i++) {
		cout << "\n---------\n" << this->categories.get(i)->getName() << " " << this->categories.get(i)->getNumberOfMovies() << "\n---------\n";
		//cout << "movssssssssss " << this->categories.get(i)->movies.getSize() << endl;
		this->categories.get(i)->displayMovieQueue(option);
		/*for (int j = 0; j < this->categories.get(i)->getNumberOfMovies(); j++) {
			cout << this->categories.get(i)->getMovies().get(j)->getName() << endl;
		}
		cout << "************************\n";*/
	}
}

void Profile::addMovieToQueue(Movie * movie)
{
	//Movie newMovie(movie.getName(), movie.getYear(), movie.getCategory(), movie.getRating(), movie.getRanking());
	cout << movie->getName() << " : " << movie->getYear() << endl;
	string category = movie->getCategory();
	int categoryIndex = this->findCategory(category);
	cout << "index: " << categoryIndex << endl;
	if (categoryIndex > -1) {
		cout << "here!!!!\n";
		this->categories.get(categoryIndex)->addMovieToQueue(*movie);
	}
	else {
		Category * newCategory = new Category(category);
		//cout << "ok " << newCategory.getMovies().get(0).getName() << endl;
		//cout << "ok\n";
		//cout << "cat sz: " << this->categories.getSize() << endl;
		this->categories.add(newCategory);
		//cout << "add ok\n";
		//cout << "size: " << this->categories.getSize() << endl;
		//cout << this->categories.get(this->categories.getSize() - 1)->getName() << endl;
		//this->categories.get(this->categories.getSize() - 1)->movies = DoublyLinkedList<Movie>();
		//cout << this->categories.get(this->categories.getSize() - 1)->movies.getSize() << endl;
		//this->categories.get(this->categories.getSize() - 1)->getMovies().add(*movie);

		this->categories.get(this->categories.getSize()-1)->addMovieToQueue(*movie);
		//cout << this->categories.get(0)->getName() << " ok2" << endl;
		//cout << "begin: \n";
		//this->displayMovieQueue(1);
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
		if (categoryName == this->categories.get(i)->getName())
			return i;
	}
	return -1;
}
