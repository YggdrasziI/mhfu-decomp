/* unit_088A6780: 0x088A6780-0x088A6798 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_088A6E44(s32, s32);

void func_088A6780(s32 arg0) {
    func_088A6E44(arg0, 0x10000002);
}

void func_088A678C(s32 arg0) {
    func_088A6E44(arg0, 0x10000001);
}
