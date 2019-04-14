#ifndef CPP_POOL_RUSH01_IMONITORMODULE_HPP
#define CPP_POOL_RUSH01_IMONITORMODULE_HPP

#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <map>
#include <fstream>
#include "TopInfo.hpp"
/*
 * TODO:
 * 	CpuModule -- cpu activity by cores
 * 	RamModule -- get TRULY RAM
 *
 * TODO:
 * 	Add more functions to module;
 * 	Displays
 *
 *	TODO:
 *		check Coplien
 *
 */



class IMonitorModule
{
public:
	virtual std::string &getValue() = 0;
	virtual std::string &getModuleName() = 0;
	virtual void update(TopInfo const &top) = 0;
};


#endif //CPP_POOL_RUSH01_IMONITORMODULE_HPP