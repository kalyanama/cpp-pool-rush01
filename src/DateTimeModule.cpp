
#include <DateTimeModule.hpp>

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{
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

//void DateTimeModule::update(TopInfo const &top)
//{
//	std::time_t t = std::time(0);   // get time now
//	std::tm* now = std::localtime(&t);
//
//	char buffer[32];
//
//	strftime(buffer, 32, "%Y-%m-%d %H:%M:%S ", now);
//
//	_value = buffer;
//}

void DateTimeModule::update(TopInfo const &top)
{
	std::map<std::string, std::string> temp;
	temp = top.getData();

	_value = temp["datetime"];
}

std::string &DateTimeModule::getModuleName()
{
	return DateTimeModule::_moduleName;
}

std::string DateTimeModule::_moduleName = "datetime";

DateTimeModule::DateTimeModule(TopInfo const &top)
{
	update(top);
}
