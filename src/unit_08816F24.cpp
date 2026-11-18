/* unit_08816F24: 0x08816F24-0x088172D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08816BE4 and text_088172D8).
 *
 * C++: the flag test keeps its `sltu` (bool). Optimized for speed.
 *
 * The cast in `(s32) (a + 1) - b` sets the operand order of the `subu`.
 * `idx` is an `s32`, which gives the `andi` when it is passed as a `u8`.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    s16 y;
    u16 h;
    u8 unk12[2];
    u8 *icon;
    s32 color;
    u16 w1C;
    u16 w1E;
    u16 w20;
    u16 w22;
    u8 unk24[4];
} Box;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A8;
extern u8 D_089AC5D8[][8];
extern u16 D_089AC588[];
extern u16 D_0893B164;
extern u16 D_0893B166;
extern s32 D_0893B168;
extern char D_08938478;
extern char D_0893AFDC;
extern char D_0893AFF0;
extern char D_0893B004;
extern char D_0893B0E0;

extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern s32 func_08829928(char *);
extern s32 func_08829A48(char *, u16);
extern u16 *func_08856884(char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_0882F9A8(char *, char *, char *, s32, s32, s32);
extern void func_08829B58(char *, s32);
extern void func_08832E34(char *, s32, s32, s32, s32, s32);
extern void func_088197A0(char *, u8, s32, s32, s32);
extern void func_0882F4A4(char *, u16, u16, u16, u16, s32);

void func_08816F24(char *arg0) {
    Box box;
    Box box2;
    s32 color;
    s32 flags;
    s32 kind;
    s32 idx;

    idx = *(u8 *)(arg0 + 0x586);
    flags = 0;
    func_0882FA24(&box, &D_0893AFDC, 0, 0, 0);
    if ((bool) (*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 4) == 1) {
        kind = 0;
        if ((u8) func_08829928(arg0) != 1) {
            kind = 1;
        }
        if ((u8) func_08829A48(arg0, *func_08856884(D_089CC438, *(u8 *)(arg0 + 0x586))) != 1) {
            kind += 2;
        }
    } else {
        kind = 4;
    }
    box.icon = D_089AC5D8[kind];
    switch (*(u8 *)(arg0 + 0x585)) {
    case 0:
        if (*(s32 *)(arg0 + 0x528) & 0x10) {
            flags = 0x20;
            color = 0;
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            func_088920A8(D_08A631A8, D_0893B164 + 0x62, D_0893B166 + D_0893B168 * 2, &D_08938478,
                          func_0885151C(D_089CC438, D_089AC588[*(u8 *)(arg0 + 0x537)]));
        } else {
            if (*(s32 *)(arg0 + 0x528) & 0x20) {
                flags = 0x10;
            } else {
                flags = 0x50;
            }
            color = 0x8000C040;
        }
        break;
    case 1:
        func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x588), 0xFF, 0);
        color = 0x80808080;
        break;
    case 2:
    case 3:
        color = 0xCC808080;
        switch (*(u8 *)(arg0 + 0x588)) {
        case 0:
            box.color = 0x80808080;
            func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x588), 0xFF, 0);
            func_0882F9A8(arg0, &D_0893AFF0, 0, *(u8 *)(arg0 + 0x537), 0xFF, 0);
            break;
        case 1:
            func_08829B58(arg0, 0);
            break;
        case 2:
            switch (*(u8 *)(arg0 + 0x589)) {
            case 1:
                func_0882F9A8(arg0, &D_0893B004, 0, *(u8 *)(arg0 + 0x537), 0xFF, 0);
                break;
            case 0:
                func_08832E34(arg0, 0xF0, 0x68, *(u8 *)(arg0 + 0x58A),
                              (s32) (*(u8 *)(arg0 + 0x58A) + 1) - *(u8 *)(arg0 + 0x58B), 0);
                break;
            }
            break;
        case 3:
            box.color = 0x80808080;
            func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x588), 0xFF, 0);
            idx = *(u8 *)(arg0 + 0x595);
            color = 0x8000C040;
            flags = 0x90;
            break;
        }
        break;
    }
    func_088197A0(arg0, idx, color, flags, 0);
    if (flags & 0x80) {
        idx = (u8) (*(u8 *)(arg0 + 0x586) >> 3);
        if (idx == (u32) *(u8 *)(arg0 + 0x595) >> 3) {
            func_0882FA24(&box2, &D_0893B0E0, (char *) 1, 0, 0);
            func_0882F4A4(arg0, box2.w1C, box2.w1E + box2.h * (*(u8 *)(arg0 + 0x586) - idx * 8), box2.w20,
                          box2.w22, 0x400000);
        }
    }
}

}
