/* unit_088D27F4: 0x088D27F4-0x088D286C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 func_088D27F4(char *arg0) {
    if (*(u8 *)(arg0 + 0x4E9) != 6) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x1E8) != 5) {
        return 0;
    }
    return (*(u16 *)(arg0 + 0x4EC) & 0x10) != 0;
}

s32 func_088D2830(char *arg0) {
    if (*(u8 *)(arg0 + 0x4E9) != 6) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x1E8) != 1) {
        return 0;
    }
    return (*(u16 *)(arg0 + 0x4EC) & 0x80) != 0;
}
