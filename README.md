# resource-mon

Monitor de recursos en tiempo real: CPU y memoria usando `/proc` y una interfaz TUI con ncurses.

---

## Integrantes

- Fredy Andres Castaño Escobar (fcastanoe@unal.edu.co)

---

## Enlace al repositorio

https://github.com/fcastanoe/resource-mon

---

## Requerimientos

- GCC (build-essential)
- ncurses (libncurses5-dev, libncursesw5-dev)
- make

---

## Cómo compilar y ejecutar

Desde la raíz del proyecto:

```bash
make all           # Compila el monitor y los tests
./bin/resource_mon  # Ejecuta la TUI (presiona 'q' para salir)
make clean         # Limpia objetos y binarios
