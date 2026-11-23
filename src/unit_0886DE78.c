/* unit_0886DE78: 0x0886DE78-0x0886DFAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned short u16;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Entry;

extern char *func_088697D4(char *, s32, s32, s8);

char *func_0886DE78(char *arg0, s32 arg1, s32 arg2) {
    s32 i;
    char *p;
    Entry *e;

    for (i = 0; i <= *(s8 *)(arg0 + 0x20); i++) {
        char *q = func_088697D4(arg0, arg2, 0, i);
        p = func_088697D4(arg0, arg2, 1, i);
        if (q != 0) {
            for (;;) {
                if (*(s16 *)p < 0) {
                    break;
                }
                if ((s16)arg1 == *(s16 *)(p + 0x2C)) {
                    return p;
                }
                p += 0x3C;
            }
        }
    }
    for (e = *(Entry **)(arg0 + 0x71C); e->unk8 != 0; e++) {
        if (e->unkC != 0) {
            p = (char *)e->unkC + *(s32 *)(arg0 + 0x50);
            while (*(s16 *)p != -1) {
                if ((s16)arg1 == *(s16 *)(p + 0x2C)) {
                    return p;
                }
                p += 0x3C;
            }
        }
    }
    return 0;
}
