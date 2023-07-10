# Learning cpp

## Resources

- [codecademy](https://www.codecademy.com/learn/c-plus-plus-for-programmers)

## Basics

Basics first; compiling something.

```sh
g++ hello.cpp -o hello && ./hello
```

## Intro

### Preprocessor

Importing standard libraries is slightly different than user-defined libraries.

```cpp
#include <iostream>
#include "some-lib"
```

>TODO: how do you specify where the library is found?

Namespaces allow you to shorten the code - you don't have to specify `std::cout`
anymore and can call `cout` directly.

```cpp
using namespace std;
```

>TODO: what if functions from namespaces clash?

### Comments

As usual, there are two kind of comments.

```cpp
// Single-line style

/*
Multi-line style
*/
```

### Variables

```cpp
char letter;
int number = 21, height = 24;
number = 18;

// constant variables have to be initialized directly
const double pi = 3.14;
```

>TODO: what about zero values?

### Types

```cpp
int number = 12;
const double pi = 3.14;
char mail = '@';
string hello = "Hello World";
bool truthy = true;
```

Type conversions can be done with `int number = (int) pi`.

### Operations

`--x` increments x by 1 and then returns it where as `x++` returns a *copy" of 
the incremented x.

### Reference and pointers

```cpp
int score = 12;
// note that references have to be initialized
int& score_address = score;
```

>The primary application for references in C++ is in function parameters.
>Because the reference parameter acts as an alias for the argument, a function
>that uses a reference parameter is able to modify the argument passed in.

### Memory address

>When not used in a declaration, the ampersand symbol & is called the address of
>operator and is used to access the memory address of a variable.

```cpp
int score = 12;
std::cout << &score;
```

### Pointers

```cpp
std::string day = "Monday";
std::string* day_ptr = &day;
```

Note that it's dangerous to have uninitialized pointers. If unsure, start with
initializing the pointer with `nullptr`.