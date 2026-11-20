/* unit_088AD63C: 0x088AD63C-0x088AD708 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD4EC (NonMatching, still
 * in assembly) and code still in assembly.
 *
 * Resets the peer table at 0x09A1FC5C (16 records of 0x18 bytes, the first
 * one for this console, whose 6-byte address is copied from the argument)
 * and the two buffer descriptors at 0x09A1FC44 and 0x09A1FC50.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_09A1FC5C[];
extern char D_09A1FC50[];
extern char D_09A1FC44[];
extern s32 D_09A1FC6C;
extern u16 D_09A1FC70;
extern u16 D_09A1FC72;
extern s32 D_09A1FC54;
extern char *D_09A1FC58;
extern s32 D_09A1FC48;
extern char *D_09A1FC4C;
extern char D_09A1F844[];
extern char D_09A1DC44[];

extern void memset(void *, s32, s32);
extern void func_0880C084(void *, const void *, s32);

void func_088AD63C(void *mac) {
    memset(D_09A1FC5C, 0, 0x180);
    memset(D_09A1FC50, 0, 0xC);
    memset(D_09A1FC44, 0, 0xC);
    func_0880C084(D_09A1FC5C, mac, 6);
    D_09A1FC6C = 1;
    D_09A1FC70 = 2;
    D_09A1FC72 = 0xAAAA;
    D_09A1FC54 = 0x400;
    D_09A1FC58 = D_09A1F844;
    D_09A1FC48 = 0x1C00;
    D_09A1FC4C = D_09A1DC44;
}
