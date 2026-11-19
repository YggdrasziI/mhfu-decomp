/* unit_088D1398: 0x088D1398-0x088D168C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between the asm piece text_088CF2C8 and
 * text_088D168C.
 *
 * Key-frame tables read at the current frame of the animation at +0x80: the
 * value of the last key (time -1), or the linear interpolation of the two
 * keys around the frame.
 *
 * C++: bool conversion. Optimized for speed. The vector is built with a VFPU
 * `asm` block (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Key4 {
    float t;
    float x;
    float y;
    float z;
} Key4;

typedef struct Key3 {
    float t;
    float a;
    float b;
} Key3;

extern "C" {

extern s32 func_08864408(float, char *, s32);

static inline bool is_end(float t) {
    return -1.001f < t && t < -0.999f;
}

static inline void vec_set(float *dst, float x, float y, float z) {
    float w = 0.0f;
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

void func_088D1398(char *arg0, Key4 *arg1, float *arg2) {
    for (;; arg1++) {
        if (is_end(arg1->t)) {
            vec_set(arg2, arg1->x, arg1->y, arg1->z);
            return;
        }
        if (func_08864408(arg1->t, arg0 + 0x80, 0) != 0 && (u8) func_08864408(arg1[1].t, arg0 + 0x80, 0) == 0) {
            arg2[0] = arg1->x + (arg1[1].x - arg1->x) * ((*(float *)(arg0 + 0x90) - arg1->t) / (arg1[1].t - arg1->t));
            arg2[1] = arg1->y + (arg1[1].y - arg1->y) * ((*(float *)(arg0 + 0x90) - arg1->t) / (arg1[1].t - arg1->t));
            arg2[2] = arg1->z + (arg1[1].z - arg1->z) * ((*(float *)(arg0 + 0x90) - arg1->t) / (arg1[1].t - arg1->t));
            return;
        }
    }
}

void func_088D153C(char *arg0, Key3 *arg1, float *arg2, float *arg3) {
    for (;; arg1++) {
        if (is_end(arg1->t)) {
            *arg2 = arg1->a;
            *arg3 = arg1->b;
            return;
        }
        if (func_08864408(arg1->t, arg0 + 0x80, 0) != 0 && (u8) func_08864408(arg1[1].t, arg0 + 0x80, 0) == 0) {
            *arg2 = arg1->a + (arg1[1].a - arg1->a) * ((*(float *)(arg0 + 0x90) - arg1->t) / (arg1[1].t - arg1->t));
            *arg3 = arg1->b + (arg1[1].b - arg1->b) * ((*(float *)(arg0 + 0x90) - arg1->t) / (arg1[1].t - arg1->t));
            return;
        }
    }
}

}
