/* unit_088444A4: 0x088444A4-0x08844578 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088444A4 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 func_088D6AC8(char *, s32);
extern char *func_088DCEBC(s32, s32);
extern s32 func_088DA150(char *, s32);
extern s32 D_09A4F0C4;

void func_088444A4(char *arg0, char *arg1) {
    u8 v;
    char *e;

    *(u8 *)(arg0 + 0x5E7) = 0;
    v = func_088D6AC8(arg1, 0x39);
    if (v != 0) {
        if (v == 0x96) {
            *(u8 *)(arg0 + 0x5E7) = 4;
        } else {
            *(u8 *)(arg0 + 0x5E7) = 2;
        }
    }
    e = func_088DCEBC(D_09A4F0C4, 1);
    if ((*(u16 *)(arg1 + 0x10F8) | (*(u16 *)(arg1 + 0x62A) | *(u16 *)(arg1 + 0x10F6))) != 0
        || (e != 0 && *(u8 *)(e + 0x1E8) == 0xC && *(u16 *)(e + 0x10F8) != 0)
        || func_088DA150(arg1, 6) != 0) {
        *(u8 *)(arg0 + 0x5E7) |= 1;
    }
}
