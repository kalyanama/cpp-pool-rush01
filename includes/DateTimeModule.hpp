#ifndef CPP_POOL_RUSH01_DATETIMEMODULE_HPP
#define CPP_POOL_RUSH01_DATETIMEMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include <map>


class DateTimeModule: public virtual IMonitorModule
{
public:

	DateTimeModule(TopInfo const &top);
	DateTimeModule(DateTimeModule const &other);

	DateTimeModule &operator=(DateTimeModule const &other);

	virtual ~DateTimeModule();

	std::string &getValue();

	void update(TopInfo const &top);
	std::string &getModuleName();

private:
	DateTimeModule();
	static std::string _moduleName;
	std::string _value;
};


#endif //CPP_POOL_RUSH01_DATETIMEMODULE_HPP