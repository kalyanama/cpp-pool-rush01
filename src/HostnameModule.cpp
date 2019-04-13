#include <sys/utsname.h>
#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
	updateValue();
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

void HostnameModule::updateValue() {
	struct utsname uts;
	uname(&uts);
	_value = uts.nodename;
}
