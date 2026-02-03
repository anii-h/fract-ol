# Fract-ol 

**Fract-ol** is a C project from the 42 curriculum that lets you explore beautiful fractals.
The program generates the **Mandelbrot** and **Julia** sets with interactive zoom and color effects.

---

## 🎯 Project Objectives

* Understand fractals and complex number math
* Generate Julia and Mandelbrot fractals graphically
* Explore graphical programming using MiniLibX
* Handle mouse and keyboard events
* Respect the 42 Norm and project constraints
* Only the mandatory part of the project is implemented

---

## 🛠️ Technologies & Constraints

**Language:** C

**Allowed functions:**

* `open`, `close`, `read`, `write`
* `malloc`, `free`
* `exit`, `perror`, `strerror`
* MiniLibX functions for graphics and events
* Math library functions (`-lm`)
* `gettimeofday()`
* `ft_printf` or equivalent you coded

**Memory leaks:** none

**Norm:** compliant

---

## 📦 Installation & Cloning (SSH)

To clone the repository using SSH, run:

```bash
git clone git@github.com:anii-h/fract-ol.git
cd fract-ol
```

ℹ️ Make sure your SSH key is added to your GitHub account before cloning.

---

## 🔨 Compilation

Compile the project with:

```bash
make
```

Available Makefile rules:

* `make` → compile the project
* `make clean` → remove object files
* `make fclean` → remove object files and executable
* `make re` → recompile everything

Compiled with flags:

```
-Wall -Wextra -Werror
```

---

## ▶️ Usage

```bash
./fractol mandelbrot
./fractol julia <real_param> <imag_param>
```

**Examples:**

```bash
./fractol mandelbrot
./fractol julia -0.7 0.27015
```

* Mouse wheel: zoom in/out
* Arrow keys (if implemented in bonus): move view
* ESC / close button: exit program

---

## 🧠 Implementation Overview

* Uses **MiniLibX** to open a window and draw pixels
* Generates fractals using complex number calculations
* Interactive zoom using mouse wheel
* Julia sets can be customized using command line parameters
* Clean memory management; no leaks
* Event handling for keyboard and mouse

---

## 👩‍💻 Author

**Ani Hambardzumyan**
Computer Science student, American University of Armenia & 42 Yerevan
