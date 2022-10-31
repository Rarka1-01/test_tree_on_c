#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

struct node 
{
	struct node* left;
	struct node* right;
	struct node* par;
	int* val;
};

typedef struct node node;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void printSpace(int n)
{
	for (int i = 0; i < n; i++)
		printf(" ");
}

void push(node** root, int El)
{
	if (*root == NULL)
	{
		(*root) = (node*)malloc(sizeof(node));
		(*root)->val = (int*)malloc(sizeof(int));
		*((*root)->val) = El;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->par = NULL;
	}
	else
	{
		node* t = *root, *t1 = NULL;

		while (t != NULL)
		{
			t1 = t;

			if (El < *(t->val))
				t = t->left;
			else
				t = t->right;
		}

		t = (node*)malloc(sizeof(node));
		t->val = (int*)malloc(sizeof(int));
		*(t->val) = El;
		t->left = NULL;
		t->right = NULL;
		t->par = t1;

		if (El < *(t1->val))
			t1->left = t;
		else
			t1->right = t;
	}
}

int maxDeep(node* tr, int len = 0)
{
	int lr = 0, ll = 0;
	if (tr == NULL)
		return len;
	else
	{
		lr = maxDeep(tr->right, len + 1);
		ll = maxDeep(tr->left, len + 1);
	}

	return max(lr, ll);
}

node** convertToArray(node* root, int* l)
{
	int len = 0;

	for (int i = 0; i < maxDeep(root); i++)
		len += pow(2, i);
	*l = len;
	node** array = (node**)malloc(len * sizeof(node*));
	for (int i = 0; i < len; i++, array[i] = NULL);

	if (len != 0)
	{
		array[0] = root;
		if (len > 1)
		{
			array[1] = root->left;
			array[2] = root->right;
		}
	}
	else
		return NULL;

	for (int i = 1; i < len; i++)
	{
		if (array[i] != NULL)
		{
			array[i * 2 + 1] = array[i]->left;
			array[i * 2 + 2] = array[i]->right;
		}
	}

	return array;
}

void pa(node* root)
{
	int len = 0;
	node** a = convertToArray(root, &len);
	printf("Len = %d\n", len);
	for (int i = 0; i < len; i++)
		if (a[i] != NULL)
			printf("%d ", *(a[i]->val));
		else
			printf("N ");
	printf("\n");
}

void print(node* root)
{
	int len = 0;
	node** a = convertToArray(root, &len);

	if (a == NULL)
		printf("Дерево пустое\n");
	else
	{
		int mD = maxDeep(root);
		printSpace(pow(2, mD) - 3);
		printf("root\n");
		for (int i = 1; i <= mD; i++)
		{
			printSpace(pow(2, mD - i + 1));
			int indLvl = pow(2, i)/2 - 1;
			for (int j = 0; j < pow(2, i - 1); j++)
			{
				if (a[indLvl + j] != NULL)
					printf("%d", *(a[indLvl + j]->val));
				else
					printf(" ");
				printSpace(pow(2, mD - i + 2) - 1);
			}
			printf("\n");
		}
	}

}

