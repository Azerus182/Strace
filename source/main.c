/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** CPP Source file
*/

#include <unistd.h>
#include <stddef.h>
#include "args/args.h"
#include "ptrace/trace.h"

int main(int ac, char const **av)
{
    args_t *args = new_args_t(ac, av);

    if (args->help != 0 || (args->p == 0 && args->command == NULL)) {
        delete_args_t(args);
        return (args->help ? 0 : 84);
    }
    if (get_target_pid(args) != 0) {
        delete_args_t(args);
        return (84);
    }
    if (trace(args->p)) {
        return (84);
    }
    delete_args_t(args);
    return (0);
}
