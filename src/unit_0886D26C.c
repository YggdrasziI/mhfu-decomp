/* unit_0886D26C: 0x0886D26C-0x0886D28C (ULES01213)
 *
 * Bounds (hypothesis): one forwarder between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void *D_09CD7EB0[];
extern int func_0887265C(void *p, int v);

int func_0886D26C(void *unused, u16 i) {
    return func_0887265C(D_09CD7EB0[i], 0);
}
