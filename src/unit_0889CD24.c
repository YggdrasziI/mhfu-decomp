/* unit_0889CD24: 0x0889CD24-0x0889CE10 (ULES01213)
 *
 * Clears every 0x64-byte entry whose 6-byte key matches the given key, then
 * refreshes the list and decrements its count when one was cleared.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern void memset(void *, s32, s32);
extern void func_0889C788(char *);

void func_0889CD24(char *obj, u8 *key) {
    s32 found = 0;
    s32 i;
    s32 j;
    s32 res;


    for (i = 0; i < *(s8 *)(obj + 0x12D8); i++) {
        for (j = 0; j < 6; j++) {
            u8 x = (obj + i * 0x64 + j)[0x12DC];
            u8 y = key[j];
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
            memset(obj + i * 0x64 + 0x12DC, 0, 0x64);
            found = 1;
        }
    }
    if (found) {
        func_0889C788(obj);
        if (*(s8 *)(obj + 0x12D8) > 0) {
            (*(s8 *)(obj + 0x12D8))--;
        }
    }
}
