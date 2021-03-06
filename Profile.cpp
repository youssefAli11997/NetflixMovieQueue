#include "stdafx.h"
#include "Profile.h"


Profile::Profile()
{
}

Profile::Profile(const Profile & profile)
{
	cout << "in copy!!\n";
	SinglyLinkedList<Category *> catgs = profile.categories;
	this->addCategories(&catgs);
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
	this->categories.clear();
}

void Profile::edit(string lbl, string fname, string lname, int ag)
{
	label = lbl;
	firstName = fname;
	lastName = lname;
	age = ag;
}

void Profile::operator<<(string category)
{
	cout << "The movies in your Queue with Category " << category << " are displayed below.";
	// fetch all movies
	SinglyLinkedList<Movie> allMovies = SinglyLinkedList<Movie>();
	for (int i = 0; i < this->categories.getSize(); i++) {
		for (int j = 0; j < this->categories.get(i)->movies.getSize(); j++) {
			if (this->categories.get(i)->movies.get(j).getCategory() != category)
				continue;
			Movie tempMovie = this->categories.get(i)->movies.get(j);
			allMovies.add(Movie(tempMovie.getName(), tempMovie.getYear(), tempMovie.getCategory(), tempMovie.getRating(), tempMovie.getRanking()));
		}
	}

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

		// sort all movies by ranking from highest to lowest (insertion sort)
		for (int i = 1; i < allMovies.getSize(); i++) {
			Movie movie = allMovies[i];
			int j = i - 1;
			while (j >= 0 && allMovies[j].getRanking() < movie.getRanking()) {
				Movie tempMovie = allMovies[j];
				allMovies.remove(j + 1);
				allMovies.insert(tempMovie, j + 1);
				j--;
			}
			allMovies.remove(j + 1);
			allMovies.insert(movie, j + 1);
		}

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
		// fetch all movies
		SinglyLinkedList<Movie> allMovies = SinglyLinkedList<Movie>();
		for (int i = 0; i < this->categories.getSize(); i++) {
			for (int j = 0; j < this->categories.get(i)->movies.getSize(); j++) {
				Movie tempMovie = this->categories.get(i)->movies.get(j);
				allMovies.add(Movie(tempMovie.getName(), tempMovie.getYear(), tempMovie.getCategory(), tempMovie.getRating(), tempMovie.getRanking()));
			}
		}

		// sort all movies by ranking from lowest to highest (insertion sort)
		for (int i = 1; i < allMovies.getSize(); i++) {
			Movie movie = allMovies[i];
			int j = i - 1;
			while (j >= 0 && allMovies[j].getRanking() > movie.getRanking()) {
				Movie tempMovie = allMovies[j];
				allMovies.remove(j + 1);
				allMovies.insert(tempMovie, j + 1);
				j--;
			}
			allMovies.remove(j + 1);
			allMovies.insert(movie, j + 1);
		}

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
	else if (option == 5) {
		// fetch all movies
		SinglyLinkedList<Movie> allMovies = SinglyLinkedList<Movie>();
		for (int i = 0; i < this->categories.getSize(); i++) {
			for (int j = 0; j < this->categories.get(i)->movies.getSize(); j++) {
				Movie tempMovie = this->categories.get(i)->movies.get(j);
				allMovies.add(Movie(tempMovie.getName(), tempMovie.getYear(), tempMovie.getCategory(), tempMovie.getRating(), tempMovie.getRanking()));
			}
		}

		// sort all movies in alphabetical order (insertion sort)
		for (int i = 1; i < allMovies.getSize(); i++) {
			Movie movie = allMovies[i];
			int j = i - 1;
			while (j >= 0 && allMovies[j].getName() > movie.getName()) {
				Movie tempMovie = allMovies[j];
				allMovies.remove(j + 1);
				allMovies.insert(tempMovie, j + 1);
				j--;
			}
			allMovies.remove(j + 1);
			allMovies.insert(movie, j + 1);
		}

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
}

void Profile::displayMovieQueue(int option, string value)
{
	if(option == 3)
		cout << "The movies in your Queue with Rating "<< value <<" are displayed below.";
	if(option == 4)
		cout << "The movies in your Queue with Category " << value << " are displayed below.";
	// fetch all movies
	SinglyLinkedList<Movie> allMovies = SinglyLinkedList<Movie>();
	for (int i = 0; i < this->categories.getSize(); i++) {
		for (int j = 0; j < this->categories.get(i)->movies.getSize(); j++) {
			if (option == 3 && this->categories.get(i)->movies.get(j).getRating() != value)
				continue;
			if (option == 4 && this->categories.get(i)->movies.get(j).getCategory() != value)
				continue;
			Movie tempMovie = this->categories.get(i)->movies.get(j);
			allMovies.add(Movie(tempMovie.getName(), tempMovie.getYear(), tempMovie.getCategory(), tempMovie.getRating(), tempMovie.getRanking()));
		}
	}

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

void Profile::addMovieToQueue(Movie * movie)
{
	string category = movie->getCategory();
	int categoryIndex = this->findCategory(category);
	if (categoryIndex > -1) {
		++*this->categories.get(categoryIndex);
		this->categories.get(categoryIndex)->movies.add(*movie);
	}
	else {
		Category * newCategory = new Category(category);
		++*newCategory;
		this->categories.add(newCategory);
		this->categories.get(this->categories.getSize() - 1)->movies.add(*movie);
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
	(*this->categories.get(pos.first))--;
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
