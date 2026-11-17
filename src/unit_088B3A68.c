/* unit_088B3A68: 0x088B3A68-0x088B3BE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08932188-0x089321A4) is linked from this unit.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

typedef struct {
    s32 unk0[25];
} Unk64;

typedef struct {
    s16 unk0[11];
} Unk16;

extern int func_088B6A08(s32, s32, s32);
extern s32 func_088B04B4(char *arg0);
extern s32 func_088AFB48(Unk64 *);
extern s32 func_088B6F64(s32, void *, s32, s32);
extern void func_088B41F8(void);

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern Unk64 D_09A28B98;
extern Unk16 D_09A291BC;

s32 func_088B3A68(Unk64 *arg0, Unk16 *arg1, s32 arg2, s32 arg3) {
    switch (D_09A2886C) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        func_088B6A08(0x8013, arg2, arg3);
        return 0;
    case 0:
        break;
    }
    if (D_09A28876 != 0) {
        func_088B6A08(0x8013, arg2, arg3);
        return 0;
    }
    if (func_088B04B4((char *) arg0) == 0) {
        func_088B6A08(0x8000, arg2, arg3);
        return 0;
    }
    if (func_088AFB48(arg0) != 0) {
        func_088B6A08(0x8007, arg2, arg3);
        return 0;
    }
    D_09A28B98 = *arg0;
    D_09A291BC = *arg1;
    if (func_088B6F64(8, func_088B41F8, arg2, arg3) == 0) {
        return 0;
    }
    func_088B6A08(0x8005, arg2, arg3);
    return 0;
}
