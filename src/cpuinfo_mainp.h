// src/cpuinfo_manip.h
#ifndef CPUINFO_MANIP_H
#define CPUINFO_MANIP_H

typedef struct {
    char vendor_id[32];
    char model_name[64];
    int cores;
    int threads;
    float *usage_percent;
} cpu_info_t;

int cpuinfo_init(cpu_info_t *info);
int cpuinfo_update_usage(cpu_info_t *info);
void cpuinfo_free(cpu_info_t *info);

#endif // CPUINFO_MANIP_H
