/* unit_0888D888: 0x0888D888-0x0888D958 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CBBE4;
extern u8 func_08865CB8(char *, s32, s32);
extern u8 func_088DACA4(char *);

u8 func_0888D888(void) {
    char *p = *(char **)(D_089CBBE4 + 0xA84);
    u8 v;

    if (func_08865CB8(p, 0, 0x65) == 1 || func_08865CB8(p, 0, 0x66) == 1) {
        return 1;
    }
    if (func_088DACA4(p) == 1) {
        return 2;
    }
    if (func_08865CB8(p, 8, 0xF) == 1) {
        return 3;
    }
    v = *(u8 *)(p + 0x1E8);
    if (v == 1 || v == 5) {
        return 0;
    }
    return 0xFF;
}
