# C++ Modules - 42 School

> Learning Modern C++ through object-oriented programming, memory management, inheritance, polymorphism, templates, and STL.

## About

The **CPP Modules** are a series of projects from the 42 curriculum designed to teach the fundamentals of C++98.

Unlike the C projects, these modules introduce:

- Classes & Objects
- Encapsulation
- Constructors & Destructors
- Operator Overloading
- Inheritance
- Polymorphism
- Abstract Classes
- Exception Handling
- Templates
- STL Containers & Algorithms

All projects are written using the **C++98 standard**.

---

# Project Structure

```
CPP00/
CPP01/
CPP02/
CPP03/
CPP04/
CPP05/
CPP06/
CPP07/
CPP08/
CPP09/
```

Each module contains multiple exercises (`ex00`, `ex01`, ...).

---

# Compilation

Compile every project using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Example:

```bash
cd CPP04/ex02

make

./animal
```

---

# Modules Overview

---

# CPP00

### Topics

- Classes
- Objects
- Member Functions
- Namespaces
- stdio streams
- Initialization Lists

### What you learn

- Creating classes
- Using constructors
- Encapsulation
- Basic OOP

---

# CPP01

### Topics

- Memory allocation
- Pointers
- References
- Dynamic allocation
- File streams

### What you learn

- Difference between stack and heap
- new / delete
- References vs pointers
- Object lifetime

---

# CPP02

### Topics

- Orthodox Canonical Form
- Copy constructor
- Assignment operator
- Fixed Point Numbers

### What you learn

- Rule of Three
- Operator overloading
- Copy semantics

---

# CPP03

### Topics

- Inheritance
- Base class
- Derived class

### What you learn

- Constructor chaining
- Protected members
- Function overriding

---

# CPP04

### Topics

- Runtime polymorphism
- Virtual functions
- Abstract classes
- Interfaces

### What you learn

- Dynamic dispatch
- Deep copy
- Virtual destructor
- Pure virtual functions

---

# CPP05

### Topics

- Exceptions
- try/catch
- throw

### What you learn

- Exception handling
- Custom exceptions
- Strong class design

---

# CPP06

### Topics

- C++ casts

### Types of casts

- static_cast
- dynamic_cast
- reinterpret_cast
- const_cast

### What you learn

- Type conversion
- RTTI
- Safe casting

---

# CPP07

### Topics

- Templates

### What you learn

- Function templates
- Class templates
- Generic programming

---

# CPP08

### Topics

- STL Containers
- Iterators
- Algorithms

### Containers

- vector
- list
- deque
- stack

### What you learn

- Generic algorithms
- Iterator usage
- STL design

---

# CPP09

### Topics

- STL in real projects

Exercises usually include:

- Bitcoin Exchange
- Reverse Polish Notation
- Ford-Johnson Merge-Insertion Sort

### What you learn

- Associative containers
- Parsing
- Performance
- Advanced STL

---

# Concepts Covered

## Object-Oriented Programming

- Classes
- Objects
- Encapsulation
- Abstraction
- Inheritance
- Polymorphism

---

## Memory Management

- Stack
- Heap
- new
- delete
- References
- Pointers

---

## Canonical Form

Every properly designed class should usually implement:

```cpp
Class();
Class(const Class&);
Class& operator=(const Class&);
~Class();
```

---

## Operator Overloading

Example:

```cpp
Fixed operator+(const Fixed&) const;

Fixed operator-(const Fixed&) const;

bool operator>(const Fixed&) const;
```

---

## Inheritance

```cpp
class Animal
{
};

class Dog : public Animal
{
};
```

---

## Polymorphism

```cpp
Animal* animal = new Dog();

animal->makeSound();
```

---

## Abstract Class

```cpp
class Animal
{
public:
    virtual void makeSound() = 0;
};
```

---

## Exception Handling

```cpp
try
{
    something();
}
catch (std::exception &e)
{
    std::cout << e.what() << std::endl;
}
```

---

## Templates

```cpp
template<typename T>

T max(T a, T b)
{
    return (a > b ? a : b);
}
```

---

## STL

Containers:

- vector
- map
- set
- stack
- deque
- list

Algorithms:

- sort
- find
- count
- for_each

Iterators:

```cpp
std::vector<int>::iterator it;
```

---

# Build

```bash
make

make clean

make fclean

make re
```

---

# Requirements

- C++98
- No external libraries
- Compile with:
  - Wall
  - Wextra
  - Werror

---

# Skills Acquired

- Object-Oriented Programming
- Memory Management
- Exception Handling
- Generic Programming
- Template Metaprogramming Basics
- STL
- Algorithmic Thinking
- Software Design

---

# Author

42 School Student

```
