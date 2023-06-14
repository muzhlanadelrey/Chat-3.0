#pragma once
#include <string>
#include <vector>
#include <memory>
#include <filesystem>
#include <exception>
#include "User.h"

class loginException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Ошибка: логин занят";
	}
};
class nameException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "ОШИБКА: имя занято";
	}
};

class Chat
{
protected:
	bool _chatWork = false;
	std::vector<User> _users;
	std::vector<Message> _messages;
	std::shared_ptr<User> _currentUser = nullptr;

	std::shared_ptr<User> getUserByLogin(const std::string& login) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;
	std::string nameFileForUsers_;
	std::string nameFileForMessages_;

public:
	void start();
	bool chatWork() const;

	void showMainMenu(); 
	void showLoginMenu(); 
	void showRegistrationMenu(); 
	void showChat(); 
	void showChatMenu(); 
	void showAllUsers(); 
	void addMessage(); 

	void adminCreation(); 
	void showAllUsersInfo(); 

	void setNameFileForUsers(const std::string& nameFile);
	void setNameFileForMessages(const std::string& nameFile);
	void saveUsers() const;
	void saveMessages() const;
	void loadUsers();
	void loadMessages();

	std::shared_ptr<User>getCurrentUser() const { return _currentUser; }

};

