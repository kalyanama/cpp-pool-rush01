
#include <sstream>
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

std::string &NetworkModule::getValue()
{
	return _value;
}

std::string &NetworkModule::getModuleName()
{
	return NetworkModule::_moduleName;
}

void NetworkModule::update(TopInfo const &top)
{
	std::map<std::string, std::string> temp;
	temp = top.getData();

	_value = temp["Networks"];
	updateParams();
}

std::string NetworkModule::_moduleName = "network";

NetworkModule::NetworkModule(TopInfo const &top)
{
	update(top);
}

const std::map<std::string, std::string> &NetworkModule::getNetworkParams() const
{
	return _networkParams;
}



void NetworkModule::updateParams()
{
	std::stringstream ifs(_value);
	std::string skip, key1, val1, key2, val2;


	ifs >> skip >> val1 >> key1 >> val2 >> key2;

	key1.erase(key1.size() - 1);
	key2.erase(key2.size() - 1);
	_networkParams.insert(std::pair<std::string, std::string >(key1, val1));
	_networkParams.insert(std::pair<std::string, std::string >(key2, val2));


}
