/* unit_088A6A78: 0x088A6A78-0x088A6BA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

void func_088A6A78(char *arg0, char *arg1) {
    if (*(s32 *)arg1 & 0x80) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x100);
        *(s16 *)(arg0 + 8) = (s16) *(s32 *)(arg1 + 0x20);
    }
    if (*(s32 *)arg1 & 0x100) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x200);
        *(s16 *)(arg0 + 0xA) = (s16) *(s32 *)(arg1 + 0x24);
    }
    if (*(s32 *)arg1 & 0x200) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x400);
        *(s16 *)(arg0 + 0xC) = (s16) *(s32 *)(arg1 + 0x28);
    }
    if (*(s32 *)arg1 & 0x1000) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x200);
        *(s8 *)(arg0 + 2) = (s8) *(s32 *)(arg1 + 0x34);
    }
    if (*(s32 *)arg1 & 0x400) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x800);
        *(s16 *)(arg0 + 0xE) = (s16) *(s32 *)(arg1 + 0x2C);
    }
    if (*(s32 *)arg1 & 0x40) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x4000);
        *(s8 *)(arg0 + 3) = (s8) *(s32 *)(arg1 + 0x1C);
    }
    if (*(s32 *)arg1 & 0x800) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x1000);
        *(s8 *)(arg0 + 0x13) = (s8) *(s32 *)(arg1 + 0x30);
    }
    if (*(s32 *)arg1 & 0x2000) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x2000);
        *(s8 *)(arg0 + 0x11) = (s8) *(s32 *)(arg1 + 0x38);
    }
}
