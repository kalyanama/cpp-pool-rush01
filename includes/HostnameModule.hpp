#ifndef CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP
#define CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class HostnameModule :  public virtual IMonitorModule
{
public:

	HostnameModule(TopInfo const &top);

	HostnameModule(HostnameModule const &other);

	HostnameModule &operator=(HostnameModule const &other);

	virtual ~HostnameModule();

	std::string &getValue();

	void update(TopInfo const &top);

	std::string &getModuleName();

private:
	HostnameModule();
	static std::string _moduleName;
	std::string _value;
};


#endif //CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP