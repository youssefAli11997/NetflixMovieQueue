// NetflixMovieQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	SinglyLinkedList<string>  list;
	//list.remove(2);
	for (int i = 0; i < 10; i++) {
		list.add(to_string(i*i));
		list.printAll();
	}
	//list.printAll();
	for (int i = 0; i < 10; i++) {
		cout << list.get(i) << endl;
	}cout << "*****************************\n";
	cout<<list.search(to_string(24))<<endl;
	cout<<list.search(to_string(25))<<endl;
	cout<<list.search(to_string(26))<<endl;
	list.printAll();
	//list.printAllReversed();
    return 0;
}

