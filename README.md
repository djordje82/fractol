# fractol

42 Berlin | fractol

A fractal renderer written in C using [MiniLibX](https://github.com/42Paris/minilibx-linux). Draws the Mandelbrot set, Julia sets, and the Tricorn fractal, with interactive zoom and pan.

## Build

```sh
make
```

MiniLibX is cloned and built automatically into `./minilibx` on first build.

## Usage

```sh
./fractol mandelbrot
./fractol tricorn
./fractol julia [real imag]
```

- `mandelbrot` and `tricorn` take no extra arguments.
- `julia` optionally takes a complex constant `c = real + imag*i` (each in `[-2.0, 2.0]`). Without arguments it defaults to `c = -0.766667 - 0.09i`. Some example values are listed in `julias.txt`.

Running with no arguments, or with invalid input, prints a usage message.

## Controls

| Input | Action |
|---|---|
| Arrow keys | Pan the view |
| `+` / `-` | Zoom in / out |
| Mouse scroll | Zoom in / out |
| `Esc` | Close the window |

## Project layout

| File | Purpose |
|---|---|
| `main.c` | Entry point: input parsing, init, and the mlx render loop |
| `input_utils.c` | Argument parsing and validation |
| `render.c` | Pixel buffer rendering for each fractal type |
| `math_utils.c` | Escape-time calculations (Mandelbrot, Julia, Tricorn) and coloring |
| `events_hooks.c` | Window setup and keyboard/mouse event hooks |
| `string_utils.c` / `utils.c` | Custom libc-style helpers (`ft_atof`, `ft_strncmp`, error handling, ...) |
| `fractol.h` | Shared types, constants, and function prototypes |

## Cleaning up

```sh
make clean   # remove object files
make fclean  # also remove the binary and minilibx
make re      # fclean + all
```
