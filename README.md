# fdf

Simple 3D wireframe viewer built with MiniLibX (Linux/X11).

This project reads a `.fdf` height map file and renders it as an isometric wireframe with interactive controls for zoom, translation, and rotation.

## Features

- Parse `.fdf` maps with altitude values and optional per-point hex colors.
- Draw wireframe lines between right and bottom neighbors.
- Interactive camera-style controls (move, zoom, rotate).
- Randomized visual theme on startup (background/panel/map colors).

## Requirements

- Linux
- `cc` (or `gcc`/`clang`)
- `make`
- X11 development libraries (commonly `libx11-dev` and `libxext-dev`)
- `zlib` development package

If needed on Debian/Ubuntu:

```bash
sudo apt update
sudo apt install build-essential libx11-dev libxext-dev zlib1g-dev
```

## Build

From the project root:

```bash
make
```

Useful targets:

```bash
make clean
make fclean
make re
```

## Run

```bash
./fdf maps/42.fdf
```

Any valid map in `maps/` can be used.

## Controls

- `Esc`: quit
- `Arrow keys`: translate
- `+` / `-` (keypad): zoom in / out
- `r`: rotate isometric angle
- `7` / `8` (keypad): rotate around x-axis
- `4` / `5` (keypad): rotate around y-axis
- `1` / `2` (keypad): rotate around z-axis

## Map Format

Each file is a grid of values separated by spaces.

- Basic point: `z`
- Colored point: `z,0xRRGGBB`

Example:

```text
0  0  0  0
0  1,0xFF0000  2,0x00FF00  0
0  0  0,0x0000FF  0
```

## Notes

- Program expects exactly one map file argument.
- Window size is initialized to `1300x800`.
- This repository includes `mlx_linux/` and `libft_pf_gnl/` as local dependencies used by the main Makefile.
