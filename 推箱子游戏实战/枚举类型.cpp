#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum ö����
enum Four_seasons1 {//������һ��Four_seasons(�ļ�)��ö��
	spring1,  //spring�ǼǺ��ڲ��ǳ���  0  
	sunmer1,  //1
	autumn1,  //2
	winter1   //3
};

enum Four_seasons2 {//�ڶ��ֶ��� 
	spring2,  //spring�ǼǺ��ڲ��ǳ���  0  
	sunmer2=-6,  //���Ը�ֵ����
	autumn2='h',  //Ҳ���Ը�ֵ�ַ�
	winter2   //3
}s,s1;//����ö������ʱֱ�Ӷ������,��Ϊȫ�ֱ���,s=spring;0

enum {//�����ֶ��� ʡ��ö����
	spring3 = 6,  //6spring�ǼǺ��ڲ��ǳ���  6  
	sunmer3 = 8,  //8
	autumn3 = 20,  //20
	winter3   //21
}ss,ss1;//ֻ�ܶ���ı���ȫ��ʼ��Ϊ0

int main(void) {
	while(0){//��һ��ö��
	enum Four_seasons1 s;//������ö�ٱ���
	enum Four_seasons1 s1;//������ö�ٱ���
	//s=0;//���ܰ�������ֵ��ö�ٱ���,ö�ٱ���Ϊ����,���Ŀ���ֻ����ö�ٶ�����
	//s = (enum Four_seasons)2;//ǿ������ת���ǿ��Ե�,���г�����ﷶΧ�ķ���
	s = spring1;
	s1 = winter1;
	
	break;
	}
	s = autumn2;
	ss1 = winter3;
	printf("ss:%d  ss1:%d\n", ss, ss1);//0,21
	printf("s:%c  s1:%d s�����ֽ�:%d\n", s, s1,sizeof(s));//h,0,4�ֽ�,���ͱ���
	


	system("pause");
	return 0;
}