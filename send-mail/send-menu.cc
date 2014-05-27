#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
    ifstream users("html/Userfile");
    string user, foodTypes[10], currentType, location, meal, day, menuLine, temp;
    int n, flag, foundFood, i;
    bool donewline = false;

    while(getline(users,user))
    {
        ifstream menu("menu.txt");
        ofstream output("output");
        stringstream buffer(user), call;
        n = 0;
        foundFood = 0;
        buffer >> user;
        call << "mutt -s \"Waterloo Food\" " << user << " < output";
        while (buffer >> foodTypes[n])
        {
            n++;
        }
        
        while(getline(menu, menuLine))
        {
            stringstream buffer2(menuLine);
            buffer2 >> temp;
            if (temp == "DAY")
            {
                buffer2 >> day;
            }
            else if (temp == "LOCATION")
            {
                string loc = location;
                getline(buffer2, location);
                location.erase(0,1);
                if (location != loc) {
                    donewline = true;
                } 
            }
            else if (temp == "MEAL")
            {
                buffer2 >> meal;
            }
            else if (temp == "TYPE")
            {
                flag = 0;
                while (buffer2 >> currentType)
                {
                    for(i = 0; i < n; i++)
                    {
                        if (currentType == foodTypes[i])
                        {
                            flag = 1;
                            foundFood = 1;
                            break;
                        }
                    }
                }

                if (flag)
                {
                    if (donewline) output << endl;
                    getline(menu, menuLine);
                    output << "You can go to " << location << " for " << meal << " on " << day << " to have " << menuLine << endl;
                    donewline = false;
                }
            }
        }
        
        if (foundFood != 0)
        {
            system(call.str().c_str());
        }
    }
}
