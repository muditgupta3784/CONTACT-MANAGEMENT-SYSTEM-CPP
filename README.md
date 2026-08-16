# Contact Management System (C++)

A lightweight, CLI-based Contact Management System built in C++ that demonstrates efficient data structures, incremental sorting, and logarithmic searching algorithms.

## 📌 Features
- **Incremental Sorting ($O(n)$):** Maintains an alphabetically sorted contact list using **Insertion Sort** upon every new entry.
- **Logarithmic Search ($O(\log n)$):** Fast contact retrieval using **Binary Search** over sorted data.
- **CLI Interface:** Clean menu-driven console interface for seamless user interaction.
- **Memory Efficient:** Uses dynamic memory allocations via C++ Standard Library structures (`std::vector`, `std::string`).

## 🛠️ Data Structures & Algorithms
- **Data Structure:** `std::vector<Contact>` / Custom Array for contiguous memory allocation.
- **Search Algorithm:** Binary Search — reduces search space by half each iteration.
- **Sorting Algorithm:** Insertion Sort — chosen over $O(n \log n)$ algorithms due to its superior performance on incrementally updated and nearly-sorted inputs.

## 🚀 How to Run Locally

### Prerequisites
- C++ Compiler (`g++` or `clang++` supporting C++11 or higher)

### Build and Run
```bash
# Clone the repository
git clone [https://github.com/muditgupta3784/CONTACT-MANAGEMENT-SYSTEM-CPP.git](https://github.com/muditgupta3784/CONTACT-MANAGEMENT-SYSTEM-CPP.git)

# Navigate to project directory
