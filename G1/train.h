/*
 * train.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Rishad Yunus
 */

#ifndef TRAIN_H_
#define TRAIN_H_

#include <iostream>
#include "aes.h"
#include "menu.h"
using namespace std;

//#define time (19 * 60);
#define trainTime 30;
void error(string message);
int getChoice(int choice);
/*typedef struct Station{
	trainTime = 30;
	time = 19 * 60;
	int totalStationNumber;
	int trainNum = 1;
	int trainFinish = 60;
} * nodePtr;

*/
class SubwayList
{
	//reasoning for double linked list is because the train can move in both directions
	//since thats the case we would want to traverse it both forward and backwards
private:
	typedef struct Station{
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

		Station *next;
		Station *prev;

	} * nodePtr;

	nodePtr head;
	nodePtr tail;

	int totalStationNumber;
	int totalTime;
	int size;

public:
	SubwayList()
    {
        this->size = 0;
        this->totalStationNumber = 0;
        this->totalTime = 0;
        this->head = nullptr;
        this->tail = nullptr;

        //initialize data
        insertAtEnd("Titiwangsa", 4,3,0,0,0.4,0,"None","PWTC","rome,england,france");
        insertAtEnd("PWTC", 8,7,4,3,0.8,0.4,"Titiwangsa","Sultan Ismail","rome,england,france");
        insertAtEnd("Sultan Ismail",8,7,8,7,0.8,0.8,"PWTC","Majilis Jamek","britian,bangladesh,egypt");
        insertAtEnd("Majilis Jamek", 6,5,8,7,0.6,0.8,"Sultan Ismail","Plaza Rakyat","britian,bangladesh,egypt");
        insertAtEnd("Plaza Rakyat", 10, 9,6,5,1,0.6,"Majilis Jamek","Hang Tuah","britian,bangladesh,egypt");
        insertAtEnd("Hang Tuah", 5,4,10,9,0.5,1,"Plaza Rakyat","Pudu","britian,bangladesh,egypt");
        insertAtEnd("Pudu", 5,4,5,4,0.5,0.5,"Hang Tuah","Chan Sow Lin","britian,bangladesh,egypt");
        insertAtEnd("Chan Sow Lin", 0,0,5,4,0,0.5,"Chan Sow Lin","None","britian,bangladesh,egypt");

    }

	void insertAtEnd(  string stationName, int distance,int travelTime, int distanceLast, int travelTimeLast, double price, double priceLast,
			string stationNameLast,string stationNameNext, string nearbySpots)
	{
		nodePtr newNode = new Station;

		newNode->stationName = stationName;
		newNode->distance = distance;
		newNode->travelTime = travelTime;
		newNode->distanceLast = distanceLast;
		newNode->travelTimeLast = travelTimeLast;
		newNode->price = price;
		newNode->priceLast = priceLast;
		newNode->stationNameLast = stationNameLast;
		newNode->stationNameNext = stationNameNext;
		newNode->nearbySpots = nearbySpots;

		newNode->prev = tail;
		tail = newNode;
		//node handling
		if ( head == nullptr ) {
			head = newNode;
			newNode->trainNum = 1;
		}else {
			newNode->next = nullptr;
			newNode->prev->next = newNode;
			newNode->trainNum = newNode->prev->trainNum+1;
		}
		size++;
		totalStationNumber++;
		totalTime += travelTime;
		sortTrainNum();
		//cout << totalTime << " ";

	}
	nodePtr getHead(){
		return head;
	}

	void sortTrainNum()
	{
	nodePtr curr = head;
	nodePtr nxt = curr->next;
	int temp;

	while (curr->next !=nullptr) {
		while (nxt !=nullptr){
			if (nxt->trainNum < curr->trainNum){
				temp = curr->trainNum;
				curr->trainNum = nxt->trainNum;
				nxt->trainNum = temp;
			}
			nxt = nxt->next;
		 }
		curr = curr->next;
		nxt = curr->next;
	}
	}

	void insertAtBegining( string stationName, int distance,int travelTime, int distanceLast, int travelTimeLast, double price, double priceLast,
			string stationNameLast,string stationNameNext, string nearbySpots)
	{
		nodePtr newNode = new Station;

		newNode->stationName = stationName;
		newNode->distance = distance;
		newNode->travelTime = travelTime;
		newNode->distanceLast = distanceLast;
		newNode->travelTimeLast = travelTimeLast;
		newNode->price = price;
		newNode->priceLast = priceLast;
		newNode->stationNameLast = stationNameLast;
		newNode->stationNameNext = stationNameNext;
		newNode->nearbySpots = nearbySpots;



		newNode->next = head;
		head = newNode;
		//node handling
		newNode->prev = nullptr;
		newNode->trainNum = tail->trainNum+1;

		size++;
		totalStationNumber++;
		totalTime += travelTime;
		//cout << totalTime << " ";
		sortTrainNum();
	}


	int getSize()
	    {
	        return size;
	    }
	string stationNameHead(){
		return head->stationName;
	}

	string stationNameTail(){
			return tail->stationName;
		}

	void showForward()
	    {
	    	nodePtr curr = head;
	        cout << "\n         --- SUBWAY STATION LIST --- " << endl;
	        while( curr != nullptr)
	        {
	        	if (curr == tail) {
					cout << curr->trainNum << "] " << "Station Name: " <<curr->stationName << endl;;
					cout << "----------------------------------------------------" << endl;
					cout << "FINAL STATION!! " << endl;
				}
	        	else
	        	{
					cout << curr->trainNum << "] " << "Station Name: " <<curr->stationName << endl;;
					cout << "----------------------------------------------------" << endl;
					cout << "Last station name: " << curr->stationNameLast << endl;
					cout << "Next station name: " << curr->stationNameNext << endl;
					cout << "Distance to next station: " << curr->distance << " KM" << endl;
					cout << "Distance from last station: " << curr->distanceLast << " KM" << endl;
					cout << "Time to next station: " << curr->travelTime << " mins" <<  endl;
					cout << "Time from last station: " << curr->travelTimeLast << " mins" <<  endl;
					cout << "Cost to next station: RM " << curr->price << endl;
					cout << "Cost from last station: RM " << curr->priceLast << endl;
					cout << "Nearby spots: " << curr->nearbySpots << endl;
	        	}

	            cout<<endl;
	            curr = curr->next;
	        }
	    }

	void showBackwards()
		    {
		    	nodePtr curr = tail;
		        cout << "\n         --- SUBWAY STATION LIST --- " << endl;
		        while(true)
		        {
		        	if (curr == head) {
		        		cout << curr->trainNum << "] " << "Station Name: " <<curr->stationName << endl;;
						cout << "----------------------------------------------------" << endl;
						cout << "FINAL STATION!! " << endl;
		        	}
		        	else
		        	{
		/*------------->*/				cout << curr->trainNum << "] " << "Station Name: " <<curr->stationName << endl;;
						cout << "----------------------------------------------------" << endl;
						cout << "Last station name: " << curr->stationNameLast << endl;
						cout << "Next station name: " << curr->stationNameNext << endl;
						cout << "Distance to next station: " << curr->distanceLast << " KM" << endl;
						cout << "Distance from last station: " << curr->distanceLast << " KM" << endl;
						cout << "Time to next station: " << curr->travelTimeLast << " mins" << endl;
						cout << "Time from last station: " << curr->travelTimeLast << " mins" <<  endl;
						cout << "Cost to next station: RM " << curr->priceLast <<  endl;
						cout << "Cost from last station: RM " << curr->priceLast << endl;
						cout << "Nearby spots: " << curr->nearbySpots << endl;
		        	}

					cout<<endl;
					if (curr->prev == nullptr) break;
					curr = curr->prev;
		        }
		    }



	void addStation(){
		int getChoice(int choice);
		Station T;
		cout << "Add Subway Station" << endl;
		cout << "1. Before "<<head->stationName << " Station" <<endl;
		cout << "2. After " <<tail->stationName << " Station" <<endl;
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

			cout << "Enter nearby Spots: " ;
			cin.ignore(80, '\n');
			getline(cin, T.nearbySpots);

			//incomplete!!!!!!!!!!!
			//T.movingRight = true;
			T.distanceLast = 0;
			T.travelTimeLast = 0;
			T.priceLast = 0;
			T.stationNameLast = "None";
			T.stationNameNext = head->stationName;

			head->stationNameLast = T.stationName;
			insertAtBegining(T.stationName, T.distance, T.travelTime, T.distanceLast, T.travelTimeLast, T.price, T.priceLast,T.stationNameLast,T.stationNameNext,T.nearbySpots);

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

			cout << "Enter nearby Spots: " ;
			cin.ignore(80, '\n');
			getline(cin, T.nearbySpots);

			//T.movingRight = false;
			T.distance = 0;
			T.travelTime = 0;
			T.price = 0;
			T.stationNameLast = tail->stationName;
			T.stationNameNext = "None";

			tail->stationNameNext = T.stationName;
			insertAtEnd(T.stationName, T.distance, T.travelTime, T.distanceLast, T.travelTimeLast, T.price, T.priceLast,T.stationNameLast,T.stationNameNext,T.nearbySpots);
			//subs.insertAtEnd(stationName, 0,0,distance,travelTime,0,price);
			}else {
				cout << endl;
			}

	}
	void search() {
		cout << "\n----Search Train details-----"<<endl;
		int id;
		cout << "Train ID:" ;
		cin>>id;
		bool check = false;
		nodePtr curr = head;
		while (curr!=nullptr) {
			if (curr->trainNum == id) {
				cout << "\nRESULTS---" <<endl;
				cout << curr->trainNum << "] " << "Station Name: " <<curr->stationName << endl;;
				cout << "----------------------------------------------------" << endl;
				cout << "Last station name: " << curr->stationNameLast << endl;
				cout << "Next station name: " << curr->stationNameNext << endl;
				cout << "Distance to next station: " << curr->distance << " KM" << endl;
				cout << "Distance from last station: " << curr->distanceLast << " KM" << endl;
				cout << "Time to next station: " << curr->travelTime << " mins" <<  endl;
				cout << "Time from last station: " << curr->travelTimeLast << " mins" <<  endl;
				cout << "Cost to next station: RM " << curr->price << endl;
				cout << "Nearby spots: " << curr->nearbySpots << endl;
				pause();
				spacer();
				check = true;
				break;
			}
			curr=curr->next;
		}
		if (!check) {
			error("TRAIN STATION DOES NOT EXIST");
			pause();
		}

	}

	void viewStationDetails() {			//Only the fare, travel time between cities, station name can be modified
		showForward();
		cout << "\nSelect the First Station" << endl;
		int first = getChoice(getSize());
		cout << "\nSelect the Second Station" << endl;
		int last = getChoice(getSize());



		string stationNameF;
		string stationNameL;
		int distanceBtw = 0;
		int timeBtw = 0;
		double fair = 0;
		if (first == last) {
			error("Same station!!");
			pause();

		}else if (first > last) {
			nodePtr curr = tail;
			bool start = false;

			while (curr!=nullptr){
				if (curr->trainNum == first) {
					stationNameF = curr->stationName;
					start = true;
				}
				if (start) {

				distanceBtw += curr->distanceLast;
				timeBtw += curr->travelTimeLast;
				fair += curr->priceLast;
				}

				if (curr->prev->trainNum == last){
					stationNameL = curr->stationName;
					break;
				}
				curr = curr->prev;
			}
			cout << "----------------------------------------------------" << endl;
			cout << "FROM: " << stationNameF ;
			cout << " To  : " << stationNameL << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "DIstance = " << distanceBtw <<" APART" <<endl;
			cout << "Travel time = " << timeBtw << " mins" <<endl;
			cout << "Travel cost = RM " << fair<< endl;
			pause();

		}else {
			nodePtr curr = head;
			bool start = false;

			while (curr!=nullptr){
				if (curr->trainNum == first) {
					stationNameF = curr->stationName;
					start = true;
				}
				if (start) {

				distanceBtw += curr->distance;
				timeBtw += curr->travelTime;
				fair += curr->price;
				}

				if (curr->next->trainNum == last){
					stationNameL = curr->next->stationName;
					break;
				}

				curr = curr->next;
			}
			cout << "----------------------------------------------------" << endl;
			cout << "FROM: " << stationNameF ;
			cout << " To  : " << stationNameL << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "DIstance = " << distanceBtw <<" KM" <<endl;
			cout << "Travel time = " << timeBtw << " mins" <<endl;
			cout << "Travel cost = RM " << fair<< endl;
			pause();
		}



	}

	void editStation() {
		nodePtr curr = head;
		showForward();
		cout << "\n---Select a station to edit---" <<endl;
		int choice = getChoice(getSize());
		while (curr!=nullptr) {
			if (curr->trainNum == choice) {
				break;
			}
			curr = curr->next;
		}
		double price;
		double priceLast;
		int travelTime;
		int travelTimeLast;
		string stationName;

		cout << endl;

		if (curr == head) {
			cout << "Enter new price to " << curr->next->stationName << " (next station): ";
			cin >> price;
			cout << "Enter the new travel time to " << curr->next->stationName << " (next station): ";
			cin >> travelTime;
			cout << "Enter new station name: ";
			cin.ignore(80, '\n');
			cin >> stationName;

			cout << "----------------------------------------------------" << endl;
			cout << "Station Name: " << stationName <<endl;
			cout << "Travel time to " << curr->next->stationName << ": " << travelTime << " mins" <<endl;
			cout << "Price to "  << curr->next->stationNameLast << ": RM" << price <<endl;
			cout << "----------------------------------------------------\n" << endl;
			pause();

			curr->travelTime = travelTime;
			curr->price = price;

		}else if(curr == tail) {
			cout << "Enter new price to " << curr->prev->stationName << " (last station): ";
			cin >> priceLast;
			cout << "Enter the last travel time to " << curr->prev->stationName << " (last station): ";
			cin >> travelTimeLast;
			cout << "Enter new station name: ";
			cin.ignore(80, '\n');
			cin >> stationName;

			cout << "----------------------------------------------------" << endl;
			cout << "Station Name: " << stationName <<endl;
			cout << "Travel time From " << curr->prev->stationNameLast << ": " << travelTimeLast << " mins" <<endl;
			cout << "Price from "  << curr->prev->stationNameLast << ": RM" << priceLast <<endl;
			cout << "----------------------------------------------------\n" << endl;
			pause();

			curr->travelTimeLast = travelTimeLast;
			curr->priceLast = priceLast;
		}
		else
		{
		cout << "Enter new price to " << curr->next->stationName << " (next station): ";
		cin >> price;
		cout << "Enter new price to " << curr->prev->stationName << " (last station): ";
		cin >> priceLast;
		cout << "Enter the new travel time to " << curr->next->stationName << " (next station): ";
		cin >> travelTime;
		cout << "Enter the last travel time to " << curr->prev->stationName << " (last station): ";
		cin >> travelTimeLast;
		cout << "Enter new station name: ";
		cin.ignore(80, '\n');
		cin >> stationName;

		cout << "----------------------------------------------------" << endl;
		cout << "Station Name: " << stationName <<endl;
		cout << "Travel time to " << curr->next->stationName << ": " << travelTime << " mins" <<endl;
		cout << "Travel time From " << curr->prev->stationNameLast << ": " << travelTimeLast << " mins" <<endl;
		cout << "Price to "  << curr->next->stationNameLast << ": RM" << price <<endl;
		cout << "Price from "  << curr->prev->stationNameLast << ": RM" << priceLast <<endl;
		cout << "----------------------------------------------------\n" << endl;
		pause();


		curr->travelTime = travelTime;
		curr->travelTimeLast = travelTimeLast;
		curr->price = price;
		curr->priceLast = priceLast;
		}
		curr->stationName = stationName;
	}



	//------------------------purchase related
	string getStationName(int trainNum){
		nodePtr curr = head;
		while (curr!=nullptr) {
			if (curr->trainNum == trainNum){
				return curr->stationName;
			}
			curr = curr->next;
		}
		return "Never happends";
	}

	double getAmount(int first, int last){

		if (first < last ){
			nodePtr curr = head;
			double amount = 0;
			bool start = false;
			while (curr!=nullptr){
				if (curr->trainNum == first) {
					start = true;
				}
				if (start) {
					amount+=curr->price;
				}
				if (curr->next->trainNum == last) {
					return amount;
				}
				curr = curr->next;
			}

		}else if (first > last){
			nodePtr curr = tail;
			double amount = 0;
			bool start = false;
			while (curr!=nullptr){
				if (curr->trainNum == first) {
					start = true;
				}
				if (start) {
					amount+= curr->priceLast;
				}
				if (curr->prev->trainNum == last) {
					return amount;
				}
				curr = curr->prev;
			}
		}
		return 0;

	}




};



#endif /* TRAIN_H_ */
