/* unit_08867058: 0x08867058-0x08867260 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern s32 D_09A0B540;
extern char *func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern void memcpy(void *, void *, unsigned int);

#define HW(i) (*(u16 *)(arg0 + (i) * 2 + 0x80408))
#define BY(i) (*(u8 *)(arg0 + (i) + 0x803D8))

void func_08867058(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *tmp;
    u8 a;
    u8 b;
    u8 mode;
    s32 i;

    tmp = func_08898694(D_09A0B540, 0x19, 0x41000);
    a = arg1 * 8;
    b = arg2 * 8;
    mode = arg3;
    for (i = 0; i < 8; i++, a++, b++) {
        if (mode == 1) {
            if (HW(a) == 0xFFFF) {
                goto next;
            }
            if (HW(b) == 0xFFFF) {
                goto next;
            }
        }
        {
            s32 *size = (s32 *)(arg0 + a * 4 + 0x80318);
            char **pa = (char **)(arg0 + a * 4 + 0x80258);
            char **pb;
            u16 h;
            s16 c;
            memcpy(tmp, *pa, *size);
            pb = (char **)(arg0 + b * 4 + 0x80258);
            memcpy(*pa, *pb, *size);
            memcpy(*pb, tmp, *size);
            h = HW(a);
            HW(a) = HW(b);
            HW(b) = h;
            c = BY(a);
            BY(a) = BY(b);
            BY(b) = c;
        }
    next:;
    }
    func_08898748(D_09A0B540, 0x19);
}
