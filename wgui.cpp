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
//	COLORREF inColor,COLORREF outColor,const char* text) {//������ť,�����ڴ�ȡָ��
//
//	struct Button* pB = (Button*)malloc(sizeof(struct Button));//��ȡ�ڴ�ָ��
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
////������ť
//void drawButton(struct Button* pB) {
//	//����
//	setfillcolor(pB->curColor);
//	fillrectangle(pB->x, pB->y, pB->width + pB->x, pB->hight + pB->y);
//	//����
//	settextcolor(WHITE);
//	setlinecolor(BLACK);
//	setbkmode(TRANSPARENT);//ȥ�����ֱ���
//	settextstyle(15, 0, "����");
//	int textHight = textheight(pB->text);
//	int textWidth = textwidth(pB->text);
//	int textX = pB->x + (pB->width - textWidth) / 2;
//	int textY = pB->y + (pB->hight - textHight) / 2;
//	outtextxy(textX, textY, pB->text);
//
//}
//
////����Ƿ��ڰ�ť��
//bool inButton(struct Button* pB,ExMessage mouse) {
//	if (mouse.x > pB->x && mouse.x<pB->x + pB->width && mouse.y>pB->y && mouse.y < pB->y + pB->hight) {
//		pB->curColor = pB->inColor;
//		return true;
//	}
//	pB->curColor = pB->outColor;
//	return false;
//}
//
////����Ƿ���
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
//	//˫����
//	BeginBatchDraw();
//	while (1) {
//
//		drawButton(play);
//		peekmessage(&mouse, EX_MOUSE);
//
//		if (clickButton(play,mouse)) {
//			//std::cout << "1";
//		}
//		//ˢ��
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	closegraph();
//	return 0;
//}