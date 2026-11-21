#include "LinklistContact.h"

//菜单
void menu()
{
	printf("**************************************************************\n");
	printf("**************    1.add               2.del    ***************\n");
	printf("**************    3.search            4.modify ***************\n");
	printf("**************    5.show              6.sort   ***************\n");
	printf("**************              0.exit             ***************\n");
	printf("**************************************************************\n");
	printf("**************************************************************\n");
	printf("**************************************************************\n");
}

////初始化通讯录
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//加载通讯录
void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("Contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf) == 1)
	{
		AddCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pf);
	pf = NULL;
}


//初始化动态通讯录
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(INI_DATA, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = INI_DATA;
	LoadContact(pc);
	return 0;
}

//寻找联系人名称功能
int FindName(const char* name, const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		return -1;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

////添加联系人
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX_DATA)
//	{
//		printf("通讯录已满，无法添加！\n");
//		return;
//	}
//	printf("请输入名字:");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄:");
//	scanf("%d", &pc->data[pc->count].age);
//	printf("请输入性别:");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话号码:");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址:");
//	scanf("%s", pc->data[pc->count].addr);
//	pc->count++;
//	printf("修改成功!\n");
//}

//增容函数
int AddCapacity(Contact* pc)
{
	assert(pc);
	if (pc->capacity == pc->count)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + INC_SZ));
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
			return 1;
		}
		else
		{
			pc->data = ptr;
			printf("增容成功\n");
		}
		pc->capacity += INC_SZ;
		return 0;
	}
	else
		return 0;
}

//动态添加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	AddCapacity(pc);
	printf("请输入名字:");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别:");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话号码:");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("修改成功!\n");
}

//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("输入你要删除的联系人:");
	scanf("%s", name);
	int pos = FindName(name, pc);
	if (pos == -1)
	{
		printf("没找到联系人，无法删除\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < pc->count - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->count--;
	}
}

//显示通讯录
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < pc->count; i++)
		{
			printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
		}
	}
}

//查找联系人函数
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入查找对象:");
	scanf("%s", name);
	int pos = FindName(name, pc);
	if (pos == -1)
	{
		printf("未找到联系人！\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

//修改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入修改对象:");
	scanf("%s", name);
	int pos = FindName(name, pc);
	if (pos == -1)
	{
		printf("未找到联系人！\n");
		return;
	}
	else
	{
		printf("请输入要修改的联系人名称:");
		scanf("%s", pc->data[pos].name);
		printf("请输入要修改的年龄:");
		scanf("%d", &pc->data[pos].age);
		printf("请输入要修改的性别:");
		scanf("%s", pc->data[pos].sex);
		printf("请输入要修改的电话号码:");
		scanf("%s", pc->data[pos].tele);
		printf("请输入要修改的地址:");
		scanf("%s", pc->data[pos].addr);
	}
	printf("修改成功！\n");
}

//用于排序联系人信息中qsort库函数的比较函数
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//以名称顺序排序联系人信息
void SortContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序完成！\n");
}

//释放内存
void FreeContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->count = 0;
	pc->capacity = 0;
}

//保存
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
	printf("保存成功!\n");
}