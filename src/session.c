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
#include "auth.h"

static SoupSession *session;
static int counter;

static void session_init(void)
{
	session = soup_session_new_with_options(SOUP_SESSION_USER_AGENT, "THAP", NULL);
	g_signal_connect(session, "authenticate", G_CALLBACK(auth_callback), &counter);
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

	switch (status) {
	case SOUP_STATUS_CANCELLED:
		printf("ERR: Message was cancelled locally\n");
		return -1;
		break;
	case SOUP_STATUS_CANT_RESOLVE:
		printf("ERR: Unable to resolve destination host name\n");
		return -1;
		break;
	case SOUP_STATUS_CANT_RESOLVE_PROXY:
		printf("ERR: Unable to resolve proxy host name\n");
		return -1;
		break;
	case SOUP_STATUS_CANT_CONNECT:
		printf("ERR: Unable to connect to remote host\n");
		return -1;
		break;
	case SOUP_STATUS_CANT_CONNECT_PROXY:
		printf("ERR: Unable to connect to proxy\n");
		return -1;
		break;
	case SOUP_STATUS_SSL_FAILED:
		printf("ERR: SSL/TLS negotiation failed\n");
		return -1;
		break;
	case SOUP_STATUS_IO_ERROR:
		printf("ERR: A network error occurred,\n");
		printf("or the other end closed the connection unexpectedly\n");
		return -1;
		break;
	case SOUP_STATUS_MALFORMED:
		printf("ERR: Malformed data (usually a programmer error)\n");
		return -1;
		break;
	case SOUP_STATUS_TRY_AGAIN:
		printf("ERR: Used internally\n");
		return -1;
		break;
	case SOUP_STATUS_TOO_MANY_REDIRECTS:
		printf("ERR: There were too many redirections\n");
		return -1;
		break;
	case SOUP_STATUS_TLS_FAILED:
		printf("ERR: Used internally\n");
		return -1;
		break;
	}

	printf("Response time: %gs\n", g_timer_elapsed(t, NULL));
	printf("Message index [use this index for further information]: %d\n", ++counter);
	messages_add(msg, counter);

	return counter;
}
