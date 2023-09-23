#include"mo990.h"


//按钮
struct Button {
	int x;
	int y;
	int width;
	int height;
	COLORREF curColor;
	COLORREF inColor;
	COLORREF outColor;
	char* name;
};

//创建按钮
struct Button* creatButton(int x,int y,int width,int height,COLORREF inColor,COLORREF outColor, const char* name){
	struct Button* pB = (Button*)malloc(sizeof(struct Button));//申请内存
	if (pB) {
		pB->x = x;
		pB->y = y;
		pB->width = width;
		pB->height = height;
		pB->inColor = inColor;
		pB->outColor = outColor;
		pB->curColor = outColor;


		int nameLength = strlen(name) + 1;
		pB->name = (char*)malloc(sizeof(name) * nameLength);

		assert(pB->name);
		strcpy_s(pB->name, nameLength, name);
		return pB;
	}
	else {
		return NULL;
	}

}

//画按钮
void drawButton(struct Button* pB) {
	//画矩形
	setfillcolor(pB->curColor);
	fillrectangle(pB->x, pB->y, pB->width + pB->x, pB->height + pB->y);
	//名字
	settextcolor(WHITE);
	setlinecolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景

	int nameWidth = textwidth(pB->name);
	int nameHeight = textheight(pB->name);
	int nameX = pB->x + (pB->width - nameWidth) / 2;
	int nameY = pB->y + (pB->height - nameHeight) / 2;
	outtextxy(nameX, nameY, pB->name);
}

//判断鼠标是否在按钮内
bool inToButton(struct Button* pB,ExMessage mouse) {
	if (mouse.x > pB->x && mouse.x<pB->x + pB->width && mouse.y>pB->y && mouse.y < pB->y + pB->height) {
		pB->curColor = pB->inColor;
		return true;
	}
	else {
		pB->curColor = pB->outColor;
		return false;
	}
}

//鼠标是否被点击
bool clickButton(struct Button* pB,ExMessage mouse) {
	if (inToButton(pB, mouse) && mouse.message == WM_LBUTTONDOWN) {
		pB->curColor = BLACK;
		Sleep(100);
		return true;
	}
	return false;
}


//菜单
struct Menu {
	int x;
	int y;
	int width;
	int height;
	COLORREF curColor;
	COLORREF inColor;
	COLORREF outColor;
	char* name[1000];
	int xx;
	int yy;
	int ww;
	int hh;
	int subNum;
	struct Button* subMenu[1000];
	int subMenuID;
	int curSub;
	//
	int xxx[5];
	int yyy[5];
	int www[5];
	int hhh[5];
};

struct Menu* creatMenu(int x,int y,int width,int height,COLORREF inColor,COLORREF outColor) {
	struct Menu* pM = (Menu*)malloc(sizeof(struct Menu));
	if (pM) {
		pM->x = x;
		pM->y = y;
		pM->width = width;
		pM->height = height;
		pM->inColor = inColor;
		pM->outColor = outColor;
		pM->curColor = outColor;
		//创建菜单按钮
		for (int i = 0; i < 1000; i++) pM->name[i] = 0;

		pM->name[0] = (char*)malloc(sizeof(pM->name[0]) * (strlen("(无)") + 1));
		assert(pM->name[0]);
		strcpy_s(pM->name[0], (strlen("(无)") + 1), "(无)");
		pM->subNum = 0;

		creatButton(pM->x,
			(pM->height + pM->y + 2) ,
			pM->width - (pM->ww - pM->xx),
			pM->height, pM->inColor, pM->outColor, pM->name[0]);
		pM->subMenuID = 0;
		pM->curSub = 1;

		int xx = pM->width / 6 * 5 + pM->x;
		int yy = pM->y + pM->height/5;
		int ww = (pM->width + pM->x - xx) / 7 * 6 + xx;
		int hh = pM->y + pM->height * 4 / 5;

		pM->xx = xx;
		pM->yy = yy;
		pM->ww = ww;
		pM->hh = hh;


		for (int i = 0; i < 5; i++) {
			pM->xxx[i] = pM->x;
			pM->yyy[i] = (pM->height + pM->y + 2) + pM->height * i;
			pM->www[i] = pM->width - (pM->ww - pM->xx);
			pM->hhh[i] = pM->height;

		}
		return pM;
	}
	return NULL;
}

//添加子菜单
bool addSubmenu(struct Menu* pM,const char* name) {
	int nameLength = strlen(name) + 1;
	//添加
	int i = 1;
	while (1) {
		if (pM->name[i] == 0) {
			pM->name[i] = (char*)malloc(sizeof(pM->name[i]) * nameLength);
			assert(pM->name[i]);
			strcpy_s(pM->name[i], nameLength, name);
			pM->subNum++;

			pM->subMenu[i] = creatButton(pM->x,
				(pM->height + pM->y + 2) + pM->height * (i - 1),
				pM->width - (pM->ww - pM->xx),
				pM->height, 
				pM->inColor, pM->outColor, pM->name[i]);
			
			return true;
			break;
		}
		if (i >= 999) {
			return false;
			break;
		}
		i++;
	}

}

//画菜单
void drawMenu(struct Menu* pM) {

	setfillcolor(pM->outColor);
	fillrectangle(pM->x, pM->y, pM->x + pM->width, pM->y + pM->height);
	setlinecolor(BLACK);
	setfillcolor(RGB(192, 192, 192));



	fillrectangle(pM->xx, pM->yy, pM->ww, pM->hh);
	setfillcolor(WHITE);
	//三角形
	POINT pts[] = { {pM->xx+(pM->ww- pM->xx)/4,pM->yy + (pM->hh- pM->yy)/4},
		{pM->ww-(pM->ww- pM->xx)/4,pM->yy + (pM->hh - pM->yy) / 4},
		{pM->ww - (pM->ww - pM->xx) / 2,pM->hh-(pM->hh- pM->yy)/4}};
	polygon(pts, 3);

	settextcolor(WHITE);
	setlinecolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景

		int nameWidth = textwidth(pM->name[0]);
		int nameHeight = textheight(pM->name[0]);
		int nameX = pM->x - (pM->x + pM->width - pM->xx) / 2 + (pM->width - nameWidth) / 2;
		int nameY = pM->y + (pM->height - nameHeight) / 2;
		outtextxy(nameX, nameY, pM->name[0]);
		

	//下拉菜单点击

}

//画出下拉菜单
static bool SubMenuLoop = false;
void drawSubMenu(struct Menu* pM,ExMessage mouse) {

	if (mouse.x > pM->xx && mouse.x<(pM->ww + pM->xx) && mouse.y>pM->yy && 
		mouse.y < (pM->hh + pM->yy) && mouse.message == WM_LBUTTONDOWN) {
		printf("1");
		setfillcolor(RGB(119, 136, 153));
		fillrectangle(pM->xx, pM->yy, pM->ww, pM->hh);
		SubMenuLoop = SubMenuLoop ? 0 : 1;
		Sleep(100);
	}
	//创建按钮和画出按钮以及绑定事件
	if (SubMenuLoop) {
		int num = pM->subNum;
			if (num >= 5) {
				//下拉
				setfillcolor(RGB(220, 220, 220));
				int yyy = pM->height * 2 + 2;
				int hhh = pM->hh * 4 - (pM->height) / 2;
				fillrectangle(pM->width, yyy, pM->ww, hhh);
				//滑块
				setfillcolor(BLACK);
				fillrectangle(pM->width + 2, yyy + 2, pM->ww-2,yyy+2+hhh/5);


				if (mouse.x > pM->xxx[0] && mouse.x<(pM->www[4]+pM->xxx[4]) &&
					mouse.y>pM->yyy[0] && mouse.y <
					(pM->yyy[4]+pM->hhh[4])) {

					if (mouse.message == WM_MOUSEWHEEL) {
							if (mouse.wheel>0 && pM->curSub<pM->subNum) {
								pM->curSub += 1;
							}
							else if (mouse.wheel <0 && pM->curSub > 1) {
								pM->curSub -= 1;
							}
							Sleep(100);
					}

				}

				for (int i = pM->curSub, j = 0; j < 5; i++, j++) {
					
					if (i > pM->subNum || i<1) {
						break;
					}

					pM->subMenu[i]->x = pM->xxx[j];
					pM->subMenu[i]->y = pM->yyy[j];
					pM->subMenu[i]->width = pM->www[j];
					pM->subMenu[i]->height = pM->hhh[j];

					drawButton(pM->subMenu[i]);
					if (clickButton(pM->subMenu[i], mouse)) {
						pM->name[0] = pM->subMenu[i]->name;
						pM->subMenuID = i;
						SubMenuLoop = false;
					}
				}
			}

	}


}