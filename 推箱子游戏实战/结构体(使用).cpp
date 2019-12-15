#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {//学生结构体
	char name[16];
	int age;
};

int main(void) {
	struct Students s1, s2;//定义两个学生
	printf("请输入第一个学生的姓名:\n");
	scanf_s("%s",s1.name,sizeof(s1.name));
	printf("请输入第一个学生的年龄:\n");
	scanf_s("%d",&s1.age);
	/*
	printf("请输入第二个学生的姓名:\n");
	scanf_s("%s", s2.name,sizeof(s2.name));
	printf("请输入第二个学生的年龄:\n");
	scanf_s("%d", &s2.age);
	*/
	printf("s1的name:%s age:%d\n", s1.name, s1.age);

	//结构体的小秘密  结构体变量之间可以直接赋值
	//memcpy(&s2, &s1, sizeof(struct Students));//和下面一样
	s2 = s1;//s1学生的所有属性全赋值给s2学生
	printf("s2的name:%s age:%d\n", s2.name, s2.age);
	//char c1[16] = { "name" }, c2[16];
	//c2 = c1;//数组不能直接赋值

	system("pause");
	return 0;
}