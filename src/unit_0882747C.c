/* unit_0882747C: 0x0882747C-0x088275B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Stores six flags from func_0885CF9C tests; returns 0 when all are clear.
 * arg3 is unused: the caller func_08827194 passes it in $a3 (same code).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef short s16;

typedef struct Rec {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    u8 unkA;
} Rec;

extern char *D_08A62C54;
extern s8 func_0885CF9C(char *, char *, u8);

s32 func_0882747C(s32 arg0, char *arg1, Rec *arg2, s32 arg3) {
    arg2->unk4 = func_0885CF9C(D_08A62C54, arg1 + 0x4E8, arg2->unk3) > 0;
    arg2->unk5 = func_0885CF9C(D_08A62C54, arg1 + 0x500, arg2->unk3) > 0;
    arg2->unk6 = func_0885CF9C(D_08A62C54, arg1 + 0x50C, arg2->unk3) > 0;
    arg2->unk7 = func_0885CF9C(D_08A62C54, arg1 + 0x518, arg2->unk3) > 0;
    arg2->unk8 = func_0885CF9C(D_08A62C54, arg1 + 0x524, arg2->unk3) > 0;
    arg2->unk9 = func_0885CF9C(D_08A62C54, arg1 + 0x4F4, arg2->unk3) > 0;
    if ((arg2->unk4 | arg2->unk5 | arg2->unk6 | arg2->unk7 | arg2->unk8 | arg2->unk9) == 0) {
        return 0;
    }
    arg2->unk2 = 0x82;
    arg2->unkA = 0;
    arg2->unk0 = 0;
    return 1;
}
