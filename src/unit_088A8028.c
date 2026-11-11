/* unit_088A8028: 0x088A8028-0x088A8048 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

extern int D_09A1D590;
extern int D_09A1D578;

int func_088A8028(char *o, int a, int b) {
    *(int *)(o + 0x120) = a;
    *(int *)(o + 0x12C) = b;
    D_09A1D590 = 0;
    D_09A1D578 = 0;
    return -a;
}
