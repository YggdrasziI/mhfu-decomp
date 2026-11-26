/* unit_08821080: 0x08821080-0x088213E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Needs the speed setting (float constant 0.2f built with lui/ori).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 r, g, b, a;
} Color;

typedef union {
    u32 w;
    Color c;
} ColorU;

extern char *D_08A62C54;
extern char *D_08A631A8;
extern u8 D_08978488[];
extern s16 *D_0897923C[];
extern u8 D_0893AC9C[];
extern s16 D_08939A54[];
extern s16 D_08939A40;
extern char D_089385D8[];

extern char *func_0885CA50(char *, char *);
extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, char *);
extern s32 func_088213E4(char *, s32, s32);
extern void func_08821924(char *, s32);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern void func_0882D6F0(char *, u16, u16, u16, u16, u8, u8, u8);
extern void func_0882B624(char *, u16, u16, u8, u8, u8, s32, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_08821080(char *arg0, s32 arg1, char *arg2, s16 arg3, s16 arg4) {
    char *e;
    s32 n;
    s32 r;
    ColorU col;
    s32 a;
    s32 b;
    s16 v;
    s16 x;
    s32 x0;
    s16 w;
    s16 *t;
    u8 *c;
    s16 *p;
    u16 y;
    s32 i;
    s16 j;
    u8 cg;
    u8 cb;
    u16 yy;

    if (*(u8 *)(arg2 + 1) == 5) {
        e = func_0885CA50(D_08A62C54, arg2);
        n = *(u8 *)(e + 9);
        func_08821890(arg0, arg1);
        func_08821A10(arg0, arg1, arg2);
        r = func_088213E4(arg0, arg1, n);
        func_08821924(arg0, arg1);
        if (r == n) {
            col.w = 0xFF968A63;
        } else {
            if (n < r) {
                col.w = 0xFF57FFFF;
                a = 4;
                b = 1;
            } else {
                col.w = 0xFFFF435D;
                a = 2;
                b = -1;
            }
            func_088915B0(D_08A631A8, arg3 + 100, arg4 + 1, a, D_089385D8, b);
        }
        c = D_0893AC9C;
        p = D_0897923C[D_08978488[*(u16 *)e]];
        p += *(u8 *)(e + 8) * 7;
        x0 = arg3;
        x = x0 + 4;
        i = 7;
        y = (s16)(arg4 + 5);
        j = 0;
        for (; i > 0; i--) {
            v = *p * 0.2f;
            if (j < v) {
                func_0882D6F0(arg0, x + j, y, v - j, 6, c[2], c[1], c[0]);
                j = v;
            }
            p++;
            c += 4;
        }
        if (r < 6) {
            w = (r * 50 + 150) * 0.2f;
            func_0882D6F0(arg0, x + w, y, 90 - w, 6, 0, 0, 0);
        }
        yy = arg4;
        t = (s16 *)(s32)D_08939A54;
        cg = col.c.g;
        cb = col.c.b;
        func_0882B624(arg0, arg3, yy, cb, cg, col.c.r, 0xB7, 0);
        func_0882BE60(arg0, x0 + D_08939A40, yy, 98 - t[2] - D_08939A40, 16, cb, cg, col.c.r, 0xB8);
        func_0882B624(arg0, x0 + 98 - t[2], yy, cb, cg, col.c.r, 0xB9, 0);
    }
}
