#ifndef CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP
#define CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class HostnameModule :  public virtual IMonitorModule
{
public:
	HostnameModule();

	HostnameModule(HostnameModule const &other);

	HostnameModule &operator=(HostnameModule const &other);

	virtual ~HostnameModule();

	std::string &getValue() override;

	void updateValue() override;

private:
	std::string _value;
};


#endif //CPP_POOL_RUSH01_HOSTNAMEMODULE_HPP