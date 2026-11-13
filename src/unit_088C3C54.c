/* unit_088C3C54: 0x088C3C54-0x088C3F18 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char D_089BAB34;
extern char D_089BACBC;
extern char D_089BE2B0;
extern char D_089BE2D0;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_088C7130(s32, s32);
extern int func_09CBDDF8(s32, s32, s32, s32, s32, s32, s32, u16, s32, s32);
extern int func_09CBE7F0(s32, s32);

void func_088C3C54(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u16 arg_sp0, s32 arg_sp4, s32 arg_sp8) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 tmp;
    s32 var_v0;

    tmp = func_08859B44(arg0 + 0x2294 + 0x7FF8, 0x54, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x54);
        if (tmp != 0) {
            *(char **)tmp = &D_089BAB34;
            *(char **)tmp = &D_089BACBC;
            *(s32 *)(tmp + 0x14) = 0;
            *(s32 *)(tmp + 0x10) = 0;
            *(s32 *)(tmp + 0x2C) = 0;
            *(s32 *)(tmp + 0x30) = 0;
            *(char **)tmp = &D_089BE2B0;
            *(s8 *)(tmp + 0x18) = 7;
        }
        if (tmp == 0) {
            func_08859C40(arg0 + 0x2294 + 0x7FF8, tmp);
        }
            var_s0 = tmp;
    } else {
        var_s0 = 0;
    }
    func_088C7130((int) (arg0), var_s0);
    if (arg1 == 0) {
        temp_v1 = *(s32 *)arg0;
        *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1 + 0x50);
        var_v0 = temp_v1 + 0x70;
        *(s32 *)(var_s0 + 0x30) = var_v0;
    } else if (arg1 == 1) {
        temp_v1_2 = *(s32 *)arg0;
        *(s32 *)(var_s0 + 0x2C) = (s32) (temp_v1_2 + 0x1D0);
        var_v0 = temp_v1_2 + 0x70;
        *(s32 *)(var_s0 + 0x30) = var_v0;
    }
    func_09CBDDF8(var_s0, arg2, arg3, arg4, arg5, arg6, arg7, arg_sp0, arg_sp4, arg_sp8);
}

void func_088C3DE8(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 tmp;
    s32 var_v0;

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
            *(char **)tmp = &D_089BE2D0;
            *(s8 *)(tmp + 0x18) = 8;
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
    func_09CBE7F0(var_s0, arg1);
}
