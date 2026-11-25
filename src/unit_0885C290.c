/* unit_0885C290: 0x0885C290-0x0885C33C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u16 id;
    s16 val;
} Entry;

typedef struct {
    u8 pad[0x2F88];
    Entry ent[1];
} Block;

extern char *D_089CC438;
extern u8 D_0899D19B[];
extern s16 func_08850EC4(char *arg0);

s16 func_0885C290(s32 arg0, s32 arg1) {
    Block *p = (Block *)(D_089CC438 + 0x4A0);
    s16 n = func_08850EC4(D_089CC438);
    s32 i;

    for (i = 0; i < n; i++) {
        if (p->ent[i].id == (u16)arg1) {
            if (D_0899D19B[(arg1 & 0xFFFF) * 24] == 0xFF) {
                return 999;
            }
            return p->ent[i].val;
        }
    }
    return 0;
}
