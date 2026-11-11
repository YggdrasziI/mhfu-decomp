/* unit_0882693C: 0x0882693C-0x088269C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

s16 *func_08856884(s32, s32);
char *func_0885C580(s32, s32);
extern s32 D_089CC438;
extern s32 D_08A62C50;

s32 func_0882693C(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg1 & 0xFFFF;
    if ((*(s16 *)((char *)(func_08856884(D_089CC438, temp_s0)) + 2) > 0) && (*func_08856884(D_089CC438, temp_s0) != 0) && (*(u8 *)((char *)(func_0885C580(D_08A62C50, temp_s0)) + 1) == 1)) {
        return 1;
    }
    return 0;
}
