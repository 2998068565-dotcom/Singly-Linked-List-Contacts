# 单链表通讯录（练习）

C 语言课程练习。仓库名是当时的学习计划，**需要先说明：目前的代码还不是单链表实现**。

## 当前状态

这份代码是动态数组版通讯录（仓库 `Contacts`）的副本：

- `LinklistContact.h` 与那份的 `Contact.h` **内容完全相同**（仅文件名不同）；
- `通讯录function.c` 与那份的 `Contact.c` 相比，只有 `#include` 的文件名和个别空格不同；
- `通讯录.c` 是入口 `main`，逻辑也相同。

也就是说，`Contact` 仍然是 `PeoInfo* data` + `count` + `capacity` 的动态数组，还没有改成链表节点。保留原样，对应当时"先复制一份，准备改链表"的中间状态。

## 文件

| 文件 | 作用 |
| --- | --- |
| `LinklistContact.h` | 结构体与函数声明（同 `Contact.h`） |
| `通讯录function.c` | 功能实现：菜单、加载/保存 `Contact.txt`、增删改查、排序、增容 |
| `通讯录.c` | 入口 `main`：菜单循环 |

## 已有的功能

添加、删除、查找、修改、显示、按姓名排序（`qsort`）、退出时保存并释放内存。

## 编译运行

```bat
cl 通讯录function.c 通讯录.c
通讯录.exe
```

头文件里已定义 `_CRT_SECURE_NO_WARNINGS`。

源码是 **GBK（代码页 936）** 编码，用 MSVC 直接编译正常；gcc/MinGW 建议加 `-fexec-charset=GBK` 或先转 UTF-8。

## 后续可做的改动

把 `Contact` 里的 `PeoInfo* data` 换成链表头指针，节点形如：

```c
typedef struct Node {
    PeoInfo info;
    struct Node* next;
} Node;
```

然后逐个改写增删改查：添加改成头插/尾插，删除要维护前驱指针，查找改成遍历。

## 说明

课程练习代码，数据文件 `Contact.txt` 运行时生成，不纳入版本库。
