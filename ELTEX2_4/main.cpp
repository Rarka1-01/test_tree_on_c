#define _CRT_SECURE_NO_WARNINGS
#include "btree.h"
//<Required>

int scInt(int* data)
{
	int pr = 0;
	pr = scanf("%d", data);
	fscanf(stdin, "%*[^\n]%*c");

	return pr;
}

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL)); 
	node* root = NULL;
	int t = 0, p = 0, tt = -1;
	
	do
	{
		do
		{
			p = 0;
			printf("Выберете пункт:\n");
			printf("1. Заполнить дерево случайными числами\n");
			printf("2. Добавить элемент в дерево\n");
			printf("3. Вывести дерево\n");
			printf("4. Выход\n");

			p = scInt(&t);

			system("cls");
		} while (p != 1 || t < 1 || t > 4);

		switch (t)
		{
		case 1: {
		
			clear(root);
			root = NULL;
			p = rand() % 6 + 4;
			for (int i = 0; i < p; i++)
				push(&root, rand() % 10);
			printf("Добавлено элементов: %d\n", p);
			system("pause");
		}break;

		case 2: {
		
			do
			{
				p = 0;
				printf("Введите число: ");
				p = scInt(&t);

				if (p != 1)
				{
					printf("Введены некорректные данные, введите целое число\n");
					system("pause");
				}
			} while (p != 1);
			
			push(&root, t);
			t = 0;
			printf("Успешно добавлено!\n");
			system("pause");
		} break;

		case 3: {
			
			print(root);
			system("pause");

		}break;

		case 4: t = -1; break;
		}

		system("cls");

	} while (t != -1);

	return 0;
}