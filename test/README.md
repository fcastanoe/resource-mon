# test/

Tests unitarios para cada módulo.

---

## cpuinfo_test.c

- Verifica:
  - `cpuinfo_init()` retorna 0 y `threads > 0`, `cores > 0`.
  - `cpuinfo_update_usage()` produce `usage_percent[i]` en [0,100].
  - Limpieza con `cpuinfo_free()`.
- Resultado esperado:
  ```
  OK: cpuinfo_test
---

## meminfo_test.c

- Verifica:
  - `meminfo_read()` retorna 0.
  - `total_mb > 0`, `swap_mb >= 0`.
  - `used_pct` y `swap_used_pct` en [0,100].
- Resultado esperado:
  ```
  OK: meminfo_test
---

## tui_test.c

- Verifica:
  - `tui_init()` y `tui_teardown()` retornan sin error.
  - `tui_render()` y `tui_getch()` se pueden invocar sin fallos.
- Resultado esperado:
  ```
  OK: tui_test 
