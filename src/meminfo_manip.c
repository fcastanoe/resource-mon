#include "meminfo_manip.h"
#include <stdio.h>

int meminfo_read(mem_info_t *info) {
    FILE *f = fopen("/proc/meminfo", "r");
    if (!f) return -1;
    long total=0, avail=0, swap_total=0, swap_free=0;
    char label[64];
    long val;
    while (fscanf(f, "%63s %ld kB\n", label, &val) == 2) {
        if (strcmp(label, "MemTotal:") == 0) total = val;
        else if (strcmp(label, "MemAvailable:") == 0) avail = val;
        else if (strcmp(label, "SwapTotal:") == 0) swap_total = val;
        else if (strcmp(label, "SwapFree:") == 0) swap_free = val;
    }
    fclose(f);
    info->total_mb = total / 1024;
    info->swap_mb  = swap_total / 1024;
    info->used_pct = total ? ((total - avail) * 100.0 / total) : 0.0;
    info->swap_used_pct = swap_total ? ((swap_total - swap_free) * 100.0 / swap_total) : 0.0;
    return 0;
}
