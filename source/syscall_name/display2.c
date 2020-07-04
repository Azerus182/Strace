/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** CPP Source file
*/

#include <sys/user.h>
#include <stddef.h>
#include <stdio.h>
#include "syscall_name/display.h"
#include "syscall_name/print_name.h"

void display_four_arg(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_prlimit64)
        printf("0x%u, %ui, %p, %p)\n", (int)regs->rdi, (unsigned int)regs->rsi,
        (void *)regs->rdx, (void *)regs->r10);
    if (regs->rax == __NR_openat)
        printf("0x%d, %p, 0x%i, 0x%i)\n", (int)regs->rdi, (void *)regs->rsi,
        (int)regs->rdx, (int)regs->r10);
}

void display_six_arg(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_mmap)
        printf("0x%lu, 0x%lu, 0x%lu, 0x%lu, 0x%lu, 0x%lu)\n",
        (unsigned long)regs->rdi, (unsigned long)regs->rsi,
        (unsigned long)regs->rdx, (unsigned long)regs->r10,
        (unsigned long)regs->r8, (unsigned long)regs->r9);
}
