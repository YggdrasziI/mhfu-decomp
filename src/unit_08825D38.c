/* unit_08825D38: 0x08825D38-0x08825DA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Flag and timer update on a record (fields by raw offset).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

void func_08825D38(char *arg0) {
    if (*(s8 *)(arg0 + 0x5F0) != 0) {
        if ((*(s32 *)(arg0 + 0x5E8) & 2) == 0) {
            *(u16 *)(arg0 + 0x5FA) = 0;
        }
        return;
    }
    if ((*(u8 *)(arg0 + 0x606) & 0x80) == 0) {
        s32 f = *(s32 *)(arg0 + 0x5E8);
        if ((f & 0x40) == 0) {
            *(s32 *)(arg0 + 0x5E8) = f & ~2;
            if ((s32)*(u16 *)(arg0 + 0x5FA) > 0) {
                *(s16 *)(arg0 + 0x5FA) = *(u16 *)(arg0 + 0x5FA) - 1;
            }
        }
    }
}
