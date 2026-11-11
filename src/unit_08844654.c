/* unit_08844654: 0x08844654-0x0884469C (ULES01213)
 *
 * Bounds (hypothesis): 1 test on a call result, between unrelated code.
 */

typedef unsigned char u8;

extern char *D_089CC438;
extern u8 func_088D6AC8(int a, int b);
extern int func_088568AC(char *p, int a);

int func_08844654(void *unused, int a) {
    u8 v = func_088D6AC8(a, 0x33);

    if (v != 0) {
        return v == 0x85;
    }
    return func_088568AC(D_089CC438, 0x35F) != 0;
}
