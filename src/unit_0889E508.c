/* unit_0889E508: 0x0889E508-0x0889E670 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_09A0B544;
extern int func_0889E440(char *);
extern s32 func_0889CE10(char *, char *);
extern void func_0889D8A8(char *, char *, s32, s32 *);

void func_0889E508(char *arg0) {
    switch (*(s32 *)(arg0 + 8)) {
    default:
        return;
    case 0:
        if ((u8)((*(s32 *)(D_09A0B544 + 0x12C0) & 0x200) != 0) != 0) {
            return;
        }
        if (*(u8 *)(D_09A0B544 + 0x1AF4) != 0) {
            *(s32 *)(arg0 + 0x14) = -1;
            *(s32 *)(arg0 + 8) += 1;
        } else {
            func_0889E440(arg0);
            *(s32 *)(arg0 + 0x20) = 3;
        }
    case 1:
        break;
    }
    if (func_0889CE10(D_09A0B544, arg0 + 0x18) == 0) {
        func_0889E440(arg0);
        *(s32 *)(arg0 + 0x20) = 2;
    }
    if (*(u8 *)(arg0 + 0xC) == 0) {
        if (++*(s32 *)(arg0 + 0x14) >= 0x25) {
            func_0889E440(arg0);
            *(s32 *)(arg0 + 0x20) = 0;
            return;
        }
        func_0889D8A8(D_09A0B544, arg0 + 0x18, 4, (s32 *)(arg0 + 0x14));
        *(s32 *)(arg0 + 0x10) = 0x96;
        *(u8 *)(arg0 + 0xC) = 1;
        *(s8 *)(arg0 + 0x24) = 5;
    } else {
        if (--*(s32 *)(arg0 + 0x10) >= 0) {
            return;
        }
        if (--*(s8 *)(arg0 + 0x24) < 0) {
            func_0889E440(arg0);
            *(s32 *)(arg0 + 0x20) = 2;
            return;
        }
        func_0889D8A8(D_09A0B544, arg0 + 0x18, 4, (s32 *)(arg0 + 0x14));
        *(s32 *)(arg0 + 0x10) = 0x96;
    }
}
