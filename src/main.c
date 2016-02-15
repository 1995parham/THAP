/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "prl.h"

int main(int argc, char *argv[])
{
	printf("THAP version \n");
	printf("Copyright (C) 2016 Parham Alvani (parham.alvani@gmail.com)\n");
	printf("THAP comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions; type `show c' for details.\n");
	printf("\n");

	const char *command;
	char prompt[1024];

	while (true) {
		sprintf(prompt, "THAP $ ");
		prl_set_prompt(prompt);
		command = prl_gets();
	}
}
