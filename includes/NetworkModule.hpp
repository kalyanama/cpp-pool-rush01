#ifndef CPP_POOL_RUSH01_NETWORKMODULE_HPP
#define CPP_POOL_RUSH01_NETWORKMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class NetworkModule :  public virtual IMonitorModule
{
public:
	NetworkModule(TopInfo const &top);

	NetworkModule(NetworkModule const &other);

	NetworkModule &operator=(NetworkModule const &other);

	virtual ~NetworkModule();

	std::string &getValue();

	std::string &getModuleName() ;

	void update(TopInfo const &top) ;

	const std::map<std::string, std::string> &getNetworkParams() const;

private:
	NetworkModule();
	std::string _value;
	static std::string _moduleName;
	std::map<std::string, std::string> _networkParams;
	void updateParams();
};


#endif //CPP_POOL_RUSH01_NETWORKMODULE_HPP