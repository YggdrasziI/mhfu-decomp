/* unit_0889A554: 0x0889A554-0x0889A614 (ULES01213)
 *
 * Bounds (hypothesis): 1 function copying a 0x14-byte record to the stack.
 */

typedef int s32;
typedef unsigned short u16;
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

extern void memset(void *, s32, s32);
extern void func_088B3684(void *, void *);
extern void func_0889C788(char *);

void func_0889A554(Rec *arg0) {
    Rec r;
    char *obj;

    r.a = arg0->a;
    r.b = arg0->b;
    obj = *(char **)((char *)&r + 0x8);
    *(s32 *)(obj + 0x12C0) &= ~0x40;
    *(u8 *)(obj + 0x1AF4) = *(s8 *)((char *)&r + 0xC) == 0;
    *(s32 *)(obj + 0x1AF8) = *(u16 *)((char *)&r + 0x10);
    *(u8 *)(obj + 0x12D8) = 0;
    memset(obj + 0x12DC, 0, 0x190);
    if (*(u8 *)(obj + 0x1AF4) != 0) {
        func_088B3684(obj + 0x12D8, obj + 0x12DC);
        func_0889C788(obj);
    } else if (*(s32 *)(obj + 0x1AF8) == 0x8003) {
        *(u8 *)(obj + 0x1AFC) = 1;
    }
}
