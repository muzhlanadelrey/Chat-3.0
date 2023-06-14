#pragma once
#include <string>
#include <fstream>
#include <filesystem>

class Message
{
	std::string _from;
	std::string _to;
	std::string _text;

public:
	Message() : _text("UNKNOWN"), _from("UNKNOWN"), _to("UNKNOWN") {}
	Message(const std::string& from, const std::string& to, const std::string& text) : _from(from), _to(to), _text(text) {}
	~Message() = default;

	const std::string getFrom() const { return _from; }
	const std::string getTo() const { return _to; }
	const std::string getText() const { return _text; }

	//Констуктор копирования
	Message(const Message& other) : _text(other._text), _from(other._from), _to(other._to) {}

	//Оператор присваивания копирования
	Message& operator = (const Message& other) {
		//Проверка на самоприсваивание
		if (this == &other) {
			return *this;
		}

		_text = other._text;
		_from = other._from;
		_to = other._to;

		return *this;
	}

	//Перегружаем операции >> и <<
	friend std::ifstream& operator >>(std::ifstream& is, Message& obj) {
		is >> obj._from;
		is >> obj._to;
		is.seekg(1, std::ios_base::cur);
		std::getline(is, obj._text);
		return is;
	}

	friend std::ostream& operator <<(std::ostream& os, const Message& obj) {
		os << obj._from << " ";
		os << obj._to << " ";
		os << obj._text;
		return os;
	}

};