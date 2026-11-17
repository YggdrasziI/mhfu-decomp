/* unit_088DBBBC: 0x088DBBBC-0x088DBD98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * NonMatching: the code stays in the assembly piece text_088DBBBC and its jump
 * table (0x0893249C-0x089324BC) in the data piece.
 *
 * func_088DB4C8 is declared with a result here (its unit returns nothing).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    char unk1[0xF];
    u8 unk10;
} Sub30;

extern char *D_089CC438;
extern s32 D_08A62C5C;
extern s32 func_0885187C(char *arg0, s32 arg1, u32 arg);
extern s32 func_08851C3C(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_08851F20(char *, s32);
extern s32 func_08851FEC(char *, s32);
extern s32 func_088520A8(char *, int);
extern s32 func_08866F6C(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_08866FB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_088DB4C8(char *, s32, s32, s32, s32, s32, s32, s32);

/* 96.3 %: the original loads D_089CC438 again for the first call
 * (func_0885187C); ours reuses the copy kept in $s2. Tried: an inline getter
 * for the local or for the calls, a local of another type, the address cast,
 * the pointer computed from the global, a second assignment. */
s32 func_088DBBBC(char *arg0, s32 arg1) {
    char *g = D_089CC438;
    Sub30 *p = (Sub30 *)(g + arg1 * 0x8C + 0x30);
    s32 *st = &((s32 *)(arg0 + 0x24))[arg1];
    s32 state = *st;
    s32 a;
    s32 b;
    s32 c;

    switch (state) {
    case 0:
        if (p->unk0 == 0) {
            return 1;
        }
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = (u16) func_0885187C(D_089CC438, arg1, state);
        b = (u8) func_08851FEC(D_089CC438, arg1);
        c = func_088520A8(D_089CC438, arg1);
        if ((u8) func_088DB4C8(arg0, (u8) arg1, p->unk10, (u8) state, a, b, c, func_08851C3C((s32) g, arg1, state)) == 1) {
            (*st)++;
        }
        break;
    case 6:
        if ((u8) func_08866F6C(D_08A62C5C, (u8) arg1, (u16) func_08851F20(g, arg1)) == 1) {
            (*st)++;
        }
        break;
    case 7:
        if ((u8) func_08866FB0(D_08A62C5C, (u8) arg1, p->unk10, (u8) func_08851FEC(g, arg1)) == 1) {
            *st = 0;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
