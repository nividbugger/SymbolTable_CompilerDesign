#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_tab.h"

void* init_table()
{
	t = malloc(sizeof(table));
	t->head = NULL;
}

symbol* init_symbol(char* name, int type, int lineno)
{
	symbol *temp;
    temp=(symbol*)malloc(sizeof(symbol));
 	temp->name=name;
	//printf("%s\t%d\t%d\n",name,type,lineno);
	//temp->size=size;
	temp->type=type;
	temp->line=lineno;
	temp->scope=1;
	temp->val="~";
	temp->next=NULL;
	switch(type)
	{
		case 1: temp->size=1;
				break;
		case 2: temp->size=2;
				break;
		case 3: temp->size=4;
				break;
		case 4: temp->size=8;
				break;
	}
	return temp;
}

void insert_into_table(char* name,int type, int lineno)
{
    symbol *new_symbol=init_symbol(name,type,lineno);
	if(t->head==NULL)
		t->head=new_symbol;
	else
	{
		symbol *temp;
		temp=t->head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new_symbol;
	}
	//printf("INSERTED\n");
}

int check_symbol_table(char* name) //return a value like integer for checking
{
    symbol *temp;
	temp=t->head;
	if(temp==NULL)
		return 0;
	while(temp!=NULL)
	{
		//printf(",%s,%s, ",temp->name,name);
		if(strcmp(temp->name,name)==0)
		{
			//printf("SENDING 1");
			return 1;
		}
		temp=temp->next;
	}
	//printf("RETS");
	return 0;
}

void insert_value_to_name(char* name,char* value)
{
    symbol *temp;
	//printf("HELLOOO");
	temp=t->head;
	while(temp->next!=NULL)
	{
		if(temp->name==name)
		{
			temp->val=value;
			return;
		}
		temp=temp->next;
	}
}

void display_symbol_table()
{
	symbol *temp;
	temp=t->head;
	if(t == NULL)
	{
		printf("Symbol Table EMPTY\n");
		return;
	}
	printf("Name\tSize\ttype\tlineno\tscope\tvalue\n");
	while (temp!=NULL)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%s\n",temp->name,temp->size,temp->type,temp->line,temp->scope,temp->val);
		temp=temp->next;
	}
	printf("\n");
}
