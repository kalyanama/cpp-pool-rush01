#ifndef CPP_POOL_RUSH01_OSINFOMODULE_HPP
#define CPP_POOL_RUSH01_OSINFOMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include <sys/utsname.h>

class OsInfoModule :  public virtual IMonitorModule
{
public:
	OsInfoModule(TopInfo const &top);

	OsInfoModule(OsInfoModule const &other);

	OsInfoModule &operator=(OsInfoModule const &other);

	virtual ~OsInfoModule();

	std::string &getValue() ;

	void update(TopInfo const &top);
	std::string &getModuleName();


private:
	OsInfoModule();
	static std::string _moduleName;
	std::string _value;
};


#endif //CPP_POOL_RUSH01_OSINFOMODULE_HPP