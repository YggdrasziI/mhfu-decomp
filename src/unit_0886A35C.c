/* unit_0886A35C: 0x0886A35C-0x0886A3AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A35C: returns the value at offset 0x10 clamped to 0 (mode 1: the
 * unclamped value of the object at offset 0x68). */
typedef int s32;

static inline s32 clamp_zero(s32 v) {
    if (v < 0) {
        return 0;
    }
    return v;
}

s32 func_0886A35C(char *a0, s32 a1) {
    s32 v;

    switch (a1) {
    case 0:
        v = clamp_zero(*(s32 *)(a0 + 0x10));
        break;
    case 1:
        v = *(s32 *)(*(char **)(a0 + 0x68) + 0x10);
        break;
    default:
        v = clamp_zero(*(s32 *)(a0 + 0x10));
        break;
    }
    return v;
}
