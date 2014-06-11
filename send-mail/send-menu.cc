#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include "foodinfo.h"
using namespace std;



int main()
{
    ifstream users("html/Userfile");
    string user, type, location, meal, day, description, menuLine, temp;
    int n, flag, foundFood, i;
    bool donewline = false;

    //read in each food item from the data file
	vector<food_info> Foods;
    ifstream menu("menu.txt");
    while (getline (menu, menuLine)) {

        //read the data about the food item
        //throw away the types
        int k = menuLine.find_first_of(' ')+1;
        day = menuLine.substr(k);
        getline(menu, menuLine);
        k = menuLine.find_first_of(' ')+1;
        location = menuLine.substr(k);
        getline(menu, menuLine);
        k = menuLine.find_first_of(' ')+1;
        meal = menuLine.substr(k);
        getline(menu, menuLine);
        k = menuLine.find_first_of(' ')+1;
        type = menuLine.substr(k);
        getline(menu, menuLine);
        //No type, keep the entire line
//        k = menuLine.find_first_of(' ')+1;
        description = menuLine;//.substr(k);

        Foods.push_back(food_info(type, location, meal, day, description));
    }

    sort(Foods.begin(), Foods.end());

    while(getline(users,user))
    {
        ofstream output("output");
        stringstream buffer(user), call;
        string buf;
        n = 0;
        foundFood = 0;
        buffer >> user;
        call << "mutt -s \"Waterloo Food\" " << user << " < output";
        map <string, int> preferences;
        while (buffer >> buf) {
            preferences[buf] = 1;
        }
        string curday;
        string curloc;
        //go through each food type and see if the user likes it
        for (vector<food_info>::iterator it = Foods.begin();
                        it != Foods.end(); it ++) {
            //This user does not like this food
            if (preferences.find(it->getType()) == preferences.end()) {
                continue;
            }
            //New Day
            if (it->getDay() != curday) {
                curday = it->getDay();
                output << curday << ":" << endl;
                curloc = "";
            }
            //New Location
            if (it->getLocation() != curloc) {
                curloc = it->getLocation();
                output << "  At " << curloc << ":" << endl;
            }
            //Output the time and food description
            output << "    " << it->getMeal() << ": " << it->getDescription() << endl;
            foundFood ++;
        }

        if (foundFood != 0)
        {
            system(call.str().c_str());
        }
    }
}
