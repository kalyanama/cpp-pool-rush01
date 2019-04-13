#ifndef CPP_POOL_RUSH01_OSINFOMODULE_HPP
#define CPP_POOL_RUSH01_OSINFOMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include <sys/utsname.h>

class OsInfoModule :  public virtual IMonitorModule
{
public:
	OsInfoModule();

	OsInfoModule(OsInfoModule const &other);

	OsInfoModule &operator=(OsInfoModule const &other);

	virtual ~OsInfoModule();

	std::string &getValue() override;

	void updateValue() override;

private:
	std::string _value;
};


#endif //CPP_POOL_RUSH01_OSINFOMODULE_HPP