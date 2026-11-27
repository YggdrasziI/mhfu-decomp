/* unit_0885F434: 0x0885F434-0x0885F7D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F434: clears bits 1 and 5 (& 0xDD) of three contiguous byte
 * arrays at D_089CC438 + 0x4A0 + 0x6A598 (415), + 0x6A14C (1100) and
 * + 0x6A737 (100). Speed setting (loops unrolled by 8); the arrays must be
 * members of one structure (p->b[i]) so the loop body adds the offset once.
 */
#pragma optimize_for_size off
typedef unsigned char u8;
typedef int s32;

typedef struct {
    char pad[0x6A14C];
    u8 a[1100];
    u8 b[415];
    u8 c[100];
} S;

extern char *D_089CC438;

void func_0885F434(char *arg0) {
    S *p = (S *)(D_089CC438 + 0x4A0);
    s32 i;

    for (i = 0; i < 415; i++) {
        p->b[i] &= 0xDD;
    }
    for (i = 0; i < 1100; i++) {
        p->a[i] &= 0xDD;
    }
    for (i = 0; i < 100; i++) {
        p->c[i] &= 0xDD;
    }
}
