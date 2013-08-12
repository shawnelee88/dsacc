#ifndef _DEQUE_H
#define _DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/*************************************************************************
 *This program provides a set of functions that operating DeQueues.
 *Author: Cong Wang
 *Date: 2005-03-30
 *Last Update: 2005-11-16
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 *************************************************************************/
typedef struct dl_node{
	void* pdata;
	struct dl_node* prev;
	struct dl_node* next;
	}dlnode_t;
typedef dlnode_t* p_dlnode_t;
typedef struct dequeue{
	int size;
	p_dlnode_t head;
	p_dlnode_t tail;
	}deque_t;
typedef deque_t* p_deque_t;

extern int errno;
p_deque_t deque_create(void);
int deque_isempty(p_deque_t);
int deque_put_head(p_deque_t,void*,size_t);
int deque_put_tail(p_deque_t,void*,size_t);
void* deque_get_head(p_deque_t);
void* deque_get_tail(p_deque_t);
void deque_pop_head(p_deque_t);
void deque_pop_tail(p_deque_t);
void deque_destroy(p_deque_t);

#endif
