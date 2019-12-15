#include <stdio.h>
#include <stdlib.h>

struct friends {
	char name[32];//姓名
	char gender;//性别g-女 b-男
	char age;//年龄
};

int main(void) {

	struct friends hwx = { "何宛夏",'g',23 };
	struct friends* my_girl = &hwx;
	printf("hwx的名字:%s 性别:%s 年龄:%d\n", hwx.name, hwx.gender == 'g' ? "女" : "男", hwx.age);

	//指针访问结构体变量的成员有两种方式
	//1:直接解引,间接访问 
	printf("my_girl的名字:%s 性别:%s 年龄:%d\n", 
		(*my_girl).name, (*my_girl).gender == 'g' ? "女" : "男",(*my_girl).age);
	//2:直接使用指针访问 ->
	printf("my_girl的名字:%s 性别:%s 年龄:%d\n",
		my_girl->name, my_girl->gender == 'g' ? "女" : "男", my_girl->age);

	system("pause");
	return 0;
}