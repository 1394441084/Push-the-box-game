#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
1 ΪʲôҪʹ�á��ṹ�����ṹ�壩 
����Ҫ��ʾһЩ������Ϣʱ��ʹ�õ������������ͺܲ����㡣 
���磺ѧ����Ϣ��ѧ�ţ��������༶���绰�����䣩 
2 ʲô�ǡ��ṹ�� �ṹ�����ǳ���Ա�Զ����һ�֡��������͡� 
��ʹ�ö�������������͡����������ṹ����϶��ɵ�һ���µġ��������͡��� 
3 �ṹ�Ķ��� 
struct �ṹ�� { 
��Ա���� ��Ա���� 
��Ա���� ��Ա���� }; 
ʵ���� 
struct student {
char name[16]; 
int age; 
char tel[12]; }; 
�ر�ע�⣺ 1��Ҫ�� struct ��ͷ 2�����Ҫʹ�÷ֺ� 3������Ա֮���÷ֺŸ���
*/

struct a {//�ṹ��Ķ���
	char name[16];
	int age;
	char trl[12];
};

struct b {//�ṹ������ṹ������,�ṹ��Ƕ��
	struct a zwc;
	struct a hwx;
};

int main(void) {
	struct a zwc;//����Ҳ��ѧ��,���Զ�����zwc//�ṹ�Ķ���
	
	//�ṹ��ĳ�ʼ��
	//��ʽһ  �����ʱ���ʼ�����е�����
	struct a hwx = { "������",23,"�绰��֪��" };
	printf("hwx������:%s  hwx����:%d\n", hwx.name,hwx.age);//�ṹ��ķ���

	//��ʽ��  �����ʱ�����ָ����ʼ�������� VS\VC��֧�� ��gcc֧��
	//struct a hwx1 = { .name = "������1",.age = 18 };

	//��ʽ��  ���ṹ��������ó���,������ʼÿһ������
	strcpy_s(zwc.name, "��ΰ��");//�����鸳ֵ
	zwc.age = 23;
	zwc.trl[0] = '\0';//��֪���绰
	printf("zwc������:%s  zwc����:%d\n", zwc.name, zwc.age);//�ṹ��ķ���

	//�ṹ���к��нṹ��
	struct b c1 = { { "��ΰ��.",23,"�绰��֪��" },{ "������",23,"�绰��֪��" } };//��ʼ��
	printf("c1.zwc.nema:%s\n", c1.zwc.name);//���÷���   a��b�ṹ���е����Ա���������ͻ
	//printf("zwc������:%s  zwc����:%d\n", zwc.name, zwc.age);//�ṹ��ķ���

	system("pause");
	return 0;
}