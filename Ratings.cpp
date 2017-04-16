#include "Ratings.h"
#include <string>
#include <sstream>
#include <iostream>
Ratings::Ratings(){

}
Ratings::Ratings(const Ratings &list){
	for(int i=0; i < list.size(); i++) {
		this->ratingsList.push_back(list.getRatings()[i]);
	}
}
Ratings::~Ratings(){
	for(int i=0; i < this->size(); i++){
		delete(this->ratingsList[i]);
	}
}
void swap(Ratings &one, Ratings &another){
	using std::swap;
	swap(one.ratingsList, another.ratingsList);
}
Ratings& Ratings::operator= ( Ratings that){
	swap(*this,that);
	return *this;
}
std::istream &operator>> (std::istream &in, Ratings &rList) {
	string line,author,title,temp;
	int rating;
	string days,months,years,hours,minutes,seconds;
	while(getline(in,line)) {
		stringstream sstr(line);
		getline(sstr,days,'/');
		getline(sstr,months,'/');
		getline(sstr,years,'T');
		getline(sstr,hours,':');
		getline(sstr,minutes,':');
		getline(sstr,seconds,'Z');

		TimeCode date =  TimeCode(stoi(days),stoi(months),stoi(years),
		stoi(hours),stoi(minutes),stoi(seconds));
		//in >> *tDate;
		sstr.ignore(2);
		getline(sstr,author,'\"');
		sstr.ignore(2);
		getline(sstr,title,'\"');
		sstr.ignore(1);
		sstr >> rating;
		Rating *aRating = new Rating(date, author, title, rating);
		rList.addRating(aRating);
	}
	return in;
}
