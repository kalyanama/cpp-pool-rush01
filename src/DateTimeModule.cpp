#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{
	update();
}

DateTimeModule::DateTimeModule(DateTimeModule const &other)
{
	*this = other;
}

DateTimeModule &DateTimeModule::operator=(DateTimeModule const &other)
{
	return *this;
}

DateTimeModule::~DateTimeModule()
{}

std::string &DateTimeModule::getValue()
{
	return _value;
}

void DateTimeModule::update()
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	char buffer[32];

	strftime(buffer, 32, "%Y-%m-%d %H:%M:%S ", now);

	_value = buffer;
}
