/* unit_08850520: 0x08850520-0x0885057C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 func_088503F8(char *, u8);
extern u16 func_0885048C(char *, u8);

u16 func_08850520(char *arg0, u8 arg1) {
    u16 sum;

    sum = func_088503F8(arg0, arg1) + func_0885048C(arg0, arg1);
    if (sum > 9999) {
        sum = 9999;
    }
    return sum;
}
