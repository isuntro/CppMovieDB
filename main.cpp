#include <iostream>
#include <fstream>
#include "Movie.h"
#include "MovieDB.h"
#include "TimeCode.h"
#include "Rating.h"
#include "Ratings.h"

int main(int argc, char* argv[]){
	using namespace std;

	MovieDB database;
	/*
	std::ifstream input( "movies.txt" );
	if(input.is_open()){
		input >> database;
		cout << database;
	}

	TimeCode date;
	ifstream timetest("ratings.txt" );
	timetest >> date;
	cout << date;
*/
	std::ifstream input( "ratings.txt" );
	Ratings *rList = new Ratings();
	input >> *rList;
	cout << *rList;


	return 0;

}
