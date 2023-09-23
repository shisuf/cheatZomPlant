#pragma once
#include<stdio.h>
#include<Windows.h>
#include<tlhelp32.h>

class cheatZV
{
public:
	 cheatZV();

	 //jmp计算跳转地址
	 void conJmpAddr(int curAddr, int tarAddr, BYTE bytes[]);
	 //定制int转byte，可能有未知问题
	 void intToByte(int num, BYTE bytes[]);

	 //是否打开程序
	 bool isOpen;

	//阳光修改99999
	 bool chSun();
	//自动收集锁
	 bool collectLoop;
	 //自动收集
	 bool chCollectSun();
	 //自动收集还原
	 bool reCollectSun();
	//卡槽CD锁
	 bool soltLoop;
	 //卡槽CD
	 bool chSlotCD();
	 //卡槽CD还原
	 bool reSoltCD();
	//子弹叠加锁
	 bool bulletLoop;
	 //子弹叠加
	 bool chBulletCD();
	 //子弹叠加还原
	 bool reBullectCD();
	//玉米加农炮CD锁
	 bool cobCannonLoop;
	 //玉米加农炮CD
	 bool chCobCannonCD();
	 //玉米加农炮CD还原
	 bool reCobCannonCD();
	//修改植物
	 bool modifySoltP(int solt, int PID);
	//植物重叠锁
	 bool plantOverlapLoop;
	 //植物重叠
	 bool chPlantOverlap();
	 //植物重叠还原
	 bool rePlantOverlap();
	//替换子弹ID锁
	 bool randBullectLoop;
	 //替换子弹ID
	 bool chRandBullect(int BID);
	 //替换子弹ID还原
	 bool reRandBullect();
	//秒杀僵尸
	 bool FkillZom();

private:
	//进程ID
	DWORD procID;
	//基址
	int BaseAddr;
	//进程
	HANDLE hProcess;
	//获取程序基址
	int getMoudleBaseAddress(DWORD procID, const wchar_t* modName);
	//子弹叠加修改基址
	int bullectAddr;
	//玉米加农炮修改基址
	int cobCannonAddr;
	//自动收集基址
	int collectAddr;
	//卡槽冷却基址
	int soltAddr;
	//植物重叠
	int plantOverlapAddr;
	//僵尸实时访问地址
	int zomAcccessAddr;
	//子弹ID地址
	int bullectIDAddr;
	//初始申请内存
	LPVOID virAddr;
};
