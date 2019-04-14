#ifndef CPP_POOL_RUSH01_IMONITORMODULE_HPP
#define CPP_POOL_RUSH01_IMONITORMODULE_HPP

#include <iostream>
#include <unistd.h>
#include <limits.h>

/*
 * TODO:
 * 	CpuModule -- cpu activity by cores
 * 	RamModule
 * 	NetworkModule
 *
 * TODO:
 * 	Add more functions to module;
 * 	Displays
 *
 *
 *
 */



class IMonitorModule
{
public:
	virtual std::string &getValue() = 0;
	virtual void update() = 0;
};


#endif //CPP_POOL_RUSH01_IMONITORMODULE_HPP