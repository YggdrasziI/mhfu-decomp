/* unit_0882545C: 0x0882545C-0x08825ADC (ULES01213)
 *
 * Bounds (hypothesis): 1 function (grid of item slots with a selection
 * cursor and its caption) between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    s16 count;
} Slot;

typedef struct {
    char pad[0x390];
    Slot slots[32];
} Game;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09A44C5C;
extern u16 D_089B5574;
extern char *D_08A62CB4;
extern u16 D_089AD054;
extern u16 D_089AD056;
extern u16 D_089AC85A;
extern u16 D_089AC85C;
extern u16 D_089AC85E;
extern u8 D_0899D198[][24];
extern u8 D_0899D19B[][24];
extern s32 D_0899D1A8[][6];
extern u8 D_0893AA5C[][4];
extern char D_08938668[];

extern char *func_088DCEBC(s32, u8);
extern int func_08879158(char *);
extern int func_088790F4(char *);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern char *func_09A63198(s32, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08832B98(char *, s32);
extern s32 func_088303B8(char *, u8, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);
extern char *func_08851528(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern char *func_0885151C(char *, u16);
extern void func_0887D02C(s32, s32, char *, s32);

void func_0882545C(char *arg0, s16 sel, u8 dark, s8 hint) {
    u8 alpha;
    s32 cols;
    Slot *slot;
    u8 *col;
    s32 c2;
    char buf[0x30];
    s32 x;
    s32 y;
    s32 rows;
    u8 *e;
    s16 yy2;
    s32 flag;
    s32 r;
    s8 b;
    u16 id2;
    s8 a;
    char *s;
    s16 xx;
    s32 r2;
    s16 yy;
    s32 n;
    u16 id;
    s32 cur;

    func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (*(u8 *)(arg0 + 0x1218) == 0) {
        x = 0xE8;
        y = 0x2C;
        cols = 8;
        rows = 4;
    } else {
        x = 0xE8;
        y = 0x5C;
        cols = 8;
        rows = 2;
    }
    cur = sel;
    if (cur < 0 && func_08879158(D_08A62CB4) == 0) {
        return;
    }
    flag = dark;
    alpha = flag == 0 ? 0xFF : 0x60;
    if (*(u8 *)(arg0 + 0x1218) == 0) {
        func_0882DCA0(arg0, 0xD8, 0x1C, 0x100, 0xB0, 0xFF);
    } else {
        func_0882DCA0(arg0, 0xD8, 0x38, 0x100, 0x94, 0xFF);
        func_0882BE60(D_089CBBEC, x - 1, y - 0x1D, 0x18, 0x18, 0xFF, 0xFF, 0xFF, 0xEF);
        func_08890E38(D_08A631A8, 0);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_088920A8(D_08A631A8, x + 0x1C, y - 0x18,
                      func_09A63198(D_09A44C5C, D_089B5574), D_089CC438 + 0x6A210);
    }
    yy = y;
    for (r2 = rows; r2 > 0; r2--) {
        xx = x;
        for (c2 = cols; c2 > 0; c2--) {
            func_0882D6F0(arg0, xx, yy, 0x16, 0x16, 0, 0, 0);
            xx += 0x1C;
        }
        yy += 0x18;
    }
    func_08832B98(arg0, 1);
    yy2 = y;
    n = 0;
    for (r = 0; r < rows; r++, yy2 += 0x18) {
        xx = x;
        for (c2 = 0; c2 < cols; c2++, xx += 0x1C) {
            id = *(u16 *)(D_089CC438 + n * 4 + 0x390);
            if (id != 0) {
                e = D_0899D198[id];
                if (e[5] != 0xFF) {
                    col = D_0893AA5C[e[6]];
                    func_0882C11C(arg0, xx, yy2, 0x16, 0x16, col[0], col[1], col[2], alpha,
                                  func_088303B8(arg0, e[5], 1));
                }
            }
            n++;
        }
    }
    if (flag == 0) {
        b = 0;
        a = 5;
    } else {
        b = a = 10;
    }
    if (cur >= 0) {
        func_0882C11C(arg0, (s16)(x - 2 + (cur % cols) * 0x1C), (s16)(y - 2 + (cur / cols) * 0x18),
                      0x1A, 0x1A, 0xFF, 0xFF, 0xFF, alpha, 0x49);
        slot = &((Game *)D_089CC438)->slots[sel];
        id = slot->id;
        if (id == 0) {
            func_0880E8F0(buf, func_08851528(D_089CC438, 0));
        } else {
            s = func_0885151C(D_089CC438, D_089AD054);
            func_0880E8F0(buf, D_08938668, a, s, b, slot->count * D_0899D1A8[id][0]);
            func_0887D02C(0x1C8, 0xA4, buf, 0xE);
            id2 = slot->id;
            switch (D_0899D19B[id2][0]) {
            case 1:
                func_0880E8F0(buf, func_08851528(D_089CC438, id2));
                break;
            case 0xFF:
                s = func_0885151C(D_089CC438, D_089AC85A);
                func_0880E8F0(buf, s, func_08851528(D_089CC438, id2));
                break;
            default:
                s = func_0885151C(D_089CC438, D_089AC85C);
                func_0880E8F0(buf, s, func_08851528(D_089CC438, id2), slot->count);
                break;
            }
        }
        func_08890E38(D_08A631A8, b);
        func_0887D02C(0x1C8, 0x94, buf, 0xE);
        if (hint >= 0) {
            func_08890E38(D_08A631A8, flag == 0 ? 2 : 0xD);
            func_0887D02C(0x1C8, 0xB4, func_0885151C(D_089CC438, D_089AC85E), 0xE);
        }
    } else {
        s = func_0885151C(D_089CC438, D_089AD056);
        func_0880E8F0(buf, D_08938668, a, s, b, func_088790F4(D_08A62CB4));
        func_0887D02C(0x1C8, 0xA4, buf, 0xE);
    }
    func_08832B98(arg0, 0);
}
