/* unit_08858238: 0x08858238-0x088585E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* layout of ScePspDateTime in pspsdk (psptypes.h) */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 microsecond;
} ScePspDateTime;

/* 6-byte table entries; each field is reached through its own symbol */
typedef struct {
    u16 val;
    u8 pad[4];
} Tbl16;

typedef struct {
    u8 val;
    u8 pad[5];
} Tbl8;

typedef struct {
    char unk0[1];
    u8 unk1;
    s8 unk2;
    s8 unk3;
    char unk4[2];
    s8 unk6;
    char unk7[0xF];
    u8 unk16;
    char unk17;
    f32 unk18;
    f32 unk1C;
    char unk20[6];
    u16 unk26;
    u8 unk28;
    u8 unk29;
    s16 unk2A;
    u8 unk2C;
    char unk2D[3];
    s32 unk30;
    char unk34[0x10];
    s8 unk44;
    s8 unk45;
    s8 unk46;
    char unk47[4];
    s8 unk4B;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E[0x12];
    u8 unk60[8];
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
} Rec;

extern void memcpy(void *, void *, s32);
extern s32 sceWlanGetEtherAddr(u8 *);
extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);
extern u16 func_088900C4(char *, s32);
extern u8 func_0884FB38(char *, s32);
extern char *D_08A631A0;
extern char *D_089CC438;
extern Tbl16 D_09CD01E0[];
extern Tbl8 D_09CD01E2[];
extern Tbl8 D_09CD01E3[];
extern Tbl8 D_09CD01E4[];
extern Tbl8 D_09CD01E5[];

void func_08858238(char *arg0, Rec *arg1, s32 arg2) {
    u8 mac[8];
    ScePspDateTime t;

    if (arg2 == 1) {
        arg1->unk16 = 0;
        arg1->unk26 = 0;
        if (arg1->unk3 >= 8) {
            arg1->unk2A = 4500;
        } else if (arg1->unk3 >= 4) {
            arg1->unk2A = 4000;
        } else {
            arg1->unk2A = 3500;
        }
        arg1->unk18 = 10.0f;
        arg1->unk1C = 10.0f;
        arg1->unk29 = 11;
        arg1->unk28 = 100;
        arg1->unk4B = (arg1->unk6 + (arg1->unk1 + arg1->unk2)) % 16;
        if (!((arg1->unk1 + arg1->unk2) & 1)) {
            arg1->unk2C = 0;
        } else {
            arg1->unk2C = 1;
        }
    } else {
        arg1->unk16 = arg1->unk3 - 1;
        if (arg1->unk16 != 0) {
            arg1->unk26 = D_09CD01E0[(u8)((arg1->unk16 & 0xFF) - 1)].val;
        } else {
            arg1->unk26 = 0;
        }
        arg1->unk2A = 3500;
        arg1->unk18 = (u16)(D_09CD01E2[arg1->unk16].val + 10);
        arg1->unk1C = (u16)(D_09CD01E3[arg1->unk16].val + 10);
        arg1->unk29 = (u16)(D_09CD01E5[arg1->unk16].val + 11);
        arg1->unk28 = (u16)(D_09CD01E4[arg1->unk16].val + 100);
        arg1->unk4B = func_088900C4(D_08A631A0, 1) % 16;
        if (func_088900C4(D_08A631A0, 1) & 1) {
            arg1->unk2C = 0;
        } else {
            arg1->unk2C = 1;
        }
        if (func_0884FB38(D_089CC438, 0x5D) == 1) {
            arg1->unk30 = 15;
        }
    }
    arg1->unk4C = 0;
    arg1->unk4D = 0;
    arg1->unk44 = -1;
    arg1->unk45 = -1;
    arg1->unk46 = -1;
    memcpy(arg1->unk60, arg0 + 0x679A0, 8);
    sceWlanGetEtherAddr(mac);
    sceRtcGetCurrentClockLocalTime(&t);
    arg1->unk68 = mac[3];
    arg1->unk69 = mac[4];
    arg1->unk6A = mac[5];
    arg1->unk6B = t.year;
    arg1->unk6C = ((t.month & 0xF) << 4) + ((t.day & 0x1E) >> 1);
    arg1->unk6D = ((t.day & 1) << 7) + (t.minute & 0x1F);
    arg1->unk6E = (t.second & 0x3F) + ((*(u16 *)(arg0 + 0x6AD76) & 0x300) >> 2);
    arg1->unk6F = *(u16 *)(arg0 + 0x6AD76);
    (*(u16 *)(arg0 + 0x6AD76))++;
    memcpy(arg1->unk4E, D_089CC438 + 0x4A0, 0x12);
}
