#include "OsInfoModule.hpp"

OsInfoModule::OsInfoModule()
{
	update();
}

OsInfoModule::OsInfoModule(OsInfoModule const &other)
{
	*this = other;
}

OsInfoModule &OsInfoModule::operator=(OsInfoModule const &other)
{
	return *this;
}

OsInfoModule::~OsInfoModule()
{}

std::string &OsInfoModule::getValue()
{
	return _value;
}

void OsInfoModule::update()
{
	struct utsname uts;
	uname(&uts);
	_value = uts.version;
}
