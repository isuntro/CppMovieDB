#include "Rating.h"
#include <string>
#include <sstream>

Rating::Rating(TimeCode &date, string author, string title, int rating){
	this->date = new TimeCode(date);
	this->author = author;
	this->title = title;
	this->rating = rating;
}
Rating::Rating(){
	this->date = new TimeCode();
	author = "";
	title = "";
	rating = 0;
}
Rating::~Rating(){
	delete(date);
};
Rating::Rating(const Rating &aRating) {
	this->date = new TimeCode(*aRating.date);
	this->author = aRating.author;
	this->title = aRating.title;
	this->rating = aRating.rating;
}
void swap(Rating &one, Rating &another){
	using std::swap;
	swap(one.date,another.date );
	swap(one.author,another.author);
	swap(one.title, another.title);
	swap(one.rating, another.rating);
}

Rating& Rating::operator= ( Rating that) {
	swap(*this, that);
	return *this;
}
std::istream& operator >>(std::istream &in, Rating &aRating) {
	TimeCode date;
	string author,title,line;
	char del1,del2,del3;
	int rating;

	if(in >> date >> del1 >> title >> del2 >> author >> del3 >> rating){
		if(del1 == ',' && del2 == ',' && del3 == ','){
			aRating = Rating (date,author,title,rating);
		}
	}
	return in;
}
