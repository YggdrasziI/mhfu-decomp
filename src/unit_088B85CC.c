/* unit_088B85CC: 0x088B85CC-0x088B85F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef unsigned int u32;

void func_088B85CC(char *arg0) {
    char *var_a2;

    var_a2 = arg0 + 4;
    do {
        *(s16 *)var_a2 = 0;
        var_a2 += 0x20;
    } while ((u32) var_a2 < (u32) (arg0 + 0x1004));
    *(s32 *)(arg0 + 0x1004) = 0;
    *(s32 *)(arg0 + 0x1008) = 0;
    *(s32 *)(arg0 + 0x100C) = 0;
}
