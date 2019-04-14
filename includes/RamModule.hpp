#ifndef CPP_POOL_RUSH01_RAMMODULE_HPP
#define CPP_POOL_RUSH01_RAMMODULE_HPP

#include <iostream>
#include <map>

#include "IMonitorModule.hpp"

class RamModule :  public virtual IMonitorModule
{
public:
	RamModule(TopInfo const &top);

	RamModule(RamModule const &other);

	RamModule &operator=(RamModule const &other);

	virtual ~RamModule();

	const std::map<std::string, float> &getRamParams() const;

	std::string &getValue();

	void update(TopInfo const &top);
	std::string &getModuleName();


private:
	RamModule();
	static std::string _moduleName;
	std::string _value;
	std::map<std::string, float> _ramParams;
	void updateRamParams(std::string const &top);
};


#endif //CPP_POOL_RUSH01_RAMMODULE_HPP