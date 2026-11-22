/* unit_0888E494: 0x0888E494-0x0888E5B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CBBE4;
extern char *D_089CC438;
extern u8 func_088DA324(char *, char *);
extern u8 func_0884FA5C(char *, s32);
extern u8 func_09A6ED48(char *);

s32 func_0888E494(char *arg0) {
    char *s0 = arg0 + 0xA0;
    char *s1 = *(char **)(D_089CBBE4 + 0xA84);

    if (func_088DA324(s1, s1) == 1 && *(u8 *)(s0 + 0x8C) != 0) {
        return 1;
    }
    if (func_0884FA5C(D_089CC438, 1) == 1 || *(u8 *)(s1 + 0x552) != 0) {
        return 0;
    }
    if (func_09A6ED48(s1) == 1) {
        return 1;
    }
    if (*(u8 *)(s1 + 0x1E8) == 10) {
        if ((*(u16 *)(s0 + 0x86) & 0x200) && (*(s32 *)(s1 + 0x480) & 0x200)) {
            /* The flag is materialised (sltu) before it is tested. */
            u8 flag = (*(s32 *)(s1 + 0x410) & 8) != 0;
            if (flag && *(u8 *)(s1 + 0x298) != 2 && *(u8 *)(s1 + 0x298) != 6) {
                return 1;
            }
        }
    }
    return 0;
}
