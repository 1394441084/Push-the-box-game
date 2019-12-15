#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
/*
1 为什么要使用宏 ? 提高代码的可读性和可维护性 ? 避免函数调用，提高程序效率
2 什么是宏 它是一种预处理器指令，在预编译阶段将宏名暴力的替换为后面的替换体 。
3 宏的定义 由三部分组成
#define      WIDTH     "960"  //直接替换
预处理指令   宏名     替换体(多行可用 \ 延续) "960"
#define  超长宏  "我家住在黄土高坡,嘿嘿额黑恶黑黑\
哎呀,要替换的宏太长了"
=="我家住在黄土高坡,嘿嘿额黑恶黑黑哎呀,要替换的宏太长了"
printf("%s\n",超长宏);
*/
#define      WIDTH     "  960  空格也进来了\n换行了这回车符也进来了"  //直接替换空格也收录
//预处理指令   宏名     替换体(多行可用 \ 延续) "960"
#define  超长宏  "我家住在黄土高坡,嘿嘿额黑恶黑黑\
哎呀,要替换的宏太长了"
#define  SQUARE(x)  x*x  //带参数的宏
#define  MAXDX(x,y)  x>y?x:y  //x>y吗?是大于就返回x,不是就返回y,返回最大值

int main(void) {
	int x = 0;
	printf("%s\n", 超长宏);
	cout << 超长宏 <<WIDTH<< endl;
	int i = 10;
	int j = SQUARE(i);//宏展开j=i*i;
	cout << j << endl;
	cout << "---------------\n";
	int d = MAXDX(i,j);//宏展开i>j?i:j
	cout << "MAXDX=" << d << endl;
	cout << "---------------\n";
	int z = SQUARE(2 + 3);//宏展开2+3*2+3;要想有正确结果就要在宏定义(x)*(x)
	cout << z << endl;//11;要想有正确结果就要在宏定义(x)*(x)

	system("pause");
	return 0;
}