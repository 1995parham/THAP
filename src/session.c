/*
 * In The Name Of God
 * ========================================
 * [] File Name : session.c
 *
 * [] Creation Date : 15-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <libsoup/soup.h>
#include <stdio.h>
#include <stdint.h>

#include "session.h"

static SoupSession *session;

void session_init(void)
{
	session = soup_session_new();
}

int session_new_connection(const char *method, const char *url)
{
	SoupMessage *msg;
	uint32_t status;

	msg = soup_message_new(method, url);
	status = soup_session_send_message(session, msg);
	
	printf("Status: %d\n", status);
	printf("Server: %s\n", soup_message_headers_get_one(msg->response_headers, "Server"));

	return status;
}
