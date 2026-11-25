/* unit_0885DBD0: 0x0885DBD0-0x0885DC30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885DBD0: when arg1 is 5, looks up entry arg2 of a 24-byte record
 * table (D_08959FDC) and returns its second byte (D_08959FDD) if its first
 * byte equals arg3; 0 otherwise.
 * One-case switch with `break` to the shared return 0 (an `if` gives bnel).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 D_08959FDC[];
extern u8 D_08959FDD[];

u8 func_0885DBD0(s32 arg0, u16 arg1, u16 arg2, u16 arg3) {
    switch (arg1) {
    case 5:
        if (arg3 == D_08959FDC[arg2 * 24]) {
            return D_08959FDD[arg2 * 24];
        }
        break;
    }
    return 0;
}
