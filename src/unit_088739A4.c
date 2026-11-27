/* unit_088739A4: 0x088739A4-0x08873A0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef short s16;
typedef int s32;

typedef struct {
    s16 a;
    s16 b;
} Pair;

extern char *D_089CC438;

void func_088739A4(char *arg0) {
    Pair *p = (Pair *)(D_089CC438 + 0x390);
    s32 i;

    for (i = 0; i < 32; i++) {
        p->a = 0;
        p->b = 0;
        p++;
    }
}
