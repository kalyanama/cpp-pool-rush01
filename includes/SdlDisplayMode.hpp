//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#ifndef CPP_POOL_RUSH01_SDLDISPLAYMODE_HPP
#define CPP_POOL_RUSH01_SDLDISPLAYMODE_HPP


#include "IDisplayMonitor.hpp"

class SdlDisplayMode : public virtual IDisplayMonitor
{
public:
	SdlDisplayMode();
	SdlDisplayMode(SdlDisplayMode const &other);
	SdlDisplayMode &operator=(SdlDisplayMode const &other);
	virtual ~SdlDisplayMode();

	void displayGKrellm(std::vector<std::string> &flags);
	void	addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules);
	void	updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top);
};


#endif //CPP_POOL_RUSH01_SDLDISPLAYMODE_HPP