#include <stdio.h>
#include <stdlib.h>

struct friends {
	char name[32];//����
	char gender;//�Ա�g-Ů b-��
	char age;//����
};

int main(void) {

	struct friends hwx = { "������",'g',23 };
	struct friends* my_girl = &hwx;
	printf("hwx������:%s �Ա�:%s ����:%d\n", hwx.name, hwx.gender == 'g' ? "Ů" : "��", hwx.age);

	//ָ����ʽṹ������ĳ�Ա�����ַ�ʽ
	//1:ֱ�ӽ���,��ӷ��� 
	printf("my_girl������:%s �Ա�:%s ����:%d\n", 
		(*my_girl).name, (*my_girl).gender == 'g' ? "Ů" : "��",(*my_girl).age);
	//2:ֱ��ʹ��ָ����� ->
	printf("my_girl������:%s �Ա�:%s ����:%d\n",
		my_girl->name, my_girl->gender == 'g' ? "Ů" : "��", my_girl->age);

	system("pause");
	return 0;
}