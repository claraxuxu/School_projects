/*
** EPITECH PROJECT, 2020
** macros.h
** File description:
** macros used throughout the project
*/

#include <stdlib.h>

#ifndef MACROS_H
#define MACROS_H

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif /* UNUSED */

#ifndef ABS
#define ABS(value) ((value) < 0 ? -(value) : (value))
#endif /* ABS */

#ifndef FREE
#define FREE(value) \
    if ((value) != (void *)0) {\
        free(value); \
        value = NULL; }
#endif /* FREE */

#endif /* MACROS_H */
