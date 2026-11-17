/* unit_088CD804: 0x088CD804-0x088CD964 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08932380-0x089323B0) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_08A62D90;
extern s32 D_09A4F0C4;
extern char *D_09A4F0D0;
extern void func_08886098(void *o, u8 v);
extern int func_0884FAC4(s32, s32);
extern void func_08882F58(s32, s32);
extern void func_088CDDAC(char *);
extern void func_088DCDEC(s32);
extern void func_09A64E90(s32);
extern int func_09A64E48(s32, s32);

s32 func_088CD804(char *arg0, char *arg1) {
    func_08886098((void *) D_08A62D90, 0);
    *(s32 *)(arg0 + 0x88) = 0;
    *(u8 *)(D_089CC438 + 0x422) = 0;
    func_0884FAC4((s32) D_089CC438, *(u16 *)*(char **)(arg1 + 0x1C));
    if (*(u8 *)(D_089CC438 + 0x480) != 0) {
        return 1;
    }
    switch (*(u8 *)(*(char **)(arg1 + 0x1C) + 6)) {
    case 1:
        func_08882F58(D_08A62D8C, 0);
        func_09A64E90(D_08A62D90);
        break;
    case 2:
    case 3:
    case 8:
    case 9:
    case 10:
        func_09A64E48(D_08A62D90, 1);
        break;
    case 11:
        if (*(u8 *)(arg0 + 0x99) == 0) {
            func_08882F58(D_08A62D8C, 0);
            if (*(u8 *)(D_089CC438 + 0x480) == 0 &&
                ((*(u16 *)(D_09A4F0D0 + 0x1F8) & 2) ? *(s32 *)(D_09A4F0D0 + 0x1FC) : 0) != 0) {
                func_088CDDAC(arg0);
            }
            func_09A64E48(D_08A62D90, 2);
        }
        break;
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
    func_088DCDEC(D_09A4F0C4);
    return 0;
}
