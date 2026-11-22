/* unit_0889C81C: 0x0889C81C-0x0889C914 (ULES01213)
 *
 * Sorts the records at 0xBC0 (count at 0xBBD, 0xC8 bytes each) and stores in
 * 0xBBC the index of the record whose 6-byte key matches func_0889C518().
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

extern void func_088B3A3C(void *);
extern void func_0889C66C(char *, s32, u8 *, s32, u8 *, u8 *, u8 *);
extern void func_0889C524(char *, s32, u8 *, s32, u8 *, u8 *);
extern u8 *func_0889C518(char *);

void func_0889C81C(char *arg0) {
    u8 tmp[0xC8];
    u8 buf[0x64];
    s32 i;
    u8 *p;
    u8 *key;
    s32 k;
    s32 r;

    func_088B3A3C(buf);
    func_0889C66C(arg0, *(u8 *)(arg0 + 0xBBD), (u8 *)(arg0 + 0xBC0), 0xC8,
                  (u8 *)(arg0 + 0xBC0), tmp, buf);
    func_0889C524(arg0, *(u8 *)(arg0 + 0xBBD) - 1, (u8 *)(arg0 + 0xC88), 0xC8,
                  (u8 *)(arg0 + 0xC88), tmp);
    i = 0;
    if (*(u8 *)(arg0 + 0xBBD) > 0) {
        p = (u8 *)arg0;
        do {
            key = func_0889C518(arg0);
            k = 0;
            do {
                if (key[k] < p[0xBC0 + k]) {
                    r = -1;
                    goto done;
                }
                if (p[0xBC0 + k] < key[k]) {
                    r = 1;
                    goto done;
                }
                k++;
            } while (k < 6);
            r = 0;
        done:
            if (r == 0) {
                *(u8 *)(arg0 + 0xBBC) = i;
            }
            p += 0xC8;
            i++;
        } while (i < *(u8 *)(arg0 + 0xBBD));
    }
}
