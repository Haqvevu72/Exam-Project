#pragma once
class Question
{
private:
	string question;
	vector<string>answers;
	string corrAnswer;
	bool saved = false;
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

	// => setters
	void setSaved(bool saved){
		this->saved = saved;
	}
	// => getters
	string getQuestion() { return question; }
	vector<string>getAnswers() { return answers; }
	string getCorrect() { return corrAnswer; }
	bool getSaved() { return saved; }
};