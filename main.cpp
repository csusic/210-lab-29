// COMSC-210 | Lab 29 | Christine Susi

//header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>
using namespace std;

//constant column widths
const int W1 = 10;

//function prototype for printing the map
void displayState(const map<string, array<list<int>, 3>>& farmMap, int);

//main function defintion begins
int main() {
	//declarations
	//create farm map 
	//simulation structure is a farm of 3 lists: Grains, Fruits, and Vegetables
    //std::map with 3-element std::array of std::lists
    std::map<string, std::array<std::list<int>, 3>> farmMap;
    
    //dummy value
    farmMap["A"][0].push_back(10);
     
    //driver function to display std::map
    displayState(farmMap, 0);
   
    //open file
    //if file not found, display error and exit 
    
    //retrieve data from an external file
    //at least 100 lines of data
    //put data into the farm map
    //close file

    //show initial state and how it changes after 25 time periods
    //move through the names in the map, and simulate changes

        //simulate increased heat
        //subtraction of crops by removing the first element

        //simulate increased rainfall 
        //addition of crops by adding to the back
        
        //simulate pests/disease
        //remove all elements
               
        //period of time between intervals, every 4 days
}
//main function definition ends

//function definition for printing the map
//parameters are the map, and the number of years
//output the map
void displayState(const map<string, array<list<int>, 3>>& farmMap, int a) {
    cout << setw(W1) << "Farm";

    for (const auto& it : farmMap) {
        cout << setw(W1) << it.first;
    }
}
