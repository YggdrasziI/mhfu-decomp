/* unit_0883488C: 0x0883488C-0x08834B0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08834730 and code still in
 * assembly (text_08834B0C).
 *
 * C++: flag tests keep their `sltu` (bool). Optimized for speed: the division
 * by 7 is a multiplication.
 *
 * func_088915B0 is variadic (it stores $t1-$t3). Its second parameter is
 * declared s32 here (with s16 the `lb` of the mark is scheduled one load
 * earlier) and s16 in unit_08832C60 (with s32 that unit's last argument load
 * moves): the real type is not settled. Its fourth parameter is s32 here and
 * s8 in unit_08818C94, for the same reason.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    u16 y;
    u16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_089AC850;
extern char D_0893B218;
extern char D_0893AFA0;
extern char D_0893B220;
extern u16 D_09B051A0[];
extern u16 D_09B051AE[];

extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern s32 func_08838AB4(s32, u8, u8);
extern char *func_09A7B790(s32, u16);
extern int func_088915B0(char *, s32, s16, s32, char *, ...);

void func_0883488C(char *arg0, s32 arg1) {
    Box box;
    s8 marks[8];
    char text[0x20];
    s32 q;
    s32 r;
    u16 *ids;
    s32 i;
    s8 *m;
    s32 n;

    n = *(u8 *)(arg0 + 0x111C);
    q = (u8) (n / 7);
    r = (u8) (n % 7);
    func_0880E8F0(text, &D_0893B218, func_0885151C(D_089CC438, D_089AC850));
    func_0882FA24(&box, &D_0893AFA0, text, 0, 0);
    if ((s8) arg1 != 0) {
        box.color = 0x80808080;
    }
    func_0882F580(arg0, &box, text, (u8) r, 0xFF, 1);
    func_0882FB38(arg0, &box, (u8) q, 2, 0, arg1);
    marks[6] = 0;
    marks[5] = 0;
    marks[4] = 0;
    marks[3] = 0;
    marks[2] = 0;
    marks[1] = 0;
    marks[0] = 0;
    if ((u8) q == 0) {
        ids = D_09B051A0;
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
            marks[3] = 10;
            marks[4] = 10;
            marks[6] = 10;
        }
        if ((bool) (*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 8) == 1) {
            marks[1] = 10;
        }
    } else {
        ids = D_09B051AE;
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
            marks[4] = 10;
            marks[5] = 10;
        } else {
            char *p = *(char **)(arg0 + 0x530);
            if ((u8) func_08838AB4((s32) arg0, p[0x298], p[0x299]) == 1) {
                marks[5] = 10;
            }
            if ((bool) (*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 8) == 1) {
                marks[5] = 10;
            }
        }
        marks[6] = 10;
    }
    for (i = 0, m = marks; i < 7; i++, ids++, m++) {
        char *s = func_09A7B790(D_09B22D70, *ids);
        func_088915B0(D_08A631A8, box.x, (s16) (box.y + i * box.h), *m, &D_0893B220, s);
    }
}

}
