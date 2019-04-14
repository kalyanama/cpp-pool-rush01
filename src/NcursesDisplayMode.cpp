//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#include "NcursesDisplayMode.hpp"
#include <iostream>
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "TopInfo.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"

NcursesDisplayMode::NcursesDisplayMode()
{}

NcursesDisplayMode::NcursesDisplayMode(NcursesDisplayMode const &other)
{
	*this = other;
}

NcursesDisplayMode &NcursesDisplayMode::operator=(NcursesDisplayMode const &other)
{
	return *this;
}

NcursesDisplayMode::~NcursesDisplayMode()
{}

void NcursesDisplayMode::addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules)
{

	for (std::vector<std::string>::iterator it = flags.begin();  it < flags.end(); ++it)
	{
		if (*it == "-c")
			modules.push_back(new CpuModule(top));
		if (*it == "-m")
			modules.push_back(new RamModule(top));
		if (*it == "-n")
			modules.push_back(new NetworkModule(top));

	}
}

void	NcursesDisplayMode::updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top)
{
	top.update();
	for (std::vector<IMonitorModule *>::iterator it = modules.begin();  it < modules.end(); ++it)
	{
		(*it)->update(top);
	}
}

void NcursesDisplayMode::displayGKrellm(std::vector<std::string> &flags)
{
	TopInfo top = TopInfo();

	std::vector<IMonitorModule *>  modules;
	modules.push_back(new HostnameModule(top));
	modules.push_back(new UsernameModule(top));
	modules.push_back(new OsInfoModule(top));
	modules.push_back(new DateTimeModule(top));

	if (flags.size() > 0)
		addModules(flags, top, modules);

	//main loop
//	while (condition)
//	{
//		updateModules(modules, top);
//	}
}
