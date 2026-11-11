/* unit_08825104: 0x08825104-0x08825148 (ULES01213)
 *
 * Bounds (hypothesis): 1 section-0 entry lookup through a table, between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *func_0885151C(char *a, u16 e);
extern u16 D_089AD020[];

char *func_08825104(int unused, u8 *p) {
    if (p == 0) {
        return 0;
    }
    return func_0885151C(D_089CC438, D_089AD020[p[5]]);
}
