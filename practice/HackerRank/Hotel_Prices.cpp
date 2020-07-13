// https://www.hackerrank.com/challenges/hotel-prices/problem

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
    int bedrooms, bathrooms;
public:
    HotelRoom(int bedrooms, int bathrooms) : bedrooms(bedrooms), bathrooms(bathrooms) {}
    virtual int get_price() {
        return 50 * bedrooms + 100 * bathrooms;
    }
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms, bathrooms) {}
    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

