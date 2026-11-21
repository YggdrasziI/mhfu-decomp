/* unit_088A2410: 0x088A2410-0x088A243C (ULES01213)
 *
 * Calls the optional callback stored in D_09A0D250 (when set), passing the
 * argument through unchanged in a0.
 */

typedef int s32;

extern s32 D_09A0D250;

void func_088A2410(void *arg0) {
    if (D_09A0D250 != 0) {
        ((void (*)(void *))D_09A0D250)(arg0);
    }
}
