/* unit_0888FCE4: 0x0888FCE4-0x0888FD38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern char *D_089CBBE4;

s32 func_0888FCE4(char *arg0) {
    char *s = arg0 + 0xA0;
    char *p = *(char **)(D_089CBBE4 + 0xA84);
    unsigned int d;

    if (*(u8 *)(arg0 + 0x12D) != 0) {
        return 1;
    }
    d = (u16)(*(s32 *)(p + 0x1F4) - *(s16 *)(s + 0x80));
    if (d < 0x4000) {
        return 1;
    }
    return d >= 0xC001;
}
