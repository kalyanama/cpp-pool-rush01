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

	CpuModule(TopInfo const &top);

	CpuModule(CpuModule const &other);

	CpuModule &operator=(CpuModule const &other);

	virtual ~CpuModule();

	void update(TopInfo const &top);
	std::string &getValue();
	std::map<std::string, float> getCpuParameters();

	std::string &getModuleName();

private:
	CpuModule();
	static std::string _moduleName;
	std::string _value;
	std::map< std::string, float > _map;
	void	setCpuName();
	void	updateParams();
};


#endif //CPP_POOL_RUSH01_CPUMODULE_HPP