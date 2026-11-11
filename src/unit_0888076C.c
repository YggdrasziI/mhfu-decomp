/* unit_0888076C: 0x0888076C-0x0888080C (ULES01213)
 *
 * Bounds (hypothesis): three forwarders between unrelated code; the last two pass
 * seven arguments (registers $a0-$a3, $t0-$t2) to the first.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 D_089AC564[];
extern void *D_08A62D84;
extern u8 D_089AA224[][4];
extern u8 D_089AA250[];
extern void func_08880350(void *p, u16 v, int a, int b, int c, int d, int e);

void func_0888076C(void *unused, int i, int a, int b, int c, int d, int e) {
    func_08880350(D_08A62D84, D_089AC564[i], a, b, c, d, e);
}

void func_0888078C(void *p, u16 i) {
    func_0888076C(p, D_089AA224[D_089AA250[i]][0], 0, 0, 0x1000, 1, 1);
}

void func_088807CC(void *p, u16 i) {
    func_0888076C(p, D_089AA224[D_089AA250[i]][0], 0, 0, 0, 1, 1);
}
