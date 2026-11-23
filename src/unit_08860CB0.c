/* unit_08860CB0: 0x08860CB0-0x08860EC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08860CB0: blends a stored RGB colour toward a target vector. */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef union Color {
    u32 w;
    u8 c[4];
} Color;

typedef struct Vec { float f[12]; } Vec;
typedef struct Obj {
    char pad[0x2AC];
    Color colors[1];
} Obj;

void func_08860CB0(Color *out, char *arg1, Obj *arg2, s32 idx) {
    float *v = ((Vec *)(arg1 + 0xC0))[idx].f;
    float g;
    float r;
    float b;
    Color tmp;

    if (arg2->colors[idx].w == 0) {
        r = v[0];
        g = v[1];
        b = v[2];
    } else {
        r = (float)(u32)arg2->colors[idx].c[0] / 255.0f;
        g = (float)(u32)arg2->colors[idx].c[1] / 255.0f;
        b = (float)(u32)arg2->colors[idx].c[2] / 255.0f;
        r = r + (v[0] - r) / 5.0f;
        g = g + (v[1] - g) / 5.0f;
        b = b + (v[2] - b) / 5.0f;
    }
    tmp.c[0] = 255.0f * r;
    tmp.c[1] = 255.0f * g;
    tmp.c[2] = 255.0f * b;
    tmp.c[3] = 0xFF;
    arg2->colors[idx].w = tmp.w;
    *out = tmp;
}
