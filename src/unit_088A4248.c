/* unit_088A4248: 0x088A4248-0x088A4280 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned int u32;

extern char D_09A0E3CC;

char *func_088A4248(u32 arg0) {
    if (arg0 >= 0x20U) {
        return 0;
    }
    return &D_09A0E3CC + (arg0 * 0x2C);
}
