#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef _QUEUE_H
#define _QUEUE_H
/**************************************************************
 *This program provides a set of functions that operating  FIFO Queue.
 *Author: Cong Wang
 *Date: 2005-03-30
 *Last Update: 2005-11-16
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 *************************************************************/

typedef struct sl_node{
	void* pdata;
	struct sl_node* next;
	}slnode_t;
typedef slnode_t* p_slnode_t;
typedef struct Queue{
	int size;
	p_slnode_t head;
	p_slnode_t tail;
	}queue_t;
typedef queue_t* p_queue_t;

extern int errno;
p_queue_t queue_create(void);
int queue_isempty(p_queue_t);
int queue_put(p_queue_t,void*,size_t);
void* queue_get(p_queue_t);
void queue_delete(p_queue_t);
void queue_destroy(p_queue_t);

#endif
