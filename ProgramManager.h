#pragma once
#include <iostream>
#include <string>
#include "Profile.h"
using namespace std;

class ProgramManager
{
public:
	ProgramManager();
	~ProgramManager();
	void start();
	void mainMenu();
	void profileMenu();
	void displayOptionsMenu();

private:
	bool isMainMenu;
	bool isProfileMenu;
	bool isDisplayOptionsMenu;
	bool exit;
	Profile * currentProfile;
	DoublyLinkedList<Profile> profiles;
	int numberOfProfiles;
};

