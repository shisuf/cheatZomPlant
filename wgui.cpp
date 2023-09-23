//#include"pch.h"
//
//using namespace std;
//
//struct Button {
//	int x;
//	int y;
//	int width;
//	int hight;
//	COLORREF curColor;
//	COLORREF inColor;
//	COLORREF outColor;
//	char* text;
//};
//
//struct Button* creatButton(int x,int y,int width,int hight,
//	COLORREF inColor,COLORREF outColor,const char* text) {//创建按钮,返回内存取指针
//
//	struct Button* pB = (Button*)malloc(sizeof(struct Button));//获取内存指针
//	pB->x = x;
//	pB->y = y;
//	pB->width = width;
//	pB->hight = hight;
//	pB->inColor = inColor;
//	pB->outColor = outColor;
//	pB->curColor = outColor;
//	int textLength = strlen(text) + 1;
//	pB->text = (char*)malloc(sizeof(char) * textLength);
//	assert(pB->text);
//	strcpy_s(pB->text, textLength, text);
//	return pB;
//	
//}
//
////画出按钮
//void drawButton(struct Button* pB) {
//	//矩形
//	setfillcolor(pB->curColor);
//	fillrectangle(pB->x, pB->y, pB->width + pB->x, pB->hight + pB->y);
//	//文字
//	settextcolor(WHITE);
//	setlinecolor(BLACK);
//	setbkmode(TRANSPARENT);//去掉文字背景
//	settextstyle(15, 0, "黑体");
//	int textHight = textheight(pB->text);
//	int textWidth = textwidth(pB->text);
//	int textX = pB->x + (pB->width - textWidth) / 2;
//	int textY = pB->y + (pB->hight - textHight) / 2;
//	outtextxy(textX, textY, pB->text);
//
//}
//
////鼠标是否在按钮内
//bool inButton(struct Button* pB,ExMessage mouse) {
//	if (mouse.x > pB->x && mouse.x<pB->x + pB->width && mouse.y>pB->y && mouse.y < pB->y + pB->hight) {
//		pB->curColor = pB->inColor;
//		return true;
//	}
//	pB->curColor = pB->outColor;
//	return false;
//}
//
////鼠标是否点击
//bool clickButton(struct Button* pB, ExMessage mouse) {
//
//	if (inButton(pB, mouse) && mouse.message == WM_LBUTTONDOWN) {
//		return true;
//	}
//	return false;
//}
//int main() {
//	initgraph(640, 480);
//	IMAGE background;
//	loadimage(&background,"./img/background.jpg");
//	putimage(0, 0, &background);
//
//	struct Button* play = creatButton(30, 30, 80, 50, RGB(193,202,255), RGB(94,108,199),"play");
//
//	ExMessage mouse;
//	//双缓冲
//	BeginBatchDraw();
//	while (1) {
//
//		drawButton(play);
//		peekmessage(&mouse, EX_MOUSE);
//
//		if (clickButton(play,mouse)) {
//			//std::cout << "1";
//		}
//		//刷新
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	closegraph();
//	return 0;
//}