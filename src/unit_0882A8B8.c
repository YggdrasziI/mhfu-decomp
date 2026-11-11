/* unit_0882A8B8: 0x0882A8B8-0x0882A8FC (ULES01213)
 *
 * Bounds (hypothesis): 1 state code from a byte field, between unrelated code.
 */

typedef unsigned char u8;

extern char *func_0883B3D4(void);

int func_0882A8B8(void) {
    char *p = func_0883B3D4();

    if (p == 0) {
        return 3;
    }
    switch (*(u8 *)(p + 0xBF)) {
    case 0:
        return 2;
    case 5:
        return 1;
    default:
        return 0;
    }
}
