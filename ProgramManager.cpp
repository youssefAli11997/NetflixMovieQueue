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
	string s;
	cin >> option;
	getline(cin, s);

	if (option < 1 || option > this->numberOfProfiles + 2) {
		return;
	}

	if (option <= this->numberOfProfiles) {
		// go to profile
		this->currentProfileIndex = option-1;
		this->isMainMenu = false;
		this->isProfileMenu = true;
	}
	else if (option == this->numberOfProfiles + 1) {
		string label;
		string fname;
		string lname;
		int age;
		string s;

		cout << "Enter Profile Label : "; getline(cin,label);
		cout << "Enter First Name : "; getline(cin, fname);
		cout << "Enter Last Name : "; getline(cin, lname);
		cout << "Enter Age : "; cin >> age; getline(cin, s);
		// TODO: input verification

		if (this->numberOfProfiles > 0) {
			int option;
			cout << "Enter Number of Profile to Copy or 0 to create new profile: ";
			cin >> option; getline(cin, s);
			if (option == 0) {
				Profile* newProfile = new Profile(label, fname, lname, age);
				profiles.add(newProfile);
				this->numberOfProfiles++;
			}
			else {
				Profile* newProfile = new Profile(label, fname, lname, age);
				//newProfile.addCategories(profiles->get(option).getCategories());
				profiles.add(newProfile);
				this->numberOfProfiles++;
			}
		}
		else {
			Profile* newProfile = new Profile(label, fname, lname, age);
			profiles.add(newProfile);
			this->numberOfProfiles++;
		}

		cout << "\nProfile Created!\n\n";
	}
	else if (option == this->numberOfProfiles + 2) {
		this->exit = true;
	}
}

void ProgramManager::profileMenu()
{
	cout << this->profiles.get(this->currentProfileIndex)->getLabel() << " Movie Queue\n\n";
	cout << "1. Display Movie Queue\n";
	cout << "2. Add Movie to Queue\n";
	cout << "3. Edit Movie in Queue\n";
	cout << "4. Remove Movie from Queue\n";
	cout << "5. Search for Movie in Queue\n";
	cout << "6. Exit Profile\n";
	cout << "Enter option : ";
	int option;
	cin >> option;

	if (option == 1) {
		// TODO: options
		this->profiles.get(this->currentProfileIndex)->displayMovieQueue(1);
	}
	else if (option == 2) {
		string name;
		int year;
		string category;
		string rating;
		int ranking;
		cout << "Enter Movie Name: "; cin >> name;
		cout << "Enter Year : "; cin >> year;
		cout << "Category : "; cin >> category;
		cout << "Rating : "; cin >> rating;
		cout << "Ranking(1 - 5) : "; cin >> ranking;

		Movie movie(name, year, category, rating, ranking);
		//cout << movie.getName() << " " << movie.getCategory() << endl;
		this->profiles.get(this->currentProfileIndex)->addMovieToQueue(&movie);

		cout << "Movie added to the Queue!\n";
		//this->profiles.get(this->currentProfileIndex)->displayMovieQueue(1);
	}
	else if (option == 3) {
		string name;
		int year;
		cout << "Enter Movie Name: "; cin >> name;
		cout << "Enter Year : "; cin >> year;
	}

	else if (option == 6) {
		this->isMainMenu = true;
		this->isProfileMenu = false;
		this->currentProfileIndex = -1;
	}
}

void ProgramManager::displayOptionsMenu()
{
}
