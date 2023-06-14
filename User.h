#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include "Message.h"

class User
{
	std::string _login;
	std::string _password;
	std::string _name;

public:
	User() : _name("UNKNOWN"), _login("UNKNOWN"), _password("UNKNOWN") {};
	User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name) {}
	~User() = default;

	const std::string& getUserLogin() const { return _login; }
	const std::string& getUserPassword() const { return _password; }
	const std::string& getUserName() const { return _name; }

	void setUserLogin(const std::string& login) { _login = login; }
	void setUserPassword(const std::string& password) { _password = password; }
	void setUserName(const std::string& name) { _name = name; }

	//���������� �����������
	User(const User& other) : _name(other._name), _login(other._login), _password(other._password) {}

	//�������� ������������ �����������
	User& operator = (const User& other) {
		//�������� �� ����������������
		if (this == &other) {
			return *this;
		}

		_name = other._name;
		_login = other._login;
		_password = other._password;

		return *this;
	}

	//����������� �������� >> � <<
	friend std::ifstream& operator >>(std::ifstream& is, User& obj) {
		is >> obj._name;
		is >> obj._login;
		is >> obj._password;
		return is;
	}

	friend std::ostream& operator <<(std::ostream& os, const User& obj) {
		os << obj._name << " ";
		os << obj._login << " ";
		os << obj._password;
		return os;
	}

};
