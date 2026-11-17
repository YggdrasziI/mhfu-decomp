/* unit_08834730: 0x08834730-0x0883488C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088346A8's neighbours and code
 * still in assembly. Its jump table (0x08930F40-0x08930F74) is linked from
 * this unit.
 */

typedef int s32;
typedef unsigned char u8;

extern void func_08816F24(char *);
extern void func_088172D8(char *);
extern void func_088180CC(char *);
extern void func_08818264(char *);
extern void func_088188A8(char *);
extern void func_088188B4(char *);
extern void func_08838E30(char *);
extern void func_08838F58(char *);
extern void func_08839824(char *);
extern void func_08839F64(char *);
extern void func_0883AB4C(char *);
extern void func_0883B870(char *);
extern int func_0883D290(char *);
extern void func_0883488C(void *p, int a);
extern void func_0881908C(char *);

void func_08834730(char *arg0) {
    u8 *p = (u8 *)(arg0 + 0x1118);

    switch (p[0]) {
    case 0:
        func_0883488C(arg0, 0);
        break;
    case 1:
        switch (p[4]) {
        case 0:
            func_08816F24(arg0);
            break;
        case 1:
            func_088172D8(arg0);
            break;
        case 9:
            func_088180CC(arg0);
            break;
        case 2:
            func_08818264(arg0);
            break;
        case 7:
            func_088188A8(arg0);
            break;
        case 8:
            func_088188B4(arg0);
            break;
        case 5:
            func_08838E30(arg0);
            break;
        case 6:
            func_08838F58(arg0);
            break;
        case 10:
            func_08839824(arg0);
            break;
        case 4:
            func_08839F64(arg0);
            break;
        case 12:
            func_0883AB4C(arg0);
            break;
        case 3:
            func_0883B870(arg0);
            break;
        case 11:
            func_0883D290(arg0);
            break;
        }
        break;
    }
    if (*(s32 *)(arg0 + 0x5E8) & 4) {
        func_0881908C(arg0);
    }
}
