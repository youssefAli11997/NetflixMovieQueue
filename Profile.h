#pragma once
#include "Category.h"
#include "Movie.h"

using namespace std;

class Profile
{
public:
	Profile();
	Profile(const Profile &profile); // copy constructor
	//Profile& operator=(const Profile& profile);
	Profile(string label, string firstName, string lastName, int age);
	~Profile();
	string getLabel();
	string getFirstName();
	string getLastName();
	int getAge();
	SinglyLinkedList<Category*> getCategories();
	void addCategories(SinglyLinkedList<Category*> categories);
	void displayMovieQueue(int option);
	void addMovieToQueue(Movie* movie);
	void editMovieInQueue(string name, int year); // TODO: determine inputs
	string removeMovieFromQueue(string name, int year);
	string searchForMovieInQueue(string name, int year); // TODO: make sure of inputs



private:
	string label;
	string firstName;
	string lastName;
	int age;
	SinglyLinkedList<Category *> categories;
	int findCategory(string categoryName);
};

