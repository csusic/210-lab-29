// COMSC-210 | Lab 30 | Christine Susic

//header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <array>
#include <list>
using namespace std;

//constant column widths
const int W1 = 12, W2 = 15;

//function prototype for printing the map
void displayState(const map<string, array<list<int>, 3>>& farmMap, int);

//main function defintion begins
int main() {
	//declarations
	//create farm map 
	//simulation structure is a farm of 3 lists: Grains, Fruits, and Vegetables
    //std::map with 3-element std::array of std::lists
    std::map<string, std::array<std::list<int>, 3>> farmMap;
    
    //dummy values
    //grains farmMap[][0]
    farmMap["A"][0].push_back(10);
    farmMap["A"][0].push_back(22);
    //fruits farmMap[][1]
    farmMap["A"][1].push_back(53);
    //vegetables farmMap[][2]
    farmMap["B"][2].push_back(10);
   
    //retrieve data from an external file
    //at least 100 lines of data
    //open file
    ifstream fin("data.txt");
    //put data into the farm map
    string farm;
    if (fin.good()) {
    	while (getline(fin, farm)) {
    	    
         farm >> type >> yield;
        	if (type == "Grains") index = 0;
        	else if (type == "Fruits") index = 1;
        	else if (type == "Vegetables") index = 2;
        	farmMap[]
        	farmMap[farm][index].push_back(yield);
    	}
    }
    //if file not found, display error and exit 
    else
        cout << "Input file not found.\n";
    //close file
    fin.close();

    //call driver function to display std::map
    displayState(farmMap, 0);

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
    cout << setw(W2) << "Grains";
    cout << setw(W2) << "Fruits";
    cout << setw(W2) << "Vegetables" << endl;
    cout << "------------------------------------------------------------" << endl;

for (const auto& it : farmMap) {
    cout << setw(W1) << it.first;
    for (int i = 0; i < 3; i++) {
        string listContent = "";
        for (int value : it.second[i]) {
            listContent += to_string(value) + " ";
        }
        cout << setw(W2) << listContent;
        }
        cout << endl;
    }
}
