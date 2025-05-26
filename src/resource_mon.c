#include "cpuinfo_manip.h"
#include "meminfo_manip.h"
#include "tui.h"
#include <unistd.h>  // sleep()

int main(void) {
    cpu_info_t cpu;
    mem_info_t mem;
    if (tui_init() != 0) return 1;
    if (cpuinfo_init(&cpu) != 0) return 1;

    while (1) {
        if (tui_getch() == 'q') break;
        cpuinfo_update_usage(&cpu);
        meminfo_read(&mem);
        tui_render(&cpu, &mem);
        sleep(1);
    }

    cpuinfo_free(&cpu);
    tui_teardown();
    return 0;
}
