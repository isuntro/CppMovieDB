#include <iostream>
#include <fstream>
#include "Movie.h"
#include "MovieDB.h"
#include "TimeCode.h"
#include "Rating.h"
#include "Ratings.h"
/* *****************************
	**** LOOK INTO USING POINTERS LESS
	**** AND MAYBE DONT USE VECTOR OF POINTERS
	*	FIX PROBLEM WITH MONTH  0
	INSTEAD OF 12
	*	FIX DISPLAY FORMAT FOR Movie
		AND CHECK FOR RATING
	*	CHECK MEMORY ALLOCATION IN
		RATINGS
	*	CHECK I/O OVERLOADING
	* 	CHECK IF GENRE SHOULD
		BE ENUM OR BITMASK
		OR OTHER TYPE
	* 	FIX INDIANA JONES RATING
		NEGATIVE
	*************************** */
int main(){
	using namespace std;

	MovieDB *database = new MovieDB();
	Ratings *rList = new Ratings();
	std::ifstream inRatings( "ratings.txt");
	std::ifstream inMovies( "movies.txt" );
	if(inMovies.is_open()){
		inMovies >> *database;
	}
	if(inRatings.is_open()){
		inRatings >> *rList;
	}
	cout << database->size() << endl;
				//database->updateRatings(*rList);
	/***************** BEGINING TASK 1 ******************/
	sortList(database->getList(),descending<int>,
		[](Movie *x) {return x->getYear();});
	cout << "Sorting DB by year ... \n" << *database << endl;
	/***************** BEGINING TASK 1 ******************/
	/***************** BEGINING TASK 2 ******************/
	auto getTask2 = [](Movie *amovie) {
		return (amovie->getGenre().find("Film-Noir")!=string::npos);
	};
	MovieDB *task2DB = extractDB(*database, getTask2);
	Movie amovie = getNthEntry(task2DB->getList(),
		descending<int>,[](Movie *amovie) {return amovie->getLength();}, 2);

	cout << " Third longest Film-Noir is: " << endl;
	cout << amovie << endl;
	delete(task2DB);
	/***************** ENDING TASK 2 *********************/

	/***************** BEGINING TASK 3 *******************/
	auto getTask3 = [](Movie *amovie) {
		return (amovie->getGenre().find("Sci-Fi")!=string::npos);
	};
	MovieDB *task3DB = extractDB(*database, getTask3);
	amovie = getNthEntry(task3DB->getList(),descending<float>,
	 	[](Movie *x){ return x->getMeanRating();}, 9);
	cout << " Tenth highest rated Sci-Fi movie is:" << endl;
	cout << amovie << endl;
	delete(task3DB);
	/***************** ENDING TASK 3 *********************/

	/***************** BEGINING TASK 4 *******************/
	Movie task4 = retrieveEntry(database->getList(),
		[](Movie x, Movie y)
		{ return (x.getMeanRating() < y.getMeanRating());});
	cout << " Highest rated movie is: \n" << task4 << endl;
	/***************** ENDING TASK 4 *********************/

	/***************** BEGINING TASK 5 *******************/
	Movie task5 = retrieveEntry(database->getList(),
		[](Movie x, Movie y)
		{ return (x.getTitle().size() < y.getTitle().size());});
	cout << " The movie with the longest title is: \n" << task5 <<endl;
	/***************** ENDING TASK 5 *******************/

	/***************** STARTING TASK 6 *******************/
	Rating task6 = getNthEntry(rList->getRatings(), descending<int>,
		[](Rating *x) { return (int)x->getDate();},100);
	cout << *rList << endl;
	cout << "The 101st chronological user ratings is: \n" << task6 << endl;
	/***************** ENDING TASK 6 *******************/

	return 0;

}
