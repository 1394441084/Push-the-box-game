#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum 枚举名
enum Four_seasons1 {//定义了一个Four_seasons(四季)的枚举
	spring1,  //spring是记号内部是常量  0  
	sunmer1,  //1
	autumn1,  //2
	winter1   //3
};

enum Four_seasons2 {//第二种定义 
	spring2,  //spring是记号内部是常量  0  
	sunmer2=-6,  //可以赋值负数
	autumn2='h',  //也可以赋值字符
	winter2   //3
}s,s1;//定义枚举类型时直接定义变量,此为全局变量,s=spring;0

enum {//第三种定义 省略枚举名
	spring3 = 6,  //6spring是记号内部是常量  6  
	sunmer3 = 8,  //8
	autumn3 = 20,  //20
	winter3   //21
}ss,ss1;//只能定义的变量全初始化为0

int main(void) {
	while(0){//第一种枚举
	enum Four_seasons1 s;//定义了枚举变量
	enum Four_seasons1 s1;//定义了枚举变量
	//s=0;//不能把整数赋值给枚举变量,枚举变量为常量,它的可能只能在枚举定义中
	//s = (enum Four_seasons)2;//强制类型转换是可以的,但有超出表达范围的风险
	s = spring1;
	s1 = winter1;
	
	break;
	}
	s = autumn2;
	ss1 = winter3;
	printf("ss:%d  ss1:%d\n", ss, ss1);//0,21
	printf("s:%c  s1:%d s多少字节:%d\n", s, s1,sizeof(s));//h,0,4字节,整型变量
	


	system("pause");
	return 0;
}