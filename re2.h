#pragma once

#define KEY_START
#define KEY_CONFIRM
#define KEY_RUN			0x0200
#define KEY_AIM
#define KEY_CANCEL
#define KEY_LEFT		0x0002
#define KEY_RIGHT		0x0008
#define KEY_FORWARD		0x0001
#define KEY_BACKWARD	0x0004

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned long u_long;

typedef struct tagDrMode
{
	u_long	tag;
	u_long	code[2];
} DR_MODE;

typedef struct tagSprt8
{
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, y0;
	u_char	u0, v0;	u_short	clut;
} SPRT_8;

typedef struct tagSprt
{
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, y0;
	u_char	u0, v0;	u_short	clut;
	short	w, h;
} SPRT;

typedef struct tagTile
{
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, y0;
	short	w, h;
} TILE;

typedef struct tagMojiDisp
{
	DR_MODE Moji_mode[2][16];
	SPRT Prim_sprt[2][256];
	SPRT_8 Prim_sprt_8[2][128];
	SPRT *pSprt_keep;
	SPRT_8 *pSprt_keep8;
} MOJIDISP;

typedef struct tagVector
{
	s32 vx,
		vy,
		vz,
		pad;
} VECTOR;

typedef struct tagSVector
{
	s16 vx,
		vy,
		vz,
		pad;
} SVECTOR;

typedef struct tagMatrix
{
	__int16 m[3][3];
	__int16 field_12;
	int t[3];
} MATRIX;

struct AT_DATA
{
	int X;
	int Y;
	int Z;
	__int16 W;
	__int16 D;
	__int16 Ofs_x;
	__int16 Ofs_z;
	__int16 Ofs_y;
	__int16 At_w;
	__int16 At_d;
	__int16 At_h;
	__int16 Atw_x;
	__int16 Atw_z;
};

struct PARTS_W
{
	int Be_flg;
	int Attribute;
	int pTmd;
	int pPacket;
	int pTmd2;
	int pPacket2;
	__int16 m[9];
	__int16 dummy_m01;
	int Pos_x;
	int Pos_y;
	int Pos_z;
	__int16 Old_x;
	__int16 Old_y;
	__int16 Old_z;
	__int16 Old_x2;
	__int16 Old_y2;
	__int16 Old_z2;
	int dummy00;
	MATRIX Workm;
	__int16 Cdir_x;
	__int16 Cdir_y;
	__int16 Cdir_z;
	__int16 dummy01;
	int Poly_rgb;
	int pSuper;
	char Parts_no;
	char Timer1;
	char Timer2;
	char Sabun_flg;
	__int16 Rot_x;
	__int16 Rot_y;
	__int16 Rot_z;
	__int16 Sabun_cnt0;
	__int16 Timer0;
	__int16 Timer3;
	int pSa_dat_head;
	__int16 Size_x;
	__int16 Size_y;
	__int16 Size_z;
	__int16 dummy03;
	PARTS_W *pOya_parts;
	unsigned __int16 Free[16];
};

struct PL_WORK
{
	unsigned int Be_flg;
	char Routine_0;
	char Routine_1;
	char Routine_2;
	char Routine_3;
	char Id;
	char Sc_id;
	char At_obj_no;
	char At_sce_no;
	char Work_no;
	char At_em_no;
	__int16 At_em_flg;
	int Attribute;
	int pTmd;
	int pPacket;
	int pTmd2;
	int pPacket2;
	__int16 M[9];
	__int16 field_36;
	int Pos_x;
	int Pos_y;
	int Pos_z;
	__int16 Old_x;
	__int16 Old_y;
	__int16 Old_z;
	__int16 field_4A;
	__int16 field_4C;
	__int16 field_4E;
	__int16 field_50;
	__int16 field_52;
	MATRIX Workm;
	__int16 Cdir_x;
	__int16 Cdir_y;
	__int16 Cdir_z;
	__int16 field_7A;
	int Poly_rgb;
	int pSuper;
	AT_DATA At_data[4];
	char Tpage;
	char Clut;
	char nFloor;
	char Parts_num;
	int pKan_t_ptr;
	__int16 Water;
	__int16 Type;
	int Sca_info;
	int pSca_hit_data;
	__int16 Sca_old_x;
	__int16 Sca_old_z;
	MATRIX Super_matrix;
	SVECTOR Super_vector;
	__int16 Spd_x;
	__int16 Spd_y;
	__int16 Spd_z;
	char In_screen;
	char Model_Tex_type;
	char Move_no;
	char Move_cnt;
	char Hokan_flg;
	char Mplay_flg;
	char Root_ck_cnt;
	char D_life_u;
	char D_life_c;
	char D_life_d;
	__int16 Status_flg;
	__int16 Life;
	__int16 Timer0;
	__int16 Timer1;
	__int16 Fpos_x;
	__int16 Fpos_y;
	__int16 Fpos_z;
	__int16 Max_life;
	__int16 Base_pos_x;
	__int16 Base_pos_y;
	__int16 Base_pos_z;
	char Timer2;
	char Timer3;
	int pKage_work;
	__int16 Neck_point_x;
	__int16 Neck_point_y;
	__int16 Neck_point_z;
	__int16 Size;
	int pNow_seq;
	int pSeq_t_ptr;
	int pSub0_kan_t_ptr;
	int pSub0_seq_t_ptr;
	int pSub1_kan_t_ptr;
	int pSub1_seq_t_ptr;
	int pRoom_kan_t_ptr;
	int pRoom_seq_t_ptr;
	PARTS_W *pSin_parts_ptr;
	int pParts_tmd;
	int pParts_packet;
	int pM_char_ptr;
	int pM_option_tmd;
	int pM_option_packet;
	int pMKage_work;
	int pEnemy_ptr;
	PL_WORK *pEnemy_neck;
	int pSa_dat;
	char Neck_flg;
	char Neck_no;
	char Ground;
	char field_1C3;
	__int16 Dest_x;
	__int16 Down_cnt;
	__int16 At_hit_flg;
	__int16 Set_flg_no;
	__int16 Sce_flg;
	char Em_set_flg;
	char Model_type;
	__int16 Damage_flg;
	char Damage_no;
	char Damage_cnt;
	__int16 field_1D4;
	__int16 field_1D6;
	__int16 Sce_free2;
	__int16 field_1DA;
	__int16 field_1DC;
	__int16 Parts0_pos_y;
	int field_1E0;
	int pOn_om;
	int nOba;
	char Attw_timer;
	char Attw_seq_no;
	__int16 Eff_at_r;
	int field_1F0;
	int field_1F4;
	__int16 field_1F8;
	char field_1FA;
	char field_1FB;
	int Tmp_routine;
};

/* 287 */
struct PLAYER_WORK
{
	int Be_flg;
	char Routine_0;
	char Routine_1;
	char Routine_2;
	char Routine_3;
	char Id;
	char Sc_id;
	char At_obj_no;
	char At_sce_no;
	char Work_no;
	char At_em_no;
	__int16 At_em_flg;
	int Attribute;
	int pTmd;
	int pPacket;
	int pTmd2;
	int pPacket2;
	WORD M[3][3];
	__int16 M_pad;
	int Pos_x;
	int Pos_y;
	int Pos_z;
	__int16 Old_x;
	__int16 Old_y;
	__int16 Old_z;
	__int16 Old_x2;
	__int16 Old_y2;
	__int16 Old_z2;
	int dummy00;
	MATRIX Workm;
	__int16 Cdir_x;
	__int16 Cdir_y;
	__int16 Cdir_z;
	__int16 dummy01;
	int Poly_rgb;
	MATRIX *pSuper;
	int Atd[32];
	u8 Tpage,
		Clut,
		nFloor,
		Parts_num;
	int pKan_t_ptr;
	__int16 Water;
	__int16 Type;
	int Sca_info;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	__int16 Spd_x;
	__int16 Spd_y;
	__int16 Spd_z;
	BYTE In_screen;
	char Model_Tex_type;
	char Move_no;
	char Move_cnt;
	char Hokan_flg;
	char Mplay_flg;
	char Root_ck_cnt;
	char D_life_u;
	char D_life_c;
	char D_life_d;
	__int16 Status_flg;
	__int16 Life;
	__int16 Timer0;
	__int16 Timer1;
	__int16 F_pos_x;
	__int16 F_pos_y;
	__int16 F_pos_z;
	__int16 Max_life;
	__int16 Base_pos_x;
	__int16 Base_pos_y;
	__int16 Base_pos_z;
	char Timer2;
	char Timer3;
	int pKage_work;
	int field_170;
	int field_174;
	DWORD *pNow_seq;
	int pSeq_t_ptr;
	int pSub0_kan_t_ptr;
	int pSub0_seq_t_ptr;
	int field_188;
	int field_18C;
	int field_190;
	int field_194;
	int pSin_parts_ptr;
	int pParts_tmd;
	int pParts_packet;
	int pM_char_ptr;
	int pM_option_tmd;
	int pM_option_packet;
	int pM_Kage_work;
	int pEnemy_ptr;
	int pEnemy_neck;
	int pSa_dat;
	char Neck_flg;
	char Neck_no;
	__int16 Ground;
	__int16 Dest_x;
	__int16 Dest_z;
	__int16 Down_cnt;
	char At_hit_flg;
	char field_1CB;
	__int16 Sce_flg;
	char Em_set_flg;
	char Model_type;
	int field_1D0;
	int field_1D4;
	int field_1D8;
	int field_1DC;
	int field_1E0;
	int field_1E4;
	int field_1E8;
	int field_1EC;
	int field_1F0;
	int field_1F4;
	int field_1F8;
	int field_1FC;
	int field_200;
	void(__cdecl *pTbefore_func)(PLAYER_WORK *);
	void(__cdecl *pTafter_func)(PLAYER_WORK *);
	int field_20C;
	int field_210;
	__int16 Poison_timer;
	char Pison_down;
	char field_217;
};

typedef struct tagRdtHeader
{
	char nSprite;
	char nCut;			// Number of objects at offset 7, seems to be number of cameras of the room
	char nOmodel;		// Number of objects at offset 10
	char nItem;			// unused?
	char nDoor;			// unused?
	char nRoom_at;		// unused?
	char Reverb_lv;		// unused?
	u8 nSprite_max;
	u32 kan0, vh0, vb0;
	u32 kan1, vh1, vb1;
	u32 sca;
	u32 rid;
	u32 rvd;
	u32 lit;
	u32 obj;
	u32 flr, blk;
	u32 tex[2];
	u32 scd[3];
	u32 esp, eff;
	u32 etim, mtim;
	u32 rbj;
} RDT_HEADER;

typedef struct tagItemWork
{
	u8 Id,
		Num,
		Size,
		dummy;
} ITEM_WORK;

struct GLOBAL
{
	int Ot0[16];
	DWORD *pOt0;
	DWORD Ot1[2][1024];
	int pOt1;
	DWORD Ot2[2][16];
	int pOt2;
	BYTE Padd_data[2][36];
	int Padd;
	DWORD Padd_trg;
	__int16 Padd1;
	__int16 Padd1_trg;
	__int16 Padd2;
	__int16 Padd2_trg;
	int Key;
	int Key_trg;
	int Key_old;
	int Random;
	int pPl_emd_top;
	int pPl_pac_top;
	int pRoom;
	int pFree_work_head;
	int pFree_work;
	PLAYER_WORK *pEm;
	PLAYER_WORK **ppEnemy_end;
	int Cccut;
	int Cccut_next;
	DWORD pPldamage_Em[64];
	DWORD pPldie_Em[64];
	int pBs_check_sum;
	int pXa_sector;
	int pOld_tim;
	int pOld_tmd;
	int pSce_aot_on;
	int Sp_bak;
	int Sce_aot[32];
	int pAot_data;
	int Game_time_offset;
	char Cbuf_id;
	char Sound_mode;
	char Bk_equip_no;
	char Bk_item_num;
	int Bk_item_work[10];
	int Kage9[35];
	int Kage[1300];
	int pBs_size;
	int pFree;
	int pSca_hit_data[32];
	int Rbj_set_flg;
	int System_flg;
	char Window_no;
	char Mirror_flg;
	__int16 Mirror_pos;
	__int16 Mirror_max;
	__int16 Mirror_min;
	char Save_cursor;
	char Dummy8[3];
	VECTOR Wep_hit_pos;
	int field_39AC;
	int field_39B0;
	DWORD field_39B4[4];
	char field_39C4;
	char field_39C5;
	char field_39C6;
	char field_39C7;
	__int16 field_39C8;
	__int16 field_39CA;
	int field_39CC;
	int field_39D0;
	int field_39D4;
	int field_39D8;
	int field_39DC;
	int field_39E0;
	int field_39E4;
	int field_39E8;
	int field_39EC;
	int Status_flg;
	int Stop_flg;
	int Use_flg[4];
	char Ctpage;
	char Cclut;
	char Next_cut_no;
	char Enemy_num;
	__int16 Room_enemy_flg;
	__int16 Room_player_flg;
	PLAYER_WORK Player;
	u16 Unk_flg1, Unk_flg2;
	PLAYER_WORK *pEnemy[33];
	DWORD Em_move_tbl[96];
	DWORD Em_ov_tbl[2][96];
	BYTE Em_bin_info[8];
	BYTE Ob_model[32][504];
	int pObj_work_end;
	__int16 Root_rot;
	__int16 Root_area_no;
	int field_8040;
	int field_8044;
	char field_8048;
	BYTE field_8049;
	char field_804A;
	char field_804B;
	int field_804C;
	__int16 Movie_Isrgb24;
	char Movie_id;
	char field_8053;
	int field_8054;
	char field_8058;
	char field_8059;
	char field_805A;
	char field_805B;
	char field_805C;
	char field_805D;
	char field_805E;
	char field_805F;
	char field_8060;
	char field_8061;
	char field_8062;
	char field_8063;
	char field_8064[584];
	__int16 field_82AC;
	__int16 field_82AE;
	int field_82B0;
	int field_82B4;
	int field_82B8;
	char Card_head[512];
	int Game_play_time;
	int Front_play_time;
	char Max_item_num;
	char Stereo;
	char Pl_id;
	char Save_area;
	char Vol_Se;
	char Vol_Bgm;
	char Key_idx;
	char Pl_poison_down;
	__int16 Pl_poison_timer;
	__int16 Extreme_lv;
	int Status_bak;
	char Equip_id;
	char Equip_no;
	__int16 Pl_life;
	__int16 Zonbi_cnt;
	__int16 Cure_cnt;
	__int16 Save_cnt;
	__int16 Pl_pos_x;
	__int16 Pl_pos_y;
	__int16 Pl_pos_z;
	int Weapon_mugen;
	__int16 field_84E8[142];
	__int16 F_atari;
	__int16 U_atari;
	__int16 Use_id;
	__int16 Get_id;
	__int16 Sce_work[8];
	__int16 DSce_work[4];
	__int16 Sce_tmp_work[8];
	__int16 Stage_no;
	__int16 Room_no;
	__int16 Cut_no;
	__int16 Room_no_old;
	__int16 Cut_no_old;
	__int16 Sce_random;
	__int16 Player_life;
	__int16 Sce_timer;
	__int16 Change_player;
	__int16 Def_em_set;
	__int16 Def_aot_set;
	__int16 Count_down_timer;
	int Scenario_flg[8];
	int Common_flg[8];
	int Room_flg[2];
	int Enemy_flg[8];
	int Enemy_flg2[8];
	int Item_flg[8];
	int Item_flg2[4];
	int Item_c_flg[7];
	int Map_o_flg;
	//
	DWORD Map_flg[4],
		Map_c_flg[2],
		Map_i_flg;
	DWORD Pri_be_flg[16][4],
		File_flg,
		Zapping_flg[2],
		Key_flg[2];
	ITEM_WORK Item_work[11],
		Item_boxwork[64];
	BYTE File_tag_bl[24];
	WORD Dummy[8];
};

typedef struct tagItemMix
{
	u8 with,
		type,
		result,
		pix_no;
} MIX_DATA;

typedef struct tagItemData
{
	u8 Item_max,
		Item_attribute,
		Item_num_col,
		Item_mix_num;
	MIX_DATA *Item_mix_data;
} ITEM_DATA;

extern GLOBAL *pG;

void Snd_se_on(u32 snd, SVECTOR *pos);
void Snd_se_walk(int, int, PLAYER_WORK *pEm);

int Get_mess_width(u8 *str, u32 mode);
void Mess_print(int x, int y, u8* str, u32 mode);

int Joint_move(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq, u32 mode);
void Set_speed(PLAYER_WORK *pEm, u32 *pKan, u32 *pSeq);

void Init_RE2(u8 *pExe);

void Config_draw_key(int x, int y, int, int);
void Config_draw_button(int x, int y, int, int);
int  Config_get_squal();

typedef struct tagPrint8
{
	u32 color : 4;
	u32 depth : 28;
	u32 otag : 4;
} PRINT8;

typedef struct tagLoopFlags
{
	int showCoord : 1;
	int captureFrame : 1;
	int reserved : 30;
} LOOP_FLAGS;

void Print8(int x, int y, char *str, PRINT8 mode);

void ResetScreen();
