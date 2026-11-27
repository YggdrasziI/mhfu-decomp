/* unit_0882E2C0: 0x0882E2C0-0x0882E53C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws entry id of the table D_0899D198 through func_0882C11C, with its
 * colour from D_0893AA5C; in mode 1 draws a white overlay (flag bit 0) or,
 * when k > 0x14, a marker through func_0882BE60 selected by the result of
 * func_0885CD18 and the entry's mask byte.
 * - h is a u16 parameter cast (s16) for func_0882C11C (lh) and passed raw
 *   (lhu straight into t0) to func_0882BE60.
 * - switch: cases compared in reverse source order (10, 5, 1); 1 and 5 one
 *   label group.
 * - k > 0x14 (not k >= 0x15) for the slti at test.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 mask;
    char pad2[2];
    /* 0x4 */ u8 flags;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 col;
    char pad7;
    /* 0x8 */ s16 bit;
    char padA[0xE];
} Entry;

extern Entry D_0899D198[];
extern u8 D_0893AA5C[];
extern u8 D_0893AA5D[];
extern u8 D_0893AA5E[];
extern s32 D_08A62C54;

extern void func_08832B98(char *, s32);
extern s32 func_088303B8(char *, u8, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, s32, s32);
extern u8 func_0885CD18(s32, u8, u16);
extern s32 func_088D7D6C(char *);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_0882E2C0(char *p, u16 id, u16 x, u16 y, u16 k, u16 h, u8 mode, s32 layer) {
    Entry *e;
    s32 v;
    u8 r;
    s32 a;
    s32 b;
    u8 flag;
    s32 m;

    e = &D_0899D198[id];
    if (e->unk5 == 0xFF) {
        return;
    }
    func_08832B98(p, 1);
    v = func_088303B8(p, e->unk5, k < 0x15);
    func_0882C11C(p, x, y, (s16)k, (s16)h, D_0893AA5C[e->col * 4], D_0893AA5D[e->col * 4],
                  D_0893AA5E[e->col * 4], layer, v);
    if (mode == 1) {
        if (e->flags & 1) {
            func_0882C11C(p, x, y, (s16)k, (s16)h, 0xFF, 0xFF, 0xFF, layer, k < 0x15 ? 0xEE : 0x84);
        } else if (k > 0x14) {
            char *q = *(char **)(p + 0x530);
            r = func_0885CD18(D_08A62C54, *(u8 *)(q + 0x4E9), *(u16 *)(q + 0x4EA));
            flag = 0;
            switch (r) {
            case 1:
            case 5:
                a = 2;
                b = 4;
                break;
            case 10:
                a = 4;
                b = 2;
                break;
            default:
                a = 0;
                b = 6;
                break;
            }
            if (e->mask & b) {
                flag = 1;
            } else if (e->mask & a) {
                m = func_088D7D6C(*(char **)(p + 0x530));
                if (!((1 << e->bit) & m)) {
                    flag = 1;
                }
            }
            if (flag) {
                func_0882BE60(p, x, y, k, h, 0xFF, 0, 0, 0x85);
            }
        }
    }
    func_08832B98(p, 0);
}
