#include <sys/utsname.h>
#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
	update();
}

HostnameModule::HostnameModule(HostnameModule const &other)
{
	*this = other;
}

HostnameModule &HostnameModule::operator=(HostnameModule const &other)
{
	return *this;
}

HostnameModule::~HostnameModule()
{}

std::string &HostnameModule::getValue() {
	return (_value);
}

void HostnameModule::update() {
	struct utsname uts;
	uname(&uts);
	_value = uts.nodename;
}
