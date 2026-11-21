/* unit_0890383C: 0x0890383C-0x089038C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Looks up the 94 strings indexed by the u16 table D_09B05A18: each one is
 * copied to a stack buffer and compared with D_089B916C; returns the index of
 * the first one for which the comparison returns 0, or 94. The
 * comparison callee is undeclared elsewhere in src/; its prototype is a
 * hypothesis (two pointers, int result).
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;

extern s32 D_09B22D70;
extern u16 D_09B05A18[];
extern char D_089B916C[];

extern char *func_09A7B790(s32, u16);
extern int func_0880ED70(char *, char *);
extern int func_0880ED04(char *, char *);

s32 func_0890383C(char *arg0) {
    char buf[128];
    s32 n = 0;
    s32 i;

    for (i = 0; i < 94; i++) {
        func_0880ED70(buf, func_09A7B790(D_09B22D70, D_09B05A18[i]));
        if (func_0880ED04(buf, D_089B916C) == 0) {
            break;
        }
        n++;
    }
    return n;
}
