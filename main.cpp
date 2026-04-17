// COMSC-210 | Lab 30 | Christine Susic

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
   
    //retrieve data from an external file
    //at least 100 lines of data
    //open file
    ifstream fin("data.txt");
    //put data into the farm map
    string key;
    int v1, v2, v3;
    if (fin.good()) {
        while (fin >> key >> v1 >> v2 >> v3) {
            //grains
            farmMap[key][0].push_back(v1);
            //fruits
            farmMap[key][1].push_back(v2);
            //vegetables
            farmMap[key][2].push_back(v3);
        }
    }
    //if file not found, display error and exit 
    else
        cout << "Input file not found.\n";
    //close file
    fin.close();
    
    //call function to display std::map for modifications
    for (int year = 1; year <= 101; year +=4) {
        //display initial year value
        displayState(farmMap, year);
        //display simulation menu
        cout << endl;
        cout << "Simulation Menu" << endl;
        cout << "[1] Heat Wave" << endl;
        cout << "[2] Increased Rainfall" << endl;
        cout << "[3] Pests/disease" << endl;
        cout << "[4] Quit" << endl;
        cout << "Input choice: ";
        //insert choice
        int choice;
        cin >> choice;
        cout << endl;
        //for loop 
        for (auto& it : farmMap) {
            for (int i = 0; i < 3; i++) {
                //simulate increased heat
                //subtraction of crops by removing the first element
                if (choice == 1) {
                    it.second[i].pop_front();
                }
                //simulate increased rainfall 
                //addition of crops by adding to the back
                if (choice == 2) {
                    it.second[i].push_back(1); 
                }
                //simulate pests/disease
                //remove all elements
                if (choice == 3) {
                    it.second[i].clear();
                }
                if (choice == 4) {
                    exit(0);
                }
            }
        }
    }

    /*//show initial state and how it changes after 25 time periods
    //move through the names in the map, and simulate changes
     for (int year = 1; year <= 100; year++) {
        for (auto& it : farmMap) {
            for (int i = 0; i < 3; i++) {
                //simulate increased heat
                //subtraction of crops by removing the first element
                if (!it.second[i].empty()) {
                    it.second[i].pop_front();
                }
                //simulate increased rainfall 
                //addition of crops by adding to the back
                it.second[i].push_back(1); 
                //simulate pests/disease
                //remove all elements
                //it.second[i].clear();
            }
                
        }
        //period of time between intervals, every 4 years
        if (year % 4 == 0) {
            //call driver function to display std::map
            displayState(farmMap, year);
        }
    }*/
}
//main function definition ends

//function definition for printing the map
//parameters are the map, and the number of years
void displayState(const map<string, array<list<int>, 3>>& farmMap, int year) {
//headers 
cout << "Year " << year << endl;
cout << setw(W1) << "Farm";
cout << setw(W2) << "Grains";
cout << setw(W2) << "Fruits";
cout << setw(W2) << "Vegetables" << endl;
cout << "------------------------------------------------------------" << endl;
//output the map
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