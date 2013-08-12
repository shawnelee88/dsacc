#ifndef _SLIST_H
#define _SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/**************************************************************
 *This header provides a set of functions that operating single lists.
 *Author: Cong Wang
 *Date: 2005-03-09
 *Last Update: 2005-11-15
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 *************************************************************/

typedef struct sl_node{
	void* pdata;
	struct sl_node *next;
	}slnode_t;
typedef slnode_t* p_slnode_t;
typedef struct slist{
	int size;
	p_slnode_t head;
	p_slnode_t tail;
	}slist_t;
typedef slist_t* p_slist_t;

extern int errno;
p_slist_t slist_create(void);
int slist_insert(p_slist_t ,int,void*,size_t);
void slist_delete(p_slist_t,int);
void slist_update(p_slist_t,int ,void*,size_t);
void slist_destroy(p_slist_t);
int slist_search(p_slist_t,void*,int (*)(void*,void*));
void* slist_visit(p_slist_t,int);
void slist_trav(p_slist_t,void(*)(void*));

#endif

