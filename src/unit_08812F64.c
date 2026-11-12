/* unit_08812F64: 0x08812F64-0x08812F90 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char D_08933A98;

void func_08812F64(char *arg0, s32 arg1) {
    *(s8 *)(arg0 + 0xAC0) = 1;
    *(s8 *)(arg0 + 0xAC1) = (s8) (arg1 | 0x80);
    *(s16 *)(arg0 + 0xAC2) = (s16) ((s16 *)&D_08933A98)[arg1];
}
