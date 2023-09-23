//#include"mo990.h"
//
//int main() {
//	initgraph(720, 640);
//	IMAGE image;
//	loadimage(&image, "./img/background");
//	putimage(0, 0, &image);
//	struct Menu* pM = creatMenu(30, 30, 200, 30, RGB(193, 202, 255), RGB(94, 108, 199));
//	addSubmenu(pM, "001");
//	addSubmenu(pM, "002");
//	addSubmenu(pM, "003");
//	addSubmenu(pM, "004");
//	addSubmenu(pM, "005");
//	addSubmenu(pM, "006");
//	addSubmenu(pM, "007");
//	addSubmenu(pM, "008");
//	addSubmenu(pM, "009");
//	addSubmenu(pM, "010");
//	addSubmenu(pM, "011");
//	addSubmenu(pM, "012");
//	addSubmenu(pM, "013");
//	addSubmenu(pM, "014");
//	addSubmenu(pM, "015");
//
//
//
//
//
//
//	BeginBatchDraw();
//	while (1) {
//		cleardevice();
//		ExMessage mouse;
//		peekmessage(&mouse, EX_MOUSE);
//		drawMenu(pM);
//		drawSubMenu(pM, mouse);
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	return 0;
//}