/* unit_0885DF38: 0x0885DF38-0x0885DFA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885DF38: returns the first u16 of the D_08959FCC (24-byte) or
 * D_08960B9C (28-byte) entry indexed by arg1+2, depending on arg1[1]
 * (5 or 6); 0 otherwise. arg0 is unused.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 v;
    u8 pad[22];
} Ent24;

typedef struct {
    u16 v;
    u8 pad[26];
} Ent28;

extern Ent24 D_08959FCC[];
extern Ent28 D_08960B9C[];

u16 func_0885DF38(s32 arg0, u8 *arg1) {
    if (arg1[1] == 5) {
        return D_08959FCC[*(u16 *)(arg1 + 2)].v;
    } else if (arg1[1] == 6) {
        return D_08960B9C[*(u16 *)(arg1 + 2)].v;
    } else {
        return 0;
    }
}
