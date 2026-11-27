/* unit_08863E70: 0x08863E70-0x088640F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct Ent {
    char pad00[0x10];
    f32 f10;
    char pad14[4];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    s32 f30;
    f32 f34;
    char *f38;
    u16 f3C;
    s8 f3E;
    u8 f3F;
} Ent;

typedef struct Obj {
    Ent ent[4];
    char pad100[0x10];
    s32 f110[4];
    char pad120[2];
    u16 f122;
} Obj;

extern void func_0885F9A0(s32, s32, s32, s32);
extern void func_0885FB54(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
extern void func_0885FBB4(int a, int b);
extern f32 func_0886025C(char *arg0, char *arg1);

static inline void vec_zero(char *dst) {
    asm {
        vzero.q C000
        sv.q C000, 0(dst)
    }
}

void func_08863E70(Obj *arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4) {
#define e (&arg0->ent[arg4])
    s32 i;
    s32 n;

    if (arg3 != 0) {

        if (e->f3F == 0) {
            func_0885F9A0(arg0->f110[0], (s32)e->f38, arg4, 1);
            e->f2C = e->f1C;
            if (e->f3C & 2) {
                e->f3C |= 4;
            } else {
                e->f3C &= ~4;
            }
            e->f28 = e->f18;
            e->f20 = e->f10;
            e->f3F = 1;
            if (e->f3E == 0) {
                func_0885FB54(arg0->f110[0], arg4, 1, e->f20);
            } else {
                for (i = 0; i < arg0->f122; i++) {
                    func_0885FBB4(arg0->f110[0], i);
                }
            }
        }
        if (arg3 < 0) {
            arg3 = -arg3;
            e->f3E = -1;
        } else {
            e->f3E = 1;
        }
        n = arg3 + 1;
        func_0885F9A0(arg0->f110[0], (s32)arg1, arg4, 0);
        e->f1C = func_0886025C((char *)arg0->f110[arg4], arg1);
        if (*(s32 *)(arg1 + 0xC) != 0) {
            e->f3C |= 2;
        } else {
            e->f3C &= ~2;
        }
        e->f18 = *(f32 *)(arg1 + 0x10);
        e->f10 = (f32)arg2;
        e->f38 = arg1;
        e->f30 = n;
        e->f34 = e->f24 = 1.0f / (f32)n;
    } else {
        func_0885F9A0(arg0->f110[0], (s32)arg1, arg4, 0);

        e->f1C = func_0886025C((char *)arg0->f110[arg4], arg1);
        if (*(s32 *)(arg1 + 0xC) != 0) {
            e->f3C |= 2;
        } else {
            e->f3C &= ~2;
        }
        e->f18 = *(f32 *)(arg1 + 0x10);
        e->f10 = (f32)arg2;
        e->f38 = arg1;
        e->f30 = 0;
        e->f3E = 0;
    }
    e->f3C |= 1;
    if (arg4 == 0) {
        vec_zero((char *)arg0 + 0x40);
    }
}
