/*
 * In The Name Of God
 * ========================================
 * [] File Name : auth.c
 *
 * [] Creation Date : 20-02-2016
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

#include "auth.h"

static GHashTable *a;

static void auth_init(void)
{
	a = g_hash_table_new(g_direct_hash, g_direct_equal);
}

void auth_callback(SoupSession *session, SoupMessage *msg,
		SoupAuth *auth, gboolean retrying,
		gpointer user_data)
{
	if (!a)
		auth_init();
	int index = *(int *) user_data;

	index++;
	g_hash_table_insert(a, GINT_TO_POINTER(index), auth);
}

SoupAuth *auth_get(int index)
{
	if (!a)
		auth_init();
	return g_hash_table_lookup(a, GINT_TO_POINTER(index));
}

void auth_authenticate(int index, const char *username, const char *password)
{
	if (!a)
		auth_init();
	SoupAuth *auth = NULL;

	auth = g_hash_table_lookup(a, GINT_TO_POINTER(index));
	if (!auth)
		return;
	soup_auth_authenticate(auth, username, password);
}
