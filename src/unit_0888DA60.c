/* unit_0888DA60 (ULES01213)
 *
 * Root search of a degree-5 polynomial (hypothesis: Durand-Kerner): the
 * coefficients are normalised by the leading one, the initial guesses are a
 * constant table scaled by a bound, then 26 refinement passes over the five
 * complex roots stored as (re, im) pairs. The absolute value is VFPU code in
 * an `asm` block.
 *
 * Optimized for speed: the float constants are built as immediates.
 *
 * The table globals are `const` so that each load stays next to its product.
 * The corrected root is a new pair (ur, ui) set in both arms of the if/else:
 * updating pr / ni in place gives a `bc1tl` with a copied slot instead of
 * `bc1t` + `nop`.
 */

#pragma optimize_for_size off

typedef int s32;

extern const float D_089AD1DC;
extern const float D_089AD1E0[2];
extern const float D_089AD1E8[2];
extern const float D_089AD1F0[2];
extern const float D_089AD1F8[2];
extern const float D_089AD200;
extern float D_089AD204[];

extern float func_08897D4C(float, float);

static inline float abs_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vabs.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0888DA60(void *arg0, float *z, float *coef) {
    float c[6];
    float inv;
    float bound;
    float r;
    s32 i;
    s32 it;
    s32 j;
    s32 k;

    inv = 1.0f / coef[0];
    c[1] = inv * coef[1];
    c[2] = inv * coef[2];
    c[3] = inv * coef[3];
    c[4] = inv * coef[4];
    c[5] = inv * coef[5];

    bound = 0.0f;
    for (i = 2; i <= 5; i++) {
        r = func_08897D4C(abs_vfpu(c[i]), D_089AD204[i]);
        if (r > bound) {
            bound = r;
        }
    }
    bound = bound * 5.0f;
    z[0] = bound * D_089AD1DC;
    z[1] = bound * D_089AD1E0[0];
    z[2] = bound * D_089AD1E0[1];
    z[3] = bound * D_089AD1E8[0];
    z[4] = bound * D_089AD1E8[1];
    z[5] = bound * D_089AD1F0[0];
    z[6] = bound * D_089AD1F0[1];
    z[7] = bound * D_089AD1F8[0];
    z[8] = bound * D_089AD1F8[1];
    z[9] = bound * D_089AD200;

    for (it = 25; it >= 0; it--) {
        for (j = 0; j < 5; j++) {
            float qi;
            float qr;
            float pr;
            float pi;
            float zi;
            float zr;
            float n;
            float ni;
            float ur;
            float ui;

            zr = z[j * 2];
            zi = z[j * 2 + 1];
            qr = 1.0f;
            qi = 0.0f;
            pr = 1.0f;
            pi = 0.0f;

            for (k = 0; k < 5; k++) {
                ni = pr * zi + pi * zr;
                pr = pr * zr - pi * zi;
                pr += c[k + 1];
                pi = ni;
                if (k != j) {
                    float dr = zr - z[k * 2];
                    float di = zi - z[k * 2 + 1];
                    float nqi = qr * di + qi * dr;
                    qr = qr * dr - qi * di;
                    qi = nqi;
                }
            }
            n = qr * qr + qi * qi;
            if (n >= 1e-3f) {
                float s = 1.0f / n;
                float a = ni * qr - pr * qi;
                float b = pr * qr + ni * qi;
                ur = s * b;
                ui = s * a;
            } else {
                ur = pr;
                ui = ni;
            }
            z[j * 2] = zr - ur;
            z[j * 2 + 1] = zi - ui;
        }
    }
}
