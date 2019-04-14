//
// Created by Mykola MALANCHUK on 2019-04-13.
//

#ifndef CPP_POOL_RUSH01_USERNAMEMODULE_HPP
#define CPP_POOL_RUSH01_USERNAMEMODULE_HPP


#include "IMonitorModule.hpp"

class UsernameModule : public virtual IMonitorModule
{
public:
	UsernameModule(TopInfo const &top);

	UsernameModule(UsernameModule const &other);

	UsernameModule &operator=(UsernameModule const &other);

	virtual ~UsernameModule();

	std::string &getValue() ;

	void update(TopInfo const &top);

	std::string &getModuleName();

private:
	UsernameModule();
	static std::string _moduleName;
	std::string _value;
};


#endif //CPP_POOL_RUSH01_USERNAMEMODULE_HPP