/* unit_0883B53C: 0x0883B53C-0x0883B870 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 c[4];
} Rgb;

extern u8 *D_09A0B544;
extern Rgb D_0893AF74[];
extern char *D_08A631A0;
extern char *D_08A631A8;

extern s32 func_0889DFAC(u8 *, s32);
extern u8 func_0889E1BC(u8 *, s32);
extern void func_0882B624(char *, u16, u16, u8, u8, u8, s32, s32);
extern s32 func_0889D7E8(u8 *, u8 *);
extern s32 func_0889D848(u8 *, u8 *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, u8 *);

void func_0883B53C(char *p, s16 x, s16 y, s32 idx, s32 mode) {
    s16 tx;
    s16 ty;
    s32 col;
    s32 off;
    Rgb *c;

    tx = x + 0x48;
    ty = y - 1;
    col = 0;
    if (mode == 0) {
        off = (u8)idx * 200;
        if (D_09A0B544[off + 0x63B] == 5) {
            col = 10;
        } else if ((u8)func_0889DFAC(D_09A0B544, idx) == 1) {
            col = 6;
        }
        switch (D_09A0B544[off + 0x63B]) {
        case 3:
            c = &D_0893AF74[func_0889E1BC(D_09A0B544, idx)];
            if ((s32)(D_09A0B544[off + 0x63A] != 0) == 1) {
                func_0882B624(p, tx, ty, c->c[0], c->c[1], c->c[2], 0x8C, 0);
            } else {
                func_0882B624(p, tx + 7, ty, c->c[0], c->c[1], c->c[2], 0x8B, 0);
            }
            break;
        case 4:
            c = &D_0893AF74[func_0889E1BC(D_09A0B544, idx)];
            if ((s32)(D_09A0B544[off + 0x63A] != 0) == 1) {
                func_0882B624(p, tx, ty, c->c[0], c->c[1], c->c[2], 0x8C, 0);
            } else if (*(s32 *)(D_08A631A0 + 0xF7A554) & 0x10) {
                func_0882B624(p, tx + 7, ty, c->c[0], c->c[1], c->c[2], 0x8B, 0);
            }
            break;
        }
    } else {
        off = (u8)idx * 200;
        if (func_0889D7E8(D_09A0B544, D_09A0B544 + off + 0x57C) != 0) {
            func_0882A9DC(p, tx, ty, 0x1B);
        } else if (func_0889D848(D_09A0B544, D_09A0B544 + off + 0x57C) != 0) {
            func_0882A9DC(p, tx, ty, 0x1EE);
        } else {
            col = 10;
        }
    }
    func_08890DE8(D_08A631A8, 0x10, 0xE);
    func_08890E38(D_08A631A8, col);
    func_088912BC(D_08A631A8, x, y, D_09A0B544 + off + 0x584);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
}
