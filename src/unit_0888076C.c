/* unit_0888076C: 0x0888076C-0x0888078C (ULES01213)
 *
 * Bounds (hypothesis): one forwarder between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 D_089AC564[];
extern void *D_08A62D84;
extern void func_08880350(void *p, u16 v);

void func_0888076C(void *unused, int i) {
    func_08880350(D_08A62D84, D_089AC564[i]);
}
