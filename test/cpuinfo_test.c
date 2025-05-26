#include "cpuinfo_manip.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    cpu_info_t info;
    if (cpuinfo_init(&info) != 0) {
        fprintf(stderr, "ERROR: cpuinfo_init failed\n");
        return 1;
    }
    // Chequear núm. threads y cores > 0
    if (info.threads <= 0 || info.cores <= 0) {
        fprintf(stderr, "FAIL: threads=%d, cores=%d\n", info.threads, info.cores);
        return 1;
    }
    // Chequear uso entre 0 y 100
    cpuinfo_update_usage(&info);
    for (int i = 0; i < info.threads; i++) {
        float u = info.usage_percent[i];
        if (u < 0.0 || u > 100.0) {
            fprintf(stderr, "FAIL: cpu%d usage out of range: %f\n", i, u);
            cpuinfo_free(&info);
            return 1;
        }
    }
    cpuinfo_free(&info);
    printf("OK: cpuinfo_test\n");
    return 0;
}
