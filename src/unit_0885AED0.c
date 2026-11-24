/* unit_0885AED0: 0x0885AED0-0x0885AF28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef struct { u16 key; s16 val; } Pair;
extern char *D_089CC438;

typedef struct { char pad[0x3F28]; Pair e[24]; } T;
s32 func_0885AED0(char *arg0, u16 key) {
    T *p = (T *)(D_089CC438 + 0x4A0);
    s16 i;
    for (i = 0; i < 24; i++) {
        if (p->e[i].key == key) {
            return p->e[i].val;
        }
    }
    return 0;
}
