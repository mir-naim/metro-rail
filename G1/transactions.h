/*
 * transactions.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Rishad Yunus
 */

#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_

#include <iostream>
#include<cstdlib>
#include <algorithm>
#include "train.h"
#include "aes.h"
#include "menu.h"

using namespace std;
//SubwayList subs;

int getChoice(int choice);

class TransactionList
{
private:
	typedef struct Transaction{
		int transID; // same		//**
		int ticketID; //same T+id    //**
		string startName;            //**
		string destName;             //**
		double amount; //cost		//**
		string departTime;//journey time
		string arrivalTime;// estimated time
		string dateTime;               //**
		string custName;              //**
		string custPassport;          //**


		Transaction * next;
		Transaction * prev;
	}*nodePtr;

	nodePtr head;
	nodePtr tail;
	int size;
	int countID; //keeps adding regardless of size

public:
	TransactionList()
    {
        this->size = 0;
        this->countID =0;
        this->head = nullptr;
        this->tail = nullptr;
    }

	int getID(){
		return rand();
	}

	void purchaseTicket(SubwayList subs) {
		Transaction T;
		string getStationName(int trainNum);

		subs.showForward();
		cout << "\n   ---Ticket Purchase---"<<endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Select your departure station ";
		int departure = getChoice(subs.getSize());

		cout << "Select your destination station: ";
		int destination = getChoice(subs.getSize());
		string custName;
		cout << "Enter your name: ";
		cin.ignore(80, '\n');
		getline(cin, custName);
		string passport;
		cout << "Enter your IC/Passport Number: ";
		//cin.ignore(80, '\n');
		getline(cin, passport);

		void  toUpperCase(std::string& str);
		T.custName = custName;  //make this upper or lower case for sort
		T.custPassport = passport;


		T.startName = subs.getStationName(departure);
		T.destName = subs.getStationName(destination);
		T.transID = getID();
		T.ticketID = getID();
		T.amount = subs.getAmount(departure, destination);
		T.arrivalTime = "NA";
		T.departTime = "NA";
		T.dateTime = "NA";

		cout << "\n\n----------------------------------------------------" << endl;
		cout << "                     RECIEPT" <<endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Ticket ID: " << T.ticketID <<endl;
		cout << "Name: " << T.custName <<endl;
		cout << "Passport: " <<T.custPassport << endl;
		cout << "Price: RM " << T.amount << endl;
		cout << "Departure Time: " <<T.departTime << endl;
		cout << "Arrival Time: " <<T.arrivalTime << endl;
		cout << "DATE: " <<T.dateTime << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "                    PAY NOW!!!" <<endl;
		cout << "----------------------------------------------------" << endl;
		pause();

		addTransaction(T.transID, T.ticketID, T.startName,T.destName, T.amount, T.dateTime, T.departTime, T.custName,T.custPassport);

		//addData()

	}
	void addTransaction(int transID, int ticketID,string startName, string destName, double amount, string dateTime, string departTime, string custName, string custPassport ){
		nodePtr newNode = new Transaction;
		if (head ==nullptr) {
			head = newNode;
		}
		else if (tail == nullptr) {
			head->next = newNode;
			tail = newNode;
			newNode->prev = head;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

		size++;
		newNode->transID = transID;
		newNode->ticketID = ticketID;
		newNode->startName = startName;
		newNode->destName = destName;
		newNode->amount = amount;
		newNode->dateTime = dateTime;
		newNode->departTime = departTime;
		newNode->custName = custName;
		newNode->custPassport = custPassport;

	}

	void showFoward() {
		if (head == nullptr) {
			error("NO TRANSACTION MADE!!");
		}
		else {
			nodePtr curr = head;
			while (curr!=nullptr){
				cout << "----------------------------------------------------" << endl;
				cout << "Transaction ID: " << curr->transID <<endl;
				cout << "Ticket ID: " << curr->ticketID <<endl;
				cout << "Name: "<< curr->custName<<endl;
				cout << "Passport: " <<curr->custPassport<<endl;
				cout << "Departing: "<<curr->startName << " Station" <<endl;
				cout << "Arrival:" << curr->destName << " Station" << endl;
				cout << "Fair: RM " << curr->amount <<endl;
				cout << "Date and Time: " << curr->dateTime <<endl;
				cout << "Departing Time: "<< curr->departTime<<endl;
				cout << "----------------------------------------------------" << endl;
				cout << endl;
				curr=curr->next;
			}
			//pause();
		}
	}

	void sortAsc() {
		nodePtr curr = head;
		nodePtr nxt = curr->next;
		Transaction temp;
		while (curr->next !=nullptr) {			//selection sort algorithm
			while (nxt !=nullptr){
				if (nxt->custName < curr->custName){
					cout << nxt->custName << " REPLACES " << curr->custName <<endl;

					temp = *(curr);
					curr->transID = nxt->transID;
					curr->ticketID = nxt->ticketID;
					curr->startName = nxt->startName;
					curr->destName = nxt->destName;
					curr->amount = nxt->amount;
					curr->departTime = nxt->departTime;
					curr->arrivalTime = nxt->arrivalTime;
					curr->dateTime = nxt->dateTime;
					curr->custName = nxt->custName;
					curr->custPassport = nxt->custPassport;

					nxt->transID = temp.transID;
					nxt->ticketID = temp.ticketID;
					nxt->startName = temp.startName;
					nxt->destName = temp.destName;
					nxt->amount = temp.amount;
					nxt->departTime = temp.departTime;
					nxt->arrivalTime = temp.arrivalTime;
					nxt->dateTime = temp.dateTime;
					nxt->custName = temp.custName;
					nxt->custPassport = temp.custPassport;

				}
				nxt = nxt->next;
			 }
			curr = curr->next;
			nxt = curr->next;
		}
		showFoward();
		pause();

	}

	void sortDesc(){
		nodePtr curr = head;
		nodePtr nxt = curr->next;
		Transaction temp;
		while (curr->next !=nullptr) {			//selection sort algorithm
			while (nxt !=nullptr){
				if (nxt->custName > curr->custName){

					temp = *(curr);
					curr->transID = nxt->transID;
					curr->ticketID = nxt->ticketID;
					curr->startName = nxt->startName;
					curr->destName = nxt->destName;
					curr->amount = nxt->amount;
					curr->departTime = nxt->departTime;
					curr->arrivalTime = nxt->arrivalTime;
					curr->dateTime = nxt->dateTime;
					curr->custName = nxt->custName;
					curr->custPassport = nxt->custPassport;

					nxt->transID = temp.transID;
					nxt->ticketID = temp.ticketID;
					nxt->startName = temp.startName;
					nxt->destName = temp.destName;
					nxt->amount = temp.amount;
					nxt->departTime = temp.departTime;
					nxt->arrivalTime = temp.arrivalTime;
					nxt->dateTime = temp.dateTime;
					nxt->custName = temp.custName;
					nxt->custPassport = temp.custPassport;

				}
				nxt = nxt->next;
			 }
			curr = curr->next;
			nxt = curr->next;
		}
		showFoward();
		pause();
	}
	nodePtr search() {
		cout << "----------------------------------------------------" << endl;
		cout << "\nSearch Name: " <<endl;
		string custName;
		cin.ignore(80, '\n');
		getline(cin, custName);

		nodePtr curr = head;
		while (curr!=nullptr){
			if (curr->custName == custName){
				return curr;
			}
			curr = curr->next;
		}
		error("TRANSACTION NOT FOUND");
		return nullptr;
	}

	void displaySearch(nodePtr searched){
		nodePtr curr = searched;
		cout << "----------------------------------------------------" << endl;
		cout << "Transaction ID: " << curr->transID <<endl;
		cout << "Ticket ID: " << curr->ticketID <<endl;
		cout << "Name: "<< curr->custName<<endl;
		cout << "Passport: " <<curr->custPassport<<endl;
		cout << "Departing: "<<curr->startName << " Station" <<endl;
		cout << "Arrival:" << curr->destName << " Station" << endl;
		cout << "Fair: RM " << curr->amount <<endl;
		cout << "Date and Time: " << curr->dateTime <<endl;
		cout << "Departing Time: "<< curr->departTime<<endl;
		cout << "----------------------------------------------------" << endl;
		cout << endl;
		pause();
	}

	void printReciept(Transaction &pointer){
		nodePtr curr = &pointer;
		cout << "\n\n----------------------------------------------------" << endl;
		cout << "                     RECIEPT" <<endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Ticket ID: " << curr->ticketID <<endl;
		cout << "Name: " << curr->custName <<endl;
		cout << "Passport: " <<curr->custPassport << endl;
		cout << "Price: RM " << curr->amount << endl;
		cout << "Departure Time: " <<curr->departTime << endl;
		cout << "Arrival Time: " <<curr->arrivalTime << endl;
		cout << "DATE: " <<curr->dateTime << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "                    PAY NOW!!!" <<endl;
		cout << "----------------------------------------------------" << endl;
		pause();
	}

	void deleteTransaction() {
		nodePtr delPtr = search();
		cout <<endl;

		if (delPtr == nullptr) {
			error("TRANSACTION DOES NOT EXIST");
		}
		else if (size < 1) {
				error("LIST NOT FOUND!!");

		}
		else
		{
			nodePtr nxt = delPtr->next;
			nodePtr lst = delPtr->prev;

			//nodePtr delPtr = new Transaction;
			//delPtr = NULL;
			if (head  == delPtr ) {
				cout << "----------------------" <<endl;
				cout << "#" << delPtr->custName << ": DELETED1!" << endl;
				cout << "----------------------\n" <<endl;
				if (head->next != nullptr) {
					head->next = nullptr;
					head->prev = nullptr;
				}
				head = head->next;
				delete delPtr;
			}
			else if (tail == delPtr) {
				cout << "----------------------" <<endl;
				cout << "#" << delPtr->custName << ": DELETED2!" << endl;
				cout << "----------------------\n" <<endl;
				if(tail->prev != nullptr){
					lst->next = nullptr;
					tail = lst;
				}
				delete delPtr;
			}
			else
			{
				cout << "----------------------" <<endl;
				cout << "#" << delPtr->custName << ": DELETED3!" << endl;
				cout << "----------------------\n" <<endl;
				lst->next = nxt;
				nxt->prev = lst;
				delete delPtr;
			}
		}


		}

	void editTransactions() {
			nodePtr curr = head;
			showFoward();
			cout << "\n---Select Transactions to edit---" <<endl;
			int choice = getChoice(getID());
			while (curr!=nullptr) {
				if (curr->ticketID == choice) {
					break;
				}
				curr = curr->next;
			}
			string startName;
			string destName;
			double amount;
			//6. Edit specific customer ticket purchase information (Cannot edit customer information, only the travel information on the ticket)
			cout << endl;

			if (curr == head) {
				cout << "Enter new Departing Station " << curr->next->startName;
				cin >> startName;
				cout << "Enter the new Arrival Station to " << curr->next->destName;
				cin >> destName;
				cout << "Enter new amount: ";
				cin.ignore(80, '\n');
				cin >> amount;

				cout << "----------------------------------------------------" << endl;
				cout << "New Departing Station: " << startName <<endl;
				cout << "New Arrival Station " << destName <<endl;
				cout << "New Price : RM" << amount <<endl;
				cout << "----------------------------------------------------\n" << endl;
				pause();

				curr->startName = startName;
				curr->destName = destName;
				curr->amount = amount;

			}else if(curr == tail) {
				cout << "Enter new Departing Station " << curr->prev->startName;
				cin >> startName;
				cout << "Enter the new Arrival Station to " << curr->prev->destName;
				cin >> destName;
				cout << "Enter new amount: ";
				cin.ignore(80, '\n');
				cin >> amount;

				cout << "----------------------------------------------------" << endl;
				cout << "New Departing Station: " << startName <<endl;
				cout << "New Arrival Station " << destName <<endl;
				cout << "New Price : RM" << amount <<endl;
				cout << "----------------------------------------------------\n" << endl;
				pause();

				curr->startName = startName;
				curr->destName = destName;
				curr->amount = amount;
			}
			else
			{
			cout << "error" << endl;
			}

		}

};



#endif /* TRANSACTIONS_H_ */
