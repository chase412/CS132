/*
 * Taesoo Lee (Chase)
 * Donald Hall
 * Levi Coffman
 *
 * Homework Assignment #9 (Group Project)
 * Due: 8/16/2017
 * Time Spent: 10 minutes (on this part)
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <ctype.h> // for character handling (upper casing, etc.)
using namespace std;

// global constants
const double TAX_RATE = 0.1; // hotel tax rate
const int NUMBER_OF_ROOMS = 6; // number of rooms per building
const int NUMBER_OF_BUILDINGS = 4; // number of total buildings
const int NUMBER_OF_IDS = 100; // total number of IDs our data file will hold

// function prototypes
void loadRooms();
int getOption();
void checkIn();
void printReceipt(double, int = 1);
void checkOut();
void getPricing();
void getOverallStatus();
void quitProgram();
void getRoom(int &, int &, string = "Building? ", string = "Room? ");
bool isValidRoom(int, int);
void hotelOperationsSummary();
int search(int[NUMBER_OF_IDS], int);
int search(string[NUMBER_OF_IDS], string);
void sortCustomerData();
void loadCustomerData();
int getID();
int makeID();
void findRoom(int, int &, int &);
void log(string);
double * getBuildingPrices();

// file streams
ofstream logOut;

// global variables (arrays)
int rooms[NUMBER_OF_BUILDINGS][NUMBER_OF_ROOMS]; // two-dimensional array
double * buildingPrices = getBuildingPrices();
int customerIDs[NUMBER_OF_IDS];
string customerNames[NUMBER_OF_IDS];
int lastID = 0;

int main() {
    // variable
	bool mainLoop = true;

	// setup
	logOut.open("Log.txt", ios::app); // will append to the log file
	loadRooms();
	loadCustomerData();

    // print greeting
    cout << "Hello World!" << endl; // it's a classic
    cout << "Welcome to our hotel!\n" << endl;

	// main loop
	// purpose- will loop until the user selects option 5- quit the program
	while (mainLoop) {
		int option = getOption();

		// option tree
		if (option == 1) { // checkin
			checkIn();
		} else if (option == 2) { // checkout
			checkOut();
		} else if (option == 3) { //price of the rooms
			getPricing();
		} else if (option == 4) { // overall status
			getOverallStatus();
		} else if (option == 5){ // quit program
			quitProgram();
			mainLoop = false;
		}
	} // end of while loop
    
    // call function to display hotel operations to employee
    hotelOperationsSummary();

	// end
	logOut.close();

	system("pause");
    return EXIT_SUCCESS;
}

//***************************************************************
// Definition of function getBuildingPrices.                    *
// returns a pointer to an array that has the building prices   *
//***************************************************************
double * getBuildingPrices() {
	double * prices = new double[NUMBER_OF_BUILDINGS];
	for (int i = 0; i < NUMBER_OF_BUILDINGS; i++) {
		*(prices + i) = (i + 1) * 100;
	}
	return prices;
}

//***************************************************************
// Definition of function loadRooms.                            *
// Loads each rooom's status by opening a status file that is   *
// continuously updated each time this program is run.          *
//***************************************************************
void loadRooms() {
	// file streams
	ifstream stateIn;
	stateIn.open("state.txt"); // contains the status of each room

	/*
     * load the status of each room from last run (if any).
     * If there is anything, will load all room states.
     * Obtained this one line of code from internet
     */
	if (stateIn.peek() != std::ifstream::traits_type::eof()) {
		log("Loaded status of rooms from last run.");

		for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
			for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
				int roomStatus;
				stateIn >> roomStatus;
				rooms[b][r] = roomStatus; // initialize array with room status
			}
		}
	} else {
		log("Loaded status of rooms from last run.");

		for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
			for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
				rooms[b][r] = -1; // initialize array with -1
			}
		}
	}
	stateIn.close(); // close the file
}

//***************************************************************
// Definition of function loadCustomerData.                     *
// Loads each customer's data by opening a data file that is    *
// continuously updated each time this program is run.          *
//***************************************************************
void loadCustomerData() {
    // file streams
	ifstream dataIn;
	dataIn.open("customerData.txt"); // contains customer data

	int ID; // customer's ID
	string name; // customer's name
    
	while (dataIn >> name) {
        
		dataIn >> ID;
        customerIDs[lastID] = ID;
		customerNames[lastID] = name;
        
        lastID++;
	}

	dataIn.close(); // close the file
}

//***************************************************************
// Definition of function getOption.                            *
// Asks the user to choose what kind of hotel assistance        *
// they would like from a menu and returns the corresponding    *
// numerical choice. Input validation on their selection is     *
// present.                                                     *
//***************************************************************
int getOption() {
	int menuSelection = 99999;
	cout << endl << "*************************************" << endl;
    // input loop
	while (menuSelection > 5 || menuSelection < 1) {
		// check if the wrong option message should be printed
		if (menuSelection != 99999) {
			cout << "Please choose a valid option" << endl;
		}
		// prompt/user input
		cout << "How may we assist you?" << endl;
		cout << "	1. Checkin" << endl;
		cout << "	2. Checkout" << endl;
		cout << "	3. Price" << endl;
		cout << "	4. Overall Status" << endl;
		cout << "	5. Quit" << endl;
		cin >> menuSelection;
		cin.ignore();
		cout << endl;
	} // end of while loop

	return menuSelection;
}

//***************************************************************
// Definition of function checkIn.                              *
// Asks the user what building they would like to stay in and   *
// for how many days and then proceeds to calculate and print   *
// a receipt for them, which includes the price per day,        *
// subtotal, taxes, and overall total.                          *
//***************************************************************
void checkIn() {
	// variables
	int building, room; // building number and room number, respectively
	int days; // days at hotel
    char before; // have they stayed at the hotel before

	do {
		getRoom(building, room,
                "What building would you like to stay in",
                "What room would you like to stay in");
		if (rooms[building][room] == -1) break; // check if this room is free
		else cout << "That room is occupied." << endl;
	} while (true);

	// finish checkin process
	do {
		cout << "How many days would you like to stay? ";
		cin >> days;
		cin.ignore();
		if (days <= 0) {
			cout << "ERROR: You have to stay at least one day." << endl;
		}
	} while (days <= 0);

	do {
		cout << "Have you stayed here before? (Y/N) ";
		cin >> before;

		if (tolower(before) == 'y' || tolower(before) == 'n') break;

		cout << "Sorry, that is not a valid input." << endl;
	} while (true);

	if (tolower(before) == 'y') {
		rooms[building][room] = getID(); // save their id number to their room
	} else {
		rooms[building][room] = makeID(); // create new id number and save to their room
	}
    
    printReceipt(buildingPrices[building], days);
    log("Checkin process completed."); // record checkin on the log file
}

//***************************************************************
// Definition of function getID.                                *
// Asks customer for first name and returns their customer ID   *
// if their name was found.                                     *
//***************************************************************
int getID() {
	do {
        // prompt/user input
		string name;
		cout << "What is your first name? ";
		cin >> name;

		// find where the name is stored
		int index = search(customerNames, name);

		if (index != -1) return customerIDs[index];
		else cout << "Sorry, that name was not found in our database." << endl;
	} while (true);
}

//***************************************************************
// Definition of function makeID.                               *
// Makes a new customer ID based off their name and returns ID. *
//***************************************************************
int makeID() {
	int ID = 0;
	char name[30];
	
	// prompt/user input
	do {
		cout << "What is your first name? ";
		cin >> name;

		if (search(customerNames, name) == -1) break;

		cout << "Sorry, that name is in use." << endl;
	} while (true);

	// make the ID number from the name
	for (int i = 0; i < 30; i++) 
		if (name[i] != '\0') 
			ID += static_cast<int>(name[i]); 
        else
            break;

	// check to see if this ID number has been used
	while (search(customerIDs, ID) != -1) ID++;

	// update the arrays
	customerIDs[lastID] = ID;
	customerNames[lastID] = name;
    
    lastID++;

	// sort the arrays
	sortCustomerData();

	return ID;
}

//***************************************************************
// Definition of sortCustomerData.                              *
// Sorts customer names in ascending order using bubble         *
// sort method and also exchanges the proper customer IDs       *
// in a different array to stay parallel with customerNames.    *
//***************************************************************
void sortCustomerData() {
	bool exchange;
	do {
		exchange = false;
		for (int i = 0; i < (lastID - 1); i++) {
			if (customerNames[i] > customerNames[i + 1]) {
				string name = customerNames[i];
				customerNames[i] = customerNames[i + 1];
				customerNames[i + 1] = name;
                
				int ID = customerIDs[i];
				customerIDs[i] = customerIDs[i + 1];
				customerIDs[i + 1] = ID;
				exchange = true;
			}
		}
	} while (exchange == true);
}

//***************************************************************
// Definition of function search.                               *
// Performs a linear search on an integer array and returns     *
// the index where the given ID number is stored. Otherwise -1  *
// is returned.                                                 *
//***************************************************************
int search(int array[NUMBER_OF_IDS], int target) {
	for (int i = 0; i < NUMBER_OF_IDS; i++) if (array[i] == target) return i;
	return -1;
}

//***************************************************************
// Definition of function search (overloaded function).         *
// Performs a binary search on a string array and returns       *
// the index where the given name is stored. Otherwise -1       *
// is returned.                                                 *
//***************************************************************
int search(string array[NUMBER_OF_IDS], string target) {
	int start = 0, end = lastID - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (array[mid] == target) return mid;
		if (array[mid] > target) end = mid - 1;
		else start = mid + 1;
	}

	return -1;
}

//***************************************************************
// Definition of function printReceipt.                         *
// Function is passed the price per night and number of days.   *
// Calculates and prints a receipt containing the subtotal,     *
// tax, and total cost of the stay.                             *
//***************************************************************
void printReceipt(double price, int numDays) {
    // variables
    double subTotal;
    double totalTax;
    double total;

    // calculations
    subTotal = price * numDays;
    totalTax = subTotal * TAX_RATE;
    total = subTotal + totalTax;
    
    // print total/receipt for customer
    cout << endl << fixed << setprecision(2); // 2 decimals
    cout << "Days stayed                " << numDays << endl;
    cout << "Price per day             $" << price << endl << endl;
    cout << "Your subtotal cost is     $" << subTotal << endl;
    cout << "Your tax is               $" << totalTax << endl;
    cout << "-----------------------------------" << endl;
    cout << "Your total is             $" << total << endl;
}

//***************************************************************
// Definition of function checkOut.                             *
// Asks the user which building and room number they stayed in, *
// validates it, and proceeds to successfully check them out    *
// and update the room status.                                  *
//***************************************************************
void checkOut() {
	int building, room; // building number and room number, respectively

	do {
		findRoom(getID(), building, room);
		if (room != -1) break;
		else cout << "Sorry, you are not checked in." << endl;
	} while (true);

    cout << "You have successfully checked out of room ";
    cout << static_cast<char>(building + 65) << (room + 1) << "." << endl;
    cout << "Please come again soon!" << endl;
    
    rooms[building][room] = -1; // mark this room as vacant now
    
    log("Checkout process completed."); // record checkout on the log file
}

//***************************************************************
// Definition of function findRoom.                             *
// Finds the room and building number a particular ID number    *
// is checked in at.                                            *
//***************************************************************
void findRoom(int ID, int & building, int & room) {
	for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
		for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
			if (rooms[b][r] == ID) {
				building = b;
				room = r;
				return;
			}
		}
	}
	building = -1;
	room = -1;
}

//***************************************************************
// Definition of function getPricing.                           *
// Prints the price per night (in USD) of each hotel option.    *
//***************************************************************
void getPricing() {
	cout << fixed << setprecision(2); // 2 decimal places
	cout << "Price per night (in USD)" << endl;

	for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
        cout << "    Building " << static_cast<char>(b + 65);
        cout << " is $" << buildingPrices[b] << endl;
	}

	cout << endl;
	log("Customer inquired about pricing."); // record inquiry on the log file
}

//***************************************************************
// Definition of function getOverallStatus.                     *
// Prints the status of each room in the entire hotel chain.    *
//***************************************************************
void getOverallStatus() {
	for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
		cout << "Building " << static_cast<char>(b + 65) << endl;
		for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
			cout << "    Room " << r + 1 << " is ";
            cout << (rooms[b][r] == -1 ? "Vacant" : "Occupied") << endl;
		}
	}

	cout << endl;
    log("Inquiry about overall status."); // record inquiry on the log file
}

//***************************************************************
// Definition of function quitProgram.                          *
// Tells the user the program is ending and saves the most      *
// up-to-date status of all rooms to a file. Returns a false    *
// boolean.                                                     *
//***************************************************************
void quitProgram() {
	cout << "Ending program..." << endl << endl;
	log("Program ended."); // record program has ended in the log

	ofstream stateOut;
	stateOut.open("state.txt");

	// save the current status of all rooms to a file
	for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
		for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
			stateOut << rooms[b][r] << endl;
		}
	}

	stateOut.close();

	ofstream dataOut;
	dataOut.open("customerData.txt");
	for (int i = 0; i < lastID; i++) {
		dataOut << customerNames[i] << endl;
		dataOut << customerIDs[i] << endl;
	}
	dataOut.close();
}

//***************************************************************
// Definition of function getRoom.                              *
// Function is passed reference variables for building and room *
// number as well as two strings to prompt the user what        *
// to enter. Function will validate their respones and ensure   *
// the proper building and room number are assigned.            *
//***************************************************************
void getRoom(int & buildingNum, int & roomNum, string buildingPrompt, string roomPrompt) {
	do {
        // variable
        char buildingLetter;
        
        // prompt/user input
		cout << buildingPrompt << " (";
		for (int i = 0; i < NUMBER_OF_BUILDINGS - 1; i++) cout << static_cast<char> (65 + i) << ", ";
		cout << static_cast<char> (65 + NUMBER_OF_BUILDINGS - 1) << "): ";
		cin >> buildingLetter;
        
        /*
         * get corresponding building number from building letter (A, B, C, or D).
         * Uses corresponding ASCII code to translate letter to number, where
         * Building A = 0, Building B = 1, Building C = 2, & Building D = 3.
         */
		buildingNum = static_cast<int>(toupper(buildingLetter) - 65);
        
        // prompt/user input
		cout << roomPrompt << " (1 through " << NUMBER_OF_ROOMS << "): ";
		cin >> roomNum;
		roomNum--; // to correspond with correct subscript in arrays

		// input validation function
		if (isValidRoom(buildingNum, roomNum)) break;
        else cout << "Sorry, that is not a valid room." << endl;
	} while (true);
}

//***************************************************************
// Definition of function isValidRoom.                          *
// Function is passed building and room number and validates    *
// whether they are valid for this setup. If valid, will return *
// true. Otherwise, false.                                      *
//***************************************************************
bool isValidRoom(int buildingNum, int roomNum) {
	return (buildingNum >= 0 && buildingNum < NUMBER_OF_BUILDINGS
            && roomNum >= 0 && roomNum < NUMBER_OF_ROOMS);
}

//***************************************************************
// Definition of function log.                                  *
// A simple function that allows us to timestamp our output     *
// file with a descriptive string that is passed to the         *
// function. This allows us to have a history of the parts of   *
// our program that were completed by a customer.               *
//***************************************************************
void log(string input) {
	logOut << "Timestamp: " << input << endl;
}

//***************************************************************
// Definition of function hotelOperationsSummary.               *
// Function prints out the total number of rooms checked out    *
// and vacant that night as well as the total income generated  *
// that night when including tax.                               *
//***************************************************************
void hotelOperationsSummary()
{
    // variables
    int totalRoomsCheckedOut = 0; // accumulator variable for rooms checked out
    double income = 0; // accumulator variable for total income generated
    
    for (int b = 0; b < NUMBER_OF_BUILDINGS; b++) {
        for (int r = 0; r < NUMBER_OF_ROOMS; r++) {
            
            if (rooms[b][r] != -1) { // if hotel room is occupied
                totalRoomsCheckedOut++;
                income += (buildingPrices[b] * (1 + TAX_RATE)); // add cost of one night
            }
        }
    }
    
    // display results to employee
    cout << "-------------------Hotel Operations Summary-------------------";
    cout << endl;
    cout << "-----------------------EMPLOYEES ONLY-------------------------";
    cout << endl << endl;
    cout << "Total number of rooms checked out tonight: " << totalRoomsCheckedOut;
    cout << endl << endl;
    
    if (totalRoomsCheckedOut == NUMBER_OF_BUILDINGS * NUMBER_OF_ROOMS) {
        cout << "Operating at full capacity!" << endl << endl;
    }
    cout << "Total number of rooms vacant tonight: ";
    cout << (NUMBER_OF_BUILDINGS * NUMBER_OF_ROOMS) - totalRoomsCheckedOut;
    cout << fixed << setprecision(2) << endl << endl; // 2 decimals
    cout << "Total income generated tonight: $" << income << endl << endl;
}