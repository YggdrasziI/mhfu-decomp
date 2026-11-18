/* unit_088AAD58: 0x088AAD58-0x088AAE10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AAC80 and func_088AAE10
 * (still in assembly). NonMatching (64.8 %): the code stays in the asm
 * piece text_088AAD58.
 *
 * Sends on a socket of func_088AA370 / func_088AA83C (inet, or PTP in ad
 * hoc mode); a short send is reported as an error.
 *
 * Gap: the original keeps the length argument unextended in $s0 and
 * sign-extends it at each use (twice in the inet branch, once in place in
 * the ad hoc one); ours extends it once at entry for both branches, which
 * also changes the first branch. Tried: an `s32` parameter with `(s16)`
 * casts, a local copy, conditional expressions for the returns, and every
 * `opt_*` pragma of the compiler on top of opt_rebuildconditionals off.
 */

#pragma opt_rebuildconditionals off

typedef short s16;
typedef int s32;

extern s32 sceNetInetSend(s32, void *, s32, s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetAdhocPtpSend(s32, void *, s32 *, s32, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;

s32 func_088AAD58(s32 sock, void *buf, s16 len) {
    s32 n;
    s32 ret;

    if (D_09A1D728 != 1) {
        ret = sceNetInetSend(sock, buf, len, 0);
        if (ret == len) {
            return len;
        }
        if (ret < 0) {
            return func_088AA14C(sceNetInetGetPspError());
        }
        return func_088AA14C(0x8001000C);
    }
    n = len;
    ret = func_088AA14C(sceNetAdhocPtpSend(sock, buf, &n, 0, 0));
    if (ret < 0) {
        return ret;
    }
    if (n != len) {
        return -0xC;
    }
    return n;
}
