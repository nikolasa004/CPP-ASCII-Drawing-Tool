# C++ ASCII Drawing Tool

A small console-based drawing program I made while practicing C++. It lets you place shapes and text on a coordinate grid using ordinary characters, combine them into larger drawings, erase parts of them, and undo or redo changes.

This wasn't a university assignment or an attempt to build a proper graphics editor. I just wanted to get more comfortable writing C++ and thought it would be fun to see how much I could draw using nothing but the terminal.

## How it started

When I was first getting used to C++, I wanted to make something a little more interesting than a collection of small exercises. Drawing seemed like a good excuse to work with classes, coordinates, loops, and data structures while still being able to *see* what the program was doing.

The idea was simple: start with an empty grid, ask the user what they want to draw, and turn the input into characters placed at particular coordinates. Eventually I added several shapes, text in different directions, overlapping priorities, erasing, and a short undo/redo history.

It's a fairly rough early project, and it definitely has its quirks, but I enjoyed experimenting with it.

## What can it draw?

The program starts with an empty coordinate grid. You choose a drawing command and enter the shape's properties and position.

![Empty ASCII coordinate grid at the start of the program](docs/images/Screenshot%202026-10-24%20163656.png)

There are several basic shapes, including squares, rectangles, triangles, circles, and straight or diagonal lines. You can also draw text, hearts, and a couple of more unusual predefined shapes.

### Triangles, circles, and other shapes

Most shapes can be rotated and drawn as outlines or be filled. The screenshots below show two simple examples:

| An outline triangle | A filled circle |
| :---: | :---: |
| ![Outline triangle drawn on the ASCII grid](docs/images/Screenshot%202026-10-24%20170439.png) | ![Filled circle created using ASCII characters](docs/images/Screenshot%202026-10-24%20170534.png) |

I also added a heart, represented by a small pattern of asterisks. Text can be placed horizontally, vertically, or diagonally.

| A heart | Text overlapping a heart |
| :---: | :---: |
| ![Heart drawn using asterisks on the grid](docs/images/Screenshot%202026-10-24%20170933.png) | ![Hello world text crossing a heart while the heart remains visible in front](docs/images/Screenshot%202026-10-24%20171023.png) |

There are even commands for drawing a **cross** and a **coffin**. My family works with funeral equipment, so I suppose those were unusually natural additions for me to make to a drawing program.

## Building a little house

The shapes can be combined to make something more recognizable. I tried putting together a very simple house using several separate drawing and erasing operations.

### 1. Draw the ground

I started with a wide, filled rectangle at the bottom of the grid. It looks a little like grass, even if it's just a lot of `/` characters.

![Wide filled rectangle used as the ground](docs/images/Screenshot%202026-10-24%20164225.png)

### 2. Add the house

Next I placed a filled square above it to make the main body of the house.

![Filled square forming the house over the ground](docs/images/Screenshot%202026-10-24%20164452.png)

### 3. Erase a doorway

The tool also supports erasing by selecting a rectangular area or a line. I used the rectangular eraser to remove part of the house and make an opening for the door.

![Rectangular erasing creates a doorway in the house](docs/images/Screenshot%202026-10-24%20164818.png)

### 4. Add a straight line

Then I drew a horizontal line above the house as the beginning of the roof.

![Horizontal line drawn across the top of the house](docs/images/Screenshot%202026-10-24%20165405.png)

### 5. Try a diagonal line

Finally, I added a slanted line to start shaping the roof. This is where I stopped taking screenshots of the house, but it shows how the individual operations can be combined.

![Diagonal line extending upward from the house roof](docs/images/Screenshot%202026-10-24%20170144.png)

The result is hardly architectural art, but the fun part was being able to construct a drawing one operation at a time instead of hardcoding the entire picture.

## Drawing options and controls

Different shapes ask for different properties, such as:

- **Position:** X and Y coordinates on the grid.
- **Size:** side length, width, height, radius, or endpoints, depending on the shape.
- **Fill:** whether supported shapes should be hollow or filled.
- **Direction:** for lines, text, and triangle orientation where applicable.
- **Level:** a numeric priority that determines which character stays visible when shapes overlap.

That last option is one of the more interesting parts. **A higher level takes priority over a lower one**, regardless of which shape was drawn first. In the heart-and-text screenshot, for example, I drew the heart first at a higher level and then added `Hello world!` at a lower level. The text crosses the same area, but the heart remains visible in front of it.

The main commands are entered in Serbian, as they were in my original version:

| Command | Action |
| --- | --- |
| `unos` | Draw a shape or add text |
| `brisanje` | Erase an area using a rectangle or line |
| `nazad` | Undo the last change |
| `napred` | Redo an undone change |
| `kraj` | Exit the program |

Inside `unos`, you can choose commands such as `kvadrat`, `pravougaonik`, `linija`, `trougao`, `krug`, `tekst`, and `srce`. The `sztr_Savic` submenu contains the cross and coffin shapes.

The grid uses logical X and Y coordinates from **0 to 39**. The horizontal axis is displayed with extra character spacing to make the drawn shapes look less compressed. The letters along the top mark groups of ten X positions, but you still enter ordinary numeric coordinates - for example, `23` rather than `B3`.

## A little about the code

The implementation uses a small object-oriented structure rather than putting the drawing logic for every shape directly into `main()`.

- `Oblik` is an abstract base class for the shapes. Derived classes implement `unosOblika()` to collect their parameters and `vratiTacke()` to generate the points to draw.
- `Tacka` stores the position and character to display at a particular location.
- Each shape has its own `.cpp` and `.h` files, such as `Kvadrat`, `Pravougaonik`, `Trougao`, `Krug`, `Linija`, `Tekst`, and `Srce`.
- `Grafika.cpp` holds the main menu, console grid, drawing routine, layer-priority handling, and undo/redo logic.

The screen is represented using a two-dimensional `vector` of strings. When a shape is drawn, it generates a list of points, and the main drawing routine decides which characters to put on the grid. An `unordered_map` stores the drawing level assigned to individual positions so new shapes can be compared with what is already there.

For **Undo/Redo**, I kept copies of previous screen states in two vectors, with a history limit of ten steps. It's a simple solution, but it was a useful exercise in managing application state.

## Running the project

The original project was made in **Visual Studio** and contains a Visual C++ solution. There are no external graphics libraries - the drawing is done with standard C++ console output.

1. Clone or download the repository.
2. Open **`Grafika/Grafika.sln`** in Visual Studio with C++ desktop development tools installed.
3. Build the solution and run it as a console application (for example, with **Ctrl+F5**).
4. Type a command from the menu and follow the prompts. Required fields are marked with `*`; some optional fields allow `/` to select the default.

For the grid to line up properly, use a **monospaced terminal font** and a window wide enough to display the full drawing area.

## Repository structure

```text
CPP-ASCII-Drawing-Tool/
├── Grafika/
│   ├── Grafika.sln
│   ├── Beleske.txt
│   └── Grafika/
│       ├── Grafika.cpp
│       ├── Grafika.vcxproj
│       ├── Grafika.vcxproj.filters
│       ├── Oblik.h
│       ├── Tacka.h
│       ├── Kvadrat.cpp / .h
│       ├── Pravougaonik.cpp / .h
│       ├── Trougao.cpp / .h
│       ├── Krug.cpp / .h
│       ├── Linija.cpp / .h
│       ├── Tekst.cpp / .h
│       ├── Srce.cpp / .h
│       ├── Krst.cpp / .h
│       └── Sanduk.cpp / .h
├── docs/images/         # Screenshots from the original program
├── .gitignore
└── README.md
```

## Limitations and final thoughts

This is an early learning project, not a polished drawing application. Input validation isn't always reliable, some shapes and diagonal lines have geometric limitations, and the program can get stuck on certain invalid inputs. Undo/redo saves the visible canvas but does not fully restore the per-position layer information, so later overlaps can behave unexpectedly. Large or overlapping shapes can also look odd in a text-only grid.

I decided to keep the code close to how I originally wrote it instead of rebuilding the whole thing. For me, this project is mostly a reminder of a time when I was experimenting with C++, learning how to structure a program with classes, and finding small problems to solve just because they sounded fun.
