/* unit_088B3BE4: 0x088B3BE4-0x088B3DE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B3A68 and a function still
 * in assembly. Its jump table (0x089321A4-0x089321C0) is linked from this
 * unit.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    s32 unk0[25];
} Unk64;

extern int memset(void *, s32, s32);
extern s32 func_088AFB48(Unk64 *);
extern void func_088B4670(void);
extern void func_088B4CA4(char *);
extern int func_088B6A08(s32, s32, s32);
extern s32 func_088B6F64(s32, void *, s32, s32);
extern int func_088B7A50(s32);

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern Unk64 D_09A28B98;

s32 func_088B3BE4(s32 arg0, s32 arg1) {
    char sp1C[0x14];

    if (D_09A28876 != 0) {
        switch (D_09A2886C) {
        case 5:
            func_088B6A08(0x8031, arg0, arg1);
            return 0;
        case 0:
            memset(&D_09A28B98, 0, 0x64);
            func_088B6A08(0x8021, arg0, arg1);
            return 0;
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        default:
            func_088B7A50(0);
            D_09A28876 = 0;
            memset(&D_09A28B98, 0, 0x64);
            func_088B4CA4(sp1C);
            func_088B6A08(0, arg0, arg1);
            return 0;
        }
    }
    switch (D_09A2886C) {
    case 0:
        memset(&D_09A28B98, 0, 0x64);
        func_088B6A08(0x8021, arg0, arg1);
        return 0;
    case 2:
    case 1:
    case 3:
    case 4:
        break;
    }
    if (D_09A2886C != 2) {
        func_088B7A50(0);
        memset(&D_09A28B98, 0, 0x64);
        func_088B6A08(0, arg0, arg1);
        return 0;
    }
    if (func_088AFB48(&D_09A28B98) != 0) {
        func_088B6A08(0x8007, arg0, arg1);
        return 0;
    }
    if (func_088B6F64(9, func_088B4670, arg0, arg1) == 0) {
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}
