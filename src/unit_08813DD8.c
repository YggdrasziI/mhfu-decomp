/* unit_08813DD8: 0x08813DD8-0x08813E10 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

s32 func_08813DD8(char *arg0) {
    char *p = arg0 + 0x970;
    s8 v = *(s8 *)(arg0 + 0x9BF);

    if (v) {
        return v;
    }
    if (*(u8 *)(arg0 + 0xA80) != 0 || *(u8 *)(p + 0x4E) != 0) {
        return 2;
    }
    return 0;
}
