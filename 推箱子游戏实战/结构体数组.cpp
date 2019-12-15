#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students {
	char name[16];
	int age;
};


int main(void) {
	struct students s[2];//定义两个学生
	printf("请输入第一个学生的姓名:\n");
	scanf_s("%s",s[0].name, sizeof(s[0].name));
	printf("请输入第一个学生的年龄:\n");
	scanf_s("%d", &s[0].age);
	/*
	printf("请输入第二个学生的姓名:\n");
	scanf_s("%s", s[1].name,sizeof(s[1].name));
	printf("请输入第二个学生的年龄:\n");
	scanf_s("%d", &s[1].age);
	*/
	printf("s1的name:%s age:%d\n", s[0].name, s[0].age);

	//结构体的小秘密  结构体变量之间可以直接赋值
	//memcpy(&s[1], &s[0], sizeof(struct Students));//和下面一样
	s[1] = s[0];//s1学生的所有属性全赋值给s2学生
	printf("s2的name:%s age:%d\n", s[1].name, s[1].age);
	//char c1[16] = { "name" }, c2[16];
	//c2 = c1;//数组不能直接赋值

	system("pause");
	return 0;
}