// modtest.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "re2.h"
#include "inject.h"

unsigned char *pExe;

typedef struct tagDmtblEm10
{
	u32 reaction[9];
} DMTBL_EM10;

#define REALISTIC	0
#define MORTAL		1
#define DESTINY		0
#define TRANSLATION	0

void Install_quickturn(u8 *pExe);

FARPROC hook_init_stage;

static void _stage_init()
{
	pG->Player.nFloor = 0;
	pG->Player.Pos_y = 0;
	pG->Cut_no = 0;
	pG->Stage_no = 0;
#if 1
	pG->Room_no = 0x0E;
	pG->Player.Pos_x = -23240;
	pG->Player.Pos_z = 20939;
#else
	pG->Room_no = 4;
	pG->Player.Pos_x = -17920;
	pG->Player.Pos_z = -21722;
#endif
	pG->Player.Cdir_y = 0;
	pG->Player.Id = 0;
	pG->Pl_life = 200;
	pG->Player.Life = 200;

	pExe[0x98EE7B - EXE_DIFF] = 0;
	*(DWORD*)&pExe[0x98EE7C - EXE_DIFF] = 200;
}

NAKED void Stage_init()
{
	__asm { call _stage_init }
	__asm { jmp [hook_init_stage] }
}

typedef struct tagItemWork2
{
	u8 Id,
		Num,
		Size;
} ITEM_WORK2;

#if DESTINY
static const ITEM_WORK2 vander_init_item[] =
{
	{ 0 },
	{ 52, 1, 0 },	// blue keycard
	{ 0 },
	{ 0 },
	{ 0 },
	{ 0 },
	{ 0 },
	{ 0 },
	{ 0 },
	{ 0 },
	{ 53, 1, 0 },	// red keycard
	{ 53, 1, 0 }	// knife
};
#endif

#if MORTAL
static const ITEM_WORK2 hunk_init_item[]=
{
	{15,5,1},	// machinegun p1
	{15,5,2},	// machinegun p2
	{2,4,0},	// handgun
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{1,0xff,0},	// knife
	{1,0xff,0}	// knife
};
#endif

void ModMain(unsigned char *pExe)
{
	::pExe = pExe;

	Init_RE2(pExe);

#if MORTAL
	// fix to the revolver
	memset(&pExe[0x4D5DCB - 0x400000], 0x90, 5);	// drop flying clip
	pExe[0x4D56D0 - EXE_DIFF] = 0xff;

	// fix start position to be in irons' gallery
	hook_init_stage = (FARPROC)&pExe[0x5069E0 - EXE_DIFF];
	INJECT(&pExe[0x50693E - EXE_DIFF], Stage_init);

	memcpy(&pExe[0x5401B8 - EXE_DIFF], hunk_init_item, sizeof(hunk_init_item));
	// fix backup lighter for hunk to be a knife
	pExe[0x502248 - EXE_DIFF] = 1;

	*(DWORD*)&pExe[0x4F9F64 - EXE_DIFF] = 0;	// make Status background black
	*(DWORD*)&pExe[0x501C09 - EXE_DIFF] = 0;	// make Status background black
#endif

#if DESTINY
	memcpy(&pExe[0x5401B8 - EXE_DIFF], vander_init_item, sizeof(vander_init_item));

	//memset(&pExe[0x506795 - EXE_DIFF], 0x90, 5);	// skip prologue
#endif

#if REALISTIC
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
#endif

	//MessageBoxA(NULL, "Pacchi appraiyeddo.\nNau zombi-chan very hardo!", "Super Mega Hard mode", MB_OK);
}
