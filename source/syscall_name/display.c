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

static void display_one_arg(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_set_tid_address) {
        printf("%p)\n", (void *)regs->rdi);
        return;
    }
    if (regs->rax == __NR_brk) {
        printf("0x%lu)\n", (unsigned long)regs->rdi);
        return;
    }
    if (regs->rax == __NR_exit_group) {
        printf("0x%d)\n", (int)regs->rdi);
    }
    if (regs->rax == __NR_close) {
        printf("0x%d)\n", (int)regs->rdi);
    }
}

static void display_two_arg(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_set_robust_list) {
        printf("0x%lu, 0x%d)\n", (unsigned long)regs->rdi, (int)regs->rsi);
    }
    if (regs->rax == __NR_statfs) {
        printf("0x%lu, 0x%lu)\n", (unsigned long)regs->rdi,
        (unsigned long)regs->rsi);
    }
    if (regs->rax == __NR_munmap) {
        printf("0x%lu, 0x%zu)\n", (unsigned long)regs->rdi, (size_t)regs->rsi);
    }
    if (regs->rax == __NR_access) {
        printf("%p, 0x%d)\n", (void *)regs->rdi, (int)regs->rsi);
    }
    if (regs->rax == __NR_stat) {
        printf("0x%p, %p)\n", (void *)regs->rdi, (void *)regs->rsi);
    }
    if (regs->rax == __NR_fstat)
        printf("0x%u, %p)\n", (unsigned int)regs->rdi, (void *)regs->rsi);
    if (regs->rax == __NR_lstat)
        printf("0x%p, %p)\n", (void *)regs->rdi, (void *)regs->rsi);
}

static void display_tree_arg_a(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_mprotect)
        printf("0x%lu, 0x%u, 0x%lu)\n", (unsigned long)regs->rdi,
        (int)regs->rsi, (unsigned long)regs->rdx);
    if (regs->rax == __NR_ioctl)
        printf("0x%u, 0x%u, 0x%lu)\n", (unsigned int)regs->rdi,
        (unsigned int)regs->rsi, (unsigned long)regs->rdx);
    if (regs->rax == __NR_arch_prctl)
        printf("%p, 0x%i, %p)\n", (void *)regs->rdi, (int)regs->rsi,
        (void *)regs->rdx);
    if (regs->rax == __NR_getdents64)
        printf("0x%u, %p, %u)\n", (unsigned int)regs->rdi, (void *)regs->rsi,
        (unsigned int)regs->rdx);
    if (regs->rax == __NR_read)
        printf("0x%u, %p, 0x%zu)\n", (unsigned int)regs->rdi, (void *)regs->rsi,
        (size_t)regs->rdx);
}

static void display_tree_arg_b(struct user_regs_struct *regs)
{
    if (regs->rax == __NR_write)
        printf("0x%u, %p, 0x%zu)\n", (unsigned int)regs->rdi, (void *)regs->rsi,
        (size_t)regs->rdx);
    if (regs->rax == __NR_open)
        printf("%p, 0x%i, 0x%i)\n", (void *)regs->rdi, (int)regs->rsi,
        (int)regs->rdx);
    if (regs->rax == __NR_poll)
        printf("%p, 0x%ui, 0x%llu)\n", (void *)regs->rdi,
        (unsigned int)regs->rsi, ((unsigned long long)regs->rdx & 0xFFFFFFFF));
    if (regs->rax == __NR_lseek)
        printf("%ui, 0x%ld, 0x%ui)\n", (unsigned int)regs->rdi, (off_t)regs->rsi,
        (unsigned int)regs->rdx);
    if (regs->rax == __NR_execve)
        printf("%p, %p, %p)\n", (void *)regs->rdi, (void *)regs->rsi,
        (void *)regs->rdx);
}

void display(struct user_regs_struct *regs)
{
    if (!print_name(regs->rax)) {
        return;
    }
    display_one_arg(regs);
    display_two_arg(regs);
    display_tree_arg_a(regs);
    display_tree_arg_b(regs);
    display_four_arg(regs);
    display_six_arg(regs);
}
