/* unit_0884F3FC: 0x0884F3FC-0x0884F440 (ULES01213)
 *
 * Bounds (hypothesis): 1 comparison of a 20-byte entry, between unrelated code.
 */

typedef unsigned short u16;

extern int func_0880BFF0(void *a, void *b, int n);
extern char D_08979804[][20];
extern char D_089CC420[];

int func_0884F3FC(void *unused, u16 i) {
    return func_0880BFF0(D_08979804[i], D_089CC420, 0x14) != 0;
}
