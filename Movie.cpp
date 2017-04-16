// Created by Tiberiu Simion Voicu on 22/03/2017.
#include "Movie.h"
using namespace std;

Movie::Movie(string title, int year, string rated, string genre,
	 		int length, float mean, int ratings){
	this->title = title;
	this->year = year;
	this->rated = rated;
    this->genre = genre;
    this->length = length;
    this->mean = mean;
	this->ratings = ratings;
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
