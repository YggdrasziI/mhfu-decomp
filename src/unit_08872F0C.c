/* unit_08872F0C: 0x08872F0C-0x08872FB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 func_08872DC4(char *, s32);
extern s32 func_0886E578(char *, u16, u16);
extern s32 func_0886E6F4(char *, u16);

s32 func_08872F0C(char *arg0) {
    s32 best;
    s32 i;
    s32 id;
    s32 r;
    s32 d;

    best = 0;
    for (i = 0; i < 2; i++) {
        id = func_08872DC4(arg0, i);
        r = func_0886E578(arg0, id, i);
        if (r >= 0) {
            d = r - func_0886E6F4(arg0, id);
            if (best < d) {
                best = d;
            }
        }
    }
    return !(best > 0);
}
