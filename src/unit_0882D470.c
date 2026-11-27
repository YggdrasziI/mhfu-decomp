/* unit_0882D470: 0x0882D470-0x0882D6F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma opt_propagation off
#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern float D_08938738[2];
extern float D_08938740[2];
extern float D_08938748[2];
extern float D_08938750[2];

extern void func_0882CF58(char *arg0, s16 *pts, u8 r, u8 g, u8 b, u8 a, s32 idx);

static inline float cos_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0882D470(char *arg0, u16 cx, u16 cy, s32 ox, s32 oy, u32 w, u32 h, s32 rot, u8 a, s32 idx) {
    s16 pts[8];
    float ang;
    float s;
    float c;
    float fw;
    float fh;
    float x;
    float y;

    ang = 9.58738e-05f * -(float)rot;
    s = sin_vfpu(ang);
    c = cos_vfpu(ang);
    fw = w;
    fh = h;
    x = fw * D_08938738[0] - ox;
    y = fh * D_08938738[1] - oy;
    pts[0] = cx + (s16)(c * x + s * y);
    pts[1] = cy + (s16)(-s * x + c * y);
    x = fw * D_08938740[0] - ox;
    y = fh * D_08938740[1] - oy;
    pts[2] = cx + (s16)(c * x + s * y);
    pts[3] = cy + (s16)(-s * x + c * y);
    x = fw * D_08938748[0] - ox;
    y = fh * D_08938748[1] - oy;
    pts[4] = cx + (s16)(c * x + s * y);
    pts[5] = cy + (s16)(-s * x + c * y);
    x = fw * D_08938750[0] - ox;
    y = fh * D_08938750[1] - oy;
    pts[6] = cx + (s16)(c * x + s * y);
    pts[7] = cy + (s16)(-s * x + c * y);
    func_0882CF58(arg0, pts, 0xFF, 0xFF, 0xFF, a, idx);
}
