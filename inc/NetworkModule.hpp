#ifndef CPP_POOL_RUSH01_NETWORKMODULE_HPP
#define CPP_POOL_RUSH01_NETWORKMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class NetworkModule :  public virtual IMonitorModule
{
public:
	NetworkModule();

	NetworkModule(NetworkModule const &other);

	NetworkModule &operator=(NetworkModule const &other);

	virtual ~NetworkModule();
};


#endif //CPP_POOL_RUSH01_NETWORKMODULE_HPP