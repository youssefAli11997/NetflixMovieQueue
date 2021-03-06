#pragma once
#include "Category.h"
#include "Movie.h"

using namespace std;

class Profile
{
public:
	Profile();
	Profile(const Profile &profile); // copy constructor
	Profile(string label, string firstName, string lastName, int age);
	~Profile();
	void edit(string lbl, string fname, string lname, int ag);
	void operator<<(string category);
	string getLabel();
	string getFirstName();
	string getLastName();
	int getAge();
	SinglyLinkedList<Category*> getCategories();
	void addCategories(SinglyLinkedList<Category*> * categories);
	void displayMovieQueue(int option);
	void displayMovieQueue(int option, string value);
	void addMovieToQueue(Movie* movie);
	void editMovieInQueue(pair<int, int> pos, Movie * movie);
	void removeMovieFromQueue(pair<int,int> pos);
	pair<int, int> searchForMovieInQueue(string name, int year);
	SinglyLinkedList<Category *> categories;


private:
	string label;
	string firstName;
	string lastName;
	int age;
	int findCategory(string categoryName);
};

