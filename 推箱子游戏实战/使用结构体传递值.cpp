#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct programmer {
	char name[16];
	int age;
	int salary;
};

//�β��ǽṹ�����,ֵ����
void add_salary1(struct programmer p,int num) {
	p.salary += num;//��н�汾1,��,�Ӳ��ɹ�
}
//�β�ʹ�ýṹ��ָ��
void add_salary2(struct programmer* p, int num) {
	if (!p)return;
	p->salary += num;//��н�汾2,yes,��н�ɹ�
}
//�β�ʹ������
void add_salary3(struct programmer &p, int num) {
	p.salary += num;//��н�汾2,yes,��н�ɹ�
}
//�β��ǽṹ�����,ֵ����
struct programmer add_salary4(struct programmer p, int num) {
	p.salary += num;
	return p;
}
//�β��ǽṹ�����,ֵ����,���ص�������
struct programmer &add_salary5(struct programmer p, int num) {
	p.salary += num;
	return p;
}


int main(void) {
	struct programmer xiaoniu;
	strcpy_s(xiaoniu.name, "Сţ");
	xiaoniu.age = 28;
	xiaoniu.salary = 20000;
	add_salary1(xiaoniu, 5000);
	//�ṹ�������Ϊ������ֵ��ֵ����,��int�Ȼ���������һ��
	printf("xiaoniu������:%s ����:%d �汾1��н��:%d\n", 
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	add_salary2(&xiaoniu, 5000);
	//�ṹ�������Ϊ������ֵ��ֵ����,��int�Ȼ���������һ��
	printf("xiaoniu������:%s ����:%d �汾2��н��:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	add_salary3(xiaoniu, 10000);
	//�ṹ�������Ϊ������ֵ��ֵ����,��int�Ȼ���������һ��
	printf("xiaoniu������:%s ����:%d �汾3��н��:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	xiaoniu= add_salary4(xiaoniu, 5000);
	printf("xiaoniu������:%s ����:%d �汾4��н��:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	//��������
	xiaoniu=add_salary5(xiaoniu,2);
	printf("xiaoniu������:%s ����:%d �汾5��н��:%d\n",
		xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	system("pause");
	return 0;
}