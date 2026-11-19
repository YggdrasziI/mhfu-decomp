/* unit_088BFCF0: 0x088BFCF0-0x088BFE54 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088BFCF0 asm piece, 1 function
 * between unit_088BFBEC and unit_088BFE54.
 *
 * C++: a virtual call. Once the save data list is ready (+0xB00 == 3),
 * groups the sizes of the existing entries (func_0884F3FC, virtual
 * function at vtable offset 0x1C) into blocks of at most 0x370000 bytes
 * and checks each block against the 64-bit size of the matching 0x50-byte
 * entry at +0xB08 (count at +0xAFC); 1 when they all agree.
 */

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned short u16;

typedef struct V20 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual s32 vfunc_1C(u16); } V20;

/* A 0x50-byte save data entry, its size at +8. */
typedef struct {
    char pad0[8];
    s64 size;
    char pad10[0x40];
} Ent;

extern "C" {

extern V20 *D_089CC434;

extern int func_0884F3FC(void *, u16);

s32 func_088BFCF0(char *arg0) {
    u32 n;
    s32 sum;
    s32 i;
    s32 off;
    s32 sz;

    if (*(s32 *) (arg0 + 0xB00) != 3) {
        return 0;
    }
    n = 0;
    sum = 0;
    i = 0;
    off = 0;
    do {
        if (*(u32 *) (arg0 + 0xAFC) < n) {
            return 0;
        }
        if (func_0884F3FC(D_089CC434, i)) {
            sz = D_089CC434->vfunc_1C(i);
            if (sum + sz > 0x370000) {
                if (*(s64 *) (*(char **) (arg0 + 0xB08) + off + 8) != sum) {
                    return 0;
                }
                sum = 0;
                off += 0x50;
                n++;
            }
            sum += sz;
        }
        i++;
    } while (i < 0x1A01);
    if (sum > 0) {
        if ((*(Ent **) (arg0 + 0xB08))[n].size != sum) {
            return 0;
        }
        n++;
    }
    if (*(u32 *) (arg0 + 0xAFC) < n) {
        return 0;
    }
    return 1;
}

}
