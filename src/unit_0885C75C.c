/* unit_0885C75C: 0x0885C75C-0x0885C818 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s16 a;
    s16 b;
} Entry;

extern char *D_08A62C50;

extern s32 func_0885AED0(char *, u16);
extern s32 func_0885C33C(char *, u16);

s32 func_0885C75C(s32 arg0, u16 *ids, s32 count, Entry *out) {
    s32 n;
    s32 i;
    s16 a;
    s32 b;

    n = 0;
    for (i = 0; i < count; i++) {
        a = func_0885AED0(D_08A62C50, ids[i]);
        b = func_0885C33C(D_08A62C50, ids[i]);
        if (a + b > 0) {
            out[n].id = ids[i];
            out[n].a = a;
            out[n].b = b;
            n++;
        }
    }
    return n;
}
