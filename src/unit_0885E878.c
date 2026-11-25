/* unit_0885E878: 0x0885E878-0x0885E950 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E878: looks up the entry func_0885E834(arg0, arg2) and tests its
 * flag byte (offset 1) against the kind byte of arg1: kind 6 tests bit 1,
 * kind 5 tests bit 0, kinds below 5 test bits 2-3 of byte 4 of the record
 * func_0885CB68(arg0, kind, arg1->id). Returns 1 when the bit is set.
 * The kind bound is written `> 4` (`>= 5` puts the slti result in v0, not at).
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 f0;
    u8 kind;
    s16 id;
} Key;

extern u8 *func_0885E834(s32, s32);
extern u8 *func_0885CB68(s32, u8, s16);

s32 func_0885E878(s32 arg0, Key *arg1, s32 arg2) {
    u8 *p = func_0885E834(arg0, arg2);

    if (p == 0) {
        return 0;
    }
    switch (arg1->kind) {
    case 5:
        if (p[1] & 1) {
            return 1;
        }
        break;
    case 6:
        if (p[1] & 2) {
            return 1;
        }
        break;
    default:
        if (arg1->kind > 4) {
            return 0;
        }
        if (p[1] & (u8)(func_0885CB68(arg0, arg1->kind, arg1->id)[4] & 0xC)) {
            return 1;
        }
        break;
    }
    return 0;
}
