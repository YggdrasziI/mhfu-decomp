/* unit_088B03CC: 0x088B03CC-0x088B040C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;

char *func_088B03CC(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 1) = (u8) *(u8 *)arg1;
    *(u8 *)arg0 = (u8) *(u8 *)(arg1 + 1);
    return arg1 + 2;
}

char *func_088B03E4(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 3) = (u8) *(u8 *)arg1;
    *(u8 *)(arg0 + 2) = (u8) *(u8 *)(arg1 + 1);
    *(u8 *)(arg0 + 1) = (u8) *(u8 *)(arg1 + 2);
    *(u8 *)arg0 = (u8) *(u8 *)(arg1 + 3);
    return arg1 + 4;
}
