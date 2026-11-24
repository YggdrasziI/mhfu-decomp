/* unit_08852618: 0x08852618-0x088526B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852618: piecewise linear interpolation over a table of
 * (key, value) float pairs ended by a key of -1.0f; the first argument
 * is unused. Past the end, the last value is returned. */

typedef int s32;

typedef struct {
    float key;
    float val;
} Pt;

void func_08852618(s32 arg0, float x, Pt *tbl, float *out) {
    float r;

    while (1) {
        if (tbl->key == -1.0f) {
            break;
        }
        if (x == tbl->key) {
            *out = tbl->val;
            return;
        }
        if (x > tbl->key && x < tbl[1].key) {
            r = (x - tbl->key) / (tbl[1].key - tbl->key);
            *out = tbl->val + r * (tbl[1].val - tbl->val);
            return;
        }
        tbl++;
    }
    *out = tbl[-1].val;
}
