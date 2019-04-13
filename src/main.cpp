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

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
    unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
    unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
    float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
    _previousTotalTicks = totalTicks;
    _previousIdleTicks  = idleTicks;
    return ret;
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.
float GetCPULoad()
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
    {
        unsigned long long totalTicks = 0;
        for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
        return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
    }
    else return -1.0f;
}
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
//	std::cout << get_cpu_freq() << std::endl;
//	std::cout << GetCPULoad() << std::endl;
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
//	PrintMacOsXVersion();
	return 0;
}