#include "tui.h"
#include <ncurses.h>

static WINDOW *mainwin;

int tui_init(void) {
    if ((mainwin = initscr()) == NULL) return -1;
    noecho(); cbreak(); nodelay(stdscr, TRUE); keypad(stdscr, TRUE);
    return 0;
}

void tui_render(const cpu_info_t *cpu, const mem_info_t *mem) {
    clear();
    mvprintw(0, 0, "CPU: %s - %s", cpu->vendor_id, cpu->model_name);
    mvprintw(1, 0, "Cores: %d  Threads: %d", cpu->cores, cpu->threads);
    for (int i = 0; i < cpu->threads; i++) {
        mvprintw(3 + i, 0, "cpu%2d: %6.2f%%", i, cpu->usage_percent[i]);
    }
    int line = 3 + cpu->threads + 1;
    mvprintw(line++, 0, "Mem Total: %ld MB", mem->total_mb);
    mvprintw(line++, 0, "Mem Used:  %.2f%%", mem->used_pct);
    mvprintw(line++, 0, "Swap Total:%ld MB", mem->swap_mb);
    mvprintw(line++, 0, "Swap Used: %.2f%%", mem->swap_used_pct);
    mvprintw(line+1, 0, "Presiona 'q' para salir.");
    refresh();
}

int tui_getch(void) {
    return getch();
}

void tui_teardown(void) {
    delwin(mainwin);
    endwin();
}
