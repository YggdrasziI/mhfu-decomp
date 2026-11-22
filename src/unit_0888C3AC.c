/* unit_0888C3AC: 0x0888C3AC-0x0888C794 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

typedef struct {
    float x, y, z, t;
} Key;

extern float D_08A62DA0[][4][4];
extern void func_0888C794(s32, float *, float *, float *, float *, float *, s32);
extern float func_08897D4C(float, float);

void func_0888C3AC(s32 arg0, Key *p, s32 n) {
    struct {
        float a[16];
        float b[16];
        float c[16];
        float dx[16];
        float dy[16];
        float dz[16];
        float ox[16];
        float oy[16];
        float oz[16];
    } w;
    s32 i;
    float (*m)[4];
    s32 j;
    float r0, r1;
    float inv, inv2, inv3;

    w.a[0] = 0.0f;
    w.c[0] = p[0].t;
    w.b[0] = p[0].t + p[0].t;
    w.dx[0] = 3.0f * (p[1].x - p[0].x);
    w.dy[0] = 3.0f * (p[1].y - p[0].y);
    w.dz[0] = 3.0f * (p[1].z - p[0].z);
    for (i = 1; i < n - 1; i++) {
        r0 = p[i].t / p[i - 1].t;
        r1 = p[i - 1].t / p[i].t;
        w.a[i] = p[i].t;
        w.b[i] = 2.0f * (p[i - 1].t + p[i].t);
        w.c[i] = p[i - 1].t;
        w.dx[i] = 3.0f * (r0 * (p[i].x - p[i - 1].x) + r1 * (p[i + 1].x - p[i].x));
        w.dy[i] = 3.0f * (r0 * (p[i].y - p[i - 1].y) + r1 * (p[i + 1].y - p[i].y));
        w.dz[i] = 3.0f * (r0 * (p[i].z - p[i - 1].z) + r1 * (p[i + 1].z - p[i].z));
    }
    w.a[n - 1] = p[n - 2].t;
    w.b[n - 1] = p[n - 2].t + p[n - 2].t;
    w.c[n - 1] = 0.0f;
    w.dx[n - 1] = 3.0f * (p[n - 1].x - p[n - 2].x);
    w.dy[n - 1] = 3.0f * (p[n - 1].y - p[n - 2].y);
    w.dz[n - 1] = 3.0f * (p[n - 1].z - p[n - 2].z);
    func_0888C794(arg0, w.ox, w.a, w.b, w.c, w.dx, n);
    func_0888C794(arg0, w.oy, w.a, w.b, w.c, w.dy, n);
    func_0888C794(arg0, w.oz, w.a, w.b, w.c, w.dz, n);
    m = D_08A62DA0[0];
    for (j = 0; j < n - 1; j++, m += 4) {
        inv = 1.0f / p[j].t;
        inv2 = inv * inv;
        inv3 = 1.0f / func_08897D4C(p[j].t, 3.0f);
        m[0][0] = inv2 * (w.ox[j] + w.ox[j + 1]) + inv3 * (2.0f * (p[j].x - p[j + 1].x));
        m[1][0] = inv2 * (3.0f * (p[j + 1].x - p[j].x)) - inv * (2.0f * w.ox[j] + w.ox[j + 1]);
        m[2][0] = w.ox[j];
        m[3][0] = p[j].x;
        m[0][1] = inv2 * (w.oy[j] + w.oy[j + 1]) + inv3 * (2.0f * (p[j].y - p[j + 1].y));
        m[1][1] = inv2 * (3.0f * (p[j + 1].y - p[j].y)) - inv * (2.0f * w.oy[j] + w.oy[j + 1]);
        m[2][1] = w.oy[j];
        m[3][1] = p[j].y;
        m[0][2] = inv2 * (w.oz[j] + w.oz[j + 1]) + inv3 * (2.0f * (p[j].z - p[j + 1].z));
        m[1][2] = inv2 * (3.0f * (p[j + 1].z - p[j].z)) - inv * (2.0f * w.oz[j] + w.oz[j + 1]);
        m[2][2] = w.oz[j];
        m[3][2] = p[j].z;
    }
}
