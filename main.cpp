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

//constant column widths, minimum and maximum values for random number
const int W1 = 12, W2 = 20, MIN = 1, MAX = 100;

//function prototype for printing the map
void displayState(const map<string, array<list<int>, 3>>& farmMap, int);

//main function defintion begins
int main() {
	//declarations
	srand(time(0));
	int choice; //choice for menu
	int random = rand() % (MAX-MIN+1) + MIN; //random data for increased crops
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
    
    //data for 25 years of crops
    cout << "25 Years of Crops" << endl;
    for (int year = 4; year <= 100; year +=4) {
        //display initial year value
        displayState(farmMap, year);
    }
    
    cout << "Start of Simulation" << endl;
    //call function to display std::map for modifications
    for (int year = 4; year <= 100; year +=4) {
        //display initial year value to modify
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
        cin >> choice;
        cout << endl;
        //for loop to access farmMap
        for (auto& it : farmMap) {
            for (int i = 0; i < 3; i++) {
                //if choice = 1, simulate increased heat
                //subtraction of crops by removing the first element
                if (choice == 1) {
                    it.second[i].pop_front();
                }
                //if choice = 2, simulate increased rainfall 
                //addition of crops by adding to the back
                if (choice == 2) {
                    it.second[i].push_back(random); 
                }
                //if choice = 3, simulate pests/disease
                //remove all elements
                if (choice == 3) {
                    it.second[i].clear();
                }
                //if choice = 4, quit the program
                if (choice == 4) {
                    exit(0);
                }
            }
        }
    }
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
cout << "-------------------------------------------------------------------------" << endl;
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