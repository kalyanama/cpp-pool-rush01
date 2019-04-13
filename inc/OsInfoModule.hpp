#ifndef CPP_POOL_RUSH01_OSINFOMODULE_HPP
#define CPP_POOL_RUSH01_OSINFOMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class OsInfoModule :  public virtual IMonitorModule
{
public:
	OsInfoModule();

	OsInfoModule(OsInfoModule const &other);

	OsInfoModule &operator=(OsInfoModule const &other);

	virtual ~OsInfoModule();
};


#endif //CPP_POOL_RUSH01_OSINFOMODULE_HPP