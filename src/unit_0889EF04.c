/* unit_0889EF04: 0x0889EF04-0x0889EF20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef struct { char b[16]; } E16;

extern char D_089B1FFC;
extern void sceKernelSignalSema(s32, s32);

void func_0889EF04(s32 arg0) {
    sceKernelSignalSema(*(s32 *)((E16 *)((&D_089B1FFC)))[arg0].b, 1);
}
