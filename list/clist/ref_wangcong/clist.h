#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef _CLIST_H
#define _CLIST_H

/************************************************************
 *This program provides a set of functions that operating circular lists.
 *Author: Cong Wang
 *Date: 2005-04-06
 *Last Update: 2005-11-15
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 ***********************************************************/

typedef struct dl_node{
	struct dl_node* prev;
	struct dl_node* next;
	void* pdata;
	}dlnode_t;
typedef dlnode_t* p_dlnode_t;
typedef struct clist{
	p_dlnode_t head;
	p_dlnode_t tail;
	int size;
	}clist_t;
typedef clist_t* p_clist_t;
	
extern int errno;
p_clist_t clist_create(void);
int clist_insert(p_clist_t ,int ,void*,size_t);
void clist_delete(p_clist_t,int);
void clist_update(p_clist_t ,int ,void*,size_t);
void clist_trav(p_clist_t,void(*)(void*));
void clist_destroy(p_clist_t);
void* clist_visit(p_clist_t,int);
int clist_search(p_clist_t,void*,int (*)(void*,void*));
void clist_rotate(p_clist_t ,int);

#endif
