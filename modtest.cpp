// modtest.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "re2.h"

typedef struct tagDmtblEm10
{
	u32 reaction[9];
} DMTBL_EM10;

void Install_quickturn(u8 *pExe);

void ModMain(unsigned char *pExe)
{
	Init_RE2(pExe);
	Install_quickturn(pExe);

	static unsigned short zhealth[] =	// 0x526C00
	{ 9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999 },
	zhealth_easy[] =			// 0x526C20
	{ 9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999 };

	memcpy(&pExe[0x526C00 - EXE_DIFF], zhealth, sizeof(zhealth));
	memcpy(&pExe[0x526C20 - EXE_DIFF], zhealth_easy, sizeof(zhealth_easy));

	// add fix to make magnums and rocket launcher not crash
	DMTBL_EM10 *tbl = (DMTBL_EM10*)&pExe[0x526EF8 - EXE_DIFF];
	u32 hgr = tbl[0].reaction[0];
	// magnum
	tbl[4].reaction[0] = hgr;
	tbl[4].reaction[1] = hgr;
	tbl[4].reaction[3] = hgr;
	tbl[4].reaction[4] = hgr;
	tbl[4].reaction[6] = hgr;
	tbl[4].reaction[7] = hgr;
	// custom magnum
	tbl[5].reaction[0] = hgr;
	tbl[5].reaction[1] = hgr;
	tbl[5].reaction[3] = hgr;
	tbl[5].reaction[4] = hgr;
	tbl[5].reaction[6] = hgr;
	tbl[5].reaction[7] = hgr;
	// rocket launcher
	tbl[16].reaction[0] = hgr;
	tbl[16].reaction[1] = hgr;
	tbl[16].reaction[3] = hgr;
	tbl[16].reaction[4] = hgr;
	tbl[16].reaction[6] = hgr;
	tbl[16].reaction[7] = hgr;

	//MessageBoxA(NULL, "Pacchi appraiyeddo.\nNau zombi-chan very hardo!", "Super Mega Hard mode", MB_OK);
}
