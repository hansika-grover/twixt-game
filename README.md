# twixt-game

A terminal implementation of [Twixt](https://en.wikipedia.org/wiki/TwIxt) — the two-player connection board game — written in C.

This was originally built as a course project for a Computer Programming course. After submission I went back, fixed a few rough edges (input handling, state bugs, build setup), and brought it to a cleaner, more complete state. The core game logic — board representation, knight-move linking, crossing detection, and win checking — was all part of the original submission.

---

## What is Twixt?

Twixt is an abstract strategy game played on a 24×24 grid. Two players place pegs and connect them with links, each trying to build an unbroken chain between their two border edges before the opponent does.

- **Red (R)** needs to connect the **top edge to the bottom edge** (row 0 → row 23)
- **Blue (B)** needs to connect the **left edge to the right edge** (col 0 → col 23)

Links form between pegs that are a **knight's move** apart (like in chess — `±1` in one direction and `±2` in the other). The key constraint: **links cannot cross each other**, so you're constantly routing around your opponent's network while trying to keep your own connected.

The game ends when one player completes a chain, or the board fills completely (draw).

---

## Building

You need `gcc` and `make`. Works on Linux, macOS, and WSL on Windows.

```bash
git clone <your-repo-url>
cd twixt-c
make
```

The binary is `./twixt`. To rebuild from scratch:

```bash
make clean && make
```

There's also a `make run` target if you want to build and launch in one step.

---

## Running

```bash
./twixt
```

You'll land at the main menu:

```
Welcome, Choose an option:
1. start new game
2. quit
```

---

## How to play

### In-game menu

Once a game starts, each turn you choose what to do:

```
1. put a peg
2. see all links
3. go back to menu
```

### Placing a peg

Choose option `1`, then enter the **row** and **column** separated by a space:

```
which spot? enter row then column: 5 3
```

Coordinates are **zero-indexed**. The board runs from `(0, 0)` at the top-left to `(23, 23)` at the bottom-right.

### Border rules

Each player owns two opposite edges and can only place on their own borders — not the opponent's:

| Player | Wins by connecting | Owns | Cannot place on |
|--------|--------------------|------|-----------------|
| R (Red) | row 0 ↔ row 23 | top and bottom rows | col 0, col 23 |
| B (Blue/Black) | col 0 ↔ col 23 | left and right columns | row 0, row 23 |

The four corner squares `(0,0)`, `(0,23)`, `(23,0)`, `(23,23)` are off-limits for both players.

### Links

After every peg placement, the game automatically creates links to any of your existing pegs that are a knight's move away. You don't have to do anything manually. A link won't form if it would cross an existing link — yours or your opponent's.

You can type `2` at any point during your turn to see a full list of all links on the board.

### Sample board state

```
----------------------------------------------------------------------------
R goes top to bottom, B goes left to right
----------------------------------------------------------------------------
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
 0   .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
 1   .  R  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
 2   .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
 3   .  .  R  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
```

R at `(1,1)` and `(3,2)` are a knight's move apart (`dr=2, dc=1`) so a link is automatically created between them.

---

## Project structure

```
.
├── main.c       entry point, main menu loop
├── game.c/h     game state globals, menus, peg placement, game loop
├── board.c/h    grid initialisation and rendering
├── links.c/h    knight-move link creation and crossing checks
├── geom.c/h     line-segment intersection geometry
├── valid.c/h    move validation (bounds, edge ownership, duplicates)
├── win.c/h      win detection using a flood-fill through the link graph
├── input.c/h    scanf wrappers with consistent EOF and error handling
└── Makefile
```

The geometry in `geom.c` uses an orientation-based segment intersection test to enforce the no-crossing rule. It works correctly here because knight-move segments on an integer lattice have no interior lattice points ; so no peg can ever sit in the middle of an existing link, which eliminates a whole class of edge cases.

---

## Limitations and known differences from the original game

**Auto-linking.** In the physical board game, placing a link between two pegs is a deliberate choice, and you can skip links you don't want. Here, links form automatically on every placement. This simplifies the interface but removes a real layer of strategy ; sometimes in proper Twixt you intentionally leave a connection unmade because it would block a better one later.

**No swap rule.** The first player (Red) has a well-documented opening advantage in Twixt. Competitive play typically includes a "swap" option letting the second player take Red's first move instead. That's not implemented here ; whoever goes first plays Red.

**Two players only.** No AI opponent. Both players share the same keyboard.

**No link removal.** Once a link is placed, it stays. The original game allows removing your own links.

---

## License

MIT — see [LICENSE](LICENSE).
