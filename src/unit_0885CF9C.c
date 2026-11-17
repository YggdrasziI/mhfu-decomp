/* unit_0885CF9C: 0x0885CF9C-0x0885D134 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08931514-0x08931530) is linked from this unit.
 */

#include "unk_tables.h"

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern s8 func_0885D134(char *, u16, s32);

s8 func_0885CF9C(char *arg0, u8 *arg1, s32 arg2) {
    s8 sum;
    UnkRec40 *rec;
    u16 id = *(u16 *)(arg1 + 2);

    if (id == 0) {
        return 0;
    }
    sum = 0;
    switch (arg1[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        rec = D_08978474[arg1[1]];
        rec += id;
        if (rec->unk1E[0].unk0 == (u8) arg2) {
            sum += rec->unk1E[0].unk1;
        }
        if (rec->unk1E[1].unk0 == (u8) arg2) {
            sum += rec->unk1E[1].unk1;
        }
        if (rec->unk1E[2].unk0 == (u8) arg2) {
            sum += rec->unk1E[2].unk1;
        }
        if (rec->unk1E[3].unk0 == (u8) arg2) {
            sum += rec->unk1E[3].unk1;
        }
        if (rec->unk1E[4].unk0 == (u8) arg2) {
            sum += rec->unk1E[4].unk1;
        }
        {
            s32 i = 0;
            u16 *p = (u16 *) arg1;
            do {
                if (p[3] != 0) {
                    sum += func_0885D134(arg0, p[3], arg2);
                }
                i++;
                p++;
            } while (i < 3);
        }
        return sum;
    case 5:
    case 6:
        {
            s32 i = 0;
            u16 *p = (u16 *) arg1;
            do {
                if (p[3] != 0) {
                    sum += func_0885D134(arg0, p[3], arg2);
                }
                i++;
                p++;
            } while (i < 3);
        }
        break;
    }
    return sum;
}
