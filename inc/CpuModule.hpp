#ifndef CPP_POOL_RUSH01_CPUMODULE_HPP
#define CPP_POOL_RUSH01_CPUMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class CpuModule: public virtual IMonitorModule
{
public:
	CpuModule();

	CpuModule(CpuModule const &other);

	CpuModule &operator=(CpuModule const &other);

	virtual ~CpuModule();
};


#endif //CPP_POOL_RUSH01_CPUMODULE_HPP