//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#include "SdlDisplayMode.hpp"
#include <iostream>
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "TopInfo.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"

SdlDisplayMode::SdlDisplayMode()
{}

SdlDisplayMode::SdlDisplayMode(SdlDisplayMode const &other)
{
	*this = other;
}

SdlDisplayMode &SdlDisplayMode::operator=(SdlDisplayMode const &other)
{
	return *this;
}

SdlDisplayMode::~SdlDisplayMode()
{}


void SdlDisplayMode::addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules)
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

void	SdlDisplayMode::updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top)
{
	top.update();
	for (std::vector<IMonitorModule *>::iterator it = modules.begin();  it < modules.end(); ++it)
	{
		(*it)->update(top);
	}
}

void SdlDisplayMode::displayGKrellm(std::vector<std::string> &flags)
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
