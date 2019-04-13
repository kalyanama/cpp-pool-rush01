#include "CpuModule.hpp"

CpuModule::CpuModule()
{}

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