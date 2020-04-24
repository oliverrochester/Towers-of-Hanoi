//Oliver Rochester
//This is the main program file that runs the towers of hanoi algorithm
//This file implements the stack class and its methods
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackStuff.h"
#include "LLStack.h"
using namespace std;

class LLStack;

//main method that runs the towers of hanoi algorithm
int main(int argc, char** argv) {

	LLStack* one = new LLStack();			//creates three separate stacks
	LLStack* two = new LLStack();			//	|
	LLStack* three = new LLStack();			//	|
	int disks;
	cout << "Enter number of disks" << endl;	//takes user input of number of disks
	cin >> disks;
	int i;
	int disk1Loc;
	int totalmoves = pow(2, disks) - 1;		//calculates the optimal amount of moves to solve puzzle 2^disks -1

	for (i = disks; i >= 1; i--) {			////pushes all nodes onto pole 0 in correct order using loop
		string s = to_string(i);					
		cout << s << endl;
		one->PUSH(s);						
	}

	LLStack* stacks[3] = { one, two, three };	//creates an array of stacks
	
	if (disks == 0) {
		cout << "No disks" << endl;				//if user enter no disks, program ends
	}
	else {
		//*****************************************************
		//if else statement that makes the first move with disk 1 based on odd or even number of disks
		//changes disk 1 location
		if (disks % 2 == 0) {
			stacks[1]->PUSH(stacks[0]->POP());	
			cout << "disk 1 from pole 0 to pole 1" << endl;
			disk1Loc = 1;

		}
		else {
			stacks[2]->PUSH(stacks[0]->POP());
			cout << "disk 1 from pole 0 to pole 2" << endl;
			disk1Loc = 2;
		}
		//*******************************************************

		//for loop that runs entire calculation
		for (int moves = 2; moves <= totalmoves; moves++) {
			//checks if odd or even move
			if (moves % 2 != 0) {
				//check for odd or even disk count
				if (disks % 2 != 0) {

					 
					//*******************************************************//
					//this section moves only the first disk on an odd number disk game

					//depending where disk 1 is located, and if game has odd number of disks, disk 1 will always
					// jump 2 poles the same way on every move
					//moves disk 1 when it is on the first pole
					if (disk1Loc == 0) {
						stacks[disk1Loc + 2]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc + 2) << endl;
						disk1Loc = disk1Loc + 2;
					}
					//moves disk one when disk one is on the last pole
					else if (disk1Loc == 2) {
						stacks[disk1Loc - 1]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc - 1) << endl;
						disk1Loc = disk1Loc - 1;
					}
					//moves disk one when it is on the second pole
					else {
						stacks[disk1Loc - 1]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc - 1) << endl;
						disk1Loc = disk1Loc - 1;
					}
					//**********************************************************
				}

				//this section moves only first disk on even number disk game
				//makes every move in relativity to disk 1's location
				//**************************************************************
				else {
					//moves disk 1 when it is on the first pole
					if (disk1Loc == 0) {
						stacks[disk1Loc + 1]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc + 1) << endl;
						disk1Loc = disk1Loc + 1;
					}  
					//moves disk 1 when it is on the last pole
					else if (disk1Loc == 2) {
						stacks[disk1Loc - 2]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc - 2) << endl;
						disk1Loc = disk1Loc - 2;
					}
					//moves disk 1 when it is on the second pole
					else {
						stacks[disk1Loc + 1]->PUSH(stacks[disk1Loc]->POP());
						cout << "disk 1 from pole " + to_string(disk1Loc) + " to pole " + to_string(disk1Loc + 1) << endl;
						disk1Loc = disk1Loc + 1;
					}
				}
				//*******************************************************************
			}


			//this part handles all other moves not involving disk 1
			//makes every move in relativity to disk 1's location
			//***************************************************************************
			else {
				string disk;
				//if disk 1's location is on the first pole,
				//the other 2 open poles are pole 2 and 3
				if (disk1Loc == 0) {
					//if else statement checking whether the poles not containing disk 1 are empty
					//if one is empty, pop from full stack, push to empty,
					//vice versa if the other one is empty
					if (stacks[disk1Loc + 1]->ISEMPTY()) {
						disk = stacks[disk1Loc + 2]->POP();
						stacks[disk1Loc + 1]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc + 2) + " to pole " + to_string(disk1Loc + 1) << endl;
					}
					else if (stacks[disk1Loc + 2]->ISEMPTY()) {
						disk = stacks[disk1Loc + 1]->POP();
						stacks[disk1Loc + 2]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc + 1) + " to pole  " + to_string(disk1Loc + 2) << endl;
					}
					//else if both other poles have disks, pop from both of them, compare the two,
					//whichever is smaller, move smaller one onto larger one
					else {
						int second = stoi(stacks[disk1Loc + 2]->POP());
						int first = stoi(stacks[disk1Loc + 1]->POP());
						//if first disk is smaller than second disk, move bigger disk to pole first, then smaller disk
						if (first < second) {
							stacks[disk1Loc + 2]->PUSH(to_string(second));
							stacks[disk1Loc + 2]->PUSH(to_string(first));
							cout << "disk " + to_string(first) + " from pole " + to_string(disk1Loc + 1) + " to pole " + to_string(disk1Loc + 2) << endl;
						}
						//if first disk is bigger than second disk, move smaller disk to pole first, then bigger disk
						else {
							stacks[disk1Loc + 1]->PUSH(to_string(first));
							stacks[disk1Loc + 1]->PUSH(to_string(second));
							cout << "disk " + to_string(second) + " from pole " + to_string(disk1Loc + 2) + " to pole " + to_string(disk1Loc + 1) << endl;
						}
					}
				}
				//if disk 1's location is on the second pole
				//the other 2 open poles are pole 1 and 3
				// move first disks other than disk one when disk one is on the second pole
				else if (disk1Loc == 1) {
					//first checks if one of the three poles are empty, and makes easy move accrodingly
					if (stacks[disk1Loc + 1]->ISEMPTY()) {
						disk = stacks[disk1Loc - 1]->POP();
						stacks[disk1Loc + 1]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc - 1) + " to pole " + to_string(disk1Loc + 1) << endl;
					}
					//checks if the other pole is empty and makes easy move accordingly
					else if (stacks[disk1Loc - 1]->ISEMPTY()) {
						disk = stacks[disk1Loc + 1]->POP();
						stacks[disk1Loc - 1]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc + 1) + " to pole " + to_string(disk1Loc - 1) << endl;
					}
					else {
						//if all poles are full, repeats process from before
						int second = stoi(stacks[disk1Loc + 1]->POP());
						int first = stoi(stacks[disk1Loc - 1]->POP());
						//else if both other poles have disks, pop from both of them, compare the two,
						//whichever is smaller, move smaller one onto larger one
						if (first < second) {
							//if first disk is smaller than second disk, move bigger disk to pole first, then smaller disk
							stacks[disk1Loc + 1]->PUSH(to_string(second));
							stacks[disk1Loc + 1]->PUSH(to_string(first));
							cout << "disk " + to_string(first) + " from pole " + to_string(disk1Loc - 1) + " to pole " + to_string(disk1Loc + 1) << endl;
						}
						//if first disk is bigger than second disk, move smaller disk to pole first, then bigger disk
						else {
							stacks[disk1Loc - 1]->PUSH(to_string(first));
							stacks[disk1Loc - 1]->PUSH(to_string(second));
							cout << "disk " + to_string(second) + " from pole " + to_string(disk1Loc + 1) + " to pole " + to_string(disk1Loc - 1) << endl;
						}
					}
				}
				//if disk 1's location is on the third pole
				//the other 2 open poles are pole 1 and 2
				else {
					//makes moves for disks other than disk one when disk one is on pole 3
					if (stacks[disk1Loc - 1]->ISEMPTY()) {
						disk = stacks[disk1Loc - 2]->POP();
						stacks[disk1Loc - 1]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc - 2) + " to pole " + to_string(disk1Loc - 1) << endl;
					}
					else if (stacks[disk1Loc - 2]->ISEMPTY()) {
						disk = stacks[disk1Loc - 1]->POP();
						stacks[disk1Loc - 2]->PUSH(disk);
						cout << "disk " + disk + " from pole " + to_string(disk1Loc - 1) + " to pole " + to_string(disk1Loc - 2) << endl;
					}
					else {
						//else if both other poles have disks, pop from both of them, compare the two,
						//whichever is smaller, move smaller one onto larger one
						int second = stoi(stacks[disk1Loc - 1]->POP());
						int first = stoi(stacks[disk1Loc - 2]->POP());
						if (first < second) {
							//if first disk is smaller than second disk, move bigger disk to pole first, then smaller disk
							stacks[disk1Loc - 1]->PUSH(to_string(second));
							stacks[disk1Loc - 1]->PUSH(to_string(first));
							cout << "disk " + to_string(first) + " from pole " + to_string(disk1Loc - 1) + " to pole " + to_string(disk1Loc + 1) << endl;
						}
						//if first disk is bigger than second disk, move smaller disk to pole first, then bigger disk
						else {
							stacks[disk1Loc - 2]->PUSH(to_string(first));
							stacks[disk1Loc - 2]->PUSH(to_string(second));
							cout << "disk " + to_string(second) + " from pole " + to_string(disk1Loc - 1) + " to pole " + to_string(disk1Loc - 2) << endl;

						}
					}

				}

			}

		}
	}
	//remove memory leaks
	delete one;
	delete two;
	delete three;
} 