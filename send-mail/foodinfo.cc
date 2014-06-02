#include "foodinfo.h"
#include <string>

using namespace std;


food_info::food_info(string type, string location,
                string meal, string day, string description) :
                Type(type), Location(location),
                Meal(meal), Day(day), Description(description) {
}

string food_info::getType() {
    return Type;
}
string food_info::getLocation() {
    return Location;
}
string food_info::getMeal() {
    return Meal;
}
string food_info::getDay() {
    return Day;
}
string food_info::getDescription() {
    return Description;
}

int convert(string str) {
    if (str == "Monday") {
        return 1;
    } else if ( str == "Tuesday") {
        return 2;
    } else if ( str == "Wednesday") {
        return 3;
    } else if ( str == "Thursday" ) {
        return 4;
    } else if ( str == "Friday" ) {
        return 5;
    } else {
        //bad input
    }
    return 1;
}

bool operator<(food_info f, food_info g) {
    //compare the days:
    int day_f = convert(f.getDay());
    int day_g = convert(g.getDay());
    if (day_f < day_g) {
        return true;
    } else if (day_f > day_g) {
        return false;
    }
    //compare the locations
    if (f.getLocation() < g.getLocation()) {
        return true;
    } else if (f.getLocation() > g.getLocation()) {
        return false;
    }

    //compare the Meals lunch < dinner
    if (f.getMeal() > g.getMeal()) {
        return true;
    } else if( f.getMeal() < g.getMeal()) {
        return false;
    }
    
    //compare the Types
    if (f.getType() < g.getType()) {
        return true;
    }
    return false;
}

