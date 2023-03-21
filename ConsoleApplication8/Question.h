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

	void setAnswers(vector<string>answers) {
		this->answers = answers;
	}

	// => Sorting Answers Randomly
	vector<string>rand_sort(vector<string>answers)
	{
		vector<string>new_vec;
		vector<int>idxs{ -1 };
		int counter = 0;
		int max = 3; int min = 0;
		while (counter < 4)
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
				new_vec.push_back(answers[idx]);
				idxs.push_back(idx);
				counter++;
			}
		}
		return new_vec;
	}


	// => getters
	string getQuestion() { return question; }
	vector<string>getAnswers() { return answers; }
	string getCorrect() { return corrAnswer; }
	bool getSaved() { return saved; }
};