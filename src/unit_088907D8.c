/* unit_088907D8: 0x088907D8-0x088908FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char D_08A631B8;
extern char D_08A631E0;
extern s32 D_08A8B1E0;
extern s32 D_08A8B1E4;
extern int func_08859AE4(char *, char *, s32);
extern int func_088908FC(char *, u8, s32);
extern int func_08892E7C(char *);

void func_088907D8(char *arg0) {
    u8 temp_a1;

    func_08859AE4(&D_08A631B8, &D_08A631E0, 0x28000);
    D_08A8B1E0 = 0;
    D_08A8B1E4 = 0;
    func_08892E7C(arg0);
    *(u8 *)(arg0 + 0x114) = (u8) *(u16 *)(arg0 + 0x5C);
    *(u8 *)(arg0 + 0x114) = (u8) ((*(u8 *)(arg0 + 0x114) + 1) & ~1);
    *(u8 *)(arg0 + 0x115) = (u8) *(u16 *)(arg0 + 0x5E);
    *(u8 *)(arg0 + 0x115) = (u8) ((*(u8 *)(arg0 + 0x115) + 1) & ~1);
    *(u8 *)(arg0 + 0x116) = 0U;
    *(u8 *)(arg0 + 0x116) = (u8) ((*(u8 *)(arg0 + 0x116) + 1) & ~1);
    *(u8 *)(arg0 + 0x117) = 2U;
    *(u8 *)(arg0 + 0x117) = (u8) ((*(u8 *)(arg0 + 0x117) + 1) & ~1);
    *(u8 *)(arg0 + 0x118) = (u8) (*(u8 *)(arg0 + 0x114) + *(u8 *)(arg0 + 0x116));
    temp_a1 = *(u8 *)(arg0 + 0x115);
    *(u8 *)(arg0 + 0x119) = (u8) (temp_a1 + *(u8 *)(arg0 + 0x117));
    *(u8 *)(arg0 + 0x11A) = (u8) (0x100 / (s32) *(u8 *)(arg0 + 0x118));
    *(u8 *)(arg0 + 0x11B) = (u8) (0x100 / (s32) *(u8 *)(arg0 + 0x119));
    *(u16 *)(arg0 + 0x11C) = (u16) (*(u8 *)(arg0 + 0x11A) * *(u8 *)(arg0 + 0x11B));
    *(s16 *)(arg0 + 0x11E) = (s16) (*(u16 *)(arg0 + 0x11C) * 3);
    func_088908FC(arg0, temp_a1, -2);
}
