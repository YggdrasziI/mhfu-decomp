/* unit_0888E28C: 0x0888E28C-0x0888E324 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;

typedef struct {
    char pad[0x5C];
    s16 cur[2];  /* 0x5C */
    s16 base[2]; /* 0x60 */
} Sub;

typedef struct {
    char pad[0x94];
    s16 num;     /* 0x94 */
    s16 den;     /* 0x96 */
    char pad2[0xA0 - 0x98];
    Sub sub;     /* 0xA0 */
} Obj;

void func_0888E28C(Obj *arg0, s16 *out) {
    Sub *s = &arg0->sub;

    if (arg0->den > 0) {
        out[0] = s->cur[0] - s->base[0];
        out[0] = s->base[0] + out[0] * arg0->num / arg0->den;
        out[1] = s->cur[1] - s->base[1];
        out[1] = s->base[1] + out[1] * arg0->num / arg0->den;
    } else {
        out[0] = s->cur[0];
        out[1] = s->cur[1];
    }
}
