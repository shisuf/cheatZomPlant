#include "cheatZV.h"


//������
cheatZV::cheatZV() {
	
	//��ʼ��
	BaseAddr = 0x400000;
	procID = 0;
	isOpen = false;
	hProcess = NULL;
	randBullectLoop = false;
	plantOverlapLoop = false;
	cobCannonLoop = false;
	bulletLoop = false;
	soltLoop = false;
	collectLoop = false;
	//����ʼ��
	cobCannonLoop = false;
	collectLoop = false;
	soltLoop = false;
	bulletLoop = false;
	plantOverlapLoop = false;
	randBullectLoop = false;

	
	HWND hd = FindWindowA(NULL, "Plants vs. Zombies");
	GetWindowThreadProcessId(hd, &procID);//��ȡ����ID
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);


	//�ж��Ƿ��
	if (!hProcess == 0) {
		isOpen = true;
		//�����ڴ�
		virAddr = VirtualAllocEx(hProcess, NULL, 64, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		//��ȡ��ַ
		BaseAddr = getMoudleBaseAddress(procID, L"PlantsVsZombies.exe");
		
		//��ʼ����ַ
		zomAcccessAddr = BaseAddr + 0x00149741;
		plantOverlapAddr = BaseAddr + 0x001BD2D;
		soltAddr = BaseAddr + 0x009CDFC;
		collectAddr = BaseAddr + 0x3CC72;
		cobCannonAddr = BaseAddr + 0x6F40A;
		bullectAddr = BaseAddr + 0x72EE4;
		bullectIDAddr = BaseAddr + 0x7BB69;
	}
	else {
		isOpen = false;
	}
	
}

//��ȡ��ַ
int cheatZV::getMoudleBaseAddress(DWORD procID, const wchar_t* modName) {
	int modBaseAddress = 0x400000;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do
			{
				if (!_wcsicmp((wchar_t*)modEntry.szModule, modName)) {
					modBaseAddress = (int)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
			

		}
	}
	CloseHandle(hSnap);
	return modBaseAddress;
}
//����jmp��ת��ַ 
void cheatZV::conJmpAddr(int curAddr,int tarAddr,BYTE bytes[]) {
	int index = tarAddr - 5 - curAddr;
	cheatZV::intToByte(index, bytes);
}

//����intתbyte��������δ֪����
void cheatZV::intToByte(int num, BYTE bytes[]) {
        bool OrNegative = false;
        if (num < 0) {
            OrNegative = true;
            num = 0 - num;
        }

        for (int k = 1; k <= 4; k++) {

            if (OrNegative) {
                bytes[k] = 0xFF - (num - num / 0x100 * 0x100);
            }
            else {
                bytes[k] = num - num / 0x100 * 0x100;
            }
			num /= 0x100;
        }if(OrNegative)     bytes[1]++;
        
        return;
}

//�����޸�99999
bool cheatZV::chSun() {
	if (isOpen) {
		int indexAddr = 0;
		int SunAddr = BaseAddr + 0x355E0C;//�����ַ
		ReadProcessMemory(hProcess, (LPCVOID)SunAddr, &indexAddr, sizeof(indexAddr), 0);
		SunAddr = indexAddr + 0x868;//һ��ƫ��
		ReadProcessMemory(hProcess, (LPCVOID)SunAddr, &indexAddr, sizeof(indexAddr), 0);
		SunAddr = indexAddr + 0x5578;//����ƫ��
		int Sun = 99999;
		WriteProcessMemory(hProcess, (LPVOID)(SunAddr), &Sun, 4, 0);
		return true;
	}
	return false;
}


//�ӵ�����
bool cheatZV::chBulletCD() {
	if (isOpen) {
		BYTE Code[6] = { 144,144,144,144,144,144 };//nop���
		WriteProcessMemory(hProcess, (LPVOID)bullectAddr, &Code, sizeof(Code), 0);
		bulletLoop = true;
		return true;
	}
	return false;
}

bool cheatZV::reBullectCD() {
	if (isOpen) {
		BYTE Code[6] = { 0x0F, 0x85, 0x98, 0xFE, 0xFF, 0xFF };//jne��ԭ�ֽ�
		WriteProcessMemory(hProcess, (LPVOID)bullectAddr, &Code, sizeof(Code), 0);
		bulletLoop = false;
		return true;
	}
	return false;
}


//���׼�ũ����ȴ{
bool cheatZV::chCobCannonCD() {
	if (isOpen) {
		BYTE Code[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };//nop���
		WriteProcessMemory(hProcess, (LPVOID)cobCannonAddr, &Code, sizeof(Code), 0);
		cobCannonLoop = true;
		return true;
	}
	return false;
}

bool cheatZV::reCobCannonCD() {
	if (isOpen) {
		BYTE Code[6] = { 0x0F, 0x85, 0x92, 0x01, 0x00, 0x00 };//��ԭ�ֽ�
		WriteProcessMemory(hProcess, (LPVOID)cobCannonAddr, &Code, sizeof(Code), 0);
		cobCannonLoop = false;
		return true;
	}
	return false;
}


//�����Զ��ռ�
bool cheatZV::chCollectSun() {
	if (isOpen) {
		BYTE Code[2] = { 0x74,0x09 };
		WriteProcessMemory(hProcess, (LPVOID)collectAddr, &Code, sizeof(Code), 0);
		collectLoop = true;
		return true;
	}
	return false;
}

bool cheatZV::reCollectSun() {
	if (isOpen) {
		BYTE Code[2] = { 0x75, 0x09 };
		WriteProcessMemory(hProcess, (LPVOID)collectAddr, &Code, sizeof(Code), 0);
		collectLoop = false;
		return true;
	}
	return false;
}


//������ȴ
bool cheatZV::chSlotCD() {
	if (isOpen) {
		BYTE Code[3] = { 0x90,0x90,0x90 };//nop���
		WriteProcessMemory(hProcess, (LPVOID)soltAddr, &Code, sizeof(Code), 0);
		soltLoop = true;
		return true;
	}
	return false;
}

bool cheatZV::reSoltCD() {
	if (isOpen) {
		BYTE Code[3] = { 0x8B,0x46,0x24 };
		WriteProcessMemory(hProcess, (LPVOID)soltAddr, &Code, sizeof(Code), 0);
		soltLoop = false;
		return true;
	}
	return false;
}


//ֲ���ص�
bool cheatZV::chPlantOverlap() {
	if (isOpen) {
		BYTE Code[6] = { 0xE9, 0x47,0x09,0x00,0x00,0x90 };
		WriteProcessMemory(hProcess, (LPVOID)plantOverlapAddr, &Code, sizeof(Code), 0);
		plantOverlapLoop = true;
		return true;
	}
	return false;
}

bool cheatZV::rePlantOverlap() {
	if (isOpen) {
		BYTE Code[6] = { 0x0F,0x84 ,0x46,0x09,0x00,0x00 };
		WriteProcessMemory(hProcess, (LPVOID)plantOverlapAddr, &Code, sizeof(Code), 0);
		plantOverlapLoop = false;
		return true;
	}
	return false;
}


//����ӵ�,PID�ӵ�ID
bool cheatZV::chRandBullect(int BID) {
	if (isOpen) {
		if (BID == 0) int BID = 11;
		//�޸ĺ���ֽ�
		BYTE Code[] = { 0xC7, 0x45, 0x5C ,0x0B, 0x00 , 0x00 , 0x00 , 0x8B , 0xC6 };//0x0BΪ�޸��ӵ�ID[3]
		Code[3] = BID ;
		if (virAddr != 0) {
			int virBullectIDAddr = (int)virAddr;
			WriteProcessMemory(hProcess, (LPVOID)virBullectIDAddr, &Code, sizeof(Code), 0);//
			//����jmp
			BYTE jmpAddr[5] = { 0 };
			jmpAddr[0] = 0xE9;
			conJmpAddr(virBullectIDAddr + 0x9, bullectIDAddr + 0x5, jmpAddr);
			WriteProcessMemory(hProcess, (LPVOID)(virBullectIDAddr + 0x9), &jmpAddr, sizeof(jmpAddr), 0);
			//jmp�������ַ
			conJmpAddr(bullectIDAddr, virBullectIDAddr, jmpAddr);
			WriteProcessMemory(hProcess, (LPVOID)bullectIDAddr, &jmpAddr, sizeof(jmpAddr), 0);
			randBullectLoop = true;
			return true;
		}
	}

	return false;
}

bool cheatZV::reRandBullect() {
	if (isOpen) {
		//��ԭ�ֽ�
		BYTE Code[] = { 0x89, 0x45 ,0x5C ,0x8B, 0xC6 };
		WriteProcessMemory(hProcess, (LPVOID)bullectIDAddr, &Code, sizeof(Code), 0);
		randBullectLoop = false;
		return true;
	}
	return false;
}


//ֲ���޸�
bool cheatZV::modifySoltP(int solt,int PID) {
	if (isOpen) {
		int modifySoltPAddr = 0x0019F9EC;
		int indexAddr = 0;
		ReadProcessMemory(hProcess, (LPVOID)modifySoltPAddr, &indexAddr, sizeof(indexAddr), 0);
		modifySoltPAddr = indexAddr + 0x4;	//һ��ƫ��
		ReadProcessMemory(hProcess, (LPVOID)modifySoltPAddr, &indexAddr, sizeof(indexAddr), 0);
		modifySoltPAddr = indexAddr + 0x0;//����ƫ��
		ReadProcessMemory(hProcess, (LPVOID)modifySoltPAddr, &indexAddr, sizeof(indexAddr), 0);
		modifySoltPAddr = indexAddr + 0x158;//����ƫ��
		ReadProcessMemory(hProcess, (LPVOID)modifySoltPAddr, &indexAddr, sizeof(indexAddr), 0);
		modifySoltPAddr = indexAddr + 0x5C;//����1��ַ
		
		//10����������
		int soltP[10] = { 0 };
		soltP[0] = modifySoltPAddr;
		for (int i = 1; i < 10; i++) soltP[i] = soltP[i - 1] + 50;//�����鸳ֵ
		if (solt <= 10 && solt > 0 && PID > 0 && PID <= 48) 
			WriteProcessMemory(hProcess, (LPVOID)soltP[solt - 1], &PID - 1,sizeof(PID), 0);
		return true;
	}
	return false;
}


//��ɱ��ʬ
bool cheatZV::FkillZom() {
	if (isOpen) {
			

		if (virAddr != 0) {
			int kAddr = (int)virAddr + 0xE;
			int tarFAddr = 0x549748;//��ת���޸ĵ�ַ����ַ
			BYTE jmpAddr[6] = { 0 };
			jmpAddr[0] = 0xE9;
			jmpAddr[5] = 0x90;
			
			BYTE tarCode[] = {0xC7, 0x41, 0x28, 0x03,0x00,0x00,0x00,0xD9, 0x41, 0x2C,0x57,0xDA, 0x61, 0x08};
			//ԭ��
			BYTE reCode[] = { 0xD9, 0x41, 0x2C, 0x57,0xDA, 0x61, 0x08 };
			//����޸��ڴ�֮��Ĵ���
			WriteProcessMemory(hProcess, (LPVOID)kAddr, &tarCode, sizeof(tarCode), 0);
			//��ת�ص�ַ
			conJmpAddr(kAddr + 0xE, tarFAddr, jmpAddr);
			WriteProcessMemory(hProcess, (LPVOID)(kAddr + 0xE), &jmpAddr, sizeof(jmpAddr), 0);
			//��ת�������ַ
			BYTE jmpOrAddr[7] = { 0 };
			jmpOrAddr[0] = 0xE9;
			jmpOrAddr[5] = 0x66;
			jmpOrAddr[6] = 0x90;
			conJmpAddr(zomAcccessAddr, kAddr, jmpOrAddr);
			WriteProcessMemory(hProcess, (LPVOID)zomAcccessAddr, &jmpOrAddr, sizeof(jmpOrAddr), 0);

			Sleep(500);
			WriteProcessMemory(hProcess, (LPVOID)zomAcccessAddr, &reCode, sizeof(reCode), 0);//��ԭ�ֽ�

			return true;
		}
	}
	return false;
}