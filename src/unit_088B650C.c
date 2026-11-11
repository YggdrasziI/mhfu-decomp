/* unit_088B650C: 0x088B650C-0x088B652C (ULES01213)
 *
 * Bounds (hypothesis): one function (pre-increments a counter) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

/* volatile reproduces the re-read after the store; the original declaration may
 * differ */
extern volatile u16 D_09A2917C;

u16 func_088B650C(void) {
    D_09A2917C++;
    return D_09A2917C;
}
