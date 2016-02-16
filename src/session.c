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
#include <time.h>

#include "session.h"
#include "messages.h"

static SoupSession *session;
static int counter;

static void session_init(void)
{
	session = soup_session_new();
}

int session_new_connection(const char *method, const char *url)
{
	if (!session)
		session_init();

	SoupMessage *msg;
	uint32_t status;
	time_t t1, t2;

	msg = soup_message_new(method, url);
	time(&t1);
	status = soup_session_send_message(session, msg);
	time(&t2);
	
	printf("Response time: %lus\n", t2 - t1);
	printf("Message index [use this index for further information]: %lu\n", ++counter);
	messages_add(msg, counter);

	return counter;
}
