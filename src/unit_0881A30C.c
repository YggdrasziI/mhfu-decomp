/* unit_0881A30C: 0x0881A30C-0x0881A7A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, called by func_088180CC.
 *
 * Optimized for speed: the 8-row loop is tested at the bottom without a
 * guard. Two Boxes; the first lists up to 8 ids, the second draws the
 * fields of the record at 0x5A8.
 *
 * The two strings kept across the last calls live in a local array (the
 * original keeps them on the stack). func_088920A8 takes `s32` coordinates
 * here (an `s16` prototype loads its first argument too early).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    u16 x;
    u16 y;
    u16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[8];
    s16 tx;
    s16 ty;
} Box;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C50;
extern u16 D_089AC608;
extern u16 D_089AC83A;
extern u16 D_089AC630[];
extern u16 D_089AC620[];
extern s8 D_0893AF2C[];
extern char D_0893854C;
extern char D_0893B0A4;
extern char D_0893B0B8;
extern char D_08938580;
extern char D_08938478;

extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, s32, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_088920A8(char *, s32, s32, char *, s32);
extern u8 func_0885B718(char *, char *, s32, s32);
extern char *func_08825104(char *, char *);

void func_0881A30C(char *arg0) {
    Box b2;
    Box b1;
    char text[0x20];
    char *ss[2];
    s16 x2;
    s16 y;
    u16 *p;
    s32 i;
    s8 c;
    char *s;
    u16 v;
    char *rec;
    s8 c0;
    s8 c3;
    s8 c1;
    s8 c4;
    s8 c2;
    char *t0;
    char *t2;
    char *t1;

    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC608));
    func_0882FA24(&b1, &D_0893B0A4, 1, 0, 0);
    if (*(char **)(arg0 + 0x5A8) == 0) {
        return;
    }
    func_0882F580(arg0, &b1, text, *(s8 *)(arg0 + 0x5C3), 0xFF, 0);
    func_0882FB38(arg0, &b1, *(u8 *)(arg0 + 0x5C4), *(u8 *)(arg0 + 0x5C5), 0, 0);
    for (y = b1.y, p = (u16 *)(arg0 + 0x5C8), i = 0; i < 8; i++, y += b1.h, p++) {
        v = *p;
        if (v == 0) {
            break;
        }
        if (!(v & 0x4000)) {
            c = (v & 0x8000) ? 2 : 0;
            s = func_08851528(D_089CC438, v & 0x3FFF);
        } else {
            c = 10;
            s = func_0885151C(D_089CC438, D_089AC83A);
        }
        func_088915B0(D_08A631A8, b1.x, y, c, &D_08938478, s);
    }
    func_0882FA24(&b2, &D_0893B0B8, 1, 0, 0);
    func_0882F580(arg0, &b2, &D_08938580, -1, 0xFF, 0);
    func_088920A8(D_08A631A8, b2.tx, b2.ty,
                  func_0885151C(D_089CC438, D_089AC630[(*(u8 *)(*(char **)(arg0 + 0x5A8) + 7) & 1) ? 2 : 0]),
                  *(u8 *)(arg0 + 0x5BB) + 1);
    if (func_0885B718(D_08A62C50, *(char **)(arg0 + 0x5A8), 1, 0) == 1) {
        c0 = c1 = c3 = (s8)(c2 = 0);
        rec = *(char **)(arg0 + 0x5A8);
        c4 = D_0893AF2C[*(s8 *)(rec + 4)];
        t0 = func_08851528(D_089CC438, *(u16 *)(rec + 2));
        t1 = func_08851528(D_089CC438, *(u16 *)(arg0 + 0x5AC));
        t2 = func_08851528(D_089CC438, *(u16 *)(arg0 + 0x5AE));
        ss[1] = func_0885151C(D_089CC438, D_089AC620[*(s8 *)(*(char **)(arg0 + 0x5A8) + 4)]);
        ss[0] = func_08825104(arg0, *(char **)(arg0 + 0x5A8));
    } else {
        c0 = c1 = c3 = c4 = c2 = 10;
        t0 = t1 = t2 = ss[1] = ss[0] = func_0885151C(D_089CC438, D_089AC83A);
        if (!(*(u8 *)(*(char **)(arg0 + 0x5A8) + 7) & 4)) {
            c1 = 0;
            t1 = func_08851528(D_089CC438, *(u16 *)(arg0 + 0x5AC));
        }
        if (!(*(u8 *)(*(char **)(arg0 + 0x5A8) + 7) & 8)) {
            c3 = 0;
            t2 = func_08851528(D_089CC438, *(u16 *)(arg0 + 0x5AE));
        }
    }
    func_088915B0(D_08A631A8, b2.x, b2.y + b2.h, c0, &D_08938478, t0);
    func_088915B0(D_08A631A8, b2.x, b2.y + b2.h * 3, c1, &D_08938478, t1);
    func_088915B0(D_08A631A8, b2.x, b2.y + b2.h * 4, c3, &D_08938478, t2);
    x2 = b2.x + 0x46;
    func_088915B0(D_08A631A8, x2, b2.y + b2.h * 5, c4, &D_08938478, ss[1]);
    func_088915B0(D_08A631A8, x2, b2.y + b2.h * 6, c2, &D_08938478, ss[0]);
}
