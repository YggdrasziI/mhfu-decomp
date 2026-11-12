/* unit_08883988: 0x08883988-0x08883B54 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_08880884(void *, s32, s32);
extern s32 func_088838B0(char *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_088858EC(char *, s32, s32, s32);

s32 func_08883988(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg_sp0) {
    s32 temp_v0;

    if (arg2 == -1) {
        return 0;
    }
    temp_v0 = func_088858EC(arg0, func_08880884(arg0, 0x7F, *(s32 *)((char *)arg0 + 0x5623D0)), arg1, arg2);
    if ((arg_sp0 == 0) && (temp_v0 == 0)) {
        return 0;
    }
    return func_088838B0(arg0, arg1, arg2, arg3, arg4, arg5, temp_v0, 0x40, arg7 + 0x2000, arg6);
}

s32 func_08883A80(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 temp_v0;

    if (arg2 == -1) {
        return 0;
    }
    temp_v0 = func_08880884(arg0, 0x7F, *(s32 *)((char *)arg0 + 0x5623D4));
    if (temp_v0 == 0) {
        return 0;
    }
    return func_088838B0(arg0, arg1, arg2, arg3, arg4, arg5, temp_v0, 0x40, arg7 + 0x2000, arg6);
}
