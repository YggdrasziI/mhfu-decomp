/* unit_088C671C: 0x088C671C-0x088C684C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BE650;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09CCD738(s32, s32);

void func_088C671C(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 tmp;
    s32 var_v0;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x50, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x50);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE650;
            *(s8 *)(tmp + 0x18) = 0x2F;
        }
        if (tmp == 0) {
            func_08859C40(arg0 + 0x2294 + 0x7FF8, tmp);
        }
            var_s0 = tmp;
    } else {
        var_s0 = 0;
    }
    func_088C7130((int) (arg0), var_s0);
    if (arg2 == 0) {
        temp_v1 = *(s32 *)arg0;
        *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1 + 0x50);
        var_v0 = temp_v1 + 0x70;
        *(s32 *)(var_s0 + 0x30) = var_v0;
    } else if (arg2 == 1) {
        temp_v1_2 = *(s32 *)arg0;
        *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1_2 + 0x1D0);
        var_v0 = temp_v1_2 + 0x70;
        *(s32 *)(var_s0 + 0x30) = var_v0;
    }
    func_09CCD738(var_s0, arg1);
}
