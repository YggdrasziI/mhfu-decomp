/* unit_0888A49C: 0x0888A49C-0x0888A538 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

/* 16-byte entries of a table at arg2 + 0x10C, indexed by the byte at arg1 + 0x8. */
typedef struct {
    float f;
    char pad[12];
} Entry_0888A49C;

extern u8 func_0888B884(char *, char *, s32);
extern s32 func_0888B994(char *, char *, char *, s32);

s32 func_0888A49C(char *arg0, char *arg1, char *arg2, s32 arg3) {
    *(u8 *)(arg1 + 0x8) = func_0888B884(arg0, arg2, arg3);
    if (func_0888B994(arg0, arg1, arg2, arg3) != 0) {
        *(float *)(arg1 + 0x4) = *(float *)(arg1 + 0x0) /
            ((Entry_0888A49C *)(arg2 + 0x10C))[*(u8 *)(arg1 + 0x8)].f;
        return 1;
    }
    *(s32 *)(arg1 + 0x4) = 0;
    *(s32 *)(arg1 + 0x0) = 0;
    return 0;
}
