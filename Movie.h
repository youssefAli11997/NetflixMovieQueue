#pragma once
class Movie
{
public:
	Movie();
	Movie(const Movie& movie);
	Movie(string name, int year, string category, string rating, int ranking);
	~Movie();
	string getName();
	string getRating();
	string getCategory();
	int getYear();
	int getRanking();


private:
	string name;
	int year;
	string rating;
	int ranking;
	string category;
};

