/* unit_0885C968: 0x0885C968-0x0885CA50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x089314A8-0x089314C4) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_089CC438;
extern char *func_08851648(int arg, u16 entry);
extern char *func_08851598(int arg, u16 entry);
extern char *func_088515C4(int arg, u16 entry);
extern char *func_088515F0(int arg, u16 entry);
extern char *func_0885161C(int arg, u16 entry);
extern char *func_08851540(int arg, u16 entry);
extern char *func_0885156C(int arg, u16 entry);

char *func_0885C968(s32 arg0, u8 arg1, u16 arg2) {
    switch (arg1) {
    case 0:
        return func_08851648(D_089CC438, arg2);
    case 1:
        return func_08851598(D_089CC438, arg2);
    case 2:
        return func_088515C4(D_089CC438, arg2);
    case 3:
        return func_088515F0(D_089CC438, arg2);
    case 4:
        return func_0885161C(D_089CC438, arg2);
    case 5:
        return func_08851540(D_089CC438, arg2);
    case 6:
        return func_0885156C(D_089CC438, arg2);
    default:
        return 0;
    }
}
