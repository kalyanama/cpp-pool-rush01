//
// Created by Mykola MALANCHUK on 2019-04-14.
//

#ifndef CPP_POOL_RUSH01_TOPINFO_HPP
#define CPP_POOL_RUSH01_TOPINFO_HPP

#include <string>
#include <map>
#include <fstream>
class TopInfo
{
public:
	TopInfo();

	TopInfo(TopInfo const &other);

	TopInfo &operator=(TopInfo const &other);

	virtual ~TopInfo();

	const std::string &getTopInfo() const;

	void	update();

	const std::map<std::string, std::string> &getData() const;

private:
	std::string _topInfo;
	std::map<std::string, std::string> _data;
};


#endif //CPP_POOL_RUSH01_TOPINFO_HPP