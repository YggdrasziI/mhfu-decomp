/* unit_0886364C: 0x0886364C-0x08863668 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef float f32;
typedef struct { char b[8]; } E8;

f32 func_0886364C(s32 arg0, char *arg1) {
    return (f32) *(s16 *)((E8 *)(arg1 + 6))[*(s32 *)(arg1 + 4)].b;
}
