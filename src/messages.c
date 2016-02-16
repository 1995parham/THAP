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
#include <stdint.h>

#include "messages.h"

static GHashTable *m;

static void messages_init(void)
{
	m = g_hash_table_new(g_int64_hash, g_int64_equal);
}

void messages_add(SoupMessage *msg, uint64_t index)
{
	if (!m)
		messages_init();
	g_hash_table_insert(m, &index, msg);
}

SoupMessage *message_get(uint64_t index)
{
	if (!m)
		messages_init();
	return g_hash_table_lookup(m, &index);
}

