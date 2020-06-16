/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** get epoll statment
*/

#include "AI.h"

/*!
** @brief Get the epoll st object
**
** @param st choice
** @return uint32_t (st) ? EPOLLIN : EPOLLOUT
*/
uint32_t get_epoll_st(bool st)
{
	return ((st) ? EPOLLIN : EPOLLOUT);
}