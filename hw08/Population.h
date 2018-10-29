#ifndef POPULATION_H
#define POPULATION_H


#include<iostream>
#include"Fish.h"
#include"Angle.h"
#include"Log.h"

class Fish;


class Population{

private:
	Fish** sea;
	int size; // num of fishes
	int index; // for search and remove

public:
	Population(); // const
	virtual ~Population();
	void add(Fish* fish); // not const
	void remove(Fish* fish); // not const
	int getSize() const;
	Fish* get(int search_index) const; // return fish at the index
	int searchFish(Fish* fish) const; // search for given fish in the arr

	Fish& operator[](int ind) const; // overload arr index

	// printable
	friend std::ostream& operator<<(std::ostream& out, const Population& water);


};

#endif
