#ifndef RATINGS_RATING_H
#define RATINGS_RATING_H
#include "Rating.h"
#include <vector>
using namespace std;

class Ratings {
private:
	vector<Rating*> ratingsList;
public:
	Ratings();
	~Ratings();
	Ratings(const Ratings &list);
	inline vector<Rating*> getRatings() const;
	inline int size() const;
	inline void addRating(Rating *aRating);
	Ratings& operator= (Ratings that);
	friend std::ostream& operator<< (std::ostream &out, const Ratings &rList);
	friend void swap(Ratings &one, Ratings &another);
};
inline vector<Rating*> Ratings::getRatings() const{
	return ratingsList;
}
inline int Ratings::size() const {
	return ratingsList.size();
}
inline void Ratings::addRating(Rating *aRating){
	this->ratingsList.push_back(aRating);
}
inline std::ostream& operator<< (std::ostream &out, const Ratings &rList) {
	for(int i =0; i<rList.getRatings().size(); i++){
        out << *rList.getRatings()[i] << endl;
    }
	return out;
}
std::istream& operator>> (std::istream &in, Ratings &rList);
#endif //RATINGS_RATING_H
