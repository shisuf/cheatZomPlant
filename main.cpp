#include"mo990.h"
#include"cheatZV.h"

using namespace std;


int main(void) {
	initgraph(720, 480);


	struct Button* chSun = creatButton(30, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "�޸�����");
	struct Button* chSlotCD = creatButton(120, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "������ȴ");
	struct Button* reSoltCD = creatButton(210, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "������ȴ��ԭ");
	struct Button* chBullectCD = creatButton(300, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "�ӵ�����");
	struct Button* reBullectCD = creatButton(390, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "�ӵ����ӻ�ԭ");
	struct Button* chCollectSun = creatButton(480, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "�Զ��ռ�");
	struct Button* reCollectSun = creatButton(570, 30, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "�Զ��ռ���ԭ");
	struct Button* chCobCannonCD = creatButton(30, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "���״�����ȴ");
	struct Button* reCobCannonCD = creatButton(120, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "���״��ڻ�ԭ");
	struct Button* FkillZom = creatButton(210, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "��ɱ��ʬ");
	struct Button* chRandBullect = creatButton(300, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "����ӵ�");
	struct Button* reRandBullect = creatButton(390, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "����ӵ���ԭ");
	struct Button* chPlantOverlap = creatButton(480, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "ֲ���ص�");
	struct Button* rePlantOverlap = creatButton(570, 80, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199), "ֲ���ص���ԭ");

	struct Menu* pSID = creatMenu(30, 130, 80, 30, RGB(193, 202, 255), RGB(94, 108, 199));
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");

	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");
	addSubmenu(pSID, "����1");


	settextstyle(18, 0, "΢���ź�");
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