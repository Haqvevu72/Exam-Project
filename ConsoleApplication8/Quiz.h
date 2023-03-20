#pragma once
class Quiz{
private:
	vector<Question>questions;
	vector<string>quizs;
public:
	// => 1 parametrized constructor
	Quiz(vector<Question>questions){
		this->questions = questions;
	}

	// => Create a question
	void create(){
		// => Getting Quiz Name
		string quizName; cout << "Quiz name: "; getline(cin, quizName);

		for (int i = 0; i < questions.size(); i++){
			// Asking me to enter question
			system("CLS");
			if (questions[i].getSaved() == false) {
				string tempQuestion; cout << i + 1 << ".Question: "; getline(cin, tempQuestion);

				// Asking me to enter answers
				string a1; cout << "Answer 1:"; getline(cin, a1);
				string a2; cout << "Answer 2:"; getline(cin, a2);
				string a3; cout << "Answer 3:"; getline(cin, a3);
				string a4; cout << "Answer 4:"; getline(cin, a4);

				// Storing included answers in one place 
				vector<string>tempAnswers{ a1,a2,a3,a4 };

				// Asking me to enter correct answer
				string tempCorrect; cout << "Correct answer: "; getline(cin, tempCorrect);

				// [1] new
				// [2] back
				// [3] save
				while (true) {
					system("cls");
					cout << i + 1 << ".Question: " << tempQuestion << endl;
				    cout << "Answer 1:"<<a1<<endl;
				    cout << "Answer 2:"<<a2<<endl; 
				    cout << "Answer 3:"<<a3<<endl;
				    cout << "Answer 4:"<<a4<<endl;
					cout << "Correct answer: " << tempCorrect << endl;

					cout << "[1] new" << endl;
					cout << "[2] back" << endl;
					cout << "[3] save" << endl;
					string choice = choose();
					if (choice == "3") {
						Question q(tempQuestion, tempAnswers, tempCorrect);
						questions[i] = q;
						questions[i].setSaved(true);
						if (i == 4) {
							i = -1;
						}
						break;
					}
					else if (choice == "2") {
						if (i == 0) {
							i -= 1;
						}
						else {
							i -= 2;
						}
						break;
					}
					else if (choice == "1") {
						if (i == 4) {
							i = -1;
						}

						break;
					}
				}
			}
			if (i == 4){
				i = -1;
			}
		}
		ofstream quiz;
		quiz.open(quizName + ".txt", ios::out);
		for (int j = 0; j < questions.size(); j++) {
			quiz << questions[j].getQuestion() << endl;
			for (string q:questions[j].getAnswers()) {
				quiz << q << endl;
			}
			quiz << questions[j].getCorrect() << endl;
		}
		quiz.close();
	}

};