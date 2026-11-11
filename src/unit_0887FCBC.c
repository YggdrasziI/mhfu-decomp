/* unit_0887FCBC: 0x0887FCBC-0x0887FD04 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_0887FCBC(s32 arg0, s32 arg1, s16 arg2) {
    *(s16 *)((char *)((arg0 + (arg1 * 0x14))) + 0x24) = arg2;
}

void func_0887FCD4(s32 arg0, s32 arg1, s16 arg2) {
    *(s16 *)((char *)((arg0 + (arg1 * 0x14))) + 0x26) = arg2;
}

void func_0887FCEC(s32 arg0, s32 arg1, s16 arg2) {
    *(s16 *)((char *)((arg0 + (arg1 * 0x14))) + 0x28) = arg2;
}
