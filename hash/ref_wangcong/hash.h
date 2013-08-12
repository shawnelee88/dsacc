#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*************************************************************
 *This header provides a set of functions that operating hash tables.
 *Author: Cong Wang
 *Date: 2005-05-03
 *Last Update: 2005-11-16
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 **************************************************************/

int hash(void*,size_t,int);
extern int errno;

/*Use separate lists here.*/
typedef struct sl_node{
	void* pdata;
	struct sl_node *next;
	}slnode_t;
typedef slnode_t* p_slnode_t;
typedef struct hash_node{
	int len;
	p_slnode_t next;
	}hsnode_t;
typedef hsnode_t* p_hsnode_t;
typedef struct hashtable{
	int size;
	p_hsnode_t table;
	}hstable_t;
typedef hstable_t* p_hstable_t;

p_hstable_t hashtable_create(int);
int hash_insert(p_hstable_t,void*,size_t);
p_slnode_t hash_find(p_hstable_t,void*,size_t,int (*)(void*,void*));
void hashtable_clear(p_hstable_t);
void hashtable_destroy(p_hstable_t);

/**********************************************************************/

/*Use open address here.*/
typedef enum status{empty,full}stat_t;
typedef struct hash_node2{
	stat_t atr;
	void* pdata;
	}hsnode2_t;
typedef hsnode2_t* p_hsnode2_t;
typedef struct hashtable2{
	int size;
	p_hsnode2_t table;
	}hstable2_t;
typedef hstable2_t* p_hstable2_t;

p_hstable2_t hashtable_create2(int);
int hash_insert2(p_hstable2_t,void*,size_t n);
p_hsnode2_t hash_find2(p_hstable2_t,void*,size_t,int (*)(void*,void*));
void hashtable_clear2(p_hstable2_t);
void hashtable_destroy2(p_hstable2_t);

#endif
