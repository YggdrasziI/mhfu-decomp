/* unit_0884FAC4: 0x0884FAC4-0x0884FAFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FAC4: set bit (arg1 & 15) of halfword word (arg1 / 16) in a bit array at 0x508. */

typedef unsigned short u16;

typedef struct {
    char pad[0x508];
    u16 bits[1];
} Obj;

void func_0884FAC4(Obj *arg0, int arg1) {
    u16 m = 1 << (arg1 & 0xF);
    arg0->bits[arg1 / 16] |= m;
}
