/*
 * In The Name Of God
 * ========================================
 * [] File Name : ui.c
 *
 * [] Creation Date : 17-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <libsoup/soup.h>
#include <stdint.h>
#include <stdio.h>

#include "messages.h"
#include "ui.h"

void ui_print_message(uint64_t index)
{
	SoupMessage *msg;
	
	msg = message_get(index);
	if (!msg)
		return;
	printf("Server: %s", soup_message_headers_get_one(msg->response_headers, "Server"));
}
