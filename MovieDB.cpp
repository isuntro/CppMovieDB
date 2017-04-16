//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//
/* ***********************************
	ADD ANY OTHER NEEDED FUNCTIONS
	FOR GENERIC QUERRYS
   *********************************** */

#include "MovieDB.h"
#include <vector>
#include <sstream>
#include <string>

MovieDB::~MovieDB(){
	for(int i=0; i< this->size(); i++)
	{
		delete this->movieList[i];
	}
}
MovieDB::MovieDB(){
}
MovieDB::MovieDB(const MovieDB &that){
	for(int i=0; i < that.size();i++ ){
		this->movieList.push_back(that.getList()[i]);
	}
}
void swap(MovieDB &one, MovieDB &another){
	using std::swap;
	swap(one.movieList, another.movieList);
}
MovieDB& MovieDB::operator= (MovieDB that){
	swap(*this, that);
	return *this;
}
/* ***********************************
	CHECK WETHER WE HAVE TO LEAVE " "
	OR NOT ALSO DOUBLE CHECK ITS WORKING
	AS INTENDED
   *********************************** */
std::istream& operator>> (std::istream &in, MovieDB &movieDB) {
    Movie *aMovie;
	string line;
	string temp;
	vector<string> tokens(8);
	//get each entry line by line
    while(getline(in,line)){
		istringstream sstr(line);
		// ignore first " then parse until next "
		// and get the title
		sstr.ignore(1);
		getline(sstr,temp,'\"');
		tokens[7] = temp;
		// loop through line getting
		// each string before comma
		for(int i=0; i<7; i++){
			getline(sstr,temp,',');
			tokens[i] = temp;
		}
		// convert string to each of the necessary types
		int year = stoi(tokens[1]);
		int length = stoi(tokens[4]);
		float mean = stoi(tokens[5]);
		int ratings = stof(tokens[6]);
		//create a new movie and add it to the database;
		aMovie = new Movie(tokens[7],year,tokens[2],tokens[3],length,mean,ratings);
		movieDB.addMovie(aMovie);
	}
    return in;
}
void MovieDB::updateRatings(Ratings &rList) {
	int ratings;
	int sum;
	for(int i=0; i < this->size(); i++) {
		Movie &aMovie = *this->getList()[i];
		for(int i=0; i<rList.size(); i++) {
			if(aMovie.getTitle() == rList.getRatings()[i]->getTitle()){
				ratings++;
				sum += rList.getRatings()[i]->getRating();
			}
		}
		aMovie.setRatings(ratings);
		aMovie.setMean((float)(sum) / (float)(ratings));
		ratings =0;
		sum = 0;
	}
}
