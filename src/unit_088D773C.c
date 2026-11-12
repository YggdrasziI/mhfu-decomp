/* unit_088D773C: 0x088D773C-0x088D777C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[4]; } E4;

s16 func_088D773C(char *arg0, s32 arg1) {
    s32 var_a2;
    char *var_a1;

    var_a2 = 0;
    var_a1 = arg0;
loop_1:
    if (*(u16 *)(var_a1 + 0x568) == (arg1 & 0xFFFF)) {
        return *(s16 *)((E4 *)(arg0 + 0x56A))[var_a2].b;
    }
    var_a2 += 1;
    var_a1 += 4;
    if (var_a2 >= 0x18) {
        return 0;
    }
    goto loop_1;
}
