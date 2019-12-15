#include "box_main.h" //��ͷ�ļ��е�����ȫ�滻���˴�

int main(void) {

	IMAGE bg_img;//����һ��ͼƬ����

	//���ⴴ���ͻ���(���Ŀͻ���)
	initgraph(CLIENT_X_AXI, CLIENT_Y_AXI);//���̨,�������ʼ,����ͻ��˵���Ļ

	//��ӳ(ͼƬ�����ĵ�ַ,ͼƬ��·��,ͼƬ�Ĵ�СX,ͼƬ�Ĵ�СY,ͼƬ�Ƿ�����(��𲻴�));
	//����Ҫ��ӳ����̨��Ļ��ͼƬ,���ص�ͼƬ������(&bg_img),ͨ��bg_img����ͼƬ
	loadimage(&bg_img, _T("blackground.bmp"), CLIENT_X_AXI, CLIENT_Y_AXI, true);//����ֻ�ǽ�ͼƬ��bg_img���Ӷ���

	//����image(ͼƬ)(����X,����Y,ͼƬ);//�ͻ��˳����
	putimage(0, 0,&bg_img);//������0,0,��ʼ����ͼƬ,����ͼƬ�����ڿͻ�����Ļ��ʾ������

	//�ѵ���ͼƬ���ؽ�images[7]��
	loadimage(&images[wall], _T("wall_right.bmp"), DJTPXS, DJTPXS, true);//ǽ
	loadimage(&images[Floor], _T("floor.bmp"), DJTPXS, DJTPXS, true);//�ذ�
	loadimage(&images[target], _T("des.bmp"), DJTPXS, DJTPXS, true);//����Ŀ�ĵ�
	loadimage(&images[people], _T("man.bmp"), DJTPXS, DJTPXS, true);//����
	loadimage(&images[box], _T("box.bmp"), DJTPXS, DJTPXS, true);//����
	loadimage(&images[hit], _T("box.bmp"), DJTPXS, DJTPXS, true);//��������Ŀ��

	//�ڿͻ��˰���images�����ͼƬ
	for (int i = 0,a = 0; i < MAP_LINE; i++) {//��
		for (int j = 0; j < MAP_COLUMN; j++) {//��
			if (Game_map[i][j] == people) {//��ȡ������������
				man.line = i;
				man.column = j;
			}
			else if (Game_map[i][j] == target) {//��ȡ�յ������
				target1[a].line = i;
				target1[a].column = j;
				a++;
			}
			//ͼƬ����61*61����,X(��)��������,Y(��)��������
			//ƫ����+i*61,ƫ����+j*61;(i++)*61,(j++)*61;
			//�����ͰѶ�ά�������ʾͼƬ�����
			putimage(OFFSET_X+j* DJTPXS, OFFSET_Y+i* DJTPXS, &images[(Game_map[i][j])]);
		}
	}

	//��Ϸ����
	bool quit = false;
	int a = 0;
	do {
		if (_kbhit()) {//�ж��Ƿ����û�����
	//KEY_UP 'w',KEY_LEFT  'a',KEY_RIGHT 'd',KEY_DOWN  's',KEY_QUIT  'q'
			a++;
			char ch = _getch();//���µļ�(�ַ�)��ֵ��char ch;
			if (ch == KEY_UP) {
				Character_orientation(UP);
			}
			else if (ch == KEY_DOWN) {
				Character_orientation(DOWN);
			}
			else if (ch == KEY_LEFT) {
				Character_orientation(LEFT);
			}
			else if (ch == KEY_RIGHT) {
				Character_orientation(RIGHT);
			}
			else if (ch == KEY_QUIT) {
				quit = true;
			}
			if (isend()) {
				End_the_scen(&bg_img);
				quit = true;
			}
		}
		if(a==100){
			End_the_scen1(&bg_img);
			quit = true;
		}
		Sleep(100);//����0.1��
	} while (quit==false);//!quit
	system("pause");
	closegraph();//��Ϸ�����ͷ���Դ
	return 0;
}