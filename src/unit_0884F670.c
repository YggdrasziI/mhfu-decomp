/* unit_0884F670: 0x0884F670-0x0884F86C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_09A1FDDC;

void func_0884F670(char *arg0, s32 arg1) {
    if (arg1 == 0x80020321) {
        if (*(u8 *)(arg0 + 0x2FBDC) != 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 1;
        } else if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 5;
        } else {
            *(s32 *)(arg0 + 0x2FBE0) = 9;
        }
    } else if (arg1 == 0x80010002) {
        if (*(u8 *)(arg0 + 0x2FBDC) != 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 2;
        } else if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 6;
        } else {
            *(s32 *)(arg0 + 0x2FBE0) = 10;
        }
    } else if (arg1 >= 0 && *(u8 *)(D_09A1FDDC + 0xD) == 0) {
        if (*(u8 *)(arg0 + 0x2FBDC) != 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 3;
        } else if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 7;
        } else {
            *(s32 *)(arg0 + 0x2FBE0) = 11;
        }
    } else {
        if (*(u8 *)(arg0 + 0x2FBDC) != 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 4;
        } else if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            *(s32 *)(arg0 + 0x2FBE0) = 8;
        } else {
            *(s32 *)(arg0 + 0x2FBE0) = 12;
        }
    }
    *(u8 *)(D_089CC438 + 0x6ADDE) = 0;
}
