/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** CPP Source file
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include "ptrace/trace.h"
#include "ptrace/macro.h"
#include "syscall_name/display.h"
#include "syscall_name/print_name.h"

static int is_making_syscall(pid_t pid, struct user_regs_struct *regs)
{
    long ret;

    ret = ptrace(PTRACE_PEEKTEXT, pid, regs->rip, 0);
    if (ret == -1) {
        return (0);
    }
    if ((ret & 0xFFFF) == SYSCALL_INSTRUCTION
        || (ret & 0xFFFF) == SYSENTER_INSTRUCTION) {
        return (1);
    }
    return (0);
}

static char next_step(pid_t pid)
{
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1 && errno) {
        fprintf(stderr, "next_step: %s\n", strerror(errno));
        return (1);
    }
    return (0);
}

static char wait_child(pid_t pid)
{
    int status;

    if (wait4(pid, &status, 0, NULL) == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        return (0);
    }
    if (WIFEXITED(status)) {
        return (0);
    }
    return (1);
}

char trace(pid_t pid)
{
    struct user_regs_struct regs;

    while (wait_child(pid)) {
        if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1 && errno) {
            fprintf(stderr, "%s\n", strerror(errno));
            return (1);
        }
        if (is_making_syscall(pid, &regs)) {
            display(&regs);
        }
        if (next_step(pid)) {
            return (1);
        }
    }
    return (0);
}
