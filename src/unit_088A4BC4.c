/* unit_088A4BC4: 0x088A4BC4-0x088A4BE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, returns the result of func_088A489C
 * when negative, 0 otherwise.
 */

typedef unsigned int u32;
typedef int s32;

extern s32 func_088A489C(u32);

s32 func_088A4BC4(u32 a0) {
    s32 ret;

    ret = func_088A489C(a0);
    if (ret < 0) {
        return ret;
    }
    return 0;
}
