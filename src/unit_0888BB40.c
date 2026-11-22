/* unit_0888BB40: 0x0888BB40-0x0888BC40 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

typedef struct {
    char pad[0xC];
    float limit;
} Unk;

s32 func_0888BB40(char *arg0, float *out, Unk *arg2, float *arr, s32 n) {
    float v;
    float best;
    s32 result;

    v = *arr;
    if (v < 0.0f) {
        *out = 0.0f;
        best = -v;
        result = -1;
    } else if (v > arg2->limit) {
        best = v - arg2->limit;
        *out = arg2->limit;
        result = 1;
    } else {
        *out = v;
        return 0;
    }
    if (n == 1) {
        return result;
    }
    for (n--; n != 0; n--) {
        arr++;
        v = *arr;
        if (v < 0.0f) {
            v = -v;
            if (best > v) {
                best = v;
                *out = 0.0f;
                result = -1;
            }
        } else if (v > arg2->limit) {
            v -= arg2->limit;
            if (best > v) {
                *out = arg2->limit;
                best = v;
                result = 1;
            }
        } else {
            *out = v;
            return 0;
        }
    }
    return result;
}
