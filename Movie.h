#pragma once
class Movie
{
public:
	Movie();
	Movie(string name, int year, string category, string rating, int ranking);
	~Movie();
	bool operator==(Movie* movie);
	bool operator!=(Movie* movie);
	string getName();
	string getRating();
	string getCategory();
	void edit(string name, int year, string category, string rating, int ranking);
	int getYear();
	int getRanking();


private:
	string name;
	int year;
	string rating;
	int ranking;
	string category;
};

