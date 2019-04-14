//
// Created by Mykola MALANCHUK on 2019-04-13.
//

#ifndef CPP_POOL_RUSH01_USERNAMEMODULE_HPP
#define CPP_POOL_RUSH01_USERNAMEMODULE_HPP


#include "IMonitorModule.hpp"

class UsernameModule : public virtual IMonitorModule
{
public:
	UsernameModule();

	UsernameModule(UsernameModule const &other);

	UsernameModule &operator=(UsernameModule const &other);

	virtual ~UsernameModule();

	std::string &getValue() ;

	void update() ;

private:
	std::string _value;
};


#endif //CPP_POOL_RUSH01_USERNAMEMODULE_HPP