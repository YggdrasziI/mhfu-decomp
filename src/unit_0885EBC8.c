/* unit_0885EBC8: 0x0885EBC8-0x0885ECF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885EBC8: half the unk8 word of the 40-byte record selected by
 * arg1->unk1 / arg1->unk2, plus func_0885F194 over a copy of arg1 with its
 * unk4 counter stepped from 0 (bounded by arg1->unk4 and by the u8 result of
 * func_0885EF20), plus func_0885EE48(arg0, arg1).
 * Needs the speed setting (guarded rotated loop). The record pointer must be
 * a local stepped with `+=` (an indexed expression swaps the `addu`); the
 * u8 result is kept as `s32 n = (u8)...` and cast again at the compare (the
 * second `andi`); the final shift and sum are compound assignments on `sum`
 * (keeps the shifted value in a saved register across the call).
 */

#pragma optimize_for_size off
#include "unk_tables.h"

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s16 v[3];
} S16x3;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    S16x3 unk6;
} Item;

extern u8 func_0885EF20(s32 arg0, Item *arg1);
extern s32 func_0885F194(s32 arg0, Item *arg1);
extern s32 func_0885EE48(s32 arg0, Item *arg1);

s32 func_0885EBC8(s32 arg0, Item *arg1) {
    u32 sum;
    s32 n;
    Item tmp;

    if (arg1->unk2 == 0) {
        return 0;
    }
    {
        UnkRec40 *rec = D_08978474[arg1->unk1];
        rec += arg1->unk2;
        sum = rec->unk8;
    }
    n = (u8)func_0885EF20(arg0, arg1);
    if (n != 0) {
        tmp.unk0 = arg1->unk0;
        tmp.unk1 = arg1->unk1;
        tmp.unk2 = arg1->unk2;
        tmp.unk4 = arg1->unk4;
        tmp.unk6 = arg1->unk6;
        for (tmp.unk4 = 0; tmp.unk4 < arg1->unk4; ) {
            sum += func_0885F194(arg0, &tmp);
            tmp.unk4++;
            if (tmp.unk4 > (u8)n) {
                break;
            }
        }
    }
    sum >>= 1;
    sum += func_0885EE48(arg0, arg1);
    return sum;
}
