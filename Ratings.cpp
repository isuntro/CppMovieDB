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
Ratings& Ratings::operator= (const Ratings &list){
	if (this != &list) {
		for(int i=0; i < this->size(); i++){
			delete(this->ratingsList[i]);
		}
		for(int i=0; i < list.size(); i++) {
			this->ratingsList.push_back(list.getRatings()[i]);
		}
	}
	return *this;
}
std::istream &operator>> (std::istream &in, Ratings &rList) {
	string line,author,title,temp;
	int rating;
	string day,month,year,hour,minute,second;
	while(getline(in,line)) {
		stringstream sstr(line);
		getline(sstr,day,'/');
		getline(sstr,month,'/');
		getline(sstr,year,'T');
		getline(sstr,hour,':');
		getline(sstr,minute,':');
		getline(sstr,second,'Z');

		TimeCode *date = new TimeCode(stoi(day),stoi(month),stoi(year),
		stoi(hour),stoi(minute),stoi(second));
		//in >> *tDate;
		sstr.ignore(2);
		getline(sstr,author,'\"');
		sstr.ignore(2);
		getline(sstr,title,'\"');
		sstr.ignore(1);
		sstr >> rating;
		Rating *aRating = new Rating(date, author, title, rating);
		rList.addRating(*aRating);
	}
	return in;
}
