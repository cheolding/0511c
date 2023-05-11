#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100 // 리스트의 최대크기
typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
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
		error("리스트 오버플로우");
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
		error("위치 오류");
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

