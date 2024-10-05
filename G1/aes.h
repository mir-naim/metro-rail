/*
 * aes.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Rishad Yunus
 */

#ifndef AES_H_
#define AES_H_

#include <iostream>
#include <limits>
using namespace std;



void spacer(){
	for (int i=0;i<5;i++){
		cout<<endl;
	}
}

void pause(){
	cout<< "Press Enter to continue...";				//if 1 doesn't work then 2 will
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

}




#endif /* AES_H_ */
