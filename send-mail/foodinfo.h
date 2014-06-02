#ifndef FOODINFO_H
#define FOODINFO_H
#include <string>

class food_info {
	private:
	std::string Type;
	std::string Location;
	std::string Meal;
	std::string Day;
	std::string Description;
	public:
	food_info(std::string, std::string, std::string, std::string, std::string);
	std::string getType();
	std::string getLocation();
	std::string getMeal();
	std::string getDay();
	std::string getDescription();
};
// we want to sort by Day -- monday < tuesday < ..
// then by location --
//then by Meal -- lunch < dinner
// then by Type
bool operator<(food_info f, food_info g);
   

#endif // FOOD_INFO_H
