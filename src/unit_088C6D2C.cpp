/* unit_088C6D2C: 0x088C6D2C-0x088C6DF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;
typedef struct V28_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual char *vfunc_28(); } V28_0;

extern "C" {

extern s32 D_09A4F060;
extern int func_088C6BCC(s32, s32, s32, s32, s32, s32, char *, s32);

void func_088C6D2C(char ***arg0) {
    s32 var_s1;
    char **temp_a0;
    char **temp_a0_2;
    char **temp_a0_3;
    char *var_s0;

    temp_a0 = *arg0;
    var_s0 = *(char **)((char *)(((V28_0 *) (temp_a0))->vfunc_28()) + 0x34);
    if (var_s0 != 0) {
        temp_a0_2 = *arg0;
        var_s1 = 0;
        if ((s32) *(u8 *)((char *)(((V28_0 *) (temp_a0_2))->vfunc_28()) + 0x3F) > 0) {
            do {
                if (*(s32 *)var_s0 == 0) {
                    func_088C6BCC(D_09A4F060, *(s32 *)(var_s0 + 4), *(s32 *)(var_s0 + 8), 0, 0xC0, var_s1 + 1, var_s0 + 0x10, *(s32 *)(var_s0 + 0xC));
                }
                temp_a0_3 = *arg0;
                var_s1 += 1;
                var_s0 += 0x20;
            } while (var_s1 < (s32) *(u8 *)((char *)(((V28_0 *) (temp_a0_3))->vfunc_28()) + 0x3F));
        }
    }
}

}
