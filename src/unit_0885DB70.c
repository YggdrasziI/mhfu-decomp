/* unit_0885DB70: 0x0885DB70-0x0885DBD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885DB70: when arg1 is 5, looks up entry arg2 (24-byte records) of
 * the table at D_08959FDA and returns its next byte (D_08959FDB) if the
 * first byte equals arg3; 0 otherwise.
 * A one-case `switch` with `break` and one shared `return 0` gives the
 * `beql` + `b`/zero then `bne`/nop shape; `if` forms give `bnel`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 D_08959FDA[];
extern u8 D_08959FDB[];

u8 func_0885DB70(s32 arg0, u16 arg1, u16 arg2, u16 arg3) {
    switch (arg1) {
    case 5:
        if (arg3 == D_08959FDA[arg2 * 24]) {
            return D_08959FDB[arg2 * 24];
        }
        break;
    }
    return 0;
}
