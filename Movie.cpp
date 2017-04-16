// Created by Tiberiu Simion Voicu on 22/03/2017.
#include "Movie.h"

Movie::Movie(string title, int year, string rated, string genre,
	 		int length, float mean, int ratings){
	this->title = title;
	this->year = year;
	this->rated = rated;
    this->genre = genre;
    this->length = length;
    this->meanRating = mean;
	this->ratings = ratings;
}
Movie::~Movie(){ };
Movie::Movie(const Movie &that){
	this->title = that.title;
	this->year = that.year;
	this->rated = that.rated;
    this->genre = that.genre;
    this->length = that.length;
    this->meanRating = that.meanRating;
	this->ratings = that.ratings;
}
void swap(Movie &one, Movie &another){
	using std::swap;

	swap (one.title, another.title);
	swap (one.year, another.year);
	swap (one.rated, another.rated);
	swap (one.genre, another.genre);
	swap (one.length, another.length);
	swap (one.meanRating, another.meanRating);
	swap (one.ratings, another.ratings);
}
Movie& Movie::operator =(Movie that){
	swap(*this,that);
	return *this;
}
/* ***********************************
				REDO
   *********************************** */
std::istream& operator >>(std::istream &in, Movie &aMovie) {
	string input,title,rated,genre;
    int year,length,ratings;
	float mean;

	while(true) {
		getline(in,input);
		if(input.length() < 70 && input.length() > 3){
			title = input;
			cout << title;
			break;
		}

		cout << "try again title";
	}
	while(true) {
		if(in >> year){
			// ignore() consumes newLine char
			// so it won't mess up next read
			in.ignore();
			cout << year;
			break;
		}
	}
	while(true) {
		getline(in,input);
		if(input.length() < 30 && input.length() > 5 ){
			rated = input;
			cout << rated;
			break;
		}
	}
	while(true) {
		getline(in,input);
		if(input.length() < 30 && input.length() > 5){
			genre = input;
			cout << genre;
			break;
		}
	}
	while(true) {
		if(in >> length){
			// ignore() consumes newLine char
			// so it won't mess up next read
			in.ignore();
			cout << length;
			break;
		}
	}
	while(true) {
		if(in >> mean){
			cout << mean;
			break;
		}
		cout << "try again rating";
	}
	while(true) {
		if(in >> ratings){
			cout << ratings;
			break;
		}
		cout << "try again rating";
	}

    aMovie = Movie(title,year,rated,genre,length,mean,ratings);
    return in;
}
