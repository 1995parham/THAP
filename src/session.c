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
#include <glib.h>
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
	GTimer *t;

	msg = soup_message_new(method, url);
	t = g_timer_new();
	g_timer_start(t);
	status = soup_session_send_message(session, msg);
	g_timer_stop(t);
	
	printf("Response time: %gs\n", g_timer_elapsed(t, NULL));
	printf("Message index [use this index for further information]: %d\n", ++counter);
	messages_add(msg, counter);

	return counter;
}
