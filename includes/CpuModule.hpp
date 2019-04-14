#ifndef CPP_POOL_RUSH01_CPUMODULE_HPP
#define CPP_POOL_RUSH01_CPUMODULE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "IMonitorModule.hpp"

class CpuModule: public virtual IMonitorModule
{
public:
	CpuModule();

	CpuModule(CpuModule const &other);

	CpuModule &operator=(CpuModule const &other);

	virtual ~CpuModule();

	void update();
	std::string &getValue();
	std::map<std::string, float> getCpuParameters();

private:
	std::string _value;
	std::map< std::string, float > _map;
	void	setCpuName();
	void	updateParams();
};


#endif //CPP_POOL_RUSH01_CPUMODULE_HPP