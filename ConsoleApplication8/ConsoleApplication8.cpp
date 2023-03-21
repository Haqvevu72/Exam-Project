#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <map>
using namespace std;
map<string, int>leaderBoard;
string choose(){
	string choice; cout << "your choice: "; getline(cin, choice);
	return choice;
}
#include "Question.h"
#include "Quiz.h"

void main(){
	srand(time(NULL));

	// Filling leaderBoard with information which coming from LeaderBoard.txt
	ifstream Read_leaderBoard;
	Read_leaderBoard.open("LeaderBoard.txt", ios::in);
	string name; string point;
	while (getline(Read_leaderBoard, name)) {
		getline(Read_leaderBoard, point);
		leaderBoard[name] = stoi(point);
		name.clear(); point.clear();
	}
	Read_leaderBoard.close();
	// We create 5 questions 
	Question q1; Question q2; Question q3; Question q4; Question q5;
	
	// And store them inside the vector called `questions`
	vector <Question> questions{q1, q2, q3, q4, q5};
	
	// Then we created quiz
	Quiz quiz(questions);

	// Wiritng results to leader board
	for (auto it = leaderBoard.begin(); it != leaderBoard.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

}