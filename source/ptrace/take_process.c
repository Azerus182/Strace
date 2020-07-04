/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** CPP Source file
*/

#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "args/args.h"
#include "ptrace/trace.h"

static char target_from_pid(args_t *target_info)
{
    if (kill(target_info->p, 0) != 0) {
        fprintf(stderr, "1-%s\n", strerror(errno));
        return (0);
    }
    if (target_info->p) {
        if (ptrace(PTRACE_ATTACH, target_info->p, 0, 0) < 0) {
            fprintf(stderr, "2-%s\n", strerror(errno));
            return (0);
        }
    }
    return (1);
}

static char target_from_command(args_t *target_info)
{
    pid_t cpid = fork();

    if (cpid < 0) {
        fprintf(stderr, "3-%s\n", strerror(errno));
        return (1);
    }
    if (cpid != 0) {
        target_info->p = cpid;
    } else {
        if (ptrace(PTRACE_TRACEME, target_info->p, 0, 0) < 0) {
            exit(1);
        }
        if (execv(*(target_info->command), target_info->command) < 0) {
            fprintf(stderr, "4-%s\n", strerror(errno));
            exit(1);
        }
    }
    return (0);
}

char get_target_pid(args_t *target_info)
{
    if (target_info->p) {
        if (target_from_pid(target_info)) {
            fprintf(stderr, "Can't set target from pid\n");
            return (1);
        }
    } else {
        if (target_from_command(target_info)) {
            fprintf(stderr, "Can't set target from command\n");
            return (1);
        }
    }
    return (0);
}
