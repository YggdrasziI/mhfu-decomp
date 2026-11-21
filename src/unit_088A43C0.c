/* unit_088A43C0: 0x088A43C0-0x088A4408 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, calls func_088A4408 on each of 32
 * 0x2C-byte entries of D_09A0E3CC.
 */

typedef unsigned int u32;

typedef struct {
    char unk0[0x2C];
} T;

extern T D_09A0E3CC[];
extern void func_088A4408(T *);

void func_088A43C0(void) {
    u32 i;
    T *p;

    for (i = 0, p = D_09A0E3CC; i < 32; i++) {
        func_088A4408(p);
        p++;
    }
}
