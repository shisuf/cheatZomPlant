#pragma once
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<easyx.h>

//������ť
extern struct Button* creatButton(int x, int y, int width, int height, COLORREF inColor, COLORREF outColor, const char* name);
//����ť
extern void drawButton(struct Button* pB);
//�ж�����Ƿ��ڰ�ť��
extern bool inToButton(struct Button* pB, ExMessage mouse);
//����Ƿ񱻵��
extern bool clickButton(struct Button* pB, ExMessage mouse);

//�����˵�
extern struct Menu* creatMenu(int x, int y, int width, int height, COLORREF inColor, COLORREF outColor);
//����Ӳ˵�
extern bool addSubmenu(struct Menu* pM, const char* name);
//���˵�
extern void drawMenu(struct Menu* pM);

extern void drawSubMenu(struct Menu* pM, ExMessage mouse);
