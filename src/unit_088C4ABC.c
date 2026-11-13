/* unit_088C4ABC: 0x088C4ABC-0x088C6234 (ULES01213)
 *
 * Bounds (hypothesis): 23 small functions between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BB13C;
extern char D_089BB18C;
extern char D_089BB1AC;
extern char D_089BB1CC;
extern char D_089BB1EC;
extern char D_089BB20C;
extern char D_089BB22C;
extern char D_089BB24C;
extern char D_089BB26C;
extern char D_089BE450;
extern char D_089BE470;
extern char D_089BE490;
extern char D_089BE4B0;
extern char D_089BE4D0;
extern char D_089BE4F0;
extern char D_089BE510;
extern char D_089BE530;
extern char D_089BE550;
extern char D_089BE570;
extern char D_089BE590;
extern char D_089BE5B0;
extern char D_089BE5D0;
extern char D_089BE5F0;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09AF7E20(s32, s32);
extern int func_09AF8348(s32, s32, s32);
extern int func_09AF9140(s32);
extern int func_09AFA768(s32, s32, s32, s32, s32, s32);
extern int func_09AFBD08(s32, s32);
extern int func_09AFC448(s32, s32);
extern int func_09AFCAA0(s32, s32, s32, s32, s32, s32, s32);
extern int func_09AFDE00(s32, s32, s32, s32);
extern int func_09AFED20(s32, s32, s32, s32, s32, s32);
extern int func_09CC4DF8(s32, s32);
extern int func_09CC5898(s32, s32);
extern int func_09CC61F8(s32);
extern int func_09CC6A98(s32, s32);
extern int func_09CC7378(s32, s32);
extern int func_09CC7B90(s32, s32);
extern int func_09CC8400(s32, s32);
extern int func_09CC9138(s32, s32);
extern int func_09CC9AA8(s32, s32);
extern int func_09CCA090(s32, s32, s32, s32);
extern int func_09CCA538(s32, s32);
extern int func_09CCAD18(s32, s32);
extern int func_09CCB958(s32, s32, s32, s32, s32);
extern int func_09CCC188(s32, s32);

void func_088C4ABC(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE450;
            *(s8 *)(tmp + 0x18) = 0x14;
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
    func_09CC4DF8(var_s0, arg1);
}

void func_088C4BB4(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0xC0, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0xC0);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE470;
            *(s8 *)(tmp + 0x18) = 0x15;
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
    func_09CC5898(var_s0, arg1);
}

void func_088C4CAC(char *arg0) {
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
            *(char **)tmp = &D_089BE490;
            *(s8 *)(tmp + 0x18) = 0x16;
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
    func_09CC61F8(var_s0);
}

void func_088C4D94(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE4B0;
            *(s8 *)(tmp + 0x18) = 0x17;
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
    func_09CC6A98(var_s0, arg1);
}

void func_088C4E8C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE4D0;
            *(s8 *)(tmp + 0x18) = 0x18;
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
    func_09CC7378(var_s0, arg1);
}

void func_088C4F84(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE4F0;
            *(s8 *)(tmp + 0x18) = 0x19;
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
    func_09CC7B90(var_s0, arg1);
}

void func_088C507C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE510;
            *(s8 *)(tmp + 0x18) = 0x1A;
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
    func_09CC8400(var_s0, arg1);
}

void func_088C5174(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE530;
            *(s8 *)(tmp + 0x18) = 0x1B;
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
    func_09CC9138(var_s0, arg1);
}

void func_088C526C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE550;
            *(s8 *)(tmp + 0x18) = 0x1C;
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
    func_09CC9AA8(var_s0, arg1);
}

void func_088C5364(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
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
            *(char **)tmp = &D_089BE570;
            *(s8 *)(tmp + 0x18) = 0x1D;
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
    func_09CCA090(var_s0, arg1, arg2, arg3);
}

void func_088C547C(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x40, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x40);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE590;
            *(s8 *)(tmp + 0x18) = 0x1E;
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
    func_09CCA538(var_s0, arg1);
}

void func_088C5574(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BB13C;
            *(s8 *)(tmp + 0x18) = 0x1F;
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
    func_09AF7E20(var_s0, arg1);
}

void func_088C566C(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE5B0;
            *(s8 *)(tmp + 0x18) = 0x20;
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
    func_09CCAD18(var_s0, arg1);
}

void func_088C5764(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x80, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x80);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE5D0;
            *(s8 *)(tmp + 0x18) = 0x21;
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
    func_09CCB958(var_s0, arg1, arg2, arg3, arg4);
}

void func_088C588C(char *arg0, s32 arg1, s32 arg2) {
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
            *(char **)tmp = &D_089BB18C;
            *(s8 *)(tmp + 0x18) = 0x22;
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
    func_09AF8348(var_s0, arg1, arg2);
}

void func_088C5994(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BE5F0;
            *(s8 *)(tmp + 0x18) = 0x23;
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
    func_09CCC188(var_s0, arg1);
}

void func_088C5A8C(char *arg0) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x5A0, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x5A0);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BB1AC;
            *(s8 *)(tmp + 0x18) = 0x24;
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
    func_09AF9140(var_s0);
}

void func_088C5B74(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0xE0, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0xE0);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BB1CC;
            *(s8 *)(tmp + 0x18) = 0x25;
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
    func_09AFA768(var_s0, arg1, arg2, arg3, arg4, arg5);
}

void func_088C5CAC(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BB1EC;
            *(s8 *)(tmp + 0x18) = 0x26;
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
    func_09AFBD08(var_s0, arg1);
}

void func_088C5DA4(char *arg0, s32 arg1) {
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
            *(char **)tmp = &D_089BB20C;
            *(s8 *)(tmp + 0x18) = 0x27;
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
    func_09AFC448(var_s0, arg1);
}

void func_088C5E9C(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x90, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x90);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BB22C;
            *(s8 *)(tmp + 0x18) = 0x28;
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
    func_09AFCAA0(var_s0, arg1, arg2, arg3, arg4, arg5, arg6);
}

void func_088C5FE4(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v1;
    s32 var_s0;
    s32 tmp;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x90, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x90);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BB24C;
            *(s8 *)(tmp + 0x18) = 0x29;
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
    func_09AFDE00(var_s0, arg1, arg2, arg3);
}

void func_088C60FC(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
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
            *(char **)tmp = &D_089BB26C;
            *(s8 *)(tmp + 0x18) = 0x2A;
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
    func_09AFED20(var_s0, arg1, arg2, arg3, arg4, arg5);
}
