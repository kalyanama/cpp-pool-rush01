#ifndef CPP_POOL_RUSH01_DATETIMEMODULE_HPP
#define CPP_POOL_RUSH01_DATETIMEMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"


class DateTimeModule: public virtual IMonitorModule
{
public:
	DateTimeModule();

	DateTimeModule(DateTimeModule const &other);

	DateTimeModule &operator=(DateTimeModule const &other);

	virtual ~DateTimeModule();

	std::string &getValue() override;

	void updateValue() override;

private:
	std::string _value;
};


#endif //CPP_POOL_RUSH01_DATETIMEMODULE_HPP