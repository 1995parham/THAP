/*
 * In The Name Of God
 * ========================================
 * [] File Name : messages.c
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

#include "messages.h"

static GHashTable *m;

static void messages_init(void)
{
	m = g_hash_table_new(g_direct_hash, g_direct_equal);
}

void messages_add(SoupMessage *msg, int index)
{
	if (!m)
		messages_init();
	g_hash_table_insert(m, GINT_TO_POINTER(index), msg);
}

SoupMessage *message_get(int index)
{
	if (!m)
		messages_init();
	return g_hash_table_lookup(m, GINT_TO_POINTER(index));
}

