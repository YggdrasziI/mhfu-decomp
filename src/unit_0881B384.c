/* unit_0881B384: 0x0881B384-0x0881B408 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881B384: draws the name text of an entry at (x, y). */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 kind;
    u16 id;
} Item;

extern char *D_08A62C54;
extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC8AC[];
extern char D_08938478[];

extern u8 func_0885CD18(char *, u8, u16);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s32, s32, char *, ...);

void func_0881B384(s32 arg0, s32 x, s32 y, Item *it)
{
    func_08891474(D_08A631A8, x, y, D_08938478,
                  func_0885151C(D_089CC438,
                                D_089AC8AC[func_0885CD18(D_08A62C54, it->kind, it->id)]));
}
