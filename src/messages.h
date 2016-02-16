/*
 * In The Name Of God
 * ========================================
 * [] File Name : messages.h
 *
 * [] Creation Date : 17-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef MESSAGES_H
#define MESSAGES_H

#include <libsoup/soup.h>

void messages_add(SoupMessage *msg, uint64_t index);

SoupMessage *message_get(uint64_t index);

#endif
