/* unit_088DBBBC: 0x088DBBBC-0x088DBD98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DBB5C and unit_088DBD98.
 * Its jump table (0x0893249C-0x089324BC) is the unit's `.rodata`.
 *
 * One step of the per-slot sequence at +0x24 (0-7), sending values of the
 * slot's 0x8C-byte record of D_089CC438 (+0x30); returns 1 when the
 * sequence is over or has nothing to do.
 *
 * The original loads D_089CC438 again for the first call of cases 0-5
 * although the copy made at the top is still live. Only a volatile read
 * gives that here; the form of the original source is not known.
 *
 * func_088DB4C8 is declared with a result here (its unit returns nothing).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern s32 D_08A62C5C;

extern s32 func_0885187C(char *, s32, s32);
extern s32 func_08851C3C(char *, s32, s32);
extern s32 func_08851F20(char *, s32);
extern s32 func_08851FEC(char *, s32);
extern s32 func_088520A8(char *, s32);
extern s32 func_08866F6C(s32, u8, u16);
extern s32 func_08866FB0(s32, u8, u8, u8);
extern s32 func_088DB4C8(char *, u8, u8, u8, u16, u8, s32, s32);

typedef struct Group {
    char pad0[0x24];
    s32 state[6];
} Group;

s32 func_088DBBBC(Group *arg0, s32 arg1) {
    char *g = D_089CC438;
    u8 *rec = (u8 *)(g + arg1 * 0x8C + 0x30);
    s32 st = arg0->state[arg1];
    u16 a;
    u8 b;
    s32 c;

    switch (st) {
    case 0:
        if (rec[0] == 0) {
            return 1;
        }
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = func_0885187C(*(char *volatile *) &D_089CC438, arg1, st);
        b = func_08851FEC(D_089CC438, arg1);
        c = func_088520A8(D_089CC438, arg1);
        if ((u8) func_088DB4C8((char *) arg0, arg1, rec[0x10], st, a, b, c, func_08851C3C(g, arg1, st)) == 1) {
            arg0->state[arg1]++;
        }
        break;
    case 6:
        if ((u8) func_08866F6C(D_08A62C5C, arg1, func_08851F20(g, arg1)) == 1) {
            arg0->state[arg1]++;
        }
        break;
    case 7:
        if ((u8) func_08866FB0(D_08A62C5C, arg1, rec[0x10], func_08851FEC(g, arg1)) == 1) {
            arg0->state[arg1] = 0;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
