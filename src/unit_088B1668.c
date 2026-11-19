/* unit_088B1668: 0x088B1668-0x088B1708 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B158C and unit_088B1708.
 *
 * Calls func_088B6964 when D_09A28876 is set, copies the 8-byte key arg0
 * to D_09A29D3C and the 0xA4-byte block arg1 to D_09A29D44, then calls
 * func_088B6B14(0x12).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s8 b[8];
} Key;

typedef struct {
    s16 h[0x52];
} Block;

extern u8 D_09A28876;
extern Key D_09A29D3C;
extern Block D_09A29D44;

extern void func_088B6964(void);
extern void func_088B6B14(s32);

void func_088B1668(Key *arg0, Block *arg1) {
    if (D_09A28876) {
        func_088B6964();
    }
    D_09A29D3C = *arg0;
    D_09A29D44 = *arg1;
    func_088B6B14(0x12);
}
