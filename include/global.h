#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#include "types.h"
#include "functions.h"
#include "variables.h"
#include "constants/global.h"
#include "constants/ereader.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

// IDE support
#if defined (__APPLE__) || defined (__CYGWIN__) || defined (_MSC_VER)
#define _(x) x
#define __(x) x
#define INCBIN_U8 {0}
#define INCBIN_U16 {0}
#define INCBIN_U32 {0}
#define INCBIN_S8 {0}
#define INCBIN_S16 {0}
#define INCBIN_S32 {0}
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) * 256))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define TEST_BUTTON_EXACT(field, button) (((field) & (button)) == (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)

struct BgOffsets
{
    u16 xOffset;
    u16 yOffset;
};

struct UnkPinballGame1334_unk2C
{
	s16 unk0;
	s16 unk2;
};

struct UnkPinballGame1334
{
	/*0x00*/ u8 unk0;
	/*0x01*/ u8 filler1[0x5];
	/*0x06*/ u16 unk6;
	/*0x08*/ u8 filler8[0x6];
	/*0x0E*/ u16 unkE;
	/*0x10*/ s16 unk10;
	/*0x12*/ s16 unk12;
	/*0x14*/ u8 filler14[0xB];
	/*0x1F*/ u8 unk1F;
	/*0x20*/ u8 filler20[0x8];
	/*0x28*/ struct UnkPinballGame1334_unk2C unk28;
	/*0x2C*/ struct UnkPinballGame1334_unk2C unk2C;
	/*0x30*/ u16 unk30;
	/*0x32*/ u16 unk32;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3C*/ u8 filler3C[0x8];
};

struct PinballGame
{
	/*0x000*/ u32 unk0;
	/*0x004*/ u8 unk4[5];
	/*0x009*/ u8 unk9[5];
	/*0x00E*/ u8 unkE[5];
	/*0x013*/ s8 progressForBonus; // Current number of Pokéballs filled by catch mode and evo mode
	/*0x014*/ s8 unk14;
	/*0x015*/ u8 filler15;
	/*0x016*/ u8 unk16;
	/*0x017*/ u8 filler17[0x6];
	/*0x01D*/ u8 unk1D;
	/*0x01E*/ u8 unk1E;
	/*0x01F*/ u8 unk1F;
	/*0x020*/ u8 filler20[0x5];
	/*0x025*/ s8 unk25;
	/*0x026*/ u16 unk26;
	/*0x028*/ u16 unk28;
	/*0x02A*/ u8 filler2A[0x6];
	/*0x030*/ u8 numLives;
	/*0x031*/ u8 ballSpeed;
	/*0x032*/ u8 filler32[0x3];
	/*0x035*/ s8 area;
	/*0x036*/ u8 filler36[0x2];
	/*0x038*/ u32 unk38;
	/*0x03C*/ u32 unk3C;
	/*0x040*/ u8 filler40[0x4];
	/*0x044*/ u32 unk44;
	/*0x048*/ u32 unk48;
	/*0x04C*/ u16 unk4C;
	/*0x04E*/ s16 unk4E;
	/*0x050*/ u8 filler50[0x4];
	/*0x054*/ u32 unk54;
	/*0x058*/ u16 unk58;
	/*0x05A*/ u16 unk5A;
	/*0x05C*/ u8 filler5C[0x8];
	/*0x064*/ s16 unk64;
	/*0x066*/ u16 unk66;
	/*0x068*/ s16 unk68;
	/*0x06A*/ s16 unk6A;
	/*0x06C*/ u8 filler6C[0x3];
	/*0x06F*/ s8 unk6F;
	/*0x070*/ u8 filler70[0x5C];
	/*0x0CC*/ u16 unkCC;
	/*0x0CE*/ u8 fillerCE[0x16];
	/*0x0E4*/ u8 unkE4;
	/*0x0E6*/ u16 unkE6;
	/*0x0E8*/ u8 fillerE8[0xA];
	/*0x0F2*/ s8 unkF2;
	/*0x0F3*/ u8 fillerF3[0x2E];
	/*0x121*/ s8 unk121;
	/*0x122*/ u8 filler122[0x9];
	/*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
	/*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
	/*0x12D*/ u8 filler12D;
	/*0x12E*/ s16 unk12E;
	/*0x130*/ s16 unk130[8];
	/*0x140*/ u8 filler140[0x52];
	/*0x192*/ u8 coins;
	/*0x193*/ u8 filler193[0x1];
	/*0x194*/ s8 unk194;
	/*0x195*/ u8 filler195[0x10];
	/*0x1A5*/ s8 unk1A5;
	/*0x1A6*/ s8 unk1A6;
	/*0x1A7*/ u8 filler1A7[0xD];
	/*0x1B4*/ u16 unk1B4;
	/*0x1B6*/ u8 filler1B6[0x4];
	/*0x1BA*/ u16 unk1BA;
	/*0x1BC*/ u8 filler1BC[0x4];
	/*0x1C0*/ u16 unk1C0;
	/*0x1C2*/ s8 unk1C2;
	/*0x1C3*/ u8 filler1C3[0x3];
	/*0x1C6*/ u16 unk1C6;
	/*0x1C8*/ u16 unk1C8;
	/*0x1CA*/ u16 unk1CA;
	/*0x1CC*/ u16 unk1CC;
	/*0x1CE*/ u16 unk1CE;
	/*0x1D0*/ u16 unk1D0;
	/*0x1D2*/ u8 filler1D2[0x2];
	/*0x1D4*/ u16 unk1D4;
	/*0x1D6*/ u16 unk1D6;
	/*0x1D8*/ u16 unk1D8;
	/*0x1DA*/ u16 unk1DA;
	/*0x1DC*/ u16 unk1DC;
	/*0x1DE*/ u8 filler1DE[0x4];
	/*0x1E2*/ s8 unk1E2;
	/*0x1E3*/ u8 filler1E3[0x2];
	/*0x1E5*/ u8 unk1E5;
	/*0x1E6*/ u8 unk1E6;
	/*0x1E7*/ u8 filler1E7[0x6];
	/*0x1ED*/ s8 unk1ED;
	/*0x1EE*/ u8 filler1EE[0x1a];
	/*0x208*/ u16 unk208;
	/*0x20A*/ u8 unk20A;
	/*0x20B*/ u8 filler20B[0x54];
	/*0x25F*/ s8 unk25F;
	/*0x260*/ u8 filler260[0x21];
	/*0x281*/ s8 unk281;
	/*0x282*/ s8 unk282;
	/*0x283*/ u8 bonusLevelCount; //how many bonus levels have been completed
	/*0x284*/ u8 filler284[0xC];
	/*0x290*/ u32 unk290;
	/*0x294*/ u8 filler294[0x4];
	/*0x298*/ u16 unk298;
	/*0x29A*/ u8 filler29A[0x2];
	/*0x29C*/ u16 unk29C;
	/*0x29E*/ u8 unk29E;
	/*0x29F*/ u8 filler29F[0x1];
	/*0x2A0*/ u8 filler2A0[0x2];
	/*0x2A2*/ u8 unk2A2;
	/*0x2A3*/ u8 filler2A3[0x37];
	/*0x2DA*/ s8 unk2DA;
	/*0x2DB*/ u8 filler2DB[0x16];
	/*0x2F1*/ u8 unk2F1;
	/*0x2F2*/ u8 filler2F2[0x2];
	/*0x2F4*/ u8 unk2F4;
	/*0x2F5*/ s8 unk2F5;
	/*0x2F6*/ u8 filler2F6[0x10];
	/*0x306*/ u8 unk306;
	/*0x307*/ u8 filler307[0x5];
	/*0x30C*/ u16 unk30C;
	/*0x30E*/ u8 filler30E[0x37];
	/*0x345*/ s8 unk345;
	/*0x346*/ s8 unk346;
	/*0x348*/ u8 filler347[0x23];
	/*0x36A*/ u8 unk36A[0x2];
	/*0x36C*/ u8 unk36C[0x2];
	/*0x36E*/ u16 unk36E[0x2];
	/*0x372*/ u8 filler370[0x226];
	/*0x598*/ u16 currentSpecies; // Current catch/hatch mode species? Is it evo mode as well?
	/*0x59A*/ u8 filler59A[0x2];
	/*0x59C*/ u16 lastCatchSpecies; // Previous catch mode species?
	/*0x59E*/ u16 lastEggSpecies; // Previous hatch/evo mode species?
	/*0x5A0*/ u8 filler5A0[0x50];
	/*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
	/*0x5F2*/ u8 filler5F2[0x4];
	/*0x5F6*/ s8 unk5F6;
	/*0x5F7*/ u8 unk5F7;
	/*0x5F8*/ u16 unk5F8;
	/*0x5FA*/ u8 unk5FA;
	/*0x5FB*/ u8 unk5FB;
	/*0x5FC*/ s16 unk5FC;
	/*0x5FE*/ u16 unk5FE;
	/*0x600*/ u16 unk600;
	/*0x602*/ u8 filler602[0x12];
	/*0x614*/ u16 unk614;
	/*0x616*/ u8 filler616[0xAE];
	/*0x6C4*/ u8 unk6C4;
	/*0x6C5*/ u8 filler6C5[0x63];
	/*0x728*/ u8 unk728; // TODO: unknown type
	/*0x729*/ u8 filler729[0x5];
	/*0x72E*/ s8 unk72E;
	/*0x72F*/ s8 unk72F;
	/*0x730*/ u8 unk730;
	/*0x731*/ u8 filler731[0xB];
	/*0x73C*/ u8 unk73C; // TODO: unknown type
	/*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
	/*0x73E*/ u8 filler73E[0x8];
	/*0x746*/ u8 unk746;
	/*0x747*/ u8 filler747[0x2];
	/*0x749*/ u8 unk749;
	/*0x74A*/ u8 filler74A[0x2];
	/*0x74C*/ volatile u8 unk74C[2][OBJ_PLTT_SIZE];
	/*0xB4C*/ volatile u8 unkB4C[2][BG_PLTT_SIZE];
	/*0xF4C*/ struct SongHeader *unkF4C;
	/*0xF50*/ u8 fillerF50[0x8];
	/*0xF58*/ struct BgOffsets bgOffsets0;
	/*0xF5C*/ struct BgOffsets bgOffsets1;
	/*0xF60*/ struct BgOffsets bgOffsets2;
	/*0xF64*/ struct BgOffsets bgOffsets3;
	/*0xF68*/ u16 unkF68[2][100];
	/*0x10F8*/u8 eReaderBonuses[NUM_EREADER_CARDS];
	/*0x10FD*/u8 field;
	/*0x10FE*/u8 unk10FE;
	/*0x10FF*/u8 unk10FF;
	/*0x1100*/u8 unk1100;
	/*0x1101*/u8 unk1101;
	/*0x1102*/u8 unk1102;
	/*0x1103*/u8 unk1103;
	/*0x1104*/u8 filler1104[0x2];
	/*0x1106*/u16 unk1106;
	/*0x1108*/u16 unk1108;
	/*0x110A*/u16 unk110A;
	/*0x110C*/u16 unk110C;
	/*0x110E*/u16 unk110E;
	/*0x1110*/volatile u16 unk1110;
	/*0x1112*/volatile u16 unk1112;
	/*0x1114*/volatile u16 unk1114;
	/*0x1116*/u16 unk1116;
	/*0x1118*/u16 unk1118;
	/*0x111A*/u8 unk111A[OBJ_PLTT_SIZE];
	/*0x131A*/u8 filler131A[0x6];
	/*0x1320*/s16 unk1320;
	/*0x1322*/s16 unk1322;
	/*0x1324*/s16 unk1324;
	/*0x1326*/s16 unk1326;
	/*0x1328*/u8 filler1328[0x4];
	/*0x132C*/struct UnkPinballGame1334 *unk132c;
	/*0x1330*/struct UnkPinballGame1334 *unk1330;
	/*0x1334*/struct UnkPinballGame1334 unk1334[2];
	/*0x13BC*/u8 filler[0x54];
} /* size=0x1410 */;

struct Unk02031520_unk10
{
	/*0x0*/ u8 unk0;
	/*0x1*/ u8 unk1;
	/*0x2*/ u8 unk2;
};

struct Unk02031520
{
	/*0x00*/ u8 filler0[0x8];
	/*0x08*/ s16 unk8;
	/*0x0A*/ u8 fillerA[0x2];
	/*0x0C*/ struct PinballGame *unkC;
	/*0x10*/ struct Unk02031520_unk10 *unk10;
	/*0x14*/ u8 filler14[0x18];
	/*0x2C*/ u8 *unk2C;
};

extern struct PinballGame *gCurrentPinballGame;
extern u32 gUnknown_02031510;
extern struct Unk02031520 gUnknown_02031520;

#endif // GUARD_GLOBAL_H
