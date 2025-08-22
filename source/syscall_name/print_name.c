/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** C Source file
*/

#include <sys/reg.h>
#include <stdio.h>
#include <sys/user.h>
#include <asm/unistd_64.h>
#include "syscall_name/print_name.h"

static int print_name_3(unsigned long long regs)
{
    if (regs == __NR_exit_group)
        return (printf("exit_group("));
    if (regs == __NR_set_robust_list)
        return (printf("set_robust_list("));
    if (regs == __NR_prlimit64)
        return (printf("prlimit64("));
    if (regs == __NR_statfs)
        return (printf("statfs("));
    if (regs == __NR_execve)
        return (printf("execve("));
    if (regs == __NR_mprotect)
        return (printf("mprotect("));
    return (0);
}

static int print_name_2(unsigned long long regs)
{
    if (regs == __NR_mmap)
        return (printf("mmap("));
    if (regs == __NR_munmap)
        return (printf("munmap("));
    if (regs == __NR_brk)
        return (printf("brk("));
    if (regs == __NR_ioctl)
        return (printf("ioctl("));
    if (regs == __NR_access)
        return (printf("access("));
    if (regs == __NR_arch_prctl)
        return (printf("arch_prctl("));
    if (regs == __NR_getdents64)
        return (printf("getdents64("));
    if (regs == __NR_set_tid_address)
        return (printf("set_tid_address("));
    if (regs == __NR_openat)
        return (printf("openat("));
    return (print_name_3(regs));
}

int print_name(unsigned long long regs)
{
    if (regs == __NR_read)
        return (printf("read("));
    if (regs == __NR_write)
        return (printf("write("));
    if (regs == __NR_open)
        return (printf("open("));
    if (regs == __NR_close)
        return (printf("close("));
    if (regs == __NR_stat)
        return (printf("stat("));
    if (regs == __NR_fstat)
        return (printf("fstat("));
    if (regs == __NR_lstat)
        return (printf("lstat("));
    if (regs == __NR_poll)
        return (printf("poll("));
    if (regs == __NR_lseek)
        return (printf("lseek("));
    return (print_name_2(regs));
}
