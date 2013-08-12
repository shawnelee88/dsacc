#ifndef _DLIST_H
#define _DLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/***************************************************************
 *This program provides a set of functions that operating double lists.
 *Author: Cong Wang
 *Date: 2005-04-05
 *Last Update: 2005-11-15
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 **************************************************************/

typedef struct dl_node{
    struct dl_node* prev;
    struct dl_node* next;
    void* pdata;
    }dlnode_t;
typedef dlnode_t* p_dlnode_t;
typedef struct dlist{
    p_dlnode_t head;
    p_dlnode_t tail;
    int size;
    }dlist_t;
typedef dlist_t* p_dlist_t;

p_dlist_t dlist_create(void);
int dlist_add_after(p_dlist_t ,int ,void*,size_t);
int dlist_add_before(p_dlist_t ,int ,void*,size_t);
void dlist_delete(p_dlist_t ,int);
void dlist_update(p_dlist_t ,int ,void*,size_t);
void dlist_destroy(p_dlist_t);
void* dlist_visit(p_dlist_t,int);
void dlist_trav(p_dlist_t,void(*)(void*));
int dlist_search(p_dlist_t,void*,int (*)(void*,void*));
extern int errno;

#endif
