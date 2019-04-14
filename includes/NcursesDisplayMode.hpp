//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#ifndef CPP_POOL_RUSH01_NCURSESDISPLAYMODE_HPP
#define CPP_POOL_RUSH01_NCURSESDISPLAYMODE_HPP


#include "IDisplayMonitor.hpp"

class NcursesDisplayMode : public virtual IDisplayMonitor
{
public:
	NcursesDisplayMode();
	NcursesDisplayMode(NcursesDisplayMode const &other);
	NcursesDisplayMode &operator=(NcursesDisplayMode const &other);
	virtual ~NcursesDisplayMode();

	void displayGKrellm(std::vector<std::string> &flags);
	void addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules);
	void	updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top) override;


};


#endif //CPP_POOL_RUSH01_NCURSESDISPLAYMODE_HPP