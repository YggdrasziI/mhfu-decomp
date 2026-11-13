/* unit_088C684C: 0x088C684C-0x088C6A3C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BE670;
extern char D_089BE690;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09CCDC68(s32, s32);
extern int func_09CCE858(s32, s32);

void func_088C684C(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x70, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x70);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE670;
            *(s8 *)(tmp + 0x18) = 0x30;
        }
        if (tmp == 0) {
            func_08859C40(arg0 + 0x2294 + 0x7FF8, tmp);
        }
            var_s0 = tmp;
    } else {
        var_s0 = 0;
    }
    func_088C7130((int) (arg0), var_s0);
    temp_v1 = *(s32 *)arg0;
    *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1 + 0x1D0);
    *(s32 *)(var_s0 + 0x30) = (s32) (temp_v1 + 0x70);
    func_09CCDC68(var_s0, arg1);
}

void func_088C6944(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0xA0, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0xA0);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE690;
            *(s8 *)(tmp + 0x18) = 0x31;
        }
        if (tmp == 0) {
            func_08859C40(arg0 + 0x2294 + 0x7FF8, tmp);
        }
            var_s0 = tmp;
    } else {
        var_s0 = 0;
    }
    func_088C7130((int) (arg0), var_s0);
    temp_v1 = *(s32 *)arg0;
    *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1 + 0x1D0);
    *(s32 *)(var_s0 + 0x30) = (s32) (temp_v1 + 0x70);
    func_09CCE858(var_s0, arg1);
}
