#ifndef FOODINFO_H
#define FOODINFO_H
#include <string>

using std::string;

class food_info {
	private:
	string Type;
	string Location;
	string Meal;
	string Day;
	string Description;
	public:
	food_info(string, string, string, string, string);
	string getType();
	string getLocation();
	string getMeal();
	string getDay();
	string getDescription();
};
// we want to sort by Day -- monday < tuesday < ..
// then by location --
//then by Meal -- lunch < dinner
// then by Type
bool operator<(food_info f, food_info g);
   

#endif // FOOD_INFO_H
