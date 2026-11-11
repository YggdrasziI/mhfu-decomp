/* unit_08832838: 0x08832838-0x08832884 (ULES01213)
 *
 * Bounds (hypothesis): 1 flag test and clear with a call, between unrelated code.
 */

typedef unsigned int u32;

extern void func_08898748(int a, int b);
extern int D_09A0B540;

void func_08832838(char *p) {
    if (*(u32 *)(p + 0x528) & 0x1000) {
        func_08898748(D_09A0B540, 0xB);
        *(u32 *)(p + 0x528) &= ~0x1000;
    }
}
