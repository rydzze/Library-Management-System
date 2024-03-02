# Library Management System

## Original Author

This project is created and maintained by [rydzze](https://github.com/rydzze).

## Introduction

The Library Management System acts as a centralized digitalized system designed to streamline various library tasks. The primary objective of this system is to assist librarians in efficiently managing and organizing books, thus alleviating the burdensome traditional methods of bookkeeping. Additionally, the system aims to facilitate patrons in browsing the library catalog, as well as simplifying the borrowing and returning transactions. Divided into three core sections - books, members, and borrowing/returning transactions - the system incorporates 13 distinct functions.

### Key Features

- **Books Section:**
  - Add, edit, display, and remove books
  - Implementing merge sort for efficient book data organization
  
- **Members Section:**
  - Add, edit, display, and remove member information

- **Borrowing/Returning Transactions:**
  - Handling borrowing and returning transactions
  
### Data Structures Used
- Linked Lists: Used to store book and member data
- Queue: Utilized for loading data from files into the system
  
## Problem Statements and Objectives

- **Problem Statements:**
  - Manual data entry dependency
  - Ineffective search and retrieval
  - Lack of real-time updates
  - Scalability issues

- **Objectives:**
  - Automate data entry
  - Improve search and retrieval
  - Provide real-time updates
  - Enhance scalability

## Implementation Details

### 1. Linked List

We implemented a linked list data structure to store the data of the books and members. This dynamic structure allows for efficient storage of data that is constantly increasing over time.

Each struct has a "next" pointer variable to connect nodes, forming a linked list. The "head" pointer tracks the beginning of each linked list.

### 2. Queue

Before loading data from files into the system, we push the data into a queue to ensure safe insertion.

- We used the queue provided in the C++ standard library, using the Member struct as the template argument.
- Data is read from files and stored temporarily in a Member instance before being pushed into the queue.
- After reading data, we insert it into the linked list of members in the system.

### 3. Merge Sort

To efficiently search for books using unique IDs, we implemented the merge sort algorithm.

- **MergeSort Function:**
  - Sorts the linked list using a divide-and-conquer approach with a time complexity of O(n log₂n).
  - Calls the divideList function to split the list into two.
  - Recursive function sorts the left and right sides of the list.
  - Merges the sorted lists.

- **DivideList Function:**
  - Uses two pointers, "slow" and "fast," to determine the split point in the list.

- **Merge Function:**
  - Merges the list by comparing book IDs.

- **compareBookID Function:**
  - Compares ASCII values of characters to determine the order.
  - If not equal, returns the difference between the ASCII values.
  - Otherwise, converts remaining numbers to integers and returns the difference.

### 4. File Handling

The system supports loading and saving data using text files.

### 5. Exception Handling

We implemented try-catch blocks to handle unexpected runtime errors.

## How to Run

To run the Library Management System, follow these steps:

1. **Install GCC or G++ Compiler:**
   - Ensure you have GCC (GNU Compiler Collection) or G++ installed on your system. If not, you can download and install it from [here](https://gcc.gnu.org/).

2. **Compile the Source Code:**
   - Open your command prompt or terminal.
   - Navigate to the directory containing the source code files.
   - Type the following command to compile the source code:
     ```
     gcc -o LibraryManagementSystem main.c Library.c Membership.c
     ```
     or
     ```
     g++ -o LibraryManagementSystem main.cpp Library.cpp Membership.cpp
     ```

3. **Run the Executable:**
   - Once the compilation is successful, run the executable file generated:
     ```
     ./LibraryManagementSystem
     ```

## Contributors

We'd like to give credit to the following contributors who have helped in the development of this project:

- [Ariff Ridzlan](https://github.com/rydzze)
- [Nawfal Syafi'](https://github.com/Blackthorn23)
- [Sarvien](https://github.com/xsumthingz)
