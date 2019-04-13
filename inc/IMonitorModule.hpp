#ifndef CPP_POOL_RUSH01_IMONITORMODULE_HPP
#define CPP_POOL_RUSH01_IMONITORMODULE_HPP

#include <iostream>


class IMonitorModule
{
public:
	virtual std::string getValue() = 0;
	virtual std::string updateValue() = 0;
};


#endif //CPP_POOL_RUSH01_IMONITORMODULE_HPP