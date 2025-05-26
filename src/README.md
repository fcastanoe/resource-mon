# src/

Código fuente de los módulos de procesamiento y la TUI.

---

## cpuinfo_manip

- **Estructura**:  
  ```c
  typedef struct {
      char vendor_id[32];
      char model_name[64];
      int cores;
      int threads;
      float *usage_percent;
  } cpu_info_t;

- **Funciones:**
  - ***int cpuinfo_init(cpu_info_t  info);***
    Inicializa vendor_id, model_name, cores, threads y reserva usage_percent.
  - ***int cpuinfo_update_usage(cpu_info_t  info);***
    Actualiza usage_percent[i] leyendo /proc/stat.
  - ***void cpuinfo_free(cpu_info_t  info);***
    Libera la memoria de usage_percent.

---

## meminfo_manip

- **Estructura**:  
  ```c
  typedef struct {
    long total_mb;
    long swap_mb;
    float used_pct;
    float swap_used_pct;
  } mem_info_t;

- **Funciones:**
  - ***int meminfo_read(mem_info_t  info);***
    Llena total_mb, swap_mb, used_pct, swap_used_pct a partir de /proc/meminfo.

---

## tui
- **Funciones:**
  - ***int tui_init(void);*** Inicializa ncurses.
  - ***void tui_render(const cpu_info_t  cpu, const mem_info_t   mem);*** Dibuja la pantalla con datos de CPU y memoria.
  - ***int tui_getch(void);*** Lee tecla sin bloqueo.
  - ***void tui_teardown(void);*** Fin de ncurses.

## resource_mon.c 

Programa principal: 

1. ***Inicializa TUI y CPU***

2. ***Loop:***
   - Lee tecla (salir con 'q')
   - Actualiza CPU y memoria
   - Renderiza datos
   - sleep(1)

3. ***Libera recursos y cierra TUI***






