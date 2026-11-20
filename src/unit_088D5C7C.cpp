/* unit_088D5C7C: 0x088D5C7C-0x088D6108 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088D5C74 and unit_088D6108.
 *
 * func_088D5C7C sets the two rates of the record at +0x80 from the id at
 * +0x324 and starts the two entries (+0x324 / +0x326) whose flag (0x80 /
 * 0x100 at +0x614) is clear; func_088D5EF0 adds to the byte at +0x67E, kept
 * within -100..100; func_088D5F30 and func_088D5FE4 pass an id (or, with -1
 * as the slot, one id per slot, 100 apart) to func_08863D58 / func_08863DF4.
 *
 * C++: virtual calls, bool conversions. Optimized for speed (float
 * constants built with `lui` / `ori`). func_088D5F30 and func_088D5FE4 keep
 * the result of the virtual call in their third argument.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Anim {
    char pad0[0x14];
    float unk14;
    char pad18[0x3C];
    float unk54;
} Anim;

typedef struct Obj {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual s32 vfunc_20(s32);

    char pad4[0x7C];
    Anim unk80;
    char padD8[0xCA];
    u16 unk1A2;
    char pad1A4[0x180];
    u16 unk324[2];
    char pad328[4];
    u16 unk32C[2];
    char pad330[4];
    s16 unk334[2];
    char pad338[4];
    u8 unk33C;
    char pad33D[0x21B];
    u8 unk558;
    char pad559[0xBB];
    s32 unk614;
    char pad618[0x66];
    s8 unk67E;
    char pad67F[0x1D];
    float unk69C;
} Obj;

extern "C" {

extern char *D_089CC438;

extern void func_08863D58(Anim *, s32, s32, float);
extern void func_08863DF4(Anim *, s32, u32, s32, float);
extern void func_08863E70(Anim *, s32, s32, s32, s32);
extern void func_08865648(Obj *);

void func_088D5C7C(Obj *arg0) {
    Anim *anim = &arg0->unk80;
    s32 r;
    float f;

    if (arg0->unk33C != 0) {
        anim->unk54 = 0.0f;
        anim->unk14 = 0.0f;
    } else if (arg0->unk558 > 0) {
        arg0->unk558--;
        anim->unk54 = 0.2f;
        anim->unk14 = 0.2f;
    } else {
        arg0->unk558 = 0;
        switch (arg0->unk324[0]) {
        case 0x587:
        case 0x58A:
            if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                f = 2.0f * arg0->unk69C;
                anim->unk54 = f;
                anim->unk14 = f;
                break;
            }
        case 0x195:
        case 0x196:
        case 0x197:
        case 0x19B:
        case 0x19C:
        case 0x19D:
        case 0x19F:
        case 0x1A0:
        case 0x1A2:
        case 0x1A3:
        case 0x1A6:
        case 0x1A7:
            if (anim->unk14 <= 2.0f) {
                anim->unk54 = 2.0f;
                anim->unk14 = 2.0f;
            }
            break;
        case 3:
        case 0x731:
        case 0x22:
        case 0x23:
            break;
        default:
            f = 2.0f * arg0->unk69C;
            anim->unk54 = f;
            anim->unk14 = f;
            break;
        }
    }
    if ((bool) (arg0->unk614 & 0x80) == 0) {
        arg0->unk614 |= 0x80;
        r = arg0->vfunc_20(arg0->unk324[0]);
        if (r != 0) {
            func_08863E70(anim, r, arg0->unk32C[0], arg0->unk334[0], 0);
        }
    }
    if ((bool) (arg0->unk614 & 0x100) == 0) {
        arg0->unk614 |= 0x100;
        r = arg0->vfunc_20(arg0->unk324[1]);
        if (r != 0) {
            func_08863E70(anim, r, arg0->unk32C[1], arg0->unk334[1], 1);
        }
    }
    func_08865648(arg0);
}

void func_088D5EF0(Obj *arg0, s32 arg1) {
    arg0->unk67E = arg0->unk67E + arg1;
    if (arg0->unk67E > 100) {
        arg0->unk67E = 100;
    } else if (arg0->unk67E < -100) {
        arg0->unk67E = -100;
    }
}

void func_088D5F30(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 i;

    if (arg3 == -1) {
        for (i = 0; i < arg0->unk1A2; i++) {
            arg2 = arg0->vfunc_20(arg1 + (s32) (i * 100));
            func_08863D58(&arg0->unk80, arg2, i, 0.0f);
        }
    } else {
        func_08863D58(&arg0->unk80, arg2, arg3, 0.0f);
    }
    arg0->unk324[0] = arg1;
}

void func_088D5FE4(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, float arg4) {
    u32 i;

    if (arg3 == -1) {
        for (i = 0; i < arg0->unk1A2; i++) {
            arg2 = arg0->vfunc_20(arg1 + (s32) (i * 100));
            func_08863DF4(&arg0->unk80, arg2, (u32) arg4, i, 0.0f);
        }
    } else {
        func_08863DF4(&arg0->unk80, arg2, (u32) arg4, arg3, 0.0f);
    }
}

}
