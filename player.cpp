#include "stdafx.h"
#include "re2.h"

extern GLOBAL *pG;

static void __cdecl pl_br_03(PLAYER_WORK *pPl, u32 Key, u32 Ket_trg);
static void __cdecl pl_br_quickturn(PLAYER_WORK *pEm, u32 Key, u32 Key_trg);
static void __cdecl pl_mv_quickturn(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq);

void(*br_tbl[13])(PLAYER_WORK *pEm, u32 Key, u32 Key_trg);
void(*mv_tbl[13])(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq);

void Install_quickturn(u8 *pExe)
{
	// fill expanded tables with old code
	memcpy(br_tbl, &pExe[0x53A7FC - 0x400000], 12 * 4);
	memcpy(mv_tbl, &pExe[0x53A82C - 0x400000], 12 * 4);
	// set hooks for quickturn
	br_tbl[03] = pl_br_03;
	br_tbl[12] = pl_br_quickturn;
	mv_tbl[12] = pl_mv_quickturn;
	// replace old table pointers
	*(u32*)&pExe[0x4D9D3C - 0x400000] = (u32)br_tbl;
	*(u32*)&pExe[0x4D9D57 - 0x400000] = (u32)mv_tbl;
}

void __cdecl pl_br_03(PLAYER_WORK *pPl, u32 Key, u32 Key_trg)
{
	static u8 tbl[] = { 0x28,0x10,0x10 };

	if (!pPl->Routine_2 || !pPl->Move_cnt)
	{
		int t = pPl->D_life_u;
		pPl->D_life_u = 0;
		if (pPl->Life <= 100)
			pPl->D_life_u = 1;
		if (pG->Unk_flg1)
			pPl->D_life_u = 1;
		if (pPl->Life <= 20)
			pPl->D_life_u = 2;
		if (t != pPl->D_life_u)
			pPl->Routine_2 = 0;
	}
	// back is pressed
	if (Key & 4)
	{
		// left
		if (Key & 2) pPl->Cdir_y += tbl[pPl->D_life_u];
		// right
		if (Key & 8) pPl->Cdir_y -= tbl[pPl->D_life_u];
		if (Key_trg & KEY_RUN)
		{
			// trigger quickturn
			*(u32*)&pPl->Routine_0 = 0xC01;
			return;
		}
		if ((Key_trg & 0x80) != 0)
			pG->Status_flg |= 0x200000;
		if (Key & 0x100 && pPl->Type & 0xFFF)
			*(u32*)&pPl->Routine_0 = 0x501;
	}
	else
	{
		*(u32*)&pPl->Routine_0 = 1;
		if (Key & 0xA) *(u32*)&pPl->Routine_0 = 0x401;
		if (Key & 1) *(u32*)&pPl->Routine_0 = 0x101;
	}
}

// no input code is required for quickturn
void pl_br_quickturn(PLAYER_WORK *pEm, u32 Key, u32 Key_trg)
{
}

void pl_mv_quickturn(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq)
{
	switch (pEm->Routine_2)
	{
	case 0:
		pEm->Routine_2 = 1;
		pEm->Timer0 = 0;
	case 1:
		if (pEm->Timer0++ < 8)
			pEm->Cdir_y += 2048 / 8;
		else *(u32*)&pEm->Routine_0 = 1;
		break;
	}

	if (*pEm->pNow_seq & 0x4000)
	{
		Snd_se_walk(0, 3 * ((*pEm->pNow_seq >> 13) & 1) + 4, pEm);
		pG->Room_player_flg |= 2;
	}
	Joint_move(pEm, pKan, pSeq, 512);
}
