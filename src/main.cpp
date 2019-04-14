#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <OsInfoModule.hpp>
#include <DateTimeModule.hpp>
#include <CpuModule.hpp>
#include <RamModule.hpp>
#include <NetworkModule.hpp>
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "TopInfo.hpp"


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

int main()
{
	TopInfo info = TopInfo();
	HostnameModule host = HostnameModule(info);
	UsernameModule user = UsernameModule(info);
	OsInfoModule os = OsInfoModule(info);
	DateTimeModule dt = DateTimeModule(info);
	CpuModule cpu = CpuModule(info);
	RamModule ram = RamModule(info);
	NetworkModule net = NetworkModule(info);

	std::cout << host.getValue() << std::endl;
	std::cout << user.getValue() << std::endl;
	std::cout << os.getValue() << std::endl;
	std::cout << dt.getValue() << std::endl;
	std::cout << cpu.getValue() << std::endl;
	std::cout << ram.getValue() << std::endl;
	std::cout << net.getValue() << std::endl;

	std::map<std::string, float> cpuParams = cpu.getCpuParameters();
	std::map<std::string, float> ramParams = ram.getRamParams();
	std::map<std::string, std::string> netParams = net.getNetworkParams();
	std::cout << "Cpu : " << std::endl;

	for(std::map<std::string, float >::const_iterator it = cpuParams.begin(); it != cpuParams.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << "\n";
	}
	std::cout << "Ram : " << std::endl;
	for(std::map<std::string, float >::const_iterator it = ramParams.begin(); it != ramParams.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << "\n";
	}
	std::cout << "Network : " << std::endl;
	for(std::map<std::string, std::string >::const_iterator it = netParams.begin(); it != netParams.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << "\n";
	}

	return 0;
}