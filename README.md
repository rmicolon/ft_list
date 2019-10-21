# ft_list
A simple implementation of [Linus Torvalds' doubly linked lists](https://github.com/torvalds/linux/blob/master/include/linux/list.h) that is compliant with [42 coding style for C](https://ncoden.fr/datas/42/norm.pdf) (in french).

## NB
- This do not use the READ_ONCE/WRITE_ONCE macros of the original, thus should not be used for any concurrent non-read-only shared memory access in its current state.
- Due to severe limitations in the 42 Coding Style, many of the original macros/functions could not be properly implemented (E.g. for_each loops). Some were added to try to make up for it (E.g. LIST_APPLY macros), but it might not be as practical.
- The 42 Coding Style is frequently evolving, so what was allowed/forbidden when this library was written might have changed.

## Installation
```
In the main directory of your project:
git clone https://github.com/rmicolon/ft_list.git
make -C ft_list
(For gcc and clang) Then compile with the following options `-L./ft_list/ -llst`
```

## Usage
If you are accustomed with the original lists then using this lib should be pretty straightforward. Available macros/functions are documented in the `ft_list.h` header file located in the `includes` directory.
