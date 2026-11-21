#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX_NAME 20
#define MAX_DATA 100
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define INI_DATA 3
#define INC_SZ 2

//菜单
void menu();

//联系人信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

////通讯录
//typedef struct Contact
//{
//	int count;
//	PeoInfo data[MAX_DATA];
//}Contact;

//动态化通讯录
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

//加载通讯录
void LoadContact(Contact* pc);

//初始化通讯录
int InitContact(Contact* pc);

//查找联系人名称功能
int FindName(const char* name, const Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//显示通讯录
void ShowContact(Contact* pc);

//查找联系人函数
void SearchContact(Contact* pc);

//修改联系人信息
void ModifyContact(Contact* pc);

//以名称顺序排序联系人信息
void SortContact(Contact* pc);

//释放内存
void FreeContact(Contact* pc);

//在txt文件保存通讯录
void SaveContact(Contact* pc);

//加载通讯录
void LoadContact(Contact* pc);

//增容函数
int AddCapacity(Contact* pc);