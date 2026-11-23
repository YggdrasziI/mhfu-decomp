/* unit_0886DD3C: 0x0886DD3C-0x0886DE78 (ULES01213)
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

extern char *func_088697D4(char *, u16, s32, s8);

char *func_0886DD3C(char *arg0, char *arg1) {
    s32 i;
    char *a;
    char *p;
    Entry *e;

    for (i = 0; i <= *(s8 *)(arg0 + 0x20); i++) {
        a = func_088697D4(arg0, *(u16 *)(arg1 + 0x29A), 0, i);
        p = func_088697D4(arg0, *(u16 *)(arg1 + 0x29A), 1, i);
        if (a != 0) {
            while (1) {
                if (*(s16 *)p < 0) {
                    break;
                }
                if (*(u16 *)(arg1 + 0x1E6) == *(s8 *)(p + 0x34)) {
                    if (*(s16 *)(arg1 + 0x4AC) == *(s16 *)(p + 0x2C)) {
                        return p;
                    }
                }
                p += 0x3C;
            }
        }
    }
    e = *(Entry **)(arg0 + 0x71C);
    while (e->unk8 != 0) {
        if (e->unkC != 0) {
            p = (char *)(e->unkC + *(s32 *)(arg0 + 0x50));
            while (*(s16 *)p != -1) {
                if (*(s16 *)(arg1 + 0x4AC) == *(s16 *)(p + 0x2C)) {
                    return p;
                }
                p += 0x3C;
            }
        }
        e++;
    }
    return 0;
}
