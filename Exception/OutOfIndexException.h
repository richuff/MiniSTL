#pragma once
#include <exception>
#include <string>

class OutOfIndexException : public std::exception {
public:
	OutOfIndexException(const std::string& msg) :message(msg){}

	virtual const char* what() const noexcept {
		return message.c_str();
	}
private:
	std::string message;
};