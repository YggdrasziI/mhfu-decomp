/* unit_0883A758: 0x0883A758-0x0883A8A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
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
    s16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

extern char *D_089CC438;
extern char *D_09A0B544;
extern char *D_08A631A8;
extern char *D_0893AF70;
extern char D_0893B3D4;

extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern s32 func_0883B498(char *, u16);
extern void func_0883B53C(char *, s16, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s16, s32, char *, ...);

void func_0883A758(char *p, s32 a, s32 b, s32 c, s32 e) {
    Box box;
    s32 sel;
    s32 i;

    func_0882FA24(&box, &D_0893B3D4, 0, a, b);
    func_0882F580(p, &box, 0, (s8)c, 0xFF, 0);
    sel = func_0883B498(p, *(u8 *)(D_089CC438 + 0x28));
    b = box.y;
    for (i = 0; i < *(s8 *)(D_09A0B544 + 0xEE3); i++) {
        if (sel != i) {
            func_0883B53C(p, box.x, b, i, e);
            b = (s16)(b + box.h);
        }
    }
    func_08890E38(D_08A631A8, 0);
    for (; i < 4; i++) {
        func_08891474(D_08A631A8, box.x, b, D_0893AF70);
        b = (s16)(b + box.h);
    }
}
