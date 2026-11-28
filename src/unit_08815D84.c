/* unit_08815D84: 0x08815D84-0x08815E28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern void func_08897DE0(Vec *out, Vec *v, float angle);
extern void func_08897D7C(Mtx *out, Vec *q);

void func_08815D84(Vec *arg0, Vec *arg1, Vec *arg2, float arg3) {
    Vec v;
    Vec q;
    Mtx m;
    Vec *pv;
    Mtx *pm;

    v.x = arg2->x - arg1->x;
    v.y = arg2->y - arg1->y;
    v.z = arg2->z - arg1->z;
    v.w = 1.0f;
    func_08897DE0(&q, &v, arg3);
    func_08897D7C(&m, &q);
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    pv = &v;
    pm = &m;
    asm {
        lv.q C100, 0(pv)
        lv.q C200, 0(pm)
        lv.q C210, 0x10(pm)
        lv.q C220, 0x20(pm)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0(arg0)
    }
}
