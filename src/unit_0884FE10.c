/* unit_0884FE10: 0x0884FE10-0x0884FE80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FE10: sets the bit of an id in a bit set at offset 0x4428. */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x4428];
    u32 bits[1];
} Obj;

extern u16 func_0884FDC4(Obj *arg0, u16 arg1);

void func_0884FE10(Obj *arg0, u16 arg1) {
    u16 idx = func_0884FDC4(arg0, arg1);
    u16 bit;

    if (idx != 0xFFFF) {
        bit = (int)idx % 32;
        arg0->bits[(u16)((u32)idx >> 5)] |= 1 << bit;
    }
}
