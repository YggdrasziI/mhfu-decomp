/* unit_088344FC: 0x088344FC-0x08834548 (ULES01213)
 *
 * Bounds (hypothesis): 1 two-way step on a byte field, between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern void func_08834548(void *p);
extern u16 func_0884FB6C(char *p);

int func_088344FC(char *p) {
    if (*(u8 *)(p + 0x111D) == 0) {
        func_08834548(p);
        return 1;
    }
    *(u16 *)(p + 0x111E) = func_0884FB6C(D_089CC438);
    return 0;
}
