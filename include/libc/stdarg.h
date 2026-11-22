#ifndef LIBC_STDARG_H
#define LIBC_STDARG_H

/* Variable arguments for mwccpsp, which ships no stdarg.h. Not the header of
 * the original toolchain: the form is the one that reproduces the code of the
 * game's variadic functions (func_08891474 and its neighbours).
 *
 * The prologue of a variadic function saves the unnamed argument registers
 * ($a0-$t3) at the top of its frame. __builtin_next_arg(last) is the address
 * just past that save area and __builtin_args_info(2) the number of named
 * integer arguments; va_start points back at the first unnamed one. The
 * `>= 8 ? 0 : ...` order of the test is the one that gives the original
 * `slti` / `bnezl` (the reverse test gives `beqzl`). */

typedef char *va_list;

#define va_start(ap, last)                                                  \
    ((ap) = (va_list) __builtin_next_arg(last) -                            \
            (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 4))
#define va_end(ap) ((void) 0)

#endif
