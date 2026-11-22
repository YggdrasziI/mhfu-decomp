/* unit_0888A668: 0x0888A668-0x0888A73C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
} State;

extern char *D_089CBBE4;
extern char *D_089CC438;
extern s32 func_0888D708(char *);
extern u8 func_0888A73C(char *, State *);

void func_0888A668(char *arg0, State *arg1) {
    char *p = *(char **)(D_089CBBE4 + 0xA84);
    u8 r;

    arg0[0x91] = 0;
    r = func_0888D708(arg0);
    arg1->unk4 = r;
    if (r == 0) {
        arg1->unk0 = 0;
        return;
    }
    if (arg1->unk0 == 0) {
        arg1->unk0++;
        arg1->unk8 = *(s32 *)(p + 0x554);
        if (*(u16 *)(D_089CC438 + 0x6AF0E) != 0x4B) {
            *(s32 *)(arg0 + 0x88) = 0x3F75BE0B;
        } else {
            *(s32 *)(arg0 + 0x88) = 0x3F5F66F3;
        }
        *(s32 *)(arg0 + 0x80) = 0;
    }
    if (func_0888A73C(arg0, arg1) == 1) {
        arg0[0x91] = 1;
    }
}
