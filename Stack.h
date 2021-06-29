#pragma once
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

struct Stack
{
	struct TreeNode *t;
	struct Stack *link;
};

struct Stack *stack = NULL;

bool isEmpty(struct Stack *top)
{
	return top == NULL;
}

void push(struct Stack *top_ref, struct TreeNode *treenode)
{
	struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
	st->t = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	if (st == NULL)
	{
		printf("Stack Overflow \n");
		return;
	}

	st->t = treenode;
	st->link = top_ref;

	stack = st;
}

struct TreeNode* pop(struct Stack *top_ref)
{
	struct TreeNode *tnode;
	struct Stack *snode;

	if (isEmpty(top_ref))
	{
		printf("Stack Underflow \n");
		getchar();
		exit(0);
	}
	else
	{
		snode = top_ref;
		tnode = snode->t;
		top_ref = top_ref->link;
		stack = top_ref;
		free(snode);
		return tnode;
	}
}

/*
void disposeStack(struct Stack *st)
{
	if (st != NULL)
	{
		free(st->t);
		free(st);
	}
}
*/