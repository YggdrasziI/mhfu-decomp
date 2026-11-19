/* unit_088D18F0: 0x088D18F0-0x088D1DD0 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between text_088D168C and unit_088D1DD0.
 *
 * C++: bool conversions. Optimized for speed.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x;
    float y;
    float z;
    float w;
} Vec;

extern "C" {

extern char *D_089CC438;
extern char *D_09D19760;

extern s32 func_0886171C(char *, s32, char *, u8);
extern void func_08862354(float *, char *);
extern void func_088629DC(char *, u16, s32, s32, s32);
extern s32 func_08864408(float, char *, s32);
extern void func_08865044(char *, float *, s32, Vec *, Vec *, Vec *);
extern s32 func_088D6A1C(char *, s32);

void func_088D18F0(char *arg0, float *arg1, s32 arg2);
void func_088D1978(char *arg0, u16 arg1);

void func_088D18F0(char *arg0, float *arg1, s32 arg2) {
    char *a;
    char *b;

    a = D_09D19760 + 0x19040;
    b = D_09D19760 + 0x19460;
    func_08862354(arg1, a + 0x10);
    func_088629DC(a, arg2, 0x80, 0x80, 0x80);
    func_0886171C(a, 0, b, arg2);
}

void func_088D1978(char *arg0, u16 arg1) {
    float mtx[16] __attribute__((aligned(16)));
    Vec pos;
    Vec rot;
    Vec scale;
    s32 id;

    switch (arg1) {
    case 0x327:
        if (func_08864408(20.0f, arg0 + 0x80, 0) == 0) {
            id = 0x44;
        } else if (func_08864408(30.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else {
            id = 0x82;
        }
        break;
    case 0x328:
        if (func_08864408(20.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else if (func_08864408(26.0f, arg0 + 0x80, 0) == 0) {
            id = 0x82;
        } else if (func_08864408(28.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else {
            id = 0x44;
        }
        break;
    case 0x329:
        if (func_08864408(36.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else if (func_08864408(40.0f, arg0 + 0x80, 0) == 0) {
            id = 0x82;
        } else if (func_08864408(42.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else {
            id = 0x44;
        }
        break;
    case 0x32A:
        if (func_08864408(20.0f, arg0 + 0x80, 0) == 0) {
            id = 0x83;
        } else if (func_08864408(22.0f, arg0 + 0x80, 0) != 0) {
            id = 0x82;
        } else if (func_08864408(24.0f, arg0 + 0x80, 0) != 0) {
            id = 0x83;
        } else {
            id = 0x44;
        }
        break;
    default:
        id = 0x44;
        break;
    }
    rot.z = -1.5707964f;
    pos.x = -9.2f;
    pos.y = -1.7f;
    pos.z = 12.0f;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    rot.x = 0.0f;
    rot.y = 0.0f;
    func_08865044(arg0, mtx, 0x12, &pos, &rot, &scale);
    func_088D18F0(arg0, mtx, id);
}

u8 func_088D1BA8(char *arg0) {
    s16 v;
    u8 r;

    v = *(s16 *)(arg0 + 0x672);
    if ((u8) func_088D6A1C(arg0, 0xD7) == 1) {
        v = 1.25f * v;
    } else if ((u8) func_088D6A1C(arg0, 0xD8) == 1) {
        v = 0.8333333f * v;
    }
    if (v < 0x1E) {
        r = 0;
    } else if (v < 0x3C) {
        r = 1;
    } else if (v < 0x50) {
        r = 2;
    } else {
        r = 3;
    }
    if (((*(u16 *)(arg0 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == 1)) {
        *(u8 *)(arg0 + 0x60E) = r;
    } else {
        r = *(u8 *)(arg0 + 0x60E);
    }
    return r;
}

s32 func_088D1CA8(char *arg0) {
    s32 r;

    r = 0;
    if (*(u8 *)(arg0 + 0x298) != 1) {
        return 0;
    }
    switch (*(u8 *)(arg0 + 0x299)) {
    case 4:
        r = 2;
        break;
    case 5:
    case 6:
        r = 1;
        break;
    case 7:
    case 0x16:
    case 0x24:
    case 0x27:
        r = 3;
        break;
    }
    switch (*(u16 *)(arg0 + 0x324)) {
    case 0x584:
        if ((u8) func_08864408(72.0f, arg0 + 0x80, 0) == 0 || *(s8 *)(arg0 + 0xBE) != 0) {
            r = 0;
        }
        break;
    case 0x593:
    case 0x594:
    case 0x598:
        r = 0;
        break;
    }
    return r;
}

}
