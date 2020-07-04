/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** C Header file
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <sys/reg.h>
#include <asm/unistd_64.h>
#include <stddef.h>
#include <sys/user.h>

void display(struct user_regs_struct *regs);
void display_four_arg(struct user_regs_struct *regs);
void display_five_arg(struct user_regs_struct *regs);
void display_six_arg(struct user_regs_struct *regs);

#endif /* end of include guard: DISPLAY_H_ */
