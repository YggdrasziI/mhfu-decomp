/* unit_0885A934: 0x0885A934-0x0885A95C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;

extern char *D_089CC438;

void func_0885A934(char *arg0, s8 arg1, s16 arg2, s16 arg3, s8 arg4) {
    *(s8 *)(arg0 + 1) = arg1;
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg3;
    *(s8 *)arg0 = 1;
    *(s8 *)(arg0 + 2) = 0;
    *(s8 *)(D_089CC438 + 0x381) = arg4;
}
