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
		string profileLabel = this->profiles.get(i).getLabel();
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


		Profile newProfile(label, fname, lname, age);
		profiles.add(newProfile);
		numberOfProfiles++;
	}
	else if (option == this->numberOfProfiles + 2) {
		this->exit = true;
	}
}

void ProgramManager::profileMenu()
{
}

void ProgramManager::displayOptionsMenu()
{
}
