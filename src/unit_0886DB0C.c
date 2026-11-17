/* unit_0886DB0C: 0x0886DB0C-0x0886DC68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function before code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Entry;

extern char *D_089CC438;
extern s32 D_08A62CB4;

extern s32 func_08851144(char *arg0);
extern void func_0886A4CC(s32, s32, char *);
extern s32 func_0886D524(s32);
extern void func_0886D5E4(s32 arg0, char *arg1, s32 *arg2);
extern s32 func_0886D644(s32 arg0, s16 arg1);
extern s32 func_08874124(s32, s32);

void func_0886DB0C(s32 arg0, Entry *arg1, s32 *arg2) {
    while (1) {
        char *p;
        s32 i;

        if (arg1->unk8 == 0) {
            break;
        }
        if (arg1->unkC != 0) {
            i = 0;
            p = (char *) (arg1->unkC + *(s32 *)(arg0 + 0x50));
            while (1) {
                if (*(s16 *) p == -1) {
                    break;
                }
                func_0886D5E4(arg0, p, arg2);
                func_0886A4CC(arg0, i, p);
                i++;
                if ((u8) func_0886D644(arg0, *(s16 *) p) == 1) {
                    if (func_08851144(D_089CC438) != 0 || func_08874124(D_08A62CB4, *(u16 *)(D_089CC438 + 0x6AF12)) != 1) {
                        *(s16 *)(p + 0x30) = 100;
                    } else {
                        *(s16 *)(p + 0x30) = *(s16 *)(*(char **)(arg0 + 0x4C) + 0x38) * (u16) func_0886D524(arg0) / 100;
                    }
                } else {
                    *(s16 *)(p + 0x30) = 100;
                }
                p += 0x3C;
            }
        }
        arg1++;
    }
}