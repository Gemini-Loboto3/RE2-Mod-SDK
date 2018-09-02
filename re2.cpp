#include <stdafx.h>
#include "re2.h"

#define JUMP(x)			__asm { jmp[mprc.(x)]}
#define ASSIGN(_y, x)	mprc._y = (FARPROC)&pExe[(x) - 0x400000]

typedef struct tagEngineCall
{
	FARPROC Snd_se_on;
	FARPROC Mess_print;
	FARPROC Get_mess_width;
	FARPROC ResetScreen;
	FARPROC Config_draw_button;
	FARPROC Config_draw_key;
	FARPROC Config_get_squal;
	//
	FARPROC Set_speed;
	FARPROC Joint_move;
	FARPROC Snd_se_walk;
} ENGINE_CALL;

static ENGINE_CALL mprc;

NAKED void Snd_se_on(u32 snd, SVECTOR *pos)
{
	JUMP(Snd_se_on);
}

NAKED void Snd_se_walk(int, int, PLAYER_WORK *pEm)
{
	JUMP(Snd_se_walk);
}

NAKED int Joint_move(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq, u32 mode)
{
	JUMP(Joint_move);
}

NAKED void Set_speed(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq)
{
	JUMP(Set_speed);
}

NAKED int Get_mess_width(u8 *str, u32 mode)
{
	JUMP(Get_mess_width);
}

NAKED void Mess_print(int x, int y, u8* str, u32 mode)
{
	JUMP(Mess_print);
}

NAKED void Config_draw_key(int x, int y, int, int)
{
	JUMP(Config_draw_key);
}

NAKED void Config_draw_button(int x, int y, int, int)
{
	JUMP(Config_draw_button);
}

NAKED int Config_get_squal()
{
	JUMP(Config_get_squal);
}

NAKED void ResetScreen()
{
	JUMP(ResetScreen);
}

GLOBAL *pG;

void Init_RE2(u8 *pExe)
{
	pG = (GLOBAL*)&pExe[0x9864E0 - 0x400000];

	ASSIGN(Snd_se_on, 0x4ED950);
	ASSIGN(Snd_se_walk, 0x4EDF40);
	ASSIGN(Joint_move, 0x4C1C30);
	ASSIGN(Set_speed, 0x4B2920);
	ASSIGN(Mess_print, 0x4CA2F9);
	ASSIGN(Get_mess_width, 0x4C7CD0);

	ASSIGN(ResetScreen, 0x442A50);

	ASSIGN(Config_draw_button, 0x44D3D0);
	ASSIGN(Config_draw_key, 0x44CD40);
	ASSIGN(Config_get_squal, 0x50B990);
}