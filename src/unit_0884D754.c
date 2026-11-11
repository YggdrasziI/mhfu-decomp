/* unit_0884D754: 0x0884D754-0x0884D790 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

void func_0884D754(char *arg0, s16 arg1, s8 arg2, s32 arg3) {
    *(u16 *)(arg0 + 0x24) = arg1;
    *(u16 *)(arg0 + 0x26) = 0;
    *(u8 *)(arg0 + 0x28) = arg2;
    if (arg3 == 1) {
        *(s32 *)(arg0 + 0x1C) = 2;
        *(u8 *)(arg0 + 0x29) = 0xFF;
    } else {
        *(s32 *)(arg0 + 0x1C) = 1;
        *(u8 *)(arg0 + 0x29) = 0;
    }
    *(u8 *)(arg0 + 0x2A) = (u8) *(u8 *)(arg0 + 0x2F);
}
