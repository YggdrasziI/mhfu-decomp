/* unit_088568AC: 0x088568AC-0x08856920 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern u16 *func_08856884(s32, s32);

s16 func_088568AC(s32 arg0, s32 arg1) {
    s32 var_s1;

    var_s1 = 0;
loop_1:
    if ((arg1 & 0xFFFF) == *func_08856884(arg0, var_s1)) {
        return *(s16 *)((char *)(func_08856884(arg0, var_s1)) + 2);
    }
    var_s1 += 1;
    if (var_s1 >= 0x18) {
        return 0;
    }
    goto loop_1;
}
