/* unit_0887370C: 0x0887370C-0x08873838 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0x56C - 0x54];
    u32 flags[1];
} Obj;

extern char *D_089CC438;

static inline u8 func_test(Obj *o, s32 bit) {
    return (o->flags[bit / 32] & (1 << (bit % 32))) != 0;
}

void func_0887370C(Obj *arg0, char **arg1, u16 *arg2) {
    char *q;
    char *p;

    while (1) {
        p = *arg1;
        if (p == 0) {
            return;
        }
        if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
            p = *arg1;
        } else {
            p = *arg1 + arg0->unk50;
        }
        while (1) {
            if (*(s32 *)(p + 8) == 0) {
                break;
            }
            if (*(s32 *)(p + 0xC) != 0) {
                q = *(char **)(p + 0xC) + arg0->unk50;
                while (1) {
                    if (*(s16 *)q == -1) {
                        break;
                    }
                    if (!func_test(arg0, *(s16 *)(q + 0x2C))) {
                        arg2[*(s16 *)q] += *(s8 *)(q + 4);
                        arg0->flags[*(s16 *)(q + 0x2C) / 32] |= 1 << (*(s16 *)(q + 0x2C) % 32);
                    }
                    q += 0x3C;
                }
            }
            p += 0x10;
        }
        arg1++;
    }
}
