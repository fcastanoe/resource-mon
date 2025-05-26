#include "meminfo_manip.h"
#include <stdio.h>

int main(void) {
    mem_info_t mem;
    if (meminfo_read(&mem) != 0) {
        fprintf(stderr, "ERROR: meminfo_read failed\n");
        return 1;
    }
    // Chequear totales > 0 y porcentajes plausibles
    if (mem.total_mb <= 0 || mem.swap_mb < 0) {
        fprintf(stderr, "FAIL: total_mb=%ld, swap_mb=%ld\n", mem.total_mb, mem.swap_mb);
        return 1;
    }
    if (mem.used_pct < 0.0 || mem.used_pct > 100.0 ||
        mem.swap_used_pct < 0.0 || mem.swap_used_pct > 100.0) {
        fprintf(stderr, "FAIL: used_pct=%.2f, swap_used_pct=%.2f\n",
                mem.used_pct, mem.swap_used_pct);
        return 1;
    }
    printf("OK: meminfo_test\n");
    return 0;
}
