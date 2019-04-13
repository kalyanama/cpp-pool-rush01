#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{}

NetworkModule::NetworkModule(NetworkModule const &other)
{
	*this = other;
}

NetworkModule &NetworkModule::operator=(NetworkModule const &other)
{
	return *this;
}

NetworkModule::~NetworkModule()
{}