# resource-mon

Monitor de recursos en tiempo real: CPU y memoria usando `/proc` y una interfaz TUI con ncurses.

---

## Integrantes

- Fredy Andres Castaño Escobar (fcastanoe@unal.edu.co)

---

## Requerimientos

- GCC (build-essential)
- ncurses (libncurses5-dev, libncursesw5-dev)
- make

---

## Estructura de Carpetas
```bash
.
├── bin/               ← ejecutables (resource_mon y tests)
├── obj/               ← archivos objeto (.o)
├── src/               ← código fuente
│   ├── cpuinfo_manip.c/h
│   ├── meminfo_manip.c/h
│   ├── tui.c/h
│   └── resource_mon.c
├── test/              ← tests unitarios
│   ├── cpuinfo_test.c
│   ├── meminfo_test.c
│   └── tui_test.c
├── Makefile
└── README.md         
```
---

## Cómo compilar y ejecutar

Desde la raíz del proyecto:

```bash
make all           # Compila el monitor y los tests
./bin/resource_mon  # Ejecuta la TUI (presiona 'q' para salir)
make clean         # Limpia objetos y binarios
```


