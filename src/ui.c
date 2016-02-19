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
#include <glib.h>
#include <stdint.h>
#include <stdio.h>

#include "messages.h"
#include "ui.h"

void ui_print_message(int index)
{
	ui_print_general(index);
	ui_print_cookies(index);
}

void ui_print_general(int index)
{
	SoupMessage *msg;

	msg = message_get(index);
	if (!msg)
		return;
	printf("Status code: %u %s\n",
			msg->status_code, msg->reason_phrase);
	printf("Server: %s\n", soup_message_headers_get_one(msg->response_headers, "Server"));
}

void ui_print_methods(int index)
{
	SoupMessage *msg;

	msg = message_get(index);
	if (!msg)
		return;
	printf("Status code: %u\n", msg->status_code);
	
	const char *methods = soup_message_headers_get_one(msg->response_headers, "Allow");
	
	if (methods)
		printf("Methods: %s\n", methods);
	else
		printf("Methods: OPTIONS HTTP verb was not allowed\n");
}

void ui_print_cookie(void *cookie, void *data)
{
	printf("\tName: %s\n", soup_cookie_get_name(cookie));
	printf("\tValue: %s\n", soup_cookie_get_value(cookie));
	printf("\tDomain: %s\n", soup_cookie_get_domain(cookie));
	printf("\tPath: %s\n", soup_cookie_get_path(cookie));
	if (soup_cookie_get_expires(cookie))
		printf("\tExpires Date: %s\n",
				soup_date_to_string(
					soup_cookie_get_expires(cookie), SOUP_DATE_COOKIE));
	if (soup_cookie_get_secure(cookie))
		printf("\tSecure: True\n");
	else
		printf("\tSecure: False\n");
	if (soup_cookie_get_http_only(cookie))
		printf("\tHTTP Only: True\n");
	else
		printf("\tHTTP Only: False\n");
	printf("-------------\n");
}

void ui_print_cookies(int index)
{
	SoupMessage *msg;

	msg = message_get(index);
	if (!msg)
		return;
	GSList *c = soup_cookies_from_response(msg);
	printf("Cookies:\n");
	g_slist_foreach(c, ui_print_cookie, NULL);
	soup_cookies_free(c);
}
