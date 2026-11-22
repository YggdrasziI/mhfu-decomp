/* unit_0887959C: 0x0887959C-0x088795F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

u8 func_0887959C(s32 arg0, s16 *arg1, s16 arg2)
{
    s32 ret;

    if (arg2 != 0) {
        if (arg1[4] >= arg2 || arg2 >= arg1[3]) {
            ret = 2;
            goto end;
        }
    }
    if (arg2 >= arg1[2]) {
        ret = 1;
    } else {
        ret = 0;
    }
end:
    return ret;
}
