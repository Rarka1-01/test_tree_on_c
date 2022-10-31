#define _CRT_SECURE_NO_WARNINGS
#include "btree.h"
//<Required>
int main()
{
	system("chcp 1251");
	system("cls");
	//srand(time(NULL)); 
	node* root = NULL;
	
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);
	push(&root, rand() % 10);

	printf("%d\n", maxDeep(root));

	pa(root);

	print(root);
	printf("123\n");

	return 0;
}