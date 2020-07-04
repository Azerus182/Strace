/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** C Header file
*/

#ifndef ARGS_H_
#define ARGS_H_

struct args_s {
    char **command;
    pid_t p;
    char s;
    char help;
    char padding[2];
};

typedef struct args_s args_t;

args_t *new_args_t(int ac, const char **av);
void delete_args_t(args_t *args);

#endif /* end of include guard: ARGS_H_ */
