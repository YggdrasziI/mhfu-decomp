/* unit_08880884: 0x08880884-0x088808DC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;
typedef float f32;

s32 func_08880884(s32 arg0, s32 arg1, s32 arg2) {
    return (s32) (((f32) arg1 * (f32) arg2) / 7.0f);
}

s32 func_088808B0(s32 arg0, s32 arg1) {
    return (s32) (100.0f * ((f32) arg1 / 127.0f));
}
