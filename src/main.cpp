#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "TopInfo.hpp"
#include "NcursesDisplayMode.hpp"
#include "GraphicalUI.hpp"

//Test functr
uint64_t get_cpu_freq(void)
{
	uint64_t freq = 0;
	size_t size = sizeof(freq);

	if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
	{
		perror("sysctl");
	}
	return freq;
}
void PrintMacOsXVersion()
{

	struct utsname uts;
	uname(&uts);
	std::cout << uts.sysname << std::endl;
	std::cout << uts.nodename << std::endl;
	std::cout << uts.release << std::endl;
	std::cout << uts.version << std::endl;
	std::cout << uts.machine << std::endl;


}

void ncurses(std::vector<std::string> & flags)
{
	IDisplayMonitor *ncursesDisplay = new NcursesDisplayMode();

	ncursesDisplay->displayGKrellm(flags);
}

void graphic(std::vector<std::string> & flags)
{
	IDisplayMonitor *graphicalUI = new GraphicalUI();

	graphicalUI->displayGKrellm(flags);
}

void	printUsage()
{
	std::cout << "Usage :" << std::endl;
	std::cout << "0 :\t\t" << "--\t\t ncurses mode" << std::endl;
	std::cout << "1 :\t\t" << "--\t\t sdl mode" << std::endl;
	std::cout << "Flags :\t\t" << std::endl;
	std::cout << "-c :\t\t" << "--\t\t add cpu module" << std::endl;
	std::cout << "-m :\t\t" << "--\t\t add memory module" << std::endl;
	std::cout << "-n :\t\t" << "--\t\t add network module" << std::endl;

	exit(EXIT_FAILURE);
}

std::vector<std::string> &getFlags(int argc, char **argv)
{
	std::vector<std::string> flags;

	for (int i = 2; i < argc; ++i)
	{
		if (strcmp(argv[i], "-c")  == 0 || strcmp(argv[i], "-m")  == 0 || strcmp(argv[i], "-n")  == 0)
			flags.push_back(argv[i]);
		else
			printUsage();
	}
	return flags;
}
int main(int argc, char **argv)
{

	if (argc < 2)
		printUsage();
	else
	{
		if (strcmp(argv[1], "0") == 0)
			ncurses(getFlags(argc, argv));
		else if (strcmp(argv[1], "1") == 0)
			graphic(getFlags(argc, argv));
		else
			printUsage();
	}
	return 0;
}
//int main(int argc, char **argv)
//{
//
//	TopInfo info = TopInfo();
//	HostnameModule host = HostnameModule(info);
//	UsernameModule user = UsernameModule(info);
//	OsInfoModule os = OsInfoModule(info);
//	DateTimeModule dt = DateTimeModule(info);
//	CpuModule cpu = CpuModule(info);
//	RamModule ram = RamModule(info);
//	NetworkModule net = NetworkModule(info);
//
//	std::cout << host.getValue() << std::endl;
//	std::cout << user.getValue() << std::endl;
//	std::cout << os.getValue() << std::endl;
//	std::cout << dt.getValue() << std::endl;
//	std::cout << cpu.getValue() << std::endl;
//	std::cout << ram.getValue() << std::endl;
//	std::cout << net.getValue() << std::endl;
//
//	std::map<std::string, float> cpuParams = cpu.getCpuParameters();
//	std::map<std::string, float> ramParams = ram.getRamParams();
//	std::map<std::string, std::string> netParams = net.getNetworkParams();
//	std::cout << "Cpu : " << std::endl;
//
//	for(std::map<std::string, float >::const_iterator it = cpuParams.begin(); it != cpuParams.end(); ++it)
//	{
//		std::cout << it->first << " => " << it->second << "\n";
//	}
//	std::cout << "Ram : " << std::endl;
//	for(std::map<std::string, float >::const_iterator it = ramParams.begin(); it != ramParams.end(); ++it)
//	{
//		std::cout << it->first << " => " << it->second << "\n";
//	}
//	std::cout << "Network : " << std::endl;
//	for(std::map<std::string, std::string >::const_iterator it = netParams.begin(); it != netParams.end(); ++it)
//	{
//		std::cout << it->first << " => " << it->second << "\n";
//	}
//
//	return 0;
//}