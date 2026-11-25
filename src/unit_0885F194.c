/* unit_0885F194: 0x0885F194-0x0885F290 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F194: for an item of kind 0-4, converts the record word at +8
 * (unsigned) to float, scales it by the pair selected by func_0885F068
 * (factor at D_08979720 + i * 8, offset at D_08979724 + i * 8) and returns
 * the result as an unsigned integer; 0 for other kinds or a negative index.
 */

#include "unk_tables.h"

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    float f;
    char pad[4];
} F8;

extern F8 D_08979720[];
extern F8 D_08979724[];

extern s8 func_0885F068(s32 arg0, u8 *arg1);

u32 func_0885F194(s32 arg0, u8 *arg1) {
    float v;
    s8 i;
    UnkRec40 *rec;

    if (arg1[1] >= 5) {
        return 0;
    }
    rec = D_08978474[arg1[1]];
    rec += *(unsigned short *)(arg1 + 2);
    v = (u32)rec->unk8;
    i = func_0885F068(arg0, arg1);
    if (i < 0) {
        return 0;
    }
    return (u32)(v * D_08979720[i].f + D_08979724[i].f);
}
