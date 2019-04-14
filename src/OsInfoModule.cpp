#include "OsInfoModule.hpp"

OsInfoModule::OsInfoModule(TopInfo const &top)
{
	update(top);
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

void OsInfoModule::update(TopInfo const &top)
{
	static_cast<void>(top);
	struct utsname uts;
	uname(&uts);
	_value = uts.version;
}

std::string &OsInfoModule::getModuleName()
{
	return OsInfoModule::_moduleName;
}

std::string OsInfoModule::_moduleName = "osinfo";

OsInfoModule::OsInfoModule()
{}
