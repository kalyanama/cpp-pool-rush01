//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#ifndef CPP_POOL_RUSH01_IDISPLAYMONITOR_HPP
#define CPP_POOL_RUSH01_IDISPLAYMONITOR_HPP


#include "IMonitorModule.hpp"
#include <vector>
class IDisplayMonitor
{
public:
	virtual void displayGKrellm(std::vector<std::string> &flags) = 0;
	virtual void addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules) = 0;
	virtual void updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top) = 0;
};


#endif //CPP_POOL_RUSH01_IDISPLAYMONITOR_HPP