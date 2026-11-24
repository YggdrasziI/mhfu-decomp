/* unit_08852200: 0x08852200-0x088522CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852200: piecewise-linear lookup in a key table ended by -1.0f.
 *
 * Out.c is volatile: the original stores 1.0f to it at the top of every loop
 * iteration, which the compiler otherwise hoists out of the loop.
 */

typedef int s32;

typedef struct {
    float t;
    float a;
    float b;
} Key;

typedef struct {
    float a;
    float b;
    volatile float c;
} Out;

void func_08852200(s32 arg0, float x, Key *k, Out *out) {
    while (1) {
        float t;

        out->c = 1.0f;
        t = k->t;
        if (t == -1.0f) {
            break;
        }
        if (x == t) {
            out->a = k->a;
            out->b = k->b;
            return;
        }
        if (x > t) {
            float n = k[1].t;
            if (x < n) {
                float r = (x - t) / (n - t);
                out->a = k->a + r * (k[1].a - k->a);
                out->b = k->b + r * (k[1].b - k->b);
                return;
            }
        }
        k++;
    }
    out->a = k[-1].a;
    out->c = k[-1].b;
}
