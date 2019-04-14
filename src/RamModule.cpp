
#include <RamModule.hpp>
#include <sys/sysctl.h>
#include <fstream>
#include <sstream>

#include "RamModule.hpp"

RamModule::RamModule(TopInfo const &top)
{
//	system("sysctl -n hw.memsize > /tmp/Mem_Size");
	int mib [] = { CTL_HW, HW_MEMSIZE };
	int64_t value = 0;
	size_t length = sizeof(value);

	sysctl(mib, 2, &value, &length, NULL, 0);

	_ramParams.insert(std::pair<std::string, int>("total",
			static_cast<float >(value/(1 << 20))));

	_value = "total: ";
	_value += std::to_string(value/(1 << 20)) + ";";
	update(top);
//	updateRamParams();
}

RamModule::RamModule(RamModule const &other)
{
	*this = other;
}

RamModule &RamModule::operator=(RamModule const &other)
{
	return *this;
}

RamModule::~RamModule()
{}

const std::map<std::string, float> &RamModule::getRamParams() const
{
	return _ramParams;
}

std::string &RamModule::getValue()
{
	return _value;
}

void RamModule::update(TopInfo const &top)
{
	std::map<std::string, std::string> temp;
	temp = top.getData();

	_value += temp["PhysMem"];
	updateRamParams( temp["PhysMem"]);
}

void RamModule::updateRamParams(std::string const &top)
{
	std::stringstream ss(top);

	float val;
	std::string key, skip;
	ss >> val >> skip >> key;

	_ramParams.insert(std::pair<std::string, float >(key, val));

	ss >> skip >> skip >> val >> skip >> key;
	_ramParams.insert(std::pair<std::string, float >(key, val));


}

std::string &RamModule::getModuleName()
{
	return RamModule::_moduleName;
}

std::string RamModule::_moduleName = "ram";

RamModule::RamModule()
{}

