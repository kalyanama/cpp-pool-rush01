#ifndef CPP_POOL_RUSH01_RAMMODULE_HPP
#define CPP_POOL_RUSH01_RAMMODULE_HPP

#include <iostream>

#include "IMonitorModule.hpp"

class RamModule :  public virtual IMonitorModule
{
public:
	RamModule();

	RamModule(RamModule const &other);

	RamModule &operator=(RamModule const &other);

	virtual ~RamModule();
};


#endif //CPP_POOL_RUSH01_RAMMODULE_HPP