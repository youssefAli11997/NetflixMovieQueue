#include "stdafx.h"
#include "ProgramManager.h"

using namespace std;

ProgramManager::ProgramManager()
{
	this->isMainMenu = true;
	this->isProfileMenu = false;
	this->isDisplayOptionsMenu = false;
	this->exit = false;
	this->numberOfProfiles = 0;
}


ProgramManager::~ProgramManager()
{
	this->profiles.clear();
}

void ProgramManager::start()
{
	while (true) {
		if (exit) {
			break;
		}
		else if (isMainMenu) {
			mainMenu();
		}
		else if (isProfileMenu) {
			profileMenu();
		}
		else if (isDisplayOptionsMenu) {
			displayOptionsMenu();
		}
	}
}

void ProgramManager::mainMenu()
{
	cout << "Welcome to the Netflix Movie Menu! Please select (or create) a profile:\n\n";
	for (int i = 0; i < this->numberOfProfiles; i++) {
		string profileLabel = this->profiles.get(i)->getLabel();
		cout << i + 1 << ". " << profileLabel << endl;
	}
	cout << this->numberOfProfiles+1 << ". Add New Profile\n" << this->numberOfProfiles+2 << ". Exit Program\n";
	int option;
	cout << "Enter option: ";

	// integer input validation
	string s;
	getline(cin, s);
	while (s.size() > 0 && !(s[0] >= '1' && s[0] <= this->numberOfProfiles + 2 + '0')) {
		cout << "Enter option: ";
		getline(cin, s);
	}
	istringstream iss(s);
	iss >> option;
	// end of integer input validation

	if (option < 1 || option > this->numberOfProfiles + 2) {
		return;
	}

	if (option <= this->numberOfProfiles) {
		// go to profile
		this->currentProfileIndex = option-1;
		this->isMainMenu = false;
		this->isProfileMenu = true;
		cout << "\n" << this->profiles.get(this->currentProfileIndex)->getLabel() << " Movie Queue\n\n";
	}
	else if (option == this->numberOfProfiles + 1) {
		string label;
		string fname;
		string lname;
		int age;

		cout << "Enter Profile Label : "; getline(cin,label);
		cout << "Enter First Name : "; getline(cin, fname);
		cout << "Enter Last Name : "; getline(cin, lname);
		cout << "Enter Age : ";
		//cin >> age; 
		//getline(cin, s);

		string s;
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
			cout << "Enter Age : ";
			getline(cin, s);
		}
		istringstream iss(s);
		iss >> age;

		if (this->numberOfProfiles > 0) {
			int option2;
			cout << "Enter Number of Profile to Copy or 0 to create new profile: ";

			// integer input validation
			string s;
			getline(cin, s);
			while (s.size() > 0 && !(s[0] >= '1' && s[0] <= this->numberOfProfiles + '0')) {
				cout << "Enter Number of Profile to Copy or 0 to create new profile: ";
				getline(cin, s);
			}
			istringstream iss(s);
			iss >> option2;
			// end of integer input validation

			if (option2 == 0) {
				Profile* newProfile = new Profile(label, fname, lname, age);
				profiles.add(newProfile);
				this->numberOfProfiles++;
				cout << "\nProfile Created!\n\n";
			}
			else {
				Profile* newProfile = new Profile(*profiles.get(option2 - 1));
				newProfile->edit(label, fname, lname, age);
				profiles.add(newProfile);
				this->numberOfProfiles++;

				cout << "\nProfile Created By Copying " << this->profiles.get(option2 - 1)->getLabel() << " (" << option2 << ")" << "!\n";
			}
		}
		else {
			Profile* newProfile = new Profile(label, fname, lname, age);
			profiles.add(newProfile);
			this->numberOfProfiles++;
			cout << "\nProfile Created!\n\n";
		}

	}
	else if (option == this->numberOfProfiles + 2) {
		this->exit = true;
	}
}

void ProgramManager::profileMenu()
{
	cout << "1. Display Movie Queue\n";
	cout << "2. Add Movie to Queue\n";
	cout << "3. Edit Movie in Queue\n";
	cout << "4. Remove Movie from Queue\n";
	cout << "5. Search for Movie in Queue\n";
	cout << "6. Exit Profile\n";
	cout << "Enter option : ";
	int option;

	// integer input validation
	string s;
	getline(cin, s);
	while (s.size() > 0 && !(s[0] >= '1' && s[0] <= '6')) {
		cout << "Enter option : ";
		getline(cin, s);
	}
	istringstream iss(s);
	iss >> option;
	// end of integer input validation

	cout << endl;

	if (option == 1) {
		if (this->profiles.get(this->currentProfileIndex)->categories.getSize() == 0) {
			cout << "The movie queue is empty! Please add movies to the queue.\n";
		}
		else {
			this->isProfileMenu = false;
			this->isDisplayOptionsMenu = true;
		}
	}
	else if (option == 2) {
		string name;
		int year;
		string category;
		string rating;
		int ranking;
		string s;
		cout << "Enter Movie Name: "; getline(cin, name);
		cout << "Enter Year : ";

		// integer input validation
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
			cout << "Enter Year : ";
			getline(cin, s);
		}
		istringstream iss(s);
		iss >> year;
		// end of integer input validation

		cout << "Category : "; getline(cin, category);
		cout << "Rating : "; getline(cin, rating);
		cout << "Ranking(1 - 5) : ";
		
		// integer input validation
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '1' && s[0] <= '5')) {
			cout << "Ranking(1 - 5) : ";
			getline(cin, s);
		}
		istringstream iss2(s);
		iss2 >> ranking;
		// end of integer input validation

		Movie movie(name, year, category, rating, ranking);

		this->profiles.get(this->currentProfileIndex)->addMovieToQueue(&movie);

		cout << "\nMovie added to the Queue!\n\n";
		//this->profiles.get(this->currentProfileIndex)->displayMovieQueue(1);
	}
	else if (option == 3) {
		string name;
		int year;
		string s;
		cout << "Enter Movie Name: "; getline(cin, name);
		cout << "Enter Year : ";  
		
		// integer input validation
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
			cout << "Enter Year : ";
			getline(cin, s);
		}
		istringstream iss(s);
		iss >> year;
		// end of integer input validation

		pair<int, int> pos = this->profiles.get(this->currentProfileIndex)->searchForMovieInQueue(name, year);
		if (pos.first == -1 && pos.second == -1) {
			cout << "Movie not found!\n";
		}
		else {
			string name;
			int year;
			string category;
			string rating;
			int ranking;
			string s;
			cout << "Enter Movie Name: "; getline(cin, name);
			cout << "Enter Year : ";

			// integer input validation
			getline(cin, s);
			while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
				cout << "Enter Year : ";
				getline(cin, s);
			}
			istringstream iss(s);
			iss >> year;
			// end of integer input validation

			cout << "Category : "; getline(cin, category);
			cout << "Rating : "; getline(cin, rating);
			cout << "Ranking(1 - 5) : ";

			// integer input validation
			getline(cin, s);
			while (s.size() > 0 && !(s[0] >= '1' && s[0] <= '5')) {
				cout << "Ranking(1 - 5) : ";
				getline(cin, s);
			}
			istringstream iss2(s);
			iss2 >> ranking;
			// end of integer input validation

			Movie movie(name, year, category, rating, ranking);

			this->profiles.get(this->currentProfileIndex)->editMovieInQueue(pos, &movie);
			cout << "Movie edited!\n";
		}

	}
	else if (option == 4) {
		string name;
		int year;
		string s;
		cout << "Enter Movie Name: "; getline(cin, name);
		cout << "Enter Year : "; 
		
		// integer input validation
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
			cout << "Enter Year : ";
			getline(cin, s);
		}
		istringstream iss(s);
		iss >> year;
		// end of integer input validation
		
		pair<int, int> pos = this->profiles.get(this->currentProfileIndex)->searchForMovieInQueue(name, year);
		if (pos.first == -1 || pos.second == -1) {
			cout << "Movie not found!\n";
		}
		else {
			this->profiles.get(this->currentProfileIndex)->removeMovieFromQueue(pos);
			cout << "Movie removed!\n";
		}
	}
	else if (option == 5) {
		string name;
		int year;
		string s;
		cout << "Enter Movie Name: "; getline(cin, name);
		cout << "Enter Year : ";

		// integer input validation
		getline(cin, s);
		while (s.size() > 0 && !(s[0] >= '0' && s[0] <= '9')) {
			cout << "Enter Year : ";
			getline(cin, s);
		}
		istringstream iss(s);
		iss >> year;
		// end of integer input validation

		pair<int,int> pos = this->profiles.get(this->currentProfileIndex)->searchForMovieInQueue(name, year);
		if (pos.first != -1 && pos.second != -1) {
			Movie movie = this->profiles.get(this->currentProfileIndex)->categories.get(pos.first)->movies.get(pos.second);
			cout << "\n----------------------------\n";
			cout << movie.getName() << endl;
			cout << "Year : " << movie.getYear() << endl;
			cout << "Category : " << movie.getCategory() << endl;
			cout << "Rated : " << movie.getRating() << endl;
			cout << "Ranked : ";
			for (int k = 0; k < movie.getRanking(); k++) {
				cout << "*";
			}cout << endl;
			cout << "----------------------------\n";
		}
		else {
			cout << "Movie not found!\n";
		}
	}
	else if (option == 6) {
		this->isMainMenu = true;
		this->isProfileMenu = false;
		this->currentProfileIndex = -1;
	}
}

void ProgramManager::displayOptionsMenu()
{
	cout << "\nDisplay options:\n\n";
	cout << "1. Highest to Lowest Ranking\n";
	cout << "2. Lowest to Highest Ranking\n";
	cout << "3. Filter by Rating\n";
	cout << "4. Filter by Category\n";
	cout << "5. Sorted movie queue\n";
	cout << "6. Exit Display Menu\n\n";
	int option; string s;
	cout << "Enter option: ";

	// integer input validation
	getline(cin, s);
	while (s.size() > 0 && !(s[0] >= '1' && s[0] <= '6')) {
		cout << "Enter option: ";
		getline(cin, s);
	}
	istringstream iss(s);
	iss >> option;
	// end of integer input validation

	if (option == 3) {
		string rating;
		cout << "Enter Rating: "; getline(cin, rating);
		this->profiles.get(this->currentProfileIndex)->displayMovieQueue(option, rating);
	}
	else if (option == 4) {
		string category;
		cout << "Enter Category: "; getline(cin, category);
		*this->profiles.get(this->currentProfileIndex) << category;
	}
	else if (option == 5) {
		this->profiles.get(this->currentProfileIndex)->displayMovieQueue(option);
	}
	else if (option == 6) {
		this->isDisplayOptionsMenu = false;
		this->isProfileMenu = true;
		cout << "\nExiting Display Menu.\n\n";
	}
	else {
		this->profiles.get(this->currentProfileIndex)->displayMovieQueue(option);
	}
}
