#include"mo990.h"
#include"cheatZV.h"

using namespace std;


int main(void) {
	initgraph(720, 480);


	struct Button* chSun = creatButton(30, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "修改阳光");
	struct Button* chSlotCD = creatButton(120, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "卡槽冷却");
	struct Button* reSoltCD = creatButton(210, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "卡槽冷却还原");
	struct Button* chBullectCD = creatButton(300, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "子弹叠加");
	struct Button* reBullectCD = creatButton(390, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "子弹叠加还原");
	struct Button* chCollectSun = creatButton(480, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "自动收集");
	struct Button* reCollectSun = creatButton(570, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "自动收集还原");
	struct Button* chCobCannonCD = creatButton(30, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "玉米大炮冷却");
	struct Button* reCobCannonCD = creatButton(120, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "玉米大炮还原");
	struct Button* FkillZom = creatButton(210, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "秒杀僵尸");
	struct Button* chRandBullect = creatButton(300, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "随机子弹");
	struct Button* reRandBullect = creatButton(390, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "随机子弹还原");
	struct Button* chPlantOverlap = creatButton(480, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "植物重叠");
	struct Button* rePlantOverlap = creatButton(570, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "植物重叠还原");

	struct Menu* pSID = creatMenu(30, 130, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199));
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");

	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");
	addSubmenu(pSID, "卡槽1");


	settextstyle(18, 0, "微软雅黑");
	IMAGE background;
	loadimage(&background, "./img/background.jpg");
	putimage(0, 0, &background);
	cheatZV cheat;
	//while (!cheat.isOpen) {
	//	cheatZV cheat1;
	//	cheat = cheat1;
	//}
	ExMessage mouse;
	peekmessage(&mouse, EX_MOUSE);
	BeginBatchDraw();

	while (1) {
		drawButton(chSun);
		drawButton(chSlotCD);
		drawButton(reSoltCD);
		drawButton(chBullectCD);
		drawButton(reBullectCD);
		drawButton(chCollectSun);
		drawButton(reCollectSun);
		drawButton(chCobCannonCD);
		drawButton(reCobCannonCD);
		drawButton(FkillZom);
		drawButton(chRandBullect);
		drawButton(reRandBullect);
		drawButton(chPlantOverlap);
		drawButton(rePlantOverlap);



		drawMenu(pSID);
		drawSubMenu(pSID,mouse);







		if (clickButton(chSun, mouse)) {
			cheat.chSun();
		}
		else if (clickButton(chSlotCD, mouse)) {
			cheat.chSlotCD();
		}
		else if (clickButton(chBullectCD, mouse)) {
			cheat.chBulletCD();
		}
		else if (clickButton(reSoltCD, mouse)) {
			cheat.reSoltCD();
		}
		else if (clickButton(reBullectCD, mouse)) {
			cheat.reBullectCD();
		}
		else if (clickButton(chCollectSun, mouse)) {
			cheat.chCollectSun();
		}
		else if (clickButton(reCollectSun, mouse)) {
			cheat.reCollectSun();
		}
		else if (clickButton(chCobCannonCD, mouse)) {
			cheat.chCobCannonCD();
		}
		else if (clickButton(reCobCannonCD, mouse)) {
			cheat.reCobCannonCD();
		}
		else if (clickButton(FkillZom, mouse)) {
			cheat.FkillZom();
		}
		else if (clickButton(chRandBullect, mouse) || cheat.randBullectLoop) {

			cheat.chRandBullect(rand()%13);
		}
		else if (clickButton(reRandBullect, mouse)) {

			cheat.reRandBullect();
		}
		else if (clickButton(chPlantOverlap, mouse)) {

			cheat.chPlantOverlap();
		}
		else if (clickButton(rePlantOverlap, mouse)) {

			cheat.rePlantOverlap();
		}
		FlushBatchDraw();
		
	}
	EndBatchDraw();
	closegraph();

	return 0;
}