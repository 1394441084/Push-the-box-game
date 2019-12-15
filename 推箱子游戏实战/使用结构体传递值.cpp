#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct programmer {
	char name[16];
	int age;
	int salary;
};

//形参是结构体变量,值传递
void add_salary1(struct programmer p,int num) {
	p.salary += num;//加薪版本1,唉,加不成功
}
//形参使用结构体指针
void add_salary2(struct programmer* p, int num) {
	if (!p)return;
	p->salary += num;//加薪版本2,yes,加薪成功
}
//形参使用引用
void add_salary3(struct programmer &p, int num) {
	p.salary += num;//加薪版本2,yes,加薪成功
}
//形参是结构体变量,值传递
struct programmer add_salary4(struct programmer p, int num) {
	p.salary += num;
	return p;
}
//形参是结构体变量,值传递,返回的是引用
struct programmer &add_salary5(struct programmer p, int num) {
	p.salary += num;
	return p;
}


int main(void) {
	struct programmer xiaoniu;
	strcpy_s(xiaoniu.name, "小牛");
	xiaoniu.age = 28;
	xiaoniu.salary = 20000;
	add_salary1(xiaoniu, 5000);
	//结构体变量作为参数传值是值传递,和int等基本类型是一样
	printf("xiaoniu的姓名:%s 年龄:%d 版本1加薪后:%d\n", 
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	add_salary2(&xiaoniu, 5000);
	//结构体变量作为参数传值是值传递,和int等基本类型是一样
	printf("xiaoniu的姓名:%s 年龄:%d 版本2加薪后:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	add_salary3(xiaoniu, 10000);
	//结构体变量作为参数传值是值传递,和int等基本类型是一样
	printf("xiaoniu的姓名:%s 年龄:%d 版本3加薪后:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	xiaoniu= add_salary4(xiaoniu, 5000);
	printf("xiaoniu的姓名:%s 年龄:%d 版本4加薪后:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	//返回引用
	xiaoniu=add_salary5(xiaoniu,2);
	printf("xiaoniu的姓名:%s 年龄:%d 版本5加薪后:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	system("pause");
	return 0;
}