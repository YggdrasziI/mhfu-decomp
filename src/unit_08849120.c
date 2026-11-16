/* unit_08849120: 0x08849120-0x08849300 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between code still in assembly and
 * unit_088493A4. Their jump tables (0x089311A0-0x089311FC) are linked from
 * this unit.
 *
 * func_08849214 passes its third argument unmasked and uses every result, so
 * func_088493A4 (u16 parameter in its unit) and func_0882A988 (void in its
 * unit) are declared here with an s32 parameter and an s32 result.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_0881C884(char *arg0);
extern s32 func_0881C944(char *arg0);
extern s32 func_0881CA34(s32 arg0);
extern s32 func_0882A8FC(char *arg0);
extern s32 func_0889615C(char *arg0);
extern s32 func_08849300(char *arg0);
extern int func_0881CAC8(char *p);
extern int func_0881CB0C(char *o);
extern s32 func_0881E8F8(char *arg0);
extern s32 func_0884953C(char *arg0);
extern s32 func_08849B6C(char *arg0);

extern s32 func_0881CB2C(char *arg0, s32 arg1);
extern s32 func_0881DB5C(char *arg0, s32 arg1);
extern s32 func_0881EAF8(char *arg0, s32 arg1);
extern s32 func_0882A988(char *arg0, s32 arg1);
extern s32 func_08896228(char *arg0, s32 arg1);
extern s32 func_088493A4(char *arg0, s32 arg1);
extern s32 func_0881EB60(char *arg0, s32 arg1);
extern s32 func_0881EC2C(char *arg0, s32 arg1);
extern s32 func_0881E92C(char *arg0, s32 arg1);
extern s32 func_088495AC(char *arg0, s32 arg1);
extern s32 func_08849BCC(char *arg0, s32 arg1);

s32 func_08849120(char *arg0, u8 arg1) {
    s32 ret = 0;

    switch (arg1) {
    case 0:
        ret = func_0881C884(arg0);
        break;
    case 1:
        ret = func_0881C944(arg0);
        break;
    case 2:
        ret = func_0881CA34((s32) arg0);
        break;
    case 3:
        ret = func_0882A8FC(arg0);
        break;
    case 4:
        ret = func_0889615C(arg0);
        break;
    case 5:
        ret = func_08849300(arg0);
        break;
    case 6:
        ret = func_0881CAC8(arg0);
        break;
    case 7:
        ret = func_0881CB0C(arg0);
        break;
    case 8:
        ret = func_0881E8F8(arg0);
        break;
    case 9:
        ret = func_0884953C(arg0);
        break;
    case 10:
        ret = func_08849B6C(arg0);
        break;
    case 11:
        ret = -1;
        break;
    }
    return ret;
}

u16 func_08849214(char *arg0, u8 arg1, s32 arg2) {
    u16 ret = 0;

    switch (arg1) {
    case 0:
        ret = func_0881CB2C(arg0, arg2);
        break;
    case 1:
        ret = func_0881DB5C(arg0, arg2);
        break;
    case 2:
        ret = func_0881EAF8(arg0, arg2);
        break;
    case 3:
        ret = func_0882A988(arg0, arg2);
        break;
    case 4:
        ret = func_08896228(arg0, arg2);
        break;
    case 5:
        ret = func_088493A4(arg0, arg2);
        break;
    case 6:
        ret = func_0881EB60(arg0, arg2);
        break;
    case 7:
        ret = func_0881EC2C(arg0, arg2);
        break;
    case 8:
        ret = func_0881E92C(arg0, arg2);
        break;
    case 9:
        ret = func_088495AC(arg0, arg2);
        break;
    case 10:
        ret = func_08849BCC(arg0, arg2);
        break;
    }
    return ret;
}
