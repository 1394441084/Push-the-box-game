#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {//ѧ���ṹ��
	char name[16];
	int age;
};

int main(void) {
	struct Students s1, s2;//��������ѧ��
	printf("�������һ��ѧ��������:\n");
	scanf_s("%s",s1.name,sizeof(s1.name));
	printf("�������һ��ѧ��������:\n");
	scanf_s("%d",&s1.age);
	/*
	printf("������ڶ���ѧ��������:\n");
	scanf_s("%s", s2.name,sizeof(s2.name));
	printf("������ڶ���ѧ��������:\n");
	scanf_s("%d", &s2.age);
	*/
	printf("s1��name:%s age:%d\n", s1.name, s1.age);

	//�ṹ���С����  �ṹ�����֮�����ֱ�Ӹ�ֵ
	//memcpy(&s2, &s1, sizeof(struct Students));//������һ��
	s2 = s1;//s1ѧ������������ȫ��ֵ��s2ѧ��
	printf("s2��name:%s age:%d\n", s2.name, s2.age);
	//char c1[16] = { "name" }, c2[16];
	//c2 = c1;//���鲻��ֱ�Ӹ�ֵ

	system("pause");
	return 0;
}