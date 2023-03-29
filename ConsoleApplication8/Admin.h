#pragma once
class Admin {
private:
	string username;
	string password;
public:
	// => Parametrized Constructor
	Admin(string username,string password) {
		this->username = username;
		this->password = password;
	}

	// => Checking username and password
	bool check(string username,string password) {
		if (this->username == username && this->password == password) {
			return true;
		}
		else {
			return false;
		}
	}
};