/* unit_08823C84: 0x08823C84-0x08823CBC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Counts the 20 records (stride 0x24) whose byte at 0xE28 is set and adds
 * the signed byte at 0x10F8.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

s32 func_08823C84(char *arg0) {
    s32 n = 0;
    s32 i;
    char *p;

    for (i = 0, p = arg0; i < 20; i++, p += 0x24) {
        if (*(u8 *)(p + 0xE28) != 0) {
            n++;
        }
    }
    return n + *(s8 *)(arg0 + 0x10F8);
}
