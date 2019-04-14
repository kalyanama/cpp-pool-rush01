#include <sys/sysctl.h>
#include <CpuModule.hpp>
#include <sstream>
#include "CpuModule.hpp"

#define BUFFERLEN 128

static int getCoreNums()
{
	int mib[4];
	int numCPU;
	size_t len = sizeof(numCPU);

/* set the mib for hw.ncpu */
	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;

/* get the number of CPUs from the system */
	sysctl(mib, 2, &numCPU, &len, NULL, 0);

	return numCPU;
}

CpuModule::CpuModule(TopInfo const &top)
{
	update(top);
	_value.push_back(';');
	setCpuName();
	_value.push_back(';');
	_value += "cores=";
	_value += std::to_string(getCoreNums());
	updateParams();
}

CpuModule::CpuModule(CpuModule const &other)
{
	*this = other;
}

CpuModule &CpuModule::operator=(CpuModule const &other)
{
	return *this;
}

CpuModule::~CpuModule()
{}


std::string &CpuModule::getValue()
{
	return _value;
}

void CpuModule::update(TopInfo const &top)
{
	std::map<std::string, std::string> temp;
	temp = top.getData();

	_value = temp["CPU usage"];
	updateParams();
}

std::map<std::string, float> CpuModule::getCpuParameters()
{
	return _map;
}

void CpuModule::setCpuName()
{
	char buffer[BUFFERLEN];
	size_t bufferlen = BUFFERLEN;
	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);

	_value += buffer;
}

void CpuModule::updateParams()
{
	std::stringstream ifs(_value);
	std::string skip, user_key, sys_key, idle_key;

	float user_value, sys_value, idle_value;


	ifs >> user_value >> skip >> user_key
		>> sys_value >> skip >> sys_key
		>> idle_value >> skip >> idle_key;


	user_key.erase(user_key.size() - 1);
	sys_key.erase(sys_key.size() - 1);

	_map.insert(std::pair<std::string, float>(user_key, user_value));
	_map.insert(std::pair<std::string, float>(sys_key, sys_value));
	_map.insert(std::pair<std::string, float>(idle_key, idle_value));
//	_map.insert(std::pair<std::string, float>("cores", getCoreNums()));
}

std::string &CpuModule::getModuleName()
{
	return CpuModule::_moduleName;
}

std::string CpuModule::_moduleName = "cpu";

CpuModule::CpuModule()
{}
