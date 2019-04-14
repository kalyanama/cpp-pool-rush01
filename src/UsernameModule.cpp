//
// Created by Mykola MALANCHUK on 2019-04-13.
//

#include "UsernameModule.hpp"
#include <iostream>
#include <UsernameModule.hpp>


UsernameModule::UsernameModule(TopInfo const &top)
{
	update(top);
}

UsernameModule::UsernameModule(UsernameModule const &other)
{
	*this = other;
}

UsernameModule &UsernameModule::operator=(UsernameModule const &other)
{
	return *this;
}

UsernameModule::~UsernameModule()
{}

std::string &UsernameModule::getValue()
{
	return _value;
}

void UsernameModule::update(TopInfo const &top)
{
	char username[_POSIX_LOGIN_NAME_MAX];
	getlogin_r(username, _POSIX_LOGIN_NAME_MAX);
	_value = username;
}

std::string &UsernameModule::getModuleName()
{
	return UsernameModule::_moduleName;
}

std::string UsernameModule::_moduleName = "username";

UsernameModule::UsernameModule()
{

}
