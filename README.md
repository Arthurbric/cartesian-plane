# Cartesian Plane Visualization in C 🖥️📐

## Overview
This project is a C program that allows users to visualize **2D Cartesian planes** and plot lines and circles using classic algorithms. The program demonstrates **computer graphics fundamentals** such as the **DDA (Digital Differential Analyzer) algorithm**, **Bresenham's line algorithm**, and **Bresenham's circle algorithm** in a Windows console environment.

---

## Features
- Draw lines using **DDA** or **Bresenham's line algorithm**.
- Draw circles using **Bresenham's circle algorithm**.
- Interactive **console menu** for user input.
- **Step-by-step Cartesian plane visualization**.
- **Animated effects** to enhance visual experience.
- Supports plotting based on user-defined coordinates and radius.

---

## How to Run
1. Compile the program with a C compiler (Windows compatible):
   ```bash
   gcc Cartesian_plane.c -o Cartesian_plane.exe -lm
  ```

2. Run the executable:

   ```bash
   Cartesian_plane.exe
   ```

3. Follow the on-screen menu to select options:

   * Draw line (DDA)
   * Draw line (Bresenham)
   * Draw circle (Bresenham)
   * Exit program

---

## Key Concepts

* **DDA Algorithm**: Generates a straight line between two points using incremental calculations.
* **Bresenham's Line Algorithm**: Efficient integer-based line plotting.
* **Bresenham's Circle Algorithm**: Plots a circle using symmetry across octants.
* **Console Graphics**: Uses Windows API to position the cursor for drawing (`SetConsoleCursorPosition`).
* **Animation**: Simple animations to illustrate plotting or transitions.

---

## Technologies

* Language: **C**
* Platform: **Windows Console**
* Libraries: `math.h`, `stdio.h`, `windows.h`, `locale.h`

---

## Contributors

* Arthur Arash Briceño Heidari

---

## License

MIT License

```

---

## Short Résumé Description

- **Cartesian Plane Visualization (C)** – Developed a Windows console program to plot lines and circles using **DDA and Bresenham algorithms**. Implemented interactive user input, coordinate-based plotting, and animations to visualize 2D Cartesian planes.  
