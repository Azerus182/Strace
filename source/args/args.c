/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** C Source file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "args/args.h"
#include "args/macro.h"

static char str_is_nbr(char const *str)
{
    do {
        if (*str < '0' || *str > '9') {
            return (0);
        }
    } while (*(++str) != 0);
    return (1);
}

static char args_get_p(const char **args, args_t *stc)
{
    if (strcmp(*args, "-p") == 0) {
        if (!str_is_nbr(args[1])) {
            return (1);
        }
        stc->p = atoi(args[1]);
        stc->command = NULL;
    } else {
        stc->p = 0;
        stc->command = (char **)args;
    }
    return (0);
}

args_t *new_args_t(int ac, const char **av)
{
    args_t *stc = malloc(sizeof(args_t));

    if (stc == NULL) {
        return (NULL);
    }
    stc->help = strcmp(av[1], "--help") ? 0 : 1;
    if (stc->help) {
        return (stc);
    }
    if (ac >= 2) {
        stc->s = strcmp(av[1], "-s") ? 0 : 1;
    }
    if (ac >= 2 + stc->s) {
        if (args_get_p(&av[1 + stc->s], stc) != 0) {
            free(stc);
            return (NULL);
        }
    }
    return (stc);
}

void delete_args_t(args_t *args)
{
    if (args == NULL) {
        return;
    }
    free(args);
}
