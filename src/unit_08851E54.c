/* unit_08851E54: 0x08851E54-0x08851EC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern char *D_08A62C54;
extern s32 func_08856CA0(char *, u8);
extern u8 func_08851CC8(char *, u8);
extern char *func_0885CB68(char *, u8, s16);

u8 func_08851E54(char *arg0, s32 arg1, s32 arg2) {
    if (func_08851CC8(arg0, func_08856CA0(arg0, arg1)) == 1) {
        return *(u8 *)(func_0885CB68(D_08A62C54, arg1, arg2) + 0x13);
    }
    return 0;
}
