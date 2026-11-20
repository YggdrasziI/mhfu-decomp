/* unit_088B01BC: 0x088B01BC-0x088B0240 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B012C and unit_088B0240.
 * Its initialised array (0x089B2A34-0x089B2A3A, in .data) is linked from this
 * unit.
 */

typedef signed char s8;
typedef unsigned char u8;

extern char D_09A202B8;

extern void memcpy(void *dst, const void *src, int size);

void func_088B01BC(u8 arg0, char *arg1) {
    s8 any[6] = {-1, -1, -1, -1, -1, -1};
    char addr[8];

    if (arg0 == 0) {
        memcpy(addr, any, 6);
    } else {
        memcpy(addr, arg1, 6);
    }
    memcpy(&D_09A202B8, addr, 6);
}