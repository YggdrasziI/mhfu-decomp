/* unit_088C3F18: 0x088C3F18-0x088C493C (ULES01213)
 *
 * Bounds (hypothesis): 10 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BE2F0;
extern char D_089BE310;
extern char D_089BE330;
extern char D_089BE350;
extern char D_089BE370;
extern char D_089BE390;
extern char D_089BE3B0;
extern char D_089BE3D0;
extern char D_089BE3F0;
extern char D_089BE410;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09CBEFE0(s32, s32);
extern int func_09CBF828(s32, s32);
extern int func_09CBFCF8(s32, s32);
extern int func_09CC03A0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern int func_09CC0B50(s32, s32);
extern int func_09CC21F8(s32, s32);
extern int func_09CC2958(s32, s32);
extern int func_09CC3480(s32, s32);
extern int func_09CC3800(s32, s32, s32);
extern int func_09CC3CC0(s32, s32);

void func_088C3F18(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE2F0;
            *(s8 *)(tmp + 0x18) = 9;
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
    func_09CBEFE0(var_s0, arg1);
}

void func_088C4010(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE310;
            *(s8 *)(tmp + 0x18) = 0xA;
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
    func_09CBF828(var_s0, arg1);
}

void func_088C4108(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE330;
            *(s8 *)(tmp + 0x18) = 0xB;
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
    func_09CBFCF8(var_s0, arg1);
}

void func_088C4200(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp4, u16 arg_sp8) {
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
            *(char **)tmp = &D_089BE350;
            *(s8 *)(tmp + 0x18) = 0xC;
        }
        if (tmp == 0) {
            func_08859C40(arg0 + 0x2294 + 0x7FF8, tmp);
        }
            var_s0 = tmp;
    } else {
        var_s0 = 0;
    }
    func_088C7130((int) (arg0), var_s0);
    func_09CC03A0(var_s0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg_sp0, arg_sp4, (s32) arg_sp8);
}

void func_088C435C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE370;
            *(s8 *)(tmp + 0x18) = 0xD;
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
    func_09CC0B50(var_s0, arg1);
}

void func_088C4454(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE390;
            *(s8 *)(tmp + 0x18) = 0xE;
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
    func_09CC21F8(var_s0, arg1);
}

void func_088C454C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE3B0;
            *(s8 *)(tmp + 0x18) = 0xF;
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
    func_09CC2958(var_s0, arg1);
}

void func_088C4644(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE3D0;
            *(s8 *)(tmp + 0x18) = 0x10;
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
    *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1 + 0x50);
    *(s32 *)(var_s0 + 0x30) = (s32) (temp_v1 + 0x70);
    func_09CC3480(var_s0, arg1);
}

void func_088C473C(char *arg0, s32 arg1, s32 arg2) {
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
            *(char **)tmp = &D_089BE3F0;
            *(s8 *)(tmp + 0x18) = 0x11;
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
    func_09CC3800(var_s0, arg1, arg2);
}

void func_088C4844(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE410;
            *(s8 *)(tmp + 0x18) = 0x12;
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
    func_09CC3CC0(var_s0, arg1);
}
