#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students {
	char name[16];
	int age;
};


int main(void) {
	struct students s[2];//��������ѧ��
	printf("�������һ��ѧ��������:\n");
	scanf_s("%s",s[0].name, sizeof(s[0].name));
	printf("�������һ��ѧ��������:\n");
	scanf_s("%d", &s[0].age);
	/*
	printf("������ڶ���ѧ��������:\n");
	scanf_s("%s", s[1].name,sizeof(s[1].name));
	printf("������ڶ���ѧ��������:\n");
	scanf_s("%d", &s[1].age);
	*/
	printf("s1��name:%s age:%d\n", s[0].name, s[0].age);

	//�ṹ���С����  �ṹ�����֮�����ֱ�Ӹ�ֵ
	//memcpy(&s[1], &s[0], sizeof(struct Students));//������һ��
	s[1] = s[0];//s1ѧ������������ȫ��ֵ��s2ѧ��
	printf("s2��name:%s age:%d\n", s[1].name, s[1].age);
	//char c1[16] = { "name" }, c2[16];
	//c2 = c1;//���鲻��ֱ�Ӹ�ֵ

	system("pause");
	return 0;
}