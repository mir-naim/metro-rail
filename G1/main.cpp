/*
 * main.cpp
 *
 *  Created on: Nov 2, 2022
 *      Author: Rishad Yunus
 */
#include <iostream>
#include <cctype>
#include "menu.h"
#include "train.h"
#include "aes.h"
#include "transactions.h"
using namespace std;

//struct TrainInfo R;

int main() {
	int passengerMenu();

	 // test case for passenger
/*
PassengerList passenger;
passenger.insertAtEnd("6", "name", 12, 12, 12,"time");
passenger.insertAtEnd("1", "name", 12, 12, 12,"time");
passenger.insertAtEnd("5", "name", 12, 12, 12,"time");
passenger.insertAtEnd("3", "name", 12, 12, 12,"time");
passenger.insertItemAt(2, "4", "name", 12, 12, 12,"time");
passenger.showForward();
passenger.sort();
cout << "sorted" <<endl;
passenger.showForward();
*/

	SubwayList subs;
	TransactionList trans;

	while (true) {
		cout << "   ---USER LEVEL---" <<endl;
		cout << "1. ADMIN" << endl;
		cout << "2. PASSENGER" << endl;
		int uchoice = getChoice(2);

		if (uchoice==1)
		{
			bool check = false;
			while (true) {
				if (check == false){
					string username, password;
					cout << "\n\nUsername: " <<endl;
					cin.ignore(80, '\n');
					getline(cin, username);
					cout << "Password: " <<endl;
					//cin.ignore(80, '\n');
					getline(cin, password);

					if ((username != "admin" && password != "admin") || username == "" || username == " " || password == "" || password == " "){
							error("INCORRECT USERNAME OR PASSWORD!!");
							break;
					}
					check = true;
				}
				else{
					int choice = adminMenu();
					spacer();
					if (choice == 8) break;
					switch (choice) {
						case 1:
						{
							subs.addStation();
							//1. Add station
						}break;

						case 2:
						{
							subs.editStation();
							//2. Edit current subway stations’ information (Only the fare, travel time between cities, station name can be modified)
						}break;

						case 3:
						{

							trans.showFoward();
							pause();
							spacer();
							//3. Sort purchase – Sort the purchase transactions based on passenger name in ascending order
						}break;

						case 4:
						{
							cout << "--Sort Purchase Menu-- " << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "1. Sort purchase records in Ascending Order."<<endl;
							cout << "2. Sort Purchase records in Descending order." << endl;
							cout << "3. Back" << endl;

							int choice = getChoice(3);
							if (choice == 1) {
								trans.sortAsc();
								cout << "Records have been sorted Successfully!!!" <<endl;
								pause();
							}else if (choice == 2) {
								trans.sortDesc();
								cout << "Records have been sorted Successfully!!!" <<endl;
								pause();
							}else{
								cout <<endl;
							}
							//4. Sort purchase – Sort the purchase transactions based on passenger name in ascending order

						}break;

						case 5:
						{
							trans.displaySearch(trans.search());
							//5. Search specific customer ticket purchase information

						}break;

						case 6:
						{
							trans.editTransactions();
							//6. Edit specific customer ticket purchase information (Cannot edit customer information, only the travel information on the ticket)

						}break;

						case 7:
						{
							trans.deleteTransaction();
							//7. Delete specific customer ticket purchase information
						}break;

						case 8:
						{
							check = false;
							break;
						}
					}
					}

			}
		}else
		{
			while (true){
				int choice = passengerMenu();
				spacer();
				if (choice == 7) break;
				switch (choice) {
					case 1:
					{
						cout << "   --Select a travel route--" << endl;
						cout << "1. "<< subs.stationNameHead() << " --> " << subs.stationNameTail() << endl;
						cout << "2. "<< subs.stationNameTail() << " --> " << subs.stationNameHead() << endl;
						int ch = getChoice(2);
						//SubwayList subs;
						if (ch == 1) {
							subs.showForward();
							pause();
							spacer();
						}else {
							subs.showBackwards();
							pause();
							spacer();
						}
						//1. Display Subway Stations
					}break;

					case 2:
					{
						subs.search();
						//2. Search for Subway Station
					}break;

					case 3:
					{
						subs.viewStationDetails();
						//3. View Subway Station Details Between Cities
					}break;

					case 4:
					{
						trans.purchaseTicket(subs);
						//4. Purchase Subway Ticket
					}break;

					case 5:
					{
						trans.showFoward();
						//5. View Purchase History
					}break;

					case 6:
					{
						trans.deleteTransaction();
						//6. Delete Purchase Transaction
					}break;

				}
			}
		}
	}
	/*
	SubwayList subs;
	subs.showForward();
	cout << "++++++++++++++++++++++++++++++++++++++" <<endl;
	subs.showBackwards();
*/
	return 0;

}






