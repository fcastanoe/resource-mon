// src/meminfo_manip.h
#ifndef MEMINFO_MANIP_H
#define MEMINFO_MANIP_H

typedef struct {
    long total_mb;
    long swap_mb;
    float used_pct;
    float swap_used_pct;
} mem_info_t;

int meminfo_read(mem_info_t *info);

#endif // MEMINFO_MANIP_H
