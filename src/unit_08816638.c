/* unit_08816638: 0x08816638-0x08816730 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u16 func_0881629C(s32, u8 **);
extern u16 func_088165FC(s32, u16);
extern void func_08816508(s32, u8 **, u32);

s32 func_08816638(s32 arg0, u8 *dst, s32 size, u8 *src) {
    u8 buf[4];
    u8 *end;
    s32 n;
    u8 *p;
    u16 c;
    s32 count;

    count = 0;
    if (size <= 0) {
        return 0;
    }
    size--;
    c = func_0881629C(arg0, &src);
    if (c != 0) {
        do {
            end = buf;
            if ((c = func_088165FC(arg0, c)) == 0) {
                break;
            }
            func_08816508(arg0, &end, c);
            p = buf;
            n = end - p;
            if (size < n) {
                break;
            }
            size -= n;
            while (n--) {
                *dst++ = *p++;
            }
            count++;
            c = func_0881629C(arg0, &src);
        } while (c != 0);
    }
    *dst = 0;
    return count;
}
