#include <iostream>
#include <vector>
#include <string>
using namespace std;
string choose(){
	string choice; cout << "your choice: "; getline(cin, choice);
	return choice;
}
#include "Question.h"
#include "Quiz.h"
void main(){
	// We create 5 questions 
	Question q1; Question q2; Question q3; Question q4; Question q5;
	
	// And store them inside the vector called `questions`
	vector <Question> questions{q1, q2, q3, q4, q5};
	
	// Then we created quiz
	Quiz quiz(questions);

	quiz.create();
}