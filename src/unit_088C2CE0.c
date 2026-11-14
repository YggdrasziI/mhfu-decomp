/* unit_088C2CE0: 0x088C2CE0-0x088C2D74 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s32 func_088C2B94(s32, s32);

void func_088C2CE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    char *var_s2;
    s32 temp_a1;
    char *var_s1;
    u32 var_s0;

    var_s2 = (char *) (arg1 + arg3);
    var_s1 = (char *) (arg2 + arg4);
    var_s0 = 0;
    if (arg5 != 0) {
        do {
            temp_a1 = func_088C2B94(arg0, ((u32) (arg4 + var_s0) >> 1) & 3) & 0xFFFF;
            var_s0 += 2;
            *(s16 *)var_s2 = *(u16 *)var_s1 ^ temp_a1;
            var_s2 += 2;
            var_s1 += 2;
        } while (var_s0 < arg5);
    }
}
