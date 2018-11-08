#pragma once

template<typename OUTSTUFF, typename INSTUFF>
OUTSTUFF ForceCast(INSTUFF in)
{
	union
	{
		INSTUFF  in;
		OUTSTUFF out;
	}
	u = { in };

	return u.out;
};

enum BioVersion
{
	BV_NEWEUR,		// European 1.00c
	BV_MEDIAKITE,	// Japanese 1.01
	BV_ASIA,		// UK/US for Asia
	BV_UKUSA,		// UK/US
	BV_UKUSA1,		// almost the same as UK/US
	BV_GERMAN,		// Germany
	BV_FRENCH,		// France
	BV_UKVR,		// PowerVR UK/US
	BV_JPVR,		// PowerVR Japanese
	BVV_UKUSADEMO,	//
	BV_UNSUPPORTED	// unknown version
};

typedef struct tagBioVersion
{
	size_t size;	// executable size
	char *pName;	// internal name of version
	u32 crc;		// crc32 of the first 512 bytes of .text
	int supported;	// 1 = supported, 0 = unsupported
} BIO_VERSION;

BioVersion DetectVersion(u8 *pExe);

#pragma pack(push, 1)
typedef struct {
	BYTE opCode;	// must be 0xE9;
	DWORD offset;	// jump offset
} JMP;

typedef struct
{
	BYTE opCode0;	// must be 0xE8
	DWORD offset0;	// call offset
	BYTE opCode1;	// must be 0xE9
	DWORD offset1;	// reroute offset
} CALLX;

#pragma pack(pop)

#define INJECT(from,to) { \
	((JMP*)(from))->opCode = 0xE9; \
	((JMP*)(from))->offset = (DWORD)(to) - ((DWORD)(from) + sizeof(JMP)); \
}

#define INJECT_EXT(from,to) (*(DWORD*)(from)) = (DWORD)(to)

#define INJECT_CALL(from,to,size)	{\
	memset((from), 0x90, size); \
	((JMP*)(from))->opCode = 0xE8; \
	((JMP*)(from))->offset = (DWORD)(to) - ((DWORD)(from) + sizeof(JMP)); \
}

#define INJECT_CALLX(from,fnc,skp)	{\
	((CALLX*)(from))->opCode0 = 0xE8; \
	((CALLX*)(from))->offset0 = (DWORD)(fnc) - ((DWORD)(from) + sizeof(JMP)); \
	((CALLX*)(from))->opCode1 = 0xE9; \
	((CALLX*)(from))->offset1 = (DWORD)(skp) - ((DWORD)(from) + sizeof(CALLX)); \
}\

void Inject(HMODULE exe);

void Inject_winmm(u8 *exe);
void Inject_winmmJP(u8 *exe);

void MessageBoxV(UINT icon, char *caption, char *message, ...);

enum InjectType
{
	IT_JUMP,
	IT_CALL,
	IT_EXTERN,
	IT_NOP
};

class CInjectCmd
{
public:
	CInjectCmd() {}
	void Execute(u8 *pProcess) {}

	InjectType type;
};

class CInjectExtern : public CInjectCmd
{
	CInjectExtern() { type = IT_EXTERN; }
	void Execute(u8 *pProcess)
	{
	}
};

class CInjector
{
public:
	CInjector() {}
};
