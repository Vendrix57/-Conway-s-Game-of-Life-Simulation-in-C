# Conway's Game of Life (C Implementation)

This project is a standalone C implementation of Conway's Game of Life, a famous cellular automaton that demonstrates how complex patterns and "life" can emerge from a set of simple mathematical rules.

## 🧠 The Logic & Rules

The simulation takes place on a 4x4 grid. Each cell is either Alive (1) or Dead (0). The state of the grid evolves in "generations" according to the following criteria:

1.  **Survival**: A live cell with 2 or 3 live neighbors lives on to the next generation.
2.  **Birth**: A dead cell with exactly 3 live neighbors becomes a live cell.
3.  **Death**: In all other cases (solitude or overpopulation), the cell dies or remains dead.

## 🚀 Technical Highlights

* **Custom Pseudo-Random Generator**: To ensure portability and control, the program implements a Linear Congruential Generator (LCG) using the formula: x_{n+1} = (5x_n + 3) mod 16. This seeds the initial population with binary values (0 or 1).
* **Neighbor Detection**: Includes a robust `count_live_neighs` function that checks the 8 surrounding cells of any given coordinate. It features boundary-checking logic to prevent memory access errors at the edges of the 4x4 matrix.
* **Dual-Buffer State Management**: The program uses two separate matrices (A and B). The "Next Generation" is calculated in a buffer matrix based on the current state of the primary matrix, ensuring that a cell change in one calculation doesn't interfere with another in the same turn.
* **Formatted ASCII UI**: Renders the grid using a structured table format in the console, making it easy to track the transition from the "Initial Stage" to the "Next Generation".

## 🛠️ How to Compile and Run

1.  **Compile the source code**:
    ```bash
    gcc main.c -o game_of_life
    ```
2.  **Run the program**:
    ```bash
    ./game_of_life
    ```

## 📜 License
This project is open-source and intended for educational use in algorithm design and discrete mathematics.
