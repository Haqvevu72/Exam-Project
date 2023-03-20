#pragma once
class Quiz{
private:
	vector<Question>questions;
public:
	// => 1 parametrized constructor
	Quiz(vector<Question>questions){
		this->questions = questions;
	}

	// => Create a question
	void create(){

		for (int i = 0; i < questions.size(); i++){
			// Asking me to enter question
			system("CLS");
			string tempQuestion; cout << i+1 << ".Question: "; getline(cin, tempQuestion);
			
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
			cout << "[1] new" << endl;
			cout << "[2] back" << endl;
			cout << "[3] save" << endl;
			string choice = choose();
			if (choice=="3"){
				Question q(tempQuestion, tempAnswers, tempCorrect);
				questions[i] = q;
			}
			else if (choice=="2") {
				if (i - 1 >= -1) {
					i -= 2;
				}
				else {
					i -= 1;
				}
			}

			
		}
	}

	// => For checking result
	void display() {
		for (Question q : questions) {
			cout << q.getQuestion() << endl;
			for (string i : q.getAnswers()) {
				cout << i << endl;
			}
			cout << q.getCorrect()<<endl;
		}
	}
};