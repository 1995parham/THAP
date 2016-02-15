/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
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
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "command.h"

/*
 * Commands in this program have the following foramt:
 * VERB [1] [2] ...
 * ** len(VERB) <= 1024
 * ** [1] [2] were arguments and passed into function.
 * every VERB have handler in following format
 * void VERB_command([1], [2], [3], ..)
*/


void quit_command(void)
{
	exit(0);
}

void show_command(char c)
{
	switch (c) {
	case 'w':
		printf("THAP is a simple http analyzer program\n");

		printf("Copyright (C) 2016 ");
		printf("Parham Alvani(parham.alvani@gmail.com)\n");

		printf("This program is free software: ");
		printf("you can redistribute it and/or modify\n");

		printf("it under the terms of the ");
		printf("GNU General Public License as published by\n");

		printf("the Free Software Foundation, ");
		printf("either version 3 of the License, or\n");

		printf("(at your option) any later version.\n");

		printf("This program is distributed in the hope");
		printf(" that it will be useful,\n");

		printf("but WITHOUT ANY WARRANTY; ");
		printf("without even the implied warranty of\n");

		printf("MERCHANTABILITY or FITNESS FOR A ");
		printf("PARTICULAR PURPOSE.  See the\n");

		printf("GNU General Public License for more details.\n");

		printf("You should have received a copy of the ");
		printf("GNU General Public License\n");

		printf("along with this program.  ");
		printf("If not, see <http://www.gnu.org/licenses/>.\n");
		break;
	case 'c':
		printf("THAP is a simple http analyzer program\n");

		printf("Copyright (C) 2016 ");
		printf("Parham Alvani(parham.alvani@gmail.com)\n");

		printf("This program is free software: ");
		printf("you can redistribute it and/or modify\n");

		printf("it under the terms of the ");
		printf("GNU General Public License as published by\n");

		printf("the Free Software Foundation, ");
		printf("either version 3 of the License, or\n");

		printf("(at your option) any later version.\n");

		printf("This program is distributed in the hope");
		printf(" that it will be useful,\n");

		printf("but WITHOUT ANY WARRANTY; ");
		printf("without even the implied warranty of\n");

		printf("MERCHANTABILITY or FITNESS FOR A ");
		printf("PARTICULAR PURPOSE.  See the\n");

		printf("GNU General Public License for more details.\n");

		printf("You should have received a copy of the ");
		printf("GNU General Public License\n");

		printf("along with this program.  ");
		printf("If not, see <http://www.gnu.org/licenses/>.\n");
		break;
	}
}

void command_dispatcher(const char *command)
{
	if (!command)
		quit_command();

	char verb[1024];
	int len;

	len = sscanf(command, "%s", verb);
	if (len < 1)
		return;

	if (!strcmp(verb, "quit")) {
		quit_command();
	} else if (!strcmp(verb, "show")) {
		char c;
		int len;

		len = sscanf(command, "%s %1s", verb, &c);
		if (len < 2 || (c != 'c' && c != 'w')) {
			printf("show [c|w]\n");
			return;
		}

		show_command(c);
	} else {
		printf("404 Not Found :D\n");
	}
}