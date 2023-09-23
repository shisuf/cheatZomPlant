#pragma once
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<easyx.h>

//创建按钮
extern struct Button* creatButton(int x, int y, int width, int height, COLORREF inColor, COLORREF outColor, const char* name);
//画按钮
extern void drawButton(struct Button* pB);
//判断鼠标是否在按钮内
extern bool inToButton(struct Button* pB, ExMessage mouse);
//鼠标是否被点击
extern bool clickButton(struct Button* pB, ExMessage mouse);

//创建菜单
extern struct Menu* creatMenu(int x, int y, int width, int height, COLORREF inColor, COLORREF outColor);
//添加子菜单
extern bool addSubmenu(struct Menu* pM, const char* name);
//画菜单
extern void drawMenu(struct Menu* pM);

extern void drawSubMenu(struct Menu* pM, ExMessage mouse);
