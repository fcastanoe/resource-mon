// src/tui.h
#ifndef TUI_H
#define TUI_H

#include "cpuinfo_manip.h"
#include "meminfo_manip.h"

int tui_init(void);
void tui_render(const cpu_info_t *cpu, const mem_info_t *mem);
int tui_getch(void);    // devuelve la tecla presionada
void tui_teardown(void);

#endif // TUI_H
