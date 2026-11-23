/* unit_088637C4: 0x088637C4-0x08863B70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_088637C4 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad00[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    char pad20[0x4];
    f32 f24;
    char pad28[0x8];
    s32 i30;
    f32 f34;
    char pad38[0x4];
    u16 flags;
    s8 b3E;
    s8 b3F;
    f32 v40;
    f32 v44;
    f32 v48;
} Ent;

extern void func_0885FB54(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
extern f32 func_08862FE0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern void func_0885FF5C(s32 arg0, s32 arg1, f32 arg2, f32 arg3);

s32 func_088637C4(char *arg0) {
    u32 i;
    s32 ret;
    char *p;
    Ent *e;
    f32 f;

    p = *(char **)(*(char **)(arg0 + 0x110) + 0x14C) + 0x150;
    ret = 0;
    for (i = 0; i < *(u16 *)(arg0 + 0x122); i++) {
        e = (Ent *)(arg0 + i * 0x40);
        e->b3F = 0;
        if (e->b3E != 0) {
            func_0885FB54(*(s32 *)(arg0 + 0x110), i, 0, e->f10);
            f = func_08862FE0(p, e->f34, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
            func_0885FF5C(*(s32 *)(arg0 + 0x110), i, f, 1.0f - f);
            if (i == 0) {
                *(s32 *)(p + 0x30) = 0;
                *(s32 *)(p + 0x34) = 0;
                *(s32 *)(p + 0x38) = 0;
            }
            e->f34 += e->f24;
            if ((f32)--e->i30 <= 0.0f) {
                e->b3E = 0;
                e->f10 += e->f14;
            }
        } else if (e->f10 + e->f14 <= e->f1C) {
            func_0885FB54(*(s32 *)(arg0 + 0x110), i, 0, e->f10);
            if (*(u8 *)(arg0 + i + 0x128) != 0) {
                func_0885FB54(*(s32 *)(arg0 + 0x110), i, 1, *(f32 *)(arg0 + 0x50));
                f = (f32)(u32)*((u16 *)arg0 + i + 0x98) / 100.0f;
                func_0885FF5C(*(s32 *)(arg0 + 0x110), i, 1.0f - f, f);
            }
            if (i == 0) {
                *(f32 *)(arg0 + 0x40) = *(f32 *)(p + 0x30);
                *(f32 *)(arg0 + 0x44) = *(f32 *)(p + 0x34);
                *(f32 *)(arg0 + 0x48) = *(f32 *)(p + 0x38);
            }
            e->f10 += e->f14;
            ret = 1;
            e->flags |= 1;
            goto zero;
        } else {
            if (e->flags & 2) {
                f = e->f18;
                if (f >= 1.0f) {
                    f -= 1.0f;
                }
                func_0885FB54(*(s32 *)(arg0 + 0x110), i, 0, f);
                if (i == 0) {
                    e->v40 = *(f32 *)(p + 0x30);
                    e->v44 = *(f32 *)(p + 0x34);
                    e->v48 = *(f32 *)(p + 0x38);
                }
                func_0885FB54(*(s32 *)(arg0 + 0x110), i, 0, e->f1C);
                e->f10 = e->f18;
                ret = 1;
                e->flags &= ~1;
            } else {
                e->f10 = e->f1C;
                func_0885FB54(*(s32 *)(arg0 + 0x110), i, 0, e->f10);
                ret = 1;
                e->flags &= ~1;
                if (i == 0) {
                    *(f32 *)(arg0 + 0x40) = *(f32 *)(p + 0x30);
                    *(f32 *)(arg0 + 0x44) = *(f32 *)(p + 0x34);
                    *(f32 *)(arg0 + 0x48) = *(f32 *)(p + 0x38);
                }
            }
            if (*(u8 *)(arg0 + i + 0x128) != 0) {
                func_0885FB54(*(s32 *)(arg0 + 0x110), i, 1, e->f10);
                f = (f32)(u32)*((u16 *)arg0 + i + 0x98) / 100.0f;
                func_0885FF5C(*(s32 *)(arg0 + 0x110), i, 1.0f - f, f);
                if (i == 0) {
                    *(f32 *)(arg0 + 0x40) = *(f32 *)(p + 0x30);
                    *(f32 *)(arg0 + 0x44) = *(f32 *)(p + 0x34);
                    *(f32 *)(arg0 + 0x48) = *(f32 *)(p + 0x38);
                }
            } else {
            zero:
                if (i == 0) {
                    *(s32 *)(p + 0x30) = 0;
                    *(s32 *)(p + 0x34) = 0;
                    *(s32 *)(p + 0x38) = 0;
                }
            }
        }
    }
    return ret;
}
