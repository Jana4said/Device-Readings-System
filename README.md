# 🔧 Device Readings System (C Project)

This project simulates a **sensor data collection system** written in the C programming language.  
It models multiple devices, validates their readings, stores them in structured collections, and provides tools for error handling and duplicate removal.

---

## ⚙️ Features
- Structured design using multiple `struct` types  
- Validation of readings based on device range  
- Sorted insertion of readings into a collection  
- Detection and removal of duplicate entries  
- Clear, modular implementation with detailed error handling  

---

## 📁 File Overview
| File | Description |
|------|--------------|
| **readings.c** | Implements all major logic for handling devices, readings, and validation |
| **readings.h** | Header file defining structures, constants, and function prototypes |
| **main.c** | Testing and demonstration of reading creation, validation, and output |
| **READ ME** | Short original project notes provided with the assignment |

---

## 🧠 Concepts Practiced
- **Structures (`struct`)**
- **Pointer handling**
- **Validation and error codes**
- **Modular program design**
- **Basic sorting and filtering logic**

---

## 🧰 Technologies Used
- **C Language**
- **Standard I/O (`stdio.h`)**
- **String manipulation (`string.h`)**

---

## 🧑‍💻 Author
**Gana Said**  
Bachelor of Computer Science (AI Stream) – Carleton University  
📧 [janasaid@cmail.carleton.ca](mailto:janasaid@cmail.carleton.ca)

---

## 🧩 How to Run
1. Compile the program:
   ```bash
   gcc main.c readings.c -o readings_system
   Run the executable:
   ./readings_system

