/* unit_0886DC68: 0x0886DC68-0x0886DD3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886DC68 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Ent;

extern char *D_089CC438;
extern void func_0886D5E4(char *arg0, char *arg1, s32 arg2);

void func_0886DC68(char *arg0, Ent **arg1, s32 arg2) {
    char *p;
    Ent *e;

    for (;;) {
        if (*arg1 == 0) {
            break;
        }
        if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
            e = *arg1;
        } else {
            e = (Ent *)((char *)*arg1 + *(s32 *)(arg0 + 0x50));
        }
        for (;;) {
            if (e->unk8 == 0) {
                break;
            }
            if (e->unkC != 0) {
                p = (char *)e->unkC + *(s32 *)(arg0 + 0x50);
                for (;;) {
                    if (*(s16 *)p == -1) {
                        break;
                    }
                    func_0886D5E4(arg0, p, arg2);
                    *(s16 *)(p + 0x30) = 100;
                    p += 0x3C;
                }
            }
            e++;
        }
        arg1++;
    }
}
