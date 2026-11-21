/* unit_088D168C: 0x088D168C-0x088D18F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D1398 and unit_088D18F0.
 *
 * NonMatching, 98.79 %. The test is written `!= 0`: the id is then read
 * first (`lh a1`) and the global kept in a0 as in the original, the offset
 * split as `lui v1, 7` / `lw -0x50EC`. The only gap is the compare: the
 * original tests against 1 (`addiu v1, zero, 1` after the `andi`, flag in
 * a0, `bnel a0, v1`), ours branches with `beqzl v1`. Every `== 1` form with
 * the load written in the condition (casts and types of the constant,
 * `== true`, switch, goto, typed structure, structure-pointer local, bit
 * fields, `void *` parameter with all 720 declaration orders, scale stores
 * moved) loads the global before the id and swaps the registers. Forms that
 * go through a single-use temporary (an `s32` flag local, an inline helper
 * returning the word or the bool, a pointer local, a manual
 * `+ 0x70000 - 0x50EC` split) give the original registers but add the
 * offset with `lui at` / `ori at` (97.54 %); a local used twice keeps the
 * split but swaps the registers again.
 *
 * C++: bool conversion, member function. Optimized for speed.
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

extern s32 func_08864408(float, char *, s32);
extern void func_08865044(char *, float *, s32, Vec *, Vec *, Vec *);
extern void func_088D18F0(char *arg0, float *arg1, s32 arg2);
extern void func_088D1978(char *arg0, u16 arg1);

struct VecC {
    float x;
    float y;
    float z;
    float w;
    void set(float x_, float y_, float z_, float w_) {
        float *dst = &x;
        float *px = &x_;
        float *py = &y_;
        float *pz = &z_;
        float *pw = &w_;
        asm {
            lv.s S000, 0(px)
            lv.s S001, 0(py)
            lv.s S002, 0(pz)
            lv.s S003, 0(pw)
            sv.q C000, 0(dst)
        }
    }
} __attribute__((aligned(16)));

void func_088D168C(char *arg0) {
    VecC rot;
    VecC pos;
    VecC scale;
    float mtx[16] __attribute__((aligned(16)));
    s16 id;

    id = *(s16 *)(arg0 + 0x324);
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) {
        id -= 0x3E8;
    }
    scale.z = 1.0f;
    scale.y = 1.0f;
    scale.x = 1.0f;
    switch (id) {
    case 0x19F: {
        rot.set(0.36651915f, 0.17453294f, 1.3613569f, 0.0f);
        pos.set(17.0f, 0.9f, 22.0f, 0.0f);
        func_08865044(arg0, mtx, 0xE, (Vec *) &pos, (Vec *) &rot, (Vec *) &scale);
        func_088D18F0(arg0, mtx, 0x46);
        return;
    }
    case 0x1A2:
        if (func_08864408(118.0f, arg0 + 0x80, 0) == 0) {
            rot.set(0.0f, 3.1415927f, 3.1415927f, 0.0f);
            pos.set(-9.0f, -1.0f, 65.0f, 0.0f);
            func_08865044(arg0, mtx, 0x12, (Vec *) &pos, (Vec *) &rot, (Vec *) &scale);
            func_088D18F0(arg0, mtx, 0x47);
        }
        break;
    case 0x324:
    case 0x325:
    case 0x326:
    case 0x327:
    case 0x328:
    case 0x329:
        func_088D1978(arg0, id);
        break;
    default:
        return;
    }
}

}
