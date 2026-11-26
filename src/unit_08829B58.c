/* unit_08829B58: 0x08829B58-0x08829E6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[6];
    s16 unk6;
    u8 unk8[4];
    s16 x;
    s16 y;
    s16 h;
    u16 n;
    u8 unk14[0x14];
} Box;

extern char *D_089CC438;
extern char *D_09A0B544;
extern char *D_08A631A8;
extern char *D_0893AF70;
extern char D_089386C0;
extern char D_089386D4;

extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern int func_0882A8B8(char *, s32);
extern char *func_0883B3D4(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088912BC(char *, s32, s16, char *);
extern void func_08832E34(char *, s32, s32, s32, s32, s32);

void func_08829B58(char *arg0, s32 arg1) {
    Box box;
    char *ptrs[4];
    s8 flags[4];
    char *g;
    s32 i;
    s32 n;
    s32 m;
    s32 sel;
    s16 y;

    switch (*(u8 *)(arg0 + 0x589)) {
    case 1:
        if (arg1 == 0) {
            func_0882FA24(&box, &D_089386C0, 0, 0, 0);
        } else {
            func_0882FA24(&box, &D_089386D4, 0, 0, 0);
        }
        g = D_089CC438;
        if ((s32)((*(s32 *)(g + 0x6AF14) & 1) != 0) == 0) {
            m = *(u8 *)(g + 0x28);
            i = 0;
            n = 0;
            for (; i < 4; i++) {
                if (m == i) {
                    continue;
                }
                if ((s32)(*(u8 *)(g + (u8)i * 0x8C + 0x30) != 0) != 0) {
                    ptrs[n] = D_09A0B544 + (u8)i * 0xC8 + 0xBC8;
                } else {
                    ptrs[n] = 0;
                }
                flags[n] = 0;
                n++;
            }
            ptrs[n] = 0;
            flags[n] = 0;
        } else {
            box.n = 3;
            box.unk6 = (u16)box.h * box.n + 0x10;
            i = 0;
            n = 0;
            for (; i < 3; i++, n++) {
                flags[i] = 0;
                switch ((u8)func_0882A8B8(arg0, i)) {
                case 1:
                    flags[i] = 10;
                case 0:
                    ptrs[i] = func_0883B3D4(arg0, i) + 8;
                    break;
                default:
                    ptrs[i] = 0;
                    break;
                }
            }
            ptrs[n] = 0;
            m = 4;
        }
        sel = *(s8 *)(arg0 + 0x587);
        if (m < sel) {
            sel--;
        }
        func_0882F580(arg0, &box, 0, sel, 0xFF, 0);
        y = box.y;
        for (i = 0; i < box.n; i++, y += box.h) {
            func_08890E38(D_08A631A8, flags[i]);
            if (ptrs[i] == 0) {
                func_08890DE8(D_08A631A8, 0xE, 0xE);
                func_08891474(D_08A631A8, box.x, y, D_0893AF70);
            } else {
                func_08890DE8(D_08A631A8, 0x10, 0xE);
                func_088912BC(D_08A631A8, box.x, y, ptrs[i]);
            }
        }
        break;
    case 0:
        func_08832E34(arg0, 0xF0, 0x68, *(u8 *)(arg0 + 0x58A), (s32)(*(u8 *)(arg0 + 0x58A) + 1) - (s32)*(u8 *)(arg0 + 0x58B), 0);
        break;
    }
}
