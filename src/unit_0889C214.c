/* unit_0889C214: 0x0889C214-0x0889C2F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function copying a 0x14-byte record to the stack.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    float x, y, z;
} F3;

typedef struct {
    float x, y;
} F2;

typedef struct {
    F3 a;
    F2 b;
} Rec;

typedef struct {
    s8 b[8];
} Addr8;

extern s32 func_088B3FFC(Addr8 *, u8 *);

void func_0889C214(Rec *arg0) {
    Rec r;
    Addr8 addr;
    u8 val;
    char *obj;
    s32 i;
    s32 j;
    s32 res;

    r.a = arg0->a;
    r.b = arg0->b;
    obj = *(char **)((char *)&r + 0x8);
    func_088B3FFC(&addr, &val);
    for (i = 0; i < *(s8 *)(obj + 0x12D8); i++) {
        for (j = 0; j < 6; j++) {
            u8 x = (obj + i * 0x64 + j)[0x12DC];
            u8 y = ((u8 *)&addr)[j];
            if (y < x) {
                res = -1;
                goto done;
            }
            if (x < y) {
                res = 1;
                goto done;
            }
        }
        res = 0;
done:
        if (res == 0) {
            *(u8 *)(obj + i * 0x64 + 0x1332) = val;
        }
    }
}
