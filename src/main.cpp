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
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"

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
	HostnameModule host = HostnameModule();
	UsernameModule user = UsernameModule();
	OsInfoModule os = OsInfoModule();
	DateTimeModule dt = DateTimeModule();
	CpuModule cpu = CpuModule();

	std::cout << host.getValue() << std::endl;
	std::cout << user.getValue() << std::endl;
	std::cout << os.getValue() << std::endl;
	std::cout << dt.getValue() << std::endl;
	std::cout << cpu.getValue() << std::endl;
	std::map<std::string, float> cpuParams = cpu.getCpuParameters();

	for(std::map<std::string, float >::const_iterator it = cpuParams.begin(); it != cpuParams.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << "\n";
	}

	//	PrintMacOsXVersion();
	return 0;
}