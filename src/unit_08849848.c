/* unit_08849848: 0x08849848-0x08849B6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 w;
    /* 0x06 */ u16 h;
    /* 0x08 */ u8 b8;
    /* 0x09 */ u8 b9;
    /* 0x0A */ u8 bA;
    /* 0x0B */ u8 bB;
    /* 0x0C */ u16 hC;
    /* 0x0E */ u16 hE;
    /* 0x10 */ u16 h10;
    /* 0x12 */ u16 h12;
    /* 0x14 */ char *w14;
    /* 0x18 */ s32 w18;
    /* 0x1C */ u16 h1C;
    /* 0x1E */ u16 h1E;
    /* 0x20 */ u16 h20;
    /* 0x22 */ u16 h22;
    /* 0x24 */ u16 h24;
    /* 0x26 */ u16 h26;
} Box;

extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A44C5C;
extern char D_0893AFC8;
extern char D_0893B758;
extern char D_0893B650[];
extern char D_089B54F8[];
extern u16 D_089B54F2;
extern u16 D_089B551C[][3];
extern u16 D_089B5554;

extern void func_0882FA24(Box *, char *, s32, s32, s32);
extern char *func_09A63198(s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern s32 func_08890E48(char *, char *);
extern s32 func_08890F70(char *, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_0882E604(char *, u16, u16, u16, u8, u8, u8, u8);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_08849848(char *arg0) {
    Box box;
    char buf[0x20];
    s16 y;
    s32 i;
    s16 w;
    s16 x;
    u32 phase;
    float ang;
    float s;
    u8 a;
    u8 b;

    func_0882FA24(&box, &D_0893AFC8, 1, 0, 0);
    box.w14 = D_089B54F8 + *(u8 *)(arg0 + 0x5DC) * 18;
    func_0880E8F0(buf, &D_0893B758, func_09A63198(D_09A44C5C, D_089B54F2));
    func_0882F580(arg0, &box, buf, -1, 0xFF, 4);
    func_08890E38(D_08A631A8, 5);
    y = (s16)box.hE;
    for (i = 0; i < 9; i++, y += (s16)box.h10) {
        if (*(u8 *)(arg0 + 0x5DC) == 0 || i != 1) {
            u8 *p = (u8 *)(arg0 + 0x5DC + i);
            w = func_08890E48(D_08A631A8, func_09A63198(D_09A44C5C, D_089B551C[i][*p]));
            x = box.x + 0xAC - ((w * 7) >> 1);
            func_08891474(D_08A631A8, x, y, D_0893B650, func_09A63198(D_09A44C5C, D_089B551C[i][*p]));
        } else {
            w = func_08890F70(D_08A631A8, func_09A63198(D_09A44C5C, D_089B5554));
            x = box.x + 0xAC - ((w * 7) >> 1);
            func_088920A8(D_08A631A8, x, y, D_0893B650, func_09A63198(D_09A44C5C, D_089B5554));
        }
    }
    if (*(u8 *)(arg0 + 0x5DC) == 0 || *(u8 *)(arg0 + 0x57F) != 1) {
        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        s = sin_vfpu(ang);
        a = 0x20;
        b = (s8)(48.0f * s) + 0xAF;
    } else {
        b = 0x70;
        a = b;
    }
    func_0882E604(arg0, box.hC + 0x7A, box.hE + box.h10 * *(u8 *)(arg0 + 0x57F), 0x46, a, b, a, 0xF0);
}
