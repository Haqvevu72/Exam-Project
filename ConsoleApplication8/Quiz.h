#pragma once
class Quiz {
private:
	vector<Question>questions;
	vector<string>quizs;
public:
	// => 1 parametrized constructor
	Quiz(vector<Question>questions) {
		this->questions = questions;
	}
	// => Create a question
	void create() {
		// => Getting Quiz Name and Checking existance before accept 
		string quizName;
		while (true) {
			system("cls");
			bool exist = false;
			cout << "Quiz name: "; getline(cin, quizName);

			ifstream existQuiz;
			existQuiz.open("Quizs.txt", ios::in);
			while (!existQuiz.eof()) {
				string exist_quiz;
				getline(existQuiz, exist_quiz);
				if (exist_quiz == quizName) {
					exist = true; break;
				}
			}
			existQuiz.close();

			if (exist) {
				cout << "Quiz name already exists ! Try other names !" << endl;
				Sleep(1200);
			}
			else {
				break;
			}
		}

		for (int i = 0; i < questions.size(); i++) {
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
					cout << "Answer 1:" << a1 << endl;
					cout << "Answer 2:" << a2 << endl;
					cout << "Answer 3:" << a3 << endl;
					cout << "Answer 4:" << a4 << endl;
					cout << "Correct answer: " << tempCorrect << endl;

					cout << "[1] new" << endl;
					cout << "[2] back" << endl;
					cout << "[3] save" << endl;
					string choice = choose();
					if (choice == "3") {
						Question q(tempQuestion, tempAnswers, tempCorrect);
						questions[i] = q;
						questions[i].setSaved(true);
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
						break;
					}
				}
			}

			// => Checking if all questions saved
			if (i == 4) {
				bool saved = true;
				for (Question q : questions) {
					if (q.getSaved() == false)
						saved = false;
				}
				if (saved) {
					break;
				}
				else {
					i = -1;
				}
			}
		}

		// => Adding File To The `quizs` vector . Then add it to `Quizs.txt`
		quizs.push_back(quizName);
		ofstream Quizs;
		Quizs.open("Quizs.txt", ios::app);
		for (string s : quizs) {
			Quizs << s << endl;
		}
		Quizs.close();

		// => Wrriting items to txt file
		ofstream quiz;
		quiz.open(quizName + ".txt", ios::out);
		for (int j = 0; j < questions.size(); j++) {
			quiz << questions[j].getQuestion() << endl;
			for (string q : questions[j].getAnswers()) {
				quiz << q << endl;
			}
			quiz << questions[j].getCorrect() << endl;
		}
		quiz.close();
		questions.clear();
	}
	// => Randomly allocating questions
	vector<Question>rand_sort(vector<Question>questions)
	{
		vector<Question>new_vec;
		vector<int>idxs{ -1 };
		int counter = 0;
		int max = 4; int min = 0;
		while (counter < 5)
		{
			bool flag = false;
			int idx = min + rand() % (max - min + 1);
			for (int i : idxs)
			{
				if (i == idx)
					flag = true;

			}
			if (!flag)
			{
				new_vec.push_back(questions[idx]);
				idxs.push_back(idx);
				counter++;
			}
		}
		return new_vec;
	}

	// => Start a Quiz
	void start() {
		// => Enter Name;
		string name;
		if (option == 1 || option == 2) {
			name = "Admin";
		}
		else if (option == 3) {
			system("CLS");
			cout << "Nick Name: "; getline(cin, name);
		}
		// Correct Answer and Incorrect Answer count
		short correct = 0; short incorrect = 0;

		// => Showing available quizs
		ifstream Quizs;
		Quizs.open("Quizs.txt", ios::in);

		int indx = 0;
		string quiz_name;
		vector<string>quizs;
		vector<int>options;
		system("CLS");
		while (getline(Quizs, quiz_name)) {
			cout << "[" << indx + 1 << "] " << quiz_name << endl;
			indx++;
			options.push_back(indx);
			quizs.push_back(quiz_name + ".txt");
			quiz_name.clear();
		}
		Quizs.close();

		// => Choosing one of the avaliable quizs
		string choice = choose();
		for (int o : options) {
			if (stoi(choice) == o) {
				quiz_name = quizs[o - 1];
				break;
			}
		}

		// => Getting quiz questions from the file and writing on objects
		ifstream quiz;
		quiz.open(quiz_name, ios::in);
		for (int i = 0; i < questions.size(); i++) {
			string question;
			string a1; string a2; string a3; string a4;
			vector<string>answers;
			string cor_ans;

			getline(quiz, question);
			getline(quiz, a1);
			getline(quiz, a2);
			getline(quiz, a3);
			getline(quiz, a4);
			answers.push_back(a1); answers.push_back(a2); answers.push_back(a3); answers.push_back(a4);
			getline(quiz, cor_ans);

			Question temp(question, answers, cor_ans);
			questions[i] = temp;
		}
		quiz.close();

		// => Sorinting Answers Randomly
		for (int i = 0; i < questions.size(); i++) {
			questions[i].setAnswers(questions[i].rand_sort(questions[i].getAnswers()));
		}

		// => Sorting Randomly Questions
		questions = rand_sort(questions);

		// => Starting Quiz
		for (int i = 0; i < questions.size(); i++) {
			if (questions[i].getSaved() == false) {
				string answer;
				while (true) {
					system("cls");
					cout << i + 1 << "." << questions[i].getQuestion() << endl;
					cout << "A) " << questions[i].getAnswers()[0] << endl;
					cout << "B) " << questions[i].getAnswers()[1] << endl;
					cout << "C) " << questions[i].getAnswers()[2] << endl;
					cout << "D) " << questions[i].getAnswers()[3] << endl;
					cout << "Answer: "; getline(cin, answer);
					if (answer == "A" || answer == "B" || answer == "C" || answer == "D") {
						break;
					}
				}

				// [1] new
				// [2] back
				// [3] submit
				while (true) {
					system("cls");
					cout << i + 1 << "." << questions[i].getQuestion() << endl;
					cout << "A) " << questions[i].getAnswers()[0] << endl;
					cout << "B) " << questions[i].getAnswers()[1] << endl;
					cout << "C) " << questions[i].getAnswers()[2] << endl;
					cout << "D) " << questions[i].getAnswers()[3] << endl;
					cout << "Answer: " << answer << endl;
					cout << "[1] new" << endl;
					cout << "[2] back" << endl;
					cout << "[3] submit" << endl;
					string choice = choose();

					if (choice == "3") {
						if (answer == "A" && questions[i].getAnswers()[0] == questions[i].getCorrect()) {
							cout << "True !" << endl;
							questions[i].setSaved(true);
							Sleep(1000);
							correct += 1;
							break;
						}
						else if (answer == "B" && questions[i].getAnswers()[1] == questions[i].getCorrect()) {
							cout << "True !" << endl;
							questions[i].setSaved(true);
							Sleep(1000);
							correct += 1;
							break;
						}
						else if (answer == "C" && questions[i].getAnswers()[2] == questions[i].getCorrect()) {
							cout << "True !" << endl;
							questions[i].setSaved(true);
							Sleep(1000);
							correct += 1;
							break;
						}
						else if (answer == "D" && questions[i].getAnswers()[3] == questions[i].getCorrect()) {
							cout << "True !" << endl;
							questions[i].setSaved(true);
							Sleep(1000);
							correct += 1;
							break;
						}
						else {
							cout << "False !" << endl;
							questions[i].setSaved(true);
							Sleep(1000);
							incorrect += 1;
							break;
						}
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
						break;
					}
				}

			}
			if (i == 4) {
				bool saved = true;
				for (Question q : questions) {
					if (q.getSaved() == false)
						saved = false;
				}
				if (saved) {
					break;
				}
				else {
					i = -1;
				}
			}

		}
		system("cls");
		cout << "Correct: " << correct << endl;
		cout << "Incorrect: " << incorrect << endl;

		// => Stroing result in LeaderBoard
			// => Adding new player to leader board
		for (auto it = leaderBoard.begin(); it != leaderBoard.end(); it++) {
			if (it->first == name) {
				if (it->second != correct) {
					leaderBoard[name] = correct;
				}
			}
			else {
				leaderBoard[name] = correct;
			}
		}

		// Create a vector of pairs from the map
		vector<pair<string, int>> vec(leaderBoard.begin(), leaderBoard.end());


		// Sort the vector of pairs by value
		sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.second > b.second;
			});

		// Print the sorted vector of pairs
		ofstream LeaderBoard;
		int counter = 0;
		LeaderBoard.open("LeaderBoard.txt", ios::out);
		for (const auto& pair : vec) {
			LeaderBoard << pair.first << endl;
			LeaderBoard << pair.second << endl;
			counter++;
			if (counter == 10) {
				break;
			}
			
		}
		LeaderBoard.close();

	}
};