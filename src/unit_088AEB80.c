/* unit_088AEB80: 0x088AEB80-0x088AEC3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088AE988 and func_088AEC3C
 * (both still in assembly).
 *
 * Looks up the 16-bit code arg0 (high byte in D_089B284C, low byte in
 * D_089B2874) with the kind arg1 (D_089B289C) in a table of 38 entries
 * and calls the handler of the first match that has one (D_089B28C4).
 * Returns 1 when a handler ran. Optimized for speed (the table pointers
 * are stepped through the loop), and the code built as `c = hi << 8;
 * c |= lo;`: the one-expression forms swap the `or` operands or the two
 * byte pointers.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef void (*Handler)(void);

extern u8 D_089B284C[];
extern u8 D_089B2874[];
extern u8 D_089B289C[];
extern Handler D_089B28C4[];

s32 func_088AEB80(u16 code, u8 kind) {
    s32 i;
    u16 c;

    for (i = 0; i < 0x26; i++) {
        c = D_089B284C[i] << 8;
        c |= D_089B2874[i];
        if (code == c &&
            D_089B289C[i] == kind && D_089B28C4[i] != 0) {
            D_089B28C4[i]();
            return 1;
        }
    }
    return 0;
}
