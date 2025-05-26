#include "cpuinfo_manip.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables estáticas para cálculo de deltas
static unsigned long long *prev_times = NULL;
static int prev_count = 0;

int cpuinfo_init(cpu_info_t *info) {
    FILE *f = fopen("/proc/cpuinfo", "r");
    if (!f) return -1;
    // Inicializa defaults
    info->cores = 0; info->threads = 0;
    strcpy(info->vendor_id, "unknown");
    strcpy(info->model_name, "unknown");
    // Parse /proc/cpuinfo
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "vendor_id", 9) == 0 && info->vendor_id[0]=='u') {
            sscanf(line, "vendor_id : %31[^\n]", info->vendor_id);
        }
        if (strncmp(line, "model name", 10) == 0 && info->model_name[0]=='u') {
            sscanf(line, "model name : %63[^\n]", info->model_name);
        }
        if (strncmp(line, "processor", 9) == 0) {
            info->threads++;
        }
    }
    fclose(f);
    info->cores = info->threads;  
    // Reserva array de deltas
    info->usage_percent = calloc(info->threads, sizeof(float));
    // Prepara prev_times
    prev_count = info->threads;
    prev_times = calloc(prev_count, sizeof(unsigned long long)*4);
    // Inicializar prev_times leyendo una primera vez
    cpuinfo_update_usage(info);
    return 0;
}
int cpuinfo_update_usage(cpu_info_t *info) {
    FILE *f = fopen("/proc/stat", "r");
    if (!f) return -1;
    unsigned long long user, nice, system, idle;
    int idx = 0;
    char tag[16];
    while (fscanf(f, "%15s %llu %llu %llu %llu",
                  tag, &user, &nice, &system, &idle) == 5) {
        if (strncmp(tag, "cpu", 3) != 0 || strcmp(tag, "cpu") == 0) continue;
        unsigned long long total = user + nice + system + idle;
        unsigned long long prev_total = prev_times[idx*4+0] +
                                        prev_times[idx*4+1] +
                                        prev_times[idx*4+2] +
                                        prev_times[idx*4+3];
        unsigned long long total_delta = total - prev_total;
        unsigned long long busy_delta = (user - prev_times[idx*4+0])
                                      + (nice - prev_times[idx*4+1])
                                      + (system - prev_times[idx*4+2]);
        info->usage_percent[idx] = total_delta ? (busy_delta * 100.0 / total_delta) : 0.0;
        // Guarda para la siguiente
        prev_times[idx*4+0] = user;
        prev_times[idx*4+1] = nice;
        prev_times[idx*4+2] = system;
        prev_times[idx*4+3] = idle;
        idx++;
        if (idx >= info->threads) break;
    }
    fclose(f);
    return 0;
}

void cpuinfo_free(cpu_info_t *info) {
    free(info->usage_percent);
    free(prev_times);
    prev_times = NULL;
}
