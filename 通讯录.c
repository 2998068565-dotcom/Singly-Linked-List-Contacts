#include "LinklistContact.h"


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	Contact Con = { 0 };
	InitContact(&Con);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&Con);
			break;
		case DEL:
			DelContact(&Con);
			break;
		case SEARCH:
			SearchContact(&Con);
			break;
		case MODIFY:
			ModifyContact(&Con);
			break;
		case SHOW:
			ShowContact(&Con);
			break;
		case SORT:
			SortContact(&Con);
			break;
		case EXIT:
			SaveContact(&Con);
			FreeContact(&Con);
			printf("退出\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}