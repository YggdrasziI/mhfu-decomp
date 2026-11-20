/* unit_088B7978: 0x088B7978-0x088B7A10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B7958 and unit_088B7A10.
 *
 * While hosting, clears the 0xC-byte peer record at D_09A2851C + 0xC6C
 * whose address is arg0.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

extern char D_09A2851C[];
extern u8 D_09A28876;

extern void memset(void *, s32, s32);
extern s32 func_088B0514(void *, void *);

void func_088B7978(Addr8 *arg0) {
    s32 i;
    char *p;

    if (D_09A28876 != 0) {
        i = 0;
        p = D_09A2851C;
        do {
            if (func_088B0514(p + 0xC6C, arg0) == 0) {
                memset(D_09A2851C + i * 0xC + 0xC6C, 0, 0xC);
                return;
            }
            i++;
            p += 0xC;
        } while (i < 4);
    }
}
