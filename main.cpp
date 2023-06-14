#include <iostream>
#include <Windows.h>
#include "Chat.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Chat chat;
	Chat users;
	Chat messages;

	chat.setNameFileForMessages("messages");
	chat.setNameFileForUsers("users");
	chat.start();
	users.loadUsers();
	messages.loadMessages();
	chat.adminCreation();

	while (chat.chatWork())
	{
		chat.showMainMenu();
		while (chat.getCurrentUser())
		{
			chat.showChatMenu();
		}
		chat.saveMessages();
		chat.saveUsers();
	}
	return 0;
}