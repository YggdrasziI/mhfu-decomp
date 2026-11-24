/* unit_088542EC: 0x088542EC-0x08854BAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
/* func_088542EC: store a 0x1078-byte record in one of the 96 slots at
 * arg0 + 0x4A58 (C++: the record assignment is copied member by member). */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef long long s64;

typedef struct { s16 a, b, c; } S3;
typedef struct { float v[4]; } F4;
typedef struct { float v[3]; } F3;

typedef struct Rec {
    s8 name[0x12];      /* 0x000 */
    u16 unk12;
    u16 unk14;
    s16 unk16[5];
    s16 unk20[7];
    s32 unk30;
    s8 unk34[0x62];
    u8 unk96;
    u8 unk97;
    u8 unk98;
    S3 unk9A;
    s64 unkA0;
    F4 unkA8;
    F3 unkB8;
    s8 unkC4[0x7E];
    s64 unk148;
    s16 unk150[0x7C];
    s8 unk248[8];
    s32 unk250[23];
    s32 unk2AC[100];
    s32 unk43C[23];
    s32 unk498[100];
    s16 unk628[11];
    s32 unk640[0x154];
    s32 unkB90[0xD0];
    s32 unkED0[35];
    s32 unkF5C[35];
    s32 unkFE8[35];
    u16 unk1074;
    u8 unk1076;
    u8 unk1077;
} Rec;

typedef struct { char pad[0x26]; s8 unk26; char pad27[40 - 0x27]; } Ent;

typedef struct Obj {
    char pad0[0x4A58];
    Rec recs[0x60];
    char pad[0x687D0 - 0x4A58 - 0x60 * 0x1078];
    Ent ents[0x60];
} Obj;

extern "C" {

extern char *D_089CC438;

extern s32 func_0880BFF0(void *, void *, s32);
extern void func_08854BAC(char *, char *);
extern void func_0885128C(char *, s32);

s32 func_088542EC(Obj *arg0, Rec *arg1) {
    s32 i;

    for (i = 0; i < 0x60; i++) {
        if (func_0880BFF0(arg0->recs[i].name, arg1->name, 0x12) == 0 &&
            func_0880BFF0(arg0->recs[i].unk248, arg1->unk248, 8) == 0) {
            arg0->recs[i] = *arg1;
            func_08854BAC((char *)arg0, (char *)arg0 + i * 40 + 0x687D0);
            func_0885128C((char *)arg0, i);
            return 1;
        }
    }
    for (i = 0; i < 0x60; i++) {
        if (*(u16 *)arg0->recs[i].name == 0) {
            arg0->recs[i] = *arg1;
            ((s32 *)(D_089CC438 + 0x6A384))[i] = 0;
            func_08854BAC((char *)arg0, (char *)arg0 + i * 40 + 0x687D0);
            func_0885128C((char *)arg0, i);
            arg0->ents[i].unk26 = 0;
            return 1;
        }
    }
    return 0;
}

}
