/* unit_0885E834: 0x0885E834-0x0885E878 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E834: returns the 16-byte D_089779D4 record selected by the u16
 * field of the 24-byte D_0899D1AE entry arg1, or 0 when it is zero.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 unk0;
    char pad[22];
} Entry24;

typedef struct {
    u8 b[16];
} Entry16;

extern Entry24 D_0899D1AE[];
extern Entry16 D_089779D4[];

u8 *func_0885E834(s32 arg0, u16 arg1) {
    u16 v = D_0899D1AE[arg1].unk0;

    if (v == 0) {
        return 0;
    }
    return D_089779D4[v].b;
}
