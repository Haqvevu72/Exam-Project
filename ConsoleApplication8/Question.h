#pragma once
class Question
{
private:
	string question;
	vector<string>answers;
	string corrAnswer;
public:
	// => Default constructor
	Question() {
	}

	// => 3 parametrized constructor
	Question(string question,vector<string>answers,string corrAnswer)
	{
		this->question = question;
		this->answers = answers;
		this->corrAnswer = corrAnswer;
	}

	// => getters
	string getQuestion() { return question; }
	vector<string>getAnswers() { return answers; }
	string getCorrect() { return corrAnswer; }
};