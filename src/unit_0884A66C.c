/* unit_0884A66C: 0x0884A66C-0x0884A6CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884A66C: formats one or two u16 values into the shared text buffer
 * D_08A631A8, depending on bit 0 of the byte at 0x5E6.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A8;
extern char D_0893B78C[];
extern char D_0893B794[];

extern int func_0889134C(char *, char *, ...);

void func_0884A66C(char *arg0, u16 arg1, u16 arg2) {
    if (!(*(u8 *)(arg0 + 0x5E6) & 1)) {
        func_0889134C(D_08A631A8, D_0893B78C, arg1, arg2);
    } else {
        func_0889134C(D_08A631A8, D_0893B794, arg1);
    }
}
