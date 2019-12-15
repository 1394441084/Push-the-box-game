#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
1 为什么要使用“结构”（结构体） 
但需要表示一些复杂信息时，使用单纯的数据类型很不方便。 
比如：学生信息（学号，姓名，班级，电话，年龄） 
2 什么是“结构” 结构，就是程序员自定义的一种“数据类型” 
是使用多个基本数据类型、或者其他结构，组合而成的一种新的“数据类型”。 
3 结构的定义 
struct 结构名 { 
成员类型 成员名； 
成员类型 成员名； }; 
实例： 
struct student {
char name[16]; 
int age; 
char tel[12]; }; 
特别注意： 1）要以 struct 开头 2）最后要使用分号 3）各成员之间用分号隔开
*/

struct a {//结构体的定义
	char name[16];
	int age;
	char trl[12];
};

struct b {//结构体包含结构体的情况,结构体嵌套
	struct a zwc;
	struct a hwx;
};

int main(void) {
	struct a zwc;//曾经也是学生,所以定义了zwc//结构的定义
	
	//结构体的初始化
	//方式一  定义的时候初始化所有的属性
	struct a hwx = { "何宛夏",23,"电话不知道" };
	printf("hwx的姓名:%s  hwx年龄:%d\n", hwx.name,hwx.age);//结构体的访问

	//方式二  定义的时候可以指定初始化的属性 VS\VC不支持 但gcc支持
	//struct a hwx1 = { .name = "何宛夏1",.age = 18 };

	//方式三  将结构体的属性拿出来,单独初始每一个属性
	strcpy_s(zwc.name, "周伟长");//给数组赋值
	zwc.age = 23;
	zwc.trl[0] = '\0';//不知道电话
	printf("zwc的姓名:%s  zwc年龄:%d\n", zwc.name, zwc.age);//结构体的访问

	//结构体中含有结构体
	struct b c1 = { { "周伟长.",23,"电话不知道" },{ "何宛夏",23,"电话不知道" } };//初始化
	printf("c1.zwc.nema:%s\n", c1.zwc.name);//引用访问   a与b结构体中的属性变量互不冲突
	//printf("zwc的姓名:%s  zwc年龄:%d\n", zwc.name, zwc.age);//结构体的访问

	system("pause");
	return 0;
}