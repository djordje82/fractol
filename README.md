*This project has been created as part of the 42 curriculum by dodordev.*

# fract'ol

42 Berlin | Computer Graphics Fractals

## Description

`fractol` is a small fractal exploration program written in C using the school's [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library. It opens a window and renders, pixel by pixel, one of three fractals computed with the escape-time algorithm:

- **Mandelbrot set**
- **Julia set** (parametrizable with a custom complex constant)
- **Tricorn** (the Mandelbrot set's antiholomorphic cousin — extra fractal, bonus)

The view can be panned and zoomed smoothly and near-infinitely, with the zoom centered on the current mouse cursor position (bonus). Iteration counts are mapped to a smooth RGB gradient so the depth and structure of each fractal is visible.

The goal of the project was to get familiar with MiniLibX (window/image management, event hooks), practice working with complex numbers, and get a first taste of computer graphics and performance considerations.

## Instructions

### Build

```sh
make
```

MiniLibX is cloned and compiled automatically into `./minilibx` on first build.

### Run

```sh
./fractol mandelbrot
./fractol tricorn
./fractol julia [real imag]
```

- `mandelbrot` and `tricorn` take no extra arguments.
- `julia` optionally takes a complex constant `c = real + imag*i` (each in `[-2.0, 2.0]`). Without arguments it defaults to `c = -0.766667 - 0.09i`. Some example values to try are listed in `julias.txt`.

Running with no arguments, or with invalid input, prints a usage message and exits.

### Controls

| Input | Action |
|---|---|
| Arrow keys | Pan the view |
| `+` / `-` | Zoom in / out (centered on screen) |
| Mouse scroll | Zoom in / out (centered on cursor) |
| `Esc` / window close button | Close the window and quit cleanly |

### Cleaning up

```sh
make clean   # remove object files
make fclean  # also remove the binary and minilibx
make re      # fclean + all
```

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

## Technical notes

Each fractal uses the same escape-time approach: for every pixel, the corresponding point in the complex plane is iterated through `z = z² + c` (or the conjugate variant for Tricorn) up to `MAX_ITER` times, escaping as soon as `|z|² > 4`. The number of iterations before escaping determines the pixel's color via a cubic-polynomial RGB gradient (`generate_color` in `math_utils.c`), giving smooth-looking bands instead of harsh iteration-count stripes.

Panning and zooming work by keeping track of a `shift_x`/`shift_y` offset and a `zoom` factor in the `t_fractal` struct; screen coordinates are converted to complex-plane coordinates on every redraw, and the mouse-wheel handler recenters the offset on the cursor's complex coordinate before scaling, so the point under the cursor stays fixed while zooming.

## Bonus features implemented

- An extra fractal type: **Tricorn**.
- Zoom centered on the actual mouse cursor position, not just the screen center.
- View panning with the arrow keys, in addition to zooming.

## Resources

- [MiniLibX documentation (42 Paris)](https://github.com/42Paris/minilibx-linux)
- [Wikipedia — Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Wikipedia — Julia set](https://en.wikipedia.org/wiki/Julia_set)
- [Wikipedia — Tricorn (mathematics)](https://en.wikipedia.org/wiki/Tricorn_(mathematics))
- [Wikipedia — Complex number](https://en.wikipedia.org/wiki/Complex_number)

### AI usage

AI (Claude) was used solely to write and expand this `README.md` file, based on a review of the existing source code and the project subject (`fractol.md`). No part of the C source code was generated or modified by AI.
