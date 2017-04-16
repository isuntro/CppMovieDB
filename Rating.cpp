#include "Rating.h"
#include <string>
#include <sstream>

Rating::Rating(TimeCode date, string author, string title, int rating){
	this->date = date;
	this->author = author;
	this->title = title;
	this->rating = rating;
}
std::istream& operator >>(std::istream &in, Rating &aRating) {
	TimeCode date;
	string author,title,line;
	char del1,del2,del3;
	int rating;

	if(in >> date >> del1 >> title >> del2 >> author >> del3 >> rating){
		if(del1 == ',' && del2 == ',' && del3 == ','){
			aRating = Rating(date,author,title,rating);
		}
	}
	return in;
}
