#include "box_main.h" //将头文件中的内容全替换到此处

int main(void) {

	IMAGE bg_img;//定义一个图片变量

	//在这创建客户端(多大的客户端)
	initgraph(CLIENT_X_AXI, CLIENT_Y_AXI);//搭建舞台,软件的起始,软件客户端的屏幕

	//放映(图片变量的地址,图片的路径,图片的大小X,图片的大小Y,图片是否拉伸(差别不大));
	//把需要放映到舞台屏幕的图片,加载到图片变量中(&bg_img),通过bg_img引用图片
	loadimage(&bg_img, _T("blackground.bmp"), CLIENT_X_AXI, CLIENT_Y_AXI, true);//这里只是将图片和bg_img连接而已

	//安置image(图片)(坐标X,坐标Y,图片);//客户端初步搭建
	putimage(0, 0,&bg_img);//从坐标0,0,开始铺设图片,这样图片就能在客户端屏幕显示出来了

	//把道具图片加载进images[7]来
	loadimage(&images[wall], _T("wall_right.bmp"), DJTPXS, DJTPXS, true);//墙
	loadimage(&images[Floor], _T("floor.bmp"), DJTPXS, DJTPXS, true);//地板
	loadimage(&images[target], _T("des.bmp"), DJTPXS, DJTPXS, true);//箱子目的地
	loadimage(&images[people], _T("man.bmp"), DJTPXS, DJTPXS, true);//人物
	loadimage(&images[box], _T("box.bmp"), DJTPXS, DJTPXS, true);//箱子
	loadimage(&images[hit], _T("box.bmp"), DJTPXS, DJTPXS, true);//箱子命中目标

	//在客户端安置images数组的图片
	for (int i = 0,a = 0; i < MAP_LINE; i++) {//行
		for (int j = 0; j < MAP_COLUMN; j++) {//列
			if (Game_map[i][j] == people) {//获取人物所在坐标
				man.line = i;
				man.column = j;
			}
			else if (Game_map[i][j] == target) {//获取终点的坐标
				target1[a].line = i;
				target1[a].column = j;
				a++;
			}
			//图片都是61*61像素,X(长)横向坐标,Y(高)纵向坐标
			//偏移量+i*61,偏移量+j*61;(i++)*61,(j++)*61;
			//这样就把二维数组和显示图片结合了
			putimage(OFFSET_X+j* DJTPXS, OFFSET_Y+i* DJTPXS, &images[(Game_map[i][j])]);
		}
	}

	//游戏环节
	bool quit = false;
	int a = 0;
	do {
		if (_kbhit()) {//判断是否有敲击键盘
	//KEY_UP 'w',KEY_LEFT  'a',KEY_RIGHT 'd',KEY_DOWN  's',KEY_QUIT  'q'
			a++;
			char ch = _getch();//按下的键(字符)赋值给char ch;
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
		Sleep(100);//休眠0.1秒
	} while (quit==false);//!quit
	system("pause");
	closegraph();//游戏结束释放资源
	return 0;
}