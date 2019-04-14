//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#include "TopInfo.hpp"
#include <iostream>
#include <sstream>

TopInfo::TopInfo()
{
 	update();
}

TopInfo::TopInfo(TopInfo const &other)
{
	*this = other;
}

TopInfo &TopInfo::operator=(TopInfo const &other)
{
	return *this;
}

TopInfo::~TopInfo()
{}

const std::string &TopInfo::getTopInfo() const
{
	return _topInfo;
}



void TopInfo::update()
{
	system(" top -l 1 | head -10 > /tmp/topInfo");

	std::ifstream ifs("/tmp/topInfo");
	if (!ifs)
	{
		std::cerr << "Error reading from /tmp/topInfo" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string in;
	std::string skip;


	for (int i = 0; i < 10; ++i)
	{
		std::getline(ifs, in);
		if (i == 0 || i == 2 || i == 3 || i == 6 || i == 8)
		{
			std::stringstream ss(in);
			_data.insert(std::pair<std::string, std::string>(
					in.substr(0, in.find(":")),
					in.substr(in.find_first_of(":")+2)
			));
		}
		if (i == 1)
		{
			_data.insert(std::pair<std::string, std::string>(
					"datetime", in
			));
		}
	}
}

const std::map<std::string, std::string> &TopInfo::getData() const
{
	return _data;
}



