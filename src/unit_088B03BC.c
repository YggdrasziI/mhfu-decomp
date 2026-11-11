/* unit_088B03BC: 0x088B03BC-0x088B03CC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

char *func_088B03BC(u8 *arg0, u8 *arg1) {
    *arg0 = *arg1;
    return (char *) (arg1 + 1);
}
