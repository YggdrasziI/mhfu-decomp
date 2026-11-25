/* unit_0885CD18: 0x0885CD18-0x0885CDB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885CD18: returns a byte for (kind arg1, id arg2): ids above 0x5DC read
 * D_089A5597 directly; kind 5 / kind 6 map the id through the first u16 of
 * D_08959FCC (24-byte records) / D_08960B9C (28-byte records) into
 * D_08978488; any other kind gives 0.
 * `arg2 > 0x5DC` (not `>= 0x5DD`) keeps the compare in $at.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 unk0;
    u8 pad[0x16];
} UnkRec24;

typedef struct {
    u16 unk0;
    u8 pad[0x1A];
} UnkRec28;

extern u8 D_089A5597[];
extern UnkRec24 D_08959FCC[];
extern UnkRec28 D_08960B9C[];
extern u8 D_08978488[];

u8 func_0885CD18(s32 arg0, u8 arg1, u16 arg2) {
    if (arg2 > 0x5DC) {
        return D_089A5597[arg2];
    }
    if (arg1 == 5) {
        return D_08978488[D_08959FCC[arg2].unk0];
    }
    if (arg1 == 6) {
        return D_08978488[D_08960B9C[arg2].unk0];
    }
    return 0;
}
