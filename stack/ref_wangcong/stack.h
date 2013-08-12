#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


/***********************************************************
 *This program provides a set of functions that operating FILO stacks.
 *Author: Cong Wang
 *Date: 2005-03-15
 *Last Update: 2005-11-16
 *Version: 1.1
 *Notice that it is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *Report bugs to xiyou.wangcong@gmail.com .
 *************************************************************/

typedef struct slnode{
	void* pdata;
	struct slnode *next;
	}slnode_t;
typedef slnode_t* p_slnode_t;
typedef struct stack{
	p_slnode_t top;
	p_slnode_t base;
	int size;
	}stack_t;
typedef stack_t* p_stack_t;

extern int errno;
p_stack_t stack_create(void);
int push(p_stack_t,void*,size_t);
void pop(p_stack_t);
void stack_destroy(p_stack_t);
int isempty(p_stack_t);
void* top(p_stack_t);

#endif

