/*
 * menu.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Rishad Yunus
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "train.h"
using namespace std;



void error(string message){
	cout << "\n***************************" <<endl;
	cout << "ERROR: " << message << endl;
	cout << "Please try again!!"<<endl;
	cout << "***************************\n" <<endl;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int getChoice(int max){
	while (true){
		string choice;
		cout << "\nEnter your choice: ";
		cin >> choice;
		if (is_number(choice)){
			if (is_number(choice) && stoi(choice) <= max && stoi(choice) > 0){
				return stoi(choice);
			}
		}


		error("INVALID CHOICE");
	}
}



int passengerMenu(){
	cout << "\nPassenger Menu--" <<endl;
	cout << "----------------------------------------------------" << endl;
	cout << "1. Display Subway Stations" << endl;
	cout << "2. Search for Subway Station" << endl;
	cout << "3. View Subway Station Details Between Cities" << endl;
	cout << "4. Purchase Subway Ticket" << endl;
	cout << "5. View Purchase History" << endl;
	cout << "6. Delete Purchase Transaction" << endl;
	cout << "7. Exit Menu" << endl;
	return getChoice(7);

}

int adminMenu(){
	cout << "\nAdmin Menu--" <<endl;
	cout << "----------------------------------------------------" << endl;
	cout << "1. Add New Station" << endl;
	cout << "2. Edit Current Station" << endl;
	cout << "3. View Purchase" << endl;
	cout << "4. Sort Purchase" << endl;
	cout << "5. Search Customer Ticket Purchase Details" << endl;
	cout << "6. Edit Customer Ticket Purchase" << endl;
	cout << "7. Delete Customer Ticket Purchase" << endl;
	cout << "8. Exit Menu" << endl;
	return getChoice(8);
}


/*
struct TrainInfo{
	string stationName;
	int trainNum;			//need to make this append itself
	int distance;
	int distanceLast;
	int travelTime;
	int travelTimeLast;
	double price;
	double priceLast;
	string stationNameLast;
	string stationNameNext;
	string nearbySpots;
	bool movingRight;
}T;

TrainInfo addStation(SubwayList subs){
	cout << "Add Subway Station" << endl;
	cout << "1. Before "<<subs.stationNameHead() << " Station" <<endl;
	cout << "2. After " <<subs.stationNameTail() << " Station" <<endl;
	cout << "3. Back" <<endl;
	int choice = getChoice(3);

	if (choice == 1) {
		string stationName;
		cout << "Enter the new Station Name: ";
		cin.ignore(80, '\n');
		getline(cin, T.stationName);

		cout << "Enter the distance to next Station: ";
		cin >> T.distance;

		cout << "Enter the time to the next Station: ";
		cin >> T.travelTime;

		cout << "Enter the Cost to the next Station: ";
		cin >> T.price;

		cout << "Enter nearby Spots" ;
		cin.ignore(80, '\n');
		getline(cin, T.nearbySpots);

		//incomplete!!!!!!!!!!!
		T.movingRight = true;
		T.distanceLast = 0;
		T.travelTimeLast = 0;
		T.priceLast = 0;
		T.stationNameLast = "None";
		T.stationNameNext = subs.stationNameHead();
		return T;
		//subs.insertAtBegining(stationName, distance,travelTime,0,0,price,0);			//need to add input form for this!!!
	}else if (choice == 2){
		string stationName;
		cout << "Enter the new Station Name: ";
		cin.ignore(80, '\n');
		getline(cin, T.stationName);

		cout << "Enter the distance from the Last Station: ";
		cin >> T.distanceLast;

		cout << "Enter the time from the Last Station: ";
		cin >> T.travelTimeLast;

		cout << "Enter the Cost from the Station: ";
		cin >> T.priceLast;

		cout << "Enter nearby Spots" ;
		cin.ignore(80, '\n');
		getline(cin, T.nearbySpots);

		T.movingRight = false;
		T.distance = 0;
		T.travelTime = 0;
		T.price = 0;
		T.stationNameLast = subs.stationNameTail();
		T.stationNameNext = "None";
		return T;
		//subs.insertAtEnd(stationName, 0,0,distance,travelTime,0,price);
		}
	else return T;
}*/

#endif /* MENU_H_ */
