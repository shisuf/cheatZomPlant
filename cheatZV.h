#pragma once
#include<stdio.h>
#include<Windows.h>
#include<tlhelp32.h>

class cheatZV
{
public:
	 cheatZV();

	 //jmp������ת��ַ
	 void conJmpAddr(int curAddr, int tarAddr, BYTE bytes[]);
	 //����intתbyte��������δ֪����
	 void intToByte(int num, BYTE bytes[]);

	 //�Ƿ�򿪳���
	 bool isOpen;

	//�����޸�99999
	 bool chSun();
	//�Զ��ռ���
	 bool collectLoop;
	 //�Զ��ռ�
	 bool chCollectSun();
	 //�Զ��ռ���ԭ
	 bool reCollectSun();
	//����CD��
	 bool soltLoop;
	 //����CD
	 bool chSlotCD();
	 //����CD��ԭ
	 bool reSoltCD();
	//�ӵ�������
	 bool bulletLoop;
	 //�ӵ�����
	 bool chBulletCD();
	 //�ӵ����ӻ�ԭ
	 bool reBullectCD();
	//���׼�ũ��CD��
	 bool cobCannonLoop;
	 //���׼�ũ��CD
	 bool chCobCannonCD();
	 //���׼�ũ��CD��ԭ
	 bool reCobCannonCD();
	//�޸�ֲ��
	 bool modifySoltP(int solt, int PID);
	//ֲ���ص���
	 bool plantOverlapLoop;
	 //ֲ���ص�
	 bool chPlantOverlap();
	 //ֲ���ص���ԭ
	 bool rePlantOverlap();
	//�滻�ӵ�ID��
	 bool randBullectLoop;
	 //�滻�ӵ�ID
	 bool chRandBullect(int BID);
	 //�滻�ӵ�ID��ԭ
	 bool reRandBullect();
	//��ɱ��ʬ
	 bool FkillZom();

private:
	//����ID
	DWORD procID;
	//��ַ
	int BaseAddr;
	//����
	HANDLE hProcess;
	//��ȡ�����ַ
	int getMoudleBaseAddress(DWORD procID, const wchar_t* modName);
	//�ӵ������޸Ļ�ַ
	int bullectAddr;
	//���׼�ũ���޸Ļ�ַ
	int cobCannonAddr;
	//�Զ��ռ���ַ
	int collectAddr;
	//������ȴ��ַ
	int soltAddr;
	//ֲ���ص�
	int plantOverlapAddr;
	//��ʬʵʱ���ʵ�ַ
	int zomAcccessAddr;
	//�ӵ�ID��ַ
	int bullectIDAddr;
	//��ʼ�����ڴ�
	LPVOID virAddr;
};
