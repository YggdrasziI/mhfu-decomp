/* unit_0884A6CC: 0x0884A6CC-0x0884A72C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884A6CC (ULES01213) */

typedef unsigned char u8;
typedef short s16;

void func_0884A6CC(char *arg0, u8 arg1) {
    switch (arg1) {
    case 4:
        arg0[0x11AD] = 0;
        break;
    case 7:
        arg0[0x11AD] = 1;
        break;
    case 6:
        arg0[0x11AD] = 2;
        break;
    }
    arg0[0x11AE] = 1;
    arg0[0x11B2] = 0;
    arg0[0x11B1] = 0;
    arg0[0x11B0] = 0;
    arg0[0x11AF] = 0;
    *(s16 *)(arg0 + 0x11BA) = 0;
    *(s16 *)(arg0 + 0x11BC) = 0;
}
