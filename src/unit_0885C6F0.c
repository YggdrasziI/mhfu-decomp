/* unit_0885C6F0: 0x0885C6F0-0x0885C718 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885C6F0: returns whether the u16 field of the 24-byte D_0899D1AE
 * entry selected by arg1 is non-zero. */

typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 unk0;
    char pad2[0x16];
} Entry24;

extern Entry24 D_0899D1AE[];

s32 func_0885C6F0(s32 arg0, u16 arg1) {
    return D_0899D1AE[arg1].unk0 != 0;
}
