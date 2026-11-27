/* unit_0881AAA4: 0x0881AAA4-0x0881B384 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0881A8F8 and code still in
 * assembly (func_0881B384). Called by func_088188A8.
 *
 * Optimized for speed: divisions by constants are multiplications.
 *
 * Local declaration order found by a hill-climb (sets the saved registers);
 * the third loop has its own x/y/counter locals. The table read is written
 * inline with its index call, before the call it is multiplied by: a pointer
 * local to the element swaps the mult operands. func_0881B7F0 takes an s32
 * fourth parameter here (s16 in unit_0883A07C), and func_0881B9A0 a u8
 * fourth and s32 fifth (s32, u8 in unit_08838640): each is the only type
 * that orders or masks the arguments as the original.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct Box {
    u8 unk0[6];
    s16 unk6;
    u8 unk8[4];
    u16 x;
    u16 y;
    u16 h;
    s16 unk12;
    void *unk14;
    u8 unk18[0x10];
} Box;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_08A62C54;
extern u16 D_089AC884;
extern u16 D_089AC888;
extern u16 D_089AC8A0[];
extern u16 D_089AC8AA;
extern u16 D_089AC8C4[];
extern u16 D_089AC8C8;
extern u16 D_089AC8CA;
extern u16 D_089AC8CC;
extern u16 D_089AD048;
extern char D_0893854C;
extern char D_08938478;
extern char D_08938548;
extern char D_08938594;
extern char D_0893B018;
extern char D_0893B02C;
extern s16 D_0893B038;
extern u16 D_0893B03A;
extern s32 D_0893B03C;
extern s32 D_0893ABBC[];

extern u8 func_08826F80(char *, int);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern void func_0882FC50(char *, char *, char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_08890DFC(char *, s16, s16);
extern void func_0881B384(char *, s16, s16, char *);
extern void func_08832884(char *, s32, char *);
extern int func_0889134C(char *, char *, ...);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08852E38(char *, u8 *, u32 *, u32 *);
extern u8 func_0885CD18(char *, u8, u16);
extern s32 func_088DADD8(char *);
extern void func_0881B7F0(char *, char *, char *, s32, s16, s16);
extern void func_0881B408(char *, char *, s32);
extern void func_0881B5C4(char *, char *, s16, s16);
extern s32 func_0882774C(char *, char *);
extern void func_0881B9A0(char *, s16, s16, u8, s32, s32, u8);

void func_0881AAA4(char *arg0, char *arg1, u8 arg2) {
    u8 lvl;
    Box box;
    u32 a; /* filled by func_08852E38 */
    u32 b;
    char text[0x40];
    u8 n;
    u8 sel;
    s16 top;
    u32 i;
    s16 x;
    s16 y;
    u16 *p;
    s32 xx;
    s32 d;
    char *g;
    s16 cx;
    s16 cy;
    u32 k;

    sel = 1;
    n = func_08826F80(arg0, 9) + 2;
    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC884));
    func_0882FA24(&box, &D_0893B018, text, 0, 0);
    switch (arg2) {
    case 0:
        box.unk6 = 0xE0;
        box.unk12 = 0xB;
        box.unk14 = &D_089AC888;
        sel = 0;
        break;
    }
    func_0882F580(arg0, &box, text, -1, 0xFF, 0);
    func_0882FB38(arg0, &box, arg2, n, 0, 0);
    func_0882FC50(arg0, &D_0893B02C, func_0885151C(D_089CC438, D_089AC8C4[sel]), 0xFF);
    top = D_0893B03A + D_0893B03C;
    switch (arg2) {
    case 0:
        func_08890E38(D_08A631A8, 5);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        y = box.y;
        x = box.x + 0x38;
        for (i = 7; i != 0; i--) {
            func_08891474(D_08A631A8, x, y, func_0885151C(D_089CC438, D_089AC8AA));
            y += box.h;
        }
        xx = x + 4;
        for (i = 4; i != 0; i--) {
            func_08891474(D_08A631A8, xx, y, func_0885151C(D_089CC438, D_089AC8AA));
            y += box.h;
        }
        cx = box.x + 0x7C;
        cy = box.y + box.h * 7;
        for (k = 0, p = D_089AC8A0; k < 5; k++, cy += box.h, p++) {
            func_08891474(D_08A631A8, cx, cy, func_0885151C(D_089CC438, *p));
            func_08891474(D_08A631A8, cx + 0x46, cy, func_0885151C(D_089CC438, D_089AC8AA));
        }
        func_08890E38(D_08A631A8, 0);
        x = box.x + 0x46;
        func_0881B384(arg0, x, box.y + box.h, arg1 + 0x4E8);
        func_08890DFC(D_08A631A8, x, box.y + box.h * 6);
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
            func_08832884(arg0, *(s8 *)(arg0 + 0x536), text);
            func_0889134C(D_08A631A8, &D_08938478, text);
        } else {
            func_0889134C(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AD048));
        }
        func_08890DE8(D_08A631A8, 0x10, 0xE);
        func_088912BC(D_08A631A8, x, box.y, D_089CC438 + 0x4A0);
        g = D_089CC438;
        func_08891474(D_08A631A8, x, box.y + box.h * 2, func_0885151C(g, D_089AC8CA), *(s32 *)(g + 0x696F0));
        func_08852E38(D_089CC438, &lvl, &a, &b);
        func_08891474(D_08A631A8, x, box.y + box.h * 3, &D_08938548, lvl);
        func_08890DFC(D_08A631A8, x, box.y + box.h * 4);
        d = b - a;
        if (d < 0) {
            func_0889134C(D_08A631A8, &D_08938548, a);
        } else {
            func_0889134C(D_08A631A8, func_0885151C(D_089CC438, D_089AC8C8), a, d);
        }
        g = D_089CC438;
        func_08891474(D_08A631A8, x, box.y + box.h * 5, func_0885151C(g, D_089AC8CC), *(s32 *)(g + 0x696E8));
        xx = x + 4;
        func_08891474(D_08A631A8, xx, box.y + box.h * 7, &D_08938594, *(s16 *)(arg1 + 0x41E));
        func_08891474(D_08A631A8, xx, box.y + box.h * 8, &D_08938594, *(s16 *)(arg1 + 0x62E) / 3);
        func_08891474(D_08A631A8, xx, box.y + box.h * 9, &D_08938594, (u16)(D_0893ABBC[func_0885CD18(D_08A62C54, *(u8 *)(arg1 + 0x4E9), *(u16 *)(arg1 + 0x4EA))] * (u16)func_088DADD8(arg1) / 100));
        func_08891474(D_08A631A8, xx, box.y + box.h * 10, &D_08938594, *(u16 *)(arg1 + 0x422));
        x = box.x + 0xC9;
        func_08891474(D_08A631A8, x, box.y + box.h * 7, &D_08938594, (s16)*(f32 *)(arg1 + 0x39C));
        func_08891474(D_08A631A8, x, box.y + box.h * 8, &D_08938594, (s16)*(f32 *)(arg1 + 0x3A0));
        func_08891474(D_08A631A8, x, box.y + box.h * 9, &D_08938594, (s16)*(f32 *)(arg1 + 0x3A4));
        func_08891474(D_08A631A8, x, box.y + box.h * 10, &D_08938594, (s16)*(f32 *)(arg1 + 0x3AC));
        func_08891474(D_08A631A8, x, box.y + box.h * 11, &D_08938594, (s16)*(f32 *)(arg1 + 0x3A8));
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_0881B7F0(arg0, D_089CC438 + 0x69942, arg1 + 0x4E8, D_0893B038, top, D_0893B03C);
        break;
    case 1:
        func_0881B408(arg0, arg1, 0);
        func_0881B5C4(arg0, arg1, D_0893B038, top);
        break;
    default:
        func_0881B9A0(arg0, box.x, box.y, arg2 - 2, func_0882774C(arg0, arg1), 9, 0xFF);
        func_0881B5C4(arg0, arg1, D_0893B038, top);
        break;
    }
}
