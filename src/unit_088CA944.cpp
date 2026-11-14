/* unit_088CA944: 0x088CA944-0x088CAA00 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct VAC_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual s32 vfunc_AC(); } VAC_0;
typedef struct VB0_1 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual void vfunc_AC(); virtual char *vfunc_B0(); } VB0_1;

extern "C" {

extern s32 D_08A62D8C;
extern void func_08885494(s32, s32, s32, s32, s32);

void func_088CA944(char **arg0) {
    s32 var_s1;
    char *var_s0;

    func_08885494(D_08A62D8C, 6, 0xC0, 0, 0);
    var_s0 = ((VB0_1 *) (arg0))->vfunc_B0();
    var_s1 = 0;
    if (((VAC_0 *) (arg0))->vfunc_AC() > 0) {
        do {
            func_08885494(D_08A62D8C, *(s32 *)(var_s0 + 4), 0xC0, var_s1 + 1, 0);
            var_s1 += 1;
            var_s0 += 0x20;
        } while (var_s1 < ((VAC_0 *) (arg0))->vfunc_AC());
    }
}

}
