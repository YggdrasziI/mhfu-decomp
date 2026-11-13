/* unit_088C354C: 0x088C354C-0x088C3948 (ULES01213)
 *
 * Bounds (hypothesis): 4 small functions between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BE1B0;
extern char D_089BE1F0;
extern char D_089BE210;
extern char D_089BE230;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09CBA4E0(s32, s32);
extern int func_09CBAC28(s32, s32, s32);
extern int func_09CBB470(s32, s32, s32);
extern int func_09CBB970(s32, s32);

void func_088C354C(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x3C, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x3C);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE1B0;
            *(s8 *)(tmp + 0x18) = 0;
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
    func_09CBA4E0(var_s0, arg1);
}

void func_088C3640(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

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
            *(char **)tmp = &D_089BE1F0;
            *(s8 *)(tmp + 0x18) = 1;
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
    func_09CBAC28(var_s0, arg1, arg2);
}

void func_088C3748(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x60, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x60);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE210;
            *(s8 *)(tmp + 0x18) = 2;
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
    func_09CBB470(var_s0, arg1, arg2);
}

void func_088C3850(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

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
            *(char **)tmp = &D_089BE230;
            *(s8 *)(tmp + 0x18) = 3;
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
    func_09CBB970(var_s0, arg1);
}
