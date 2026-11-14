/* unit_08861C7C: 0x08861C7C-0x08861D7C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 *D_089CC000;
extern s32 func_0886171C(s32, s32, s32, s32);
extern s32 func_08862354(s32, s32);
extern s32 func_088629DC(s32, s32, s32, s32, s32);
extern s32 func_08862BB8(s32, s32, s32);
extern s32 func_08862D34(s32, s32, s32);

void func_08861C7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s0;

    temp_s0 = arg3 & 0xFFFF;
    func_08862D34(arg0, temp_s0, arg4 & 0xFF);
    *D_089CC000 = 0xDBFF0006;
    D_089CC000 += 1;
    func_08862354(arg2, arg0 + 0x10);
    func_08862BB8(arg0, temp_s0, arg5);
    func_088629DC(arg0, temp_s0, 0xFF, 0xFF, 0xFF);
    func_0886171C(arg0, 0, arg1, arg3 & 0xFF);
    *D_089CC000 = 0xDBFF8007;
    D_089CC000 += 1;
}
