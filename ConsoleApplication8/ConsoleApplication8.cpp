#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <map>
using namespace std;
map<string,int>leaderBoard;
string choose(){
	string choice; cout << "your choice: "; getline(cin, choice);
	return choice;
}
bool admin_guest() {
	while (true) {
		system("CLS");
		cout << "[1] Admin" << endl;
		cout << "[2] Guest" << endl;
		string choice = choose();
		if (choice == "1") {
			return true;
		}
		else if (choice == "2") {
			return false;
		}
	}
}
int options() {
	bool adminguest = admin_guest();
	while (true) {
		if (adminguest == true) {
			system("CLS");
			cout << "[1] Create quiz" << endl;
			cout << "[2] Play quiz" << endl;
			string choice = choose();
			if (choice == "1") {
				return 1;
			}
			else if (choice == "2") {
				return 2;
			}
		}
		if (adminguest == false) {
			system("CLS");
			cout << "[1] Play quiz" << endl;
			string choice = choose();
			if (choice == "1") {
				return 3;
			}
		}
	}
}
int option = options();
#include "Question.h"
#include "Quiz.h"
void quiz() {
	srand(time(NULL));

	// Filling leaderBoard with information which coming from LeaderBoard.txt
	ifstream Read_leaderBoard;
	Read_leaderBoard.open("LeaderBoard.txt", ios::in);
	string name; string point;
	while (!Read_leaderBoard.eof()) {
		getline(Read_leaderBoard, name);
		getline(Read_leaderBoard, point);
		leaderBoard[name] = atoi(point.c_str());
		name.clear(); point.clear();
	}
	Read_leaderBoard.close();

	// We create 5 questions 
	Question q1; Question q2; Question q3; Question q4; Question q5;

	// And store them inside the vector called `questions`
	vector <Question> questions{ q1, q2, q3, q4, q5 };

	// Then we created quiz
	Quiz q(questions);

	if (option==1) {
		q.create();
	}
	else if (option == 2 || option==3) {
		q.start();
	}
}
void main(){
	quiz();
}