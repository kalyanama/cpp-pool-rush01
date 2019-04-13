#include <sys/sysctl.h>
#include "CpuModule.hpp"
#define BUFFERLEN 128
CpuModule::CpuModule()
{
	updateValue();
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

void CpuModule::updateValue()
{
	char buffer[BUFFERLEN];
	size_t bufferlen = BUFFERLEN;
	sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);

	_value = buffer;
}
