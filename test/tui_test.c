#include "tui.h"
#include <stdio.h>

int main(void) {
    // Init
    if (tui_init() != 0) {
        fprintf(stderr, "ERROR: tui_init failed\n");
        return 1;
    }
    // Render con datos de prueba
    cpu_info_t cpu = {.vendor_id="Test", .model_name="TUI", .cores=1, .threads=1};
    float arr[1] = {0.0f};
    cpu.usage_percent = arr;
    mem_info_t mem = {.total_mb=100, .swap_mb=50, .used_pct=10.0f, .swap_used_pct=5.0f};
    // Llamamos render y getch, debería devolver ERR (no hay input)
    tui_render(&cpu, &mem);
    int ch = tui_getch();
    (void)ch;
    // Tear down
    tui_teardown();
    printf("OK: tui_test\n");
    return 0;
}
