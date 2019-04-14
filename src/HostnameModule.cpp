#include <sys/utsname.h>
#include <HostnameModule.hpp>

#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
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

void HostnameModule::update(TopInfo const &top)
{
	static_cast<void>(top);

	struct utsname uts;
	uname(&uts);
	_value = uts.nodename;
}

std::string &HostnameModule::getModuleName()
{
	return HostnameModule::_moduleName;
}

std::string HostnameModule::_moduleName = "hostname";

HostnameModule::HostnameModule(TopInfo const & top)
{
	update(top);
}
