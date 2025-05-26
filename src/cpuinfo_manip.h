#ifndef CPUINFO_MANIP_H
#define CPUINFO_MANIP_H

typedef struct {
    char vendor_id[32];
    char model_name[64];
    int cores;
    int threads;
    float *usage_percent;   // array dinámico de tamaño threads
} cpu_info_t;

/**
 * Inicializa la estructura cpu_info_t:
 *   - Extrae vendor_id y model_name de /proc/cpuinfo
 *   - Reserva el array usage_percent (tamaño = threads)
 * Retorna 0 en éxito, !=0 en error.
 */
int cpuinfo_init(cpu_info_t *info);

/**
 * Actualiza los porcentajes de uso por hilo leyendo /proc/stat.
 * Retorna 0 en éxito, !=0 en error.
 */
int cpuinfo_update_usage(cpu_info_t *info);

/**
 * Libera la memoria asociada a usage_percent.
 */
void cpuinfo_free(cpu_info_t *info);

#endif // CPUINFO_MANIP_H
