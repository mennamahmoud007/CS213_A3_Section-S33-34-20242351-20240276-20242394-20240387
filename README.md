# CS213_A3_Section-S33-34-20242351-20240276-20242394-20240387
# 🎮 CS213 - Tic-Tac-Toe Variations Project

This repository contains implementations of **14 different Tic-Tac-Toe inspired games** developed as part of the CS213 Object Oriented Programming Assignment 3 with DR.Mohamed ElRamly at FCAI

Each game is written in C++ following the project framework, with full OOP structure separation into classes, boards, players, move mechanics and game engines


## 📌 List of Implemented Games & Descriptions

### 1. Ordinary XO
- **Board:** 3×3  
- **Objective:** Classic Tic-Tac-Toe — make 3 in a row before your opponent.  
- **Rules:** Players alternate placing `X` and `O` on empty cells.  
- **Winning:** 3 aligned horizontally, vertically, or diagonally.

---

### 2. SUS
- **Board:** 3×3  
- **Objective:** Form the sequence **S–U–S**.  
- **Rules:**  
  - Each player always plays the same letter (`S` or `U`).  
  - A point is scored for every new “S-U-S” created.  
- **Winning:** Player with the most sequences when the board fills.

---

### 3. Four-in-a-Row
- **Board:** 6×7  
- **Objective:** Get four marks in a row.  
- **Mechanics:** Marks fall to the lowest available cell in a chosen column.

---

### 4. 5×5 Tic-Tac-Toe
- **Board:** 5×5  
- **Objective:** Create the most **3-in-a-row** sequences.  
- **Game Length:** 24 total moves.

---

### 5. Word Tic-Tac-Toe
- **Board:** 3×3  
- **Objective:** Form a valid 3-letter English word.  
- **Extra:** Uses the dictionary file `dic.txt`.

---

### 6. Misère Tic-Tac-Toe
- **Board:** 3×3  
- **Objective:** Avoid forming 3 in a row.  
- **Losing:** Player who completes a line loses.

---

### 7. Diamond Tic-Tac-Toe
- **Board:** Diamond-shaped 5×5  
- **Objective:** Complete **two lines at the same time** (one of length 3, one of length 4).

---

### 8. 4×4 Tic-Tac-Toe
- **Board:** 4×4  
- **Mechanics:**  
  - Each player starts with 4 tokens.  
  - Players **move tokens** to adjacent empty squares (no diagonal moves).  
- **Winning:** First to create a 3-in-a-row alignment.

---

### 9. Pyramid Tic-Tac-Toe
- **Board:** Pyramid (levels: 5–3–1)  
- **Objective:** Make 3 in a row.

---

### 10. Numerical Tic-Tac-Toe
- **Board:** 3×3  
- **Rules:**  
  - Player 1 uses odd numbers  
  - Player 2 uses even numbers  
  - Each number used once  
- **Winning:** Any line summing to **15**.

---

### 11. Obstacles Tic-Tac-Toe
- **Board:** 6×6  
- **Mechanics:** After every round, **two obstacles** appear randomly.  
- **Winning:** First to connect 4 marks.

---

### 12. Infinity Tic-Tac-Toe
- **Board:** 3×3  
- **Mechanics:** Every 3 moves, the **oldest mark disappears**.  
- **Winning:** Form 3 in a row before your marks vanish.

---

### 13. Ultimate Tic-Tac-Toe (Bonus)
- **Board:** 3×3 main board, each cell contains a 3×3 sub-board.  
- **Rules:** Winning a sub-board claims a cell on the main board.  
- **Winning:** 3 claimed boards aligned.

---

### 14. Memory Tic-Tac-Toe (Bonus)
- **Board:** 3×3  
- **Mechanics:** Marks are **hidden** as soon as they are placed.  
- **Winning:** First to align 3 hidden marks.

---

## 📂 Repository Structure
