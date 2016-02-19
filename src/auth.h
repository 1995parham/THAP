/*
 * In The Name Of God
 * ========================================
 * [] File Name : auth.h
 *
 * [] Creation Date : 20-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef AUTH_H
#define AUTH_H

void auth_callback(SoupSession *session, SoupMessage *msg,
		SoupAuth *auth, gboolean retrying,
		gpointer user_data);

SoupAuth *auth_get(int index);

void auth_authenticate(int index, const char *username, const char *password);

#endif
