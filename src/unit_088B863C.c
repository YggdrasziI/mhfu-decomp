/* unit_088B863C: 0x088B863C-0x088B86D4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 func_088B863C(s32 arg0, s32 arg1) {
    s32 var_a1;
    char *var_a2;

    var_a2 = (char *) (arg0 + 4);
    var_a1 = 0;
loop_1:
    if ((*(u16 *)var_a2 == 1) && (*(u16 *)(var_a2 + 2) == (arg1 & 0xFFFF))) {
        return 1;
    }
    var_a1 += 1;
    var_a2 += 0x20;
    if (var_a1 >= 0x80) {
        return 0;
    }
    goto loop_1;
}

s32 func_088B8688(s32 arg0, s32 arg1) {
    s32 var_a1;
    char *var_a2;

    var_a2 = (char *) (arg0 + 4);
    var_a1 = 0;
loop_1:
    if ((*(u16 *)var_a2 == 1) && (*(u8 *)(var_a2 + 0x18) == (arg1 & 0xFF))) {
        return 1;
    }
    var_a1 += 1;
    var_a2 += 0x20;
    if (var_a1 >= 0x80) {
        return 0;
    }
    goto loop_1;
}
