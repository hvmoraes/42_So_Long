# So_Long

A 2D tile-based game built with the MiniLibX graphics library as part of the 42 Lisboa curriculum. The project implements a Pac-Man inspired game where the player navigates a map, collects items, avoids or defeats enemies, and reaches the exit.

## Demo

https://user-images.githubusercontent.com/72853404/228872644-9970e69e-d1f4-47a0-ac6b-aedd3b66b08c.mp4

## Table of Contents

- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Map Format](#map-format)
- [Architecture](#architecture)
- [What I Learned](#what-i-learned)

## About

So_Long is a small 2D game project that introduces graphics programming in C using the MiniLibX library. The player controls a character that must collect all consumables on the map before reaching the exit, while avoiding enemies that roam the map. The game includes animated sprites, enemy AI with random movement, and a vulnerability mechanic.

**Grade:** 125/100 (with bonus)

## Features

- Tile-based map rendering with XPM textures
- Player movement with WASD keys
- Animated sprite frames for player and enemies
- Enemy AI with random directional movement
- Vulnerability timer mechanic — enemies become temporarily vulnerable
- Flood-fill path validation to ensure maps are solvable
- Movement counter displayed on-screen
- Closed-map validation (walls must surround the map)
- Win/lose conditions with score tracking

## Getting Started

### Prerequisites

- macOS (MiniLibX uses OpenGL and AppKit frameworks)
- `gcc` compiler
- `make`

### Building

```bash
git clone https://github.com/hvmoraes/42_So_Long.git
cd 42_So_Long
make
```

This compiles the MiniLibX library, the Libft library, and the game binary.

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Full rebuild
```

## Usage

```bash
./so_long Maps/small_map.ber
```

### Controls

| Key | Action     |
|-----|------------|
| W   | Move up    |
| A   | Move left  |
| S   | Move down  |
| D   | Move right |
| ESC | Quit game  |

## Map Format

Maps use the `.ber` extension with the following characters:

| Char | Meaning     |
|------|-------------|
| `1`  | Wall        |
| `0`  | Empty space |
| `P`  | Player      |
| `E`  | Exit        |
| `C`  | Consumable  |
| `X`  | Enemy       |

**Rules:**
- The map must be rectangular and fully enclosed by walls (`1`)
- Exactly one player (`P`) and one exit (`E`)
- At least one consumable (`C`) and one enemy (`X`)
- A valid path must exist from the player to all consumables and the exit

### Example Map

```
1111111111111
10010000000C1
1000011111001
1P0011E000X1
1111111111111
```

## Architecture

```
42_So_Long/
├── inc/
│   ├── so_long.h          # Main header with prototypes
│   ├── sl_macros.h        # Constants (tile size, keys, colors, images)
│   └── sl_structs.h       # Data structures (entities, map, game state)
├── src/
│   ├── core/
│   │   ├── main.c         # Entry point, key event handlers
│   │   ├── init.c         # Entity initialization (player, enemies, consumables)
│   │   ├── end.c          # Game end conditions (win, die, close, invalid)
│   │   └── free.c         # Memory cleanup and resource deallocation
│   ├── entities/
│   │   ├── pacman.c       # Player movement and collision logic
│   │   ├── enemy.c        # Enemy movement and wall collision
│   │   ├── gif.c          # Game loop (animation, rendering, enemy movement)
│   │   └── collision.c    # Enemy-player collision detection
│   ├── map/
│   │   ├── map_parsing.c  # Map reading, entity counting, pixel drawing
│   │   ├── map_validation.c # Map validation, exit rendering, vulnerability
│   │   ├── map_checks.c   # Closed-map and character validation
│   │   └── pathfinding.c  # Flood-fill pathfinding for map accessibility
│   ├── render/
│   │   ├── render.c       # Tile and sprite rendering
│   │   └── init_imgs.c    # XPM texture loading
│   └── utils/
│       ├── mallocs.c      # Memory allocation for game entities
│       └── get_next_line.c # Line-by-line file reading utility
├── Images/                # XPM sprite textures
├── Maps/                  # .ber map files
├── Libft/                 # Custom C standard library
├── mlx/                   # MiniLibX graphics library
└── Makefile
```

## What I Learned

- **Graphics programming in C** — working with a low-level graphics library (MiniLibX), managing image buffers, and rendering tiles per-pixel
- **Event-driven architecture** — handling keyboard input and game loop timing through callback hooks
- **Memory management** — tracking allocations across multiple subsystems (sprites, entities, map data) and ensuring complete cleanup on all exit paths
- **Map parsing and validation** — reading structured file formats, validating constraints, and implementing flood-fill algorithms for path accessibility
- **Game loop design** — balancing animation timing, entity updates, and rendering within a single frame callback
