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
		// fetch all movies
		SinglyLinkedList<Movie> allMovies = SinglyLinkedList<Movie>();
		for (int i = 0; i < this->categories.getSize(); i++) {
			for (int j = 0; j < this->categories.get(i)->movies.getSize(); j++) {
				Movie tempMovie = this->categories.get(i)->movies.get(j);
				allMovies.add(Movie(tempMovie.getName(), tempMovie.getYear(), tempMovie.getCategory(), tempMovie.getRating(), tempMovie.getRanking()));
			}
		}

		cout << "sz: " << allMovies.getSize();

		// sort all movies by ranking from highest to lowest (insertion sort)
		for (int i = 1; i < allMovies.getSize(); i++) {
			Movie movie = allMovies[i];
			int j = i - 1;
			cout << "\n ranks: " << allMovies[j].getRanking() << " " << movie.getRanking() << endl;
			while (j >= 0 && allMovies[j].getRanking() < movie.getRanking()) {
				Movie tempMovie = allMovies[j];
				cout << tempMovie.getName() << " " << tempMovie.getYear() << endl;
				cout << allMovies[j + 1].getName() << " " << allMovies[j + 1].getYear() << endl;
				//allMovies[j + 1].edit(&tempMovie.getName(), &tempMovie.getYear(), &tempMovie.getCategory(), &tempMovie.getRating(), &tempMovie.getRanking());
				//allMovies[j + 1] = Movie(tempMovie);
				allMovies.remove(j + 1);
				allMovies.insert(tempMovie, j + 1);
				cout << allMovies[j + 1].getName() << " " << allMovies[j + 1].getYear() << endl;
				j--;
			}
			cout << allMovies[0].getName() << " " << allMovies[0].getYear() << endl;
			allMovies.remove(j + 1);
			allMovies.insert(movie, j + 1);
			//allMovies[j + 1] = Movie(movie);
			//allMovies[j + 1].edit(movie.getName(), movie.getYear(), movie.getCategory(), movie.getRating(), movie.getRanking());
		}

		cout << "sz: " << allMovies.getSize()<<endl;

		// display all movies
		for (int i = 0; i < allMovies.getSize(); i++) {
			Movie movie = allMovies[i];
			cout << "\n----------------------------\n";
			cout << movie.getName() << endl;
			cout << "Year : " << movie.getYear() << endl;
			cout << "Category : " << movie.getCategory() << endl;
			cout << "Rated : " << movie.getRating() << endl;
			cout << "Ranked : ";
			for (int k = 0; k < movie.getRanking(); k++) {
				cout << "*";
			}cout << endl;
		}
		cout << "----------------------------\n";
	}
	else if (option == 2) {

	}
	else if (option == 3) {

	}
	else if (option == 4) {

	}
	else if (option == 5) {

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
