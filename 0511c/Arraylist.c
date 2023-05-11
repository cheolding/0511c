#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ�ũ��
typedef int element; // �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L)
{
	L->size = 0;
}
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}
// ����Ʈ ���
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	int move = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
		{
			move++;
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
		printf("\n move :%d \n", move);
	}
	
}

element delete(ArrayListType* L, int pos)
{
	int move = 0;
	element item;
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
		move++;
	}
	printf("\nmove : %d\n", move);
	L->size--;
	return item;
}

int main(void)
{
	ArrayListType list;
	init(&list);
	int select;
	int item;
	int xy;

	while (1)
	{
		printf("\nMenu\n(1)Insert\n(2)Delete\n(3)Print\n(0)Exit\nEnter the menu:");
		scanf("%d", &select);

		if (select == 1)
		{
			printf("Enter the number and position :");
			scanf("%d %d", &item, &xy);
			insert(&list, xy, item);

			while (list.size == 0)
			{
				printf("list size zero Enter the number and position :");
				scanf("%d %d", &item, &xy);
				insert(&list, xy, item);
			}
		}
		else if (select == 2)
		{
			int number = 0;
			printf("Enter the position :");
			scanf("%d", &xy);
			number =delete(&list, xy);
			printf("Delete :%d\n", number);
		}
		else if (select == 3)
		{
			print_list(&list);
		}
		else if (select == 0)
		{
			printf("Exit the program ");
			break;
		}
	}
}

