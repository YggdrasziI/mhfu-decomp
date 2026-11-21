/* unit_088AAD58: 0x088AAD58-0x088AAE10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AAC80 and func_088AAE10
 * (still in assembly).
 *
 * Sends on a socket of func_088AA370 / func_088AA83C (inet, or PTP in ad
 * hoc mode); a short send is reported as an error.
 *
 * The length is an `int` narrowed where it is used: cast to `s16` in the
 * inet send call (so the conversion is not shared with the ad hoc branch),
 * narrowed in place in the ad hoc branch.
 */

#pragma opt_rebuildconditionals off

typedef short s16;
typedef int s32;

/* pspsdk prototype (size_t length). */
extern s32 sceNetInetSend(s32, const void *, unsigned int, s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetAdhocPtpSend(s32, void *, s32 *, s32, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;

s32 func_088AAD58(s32 sock, void *buf, s32 len) {
    s32 n;
    s32 ret;

    if (D_09A1D728 != 1) {
        ret = sceNetInetSend(sock, buf, (s16) len, 0);
        if (ret != (s16)len) {
            if (ret < 0) {
                return func_088AA14C(sceNetInetGetPspError());
            }
            return func_088AA14C(0x8001000C);
        }
        return (s16)len;
    }
    len = (s16)len;
    n = len;
    ret = func_088AA14C(sceNetAdhocPtpSend(sock, buf, &n, 0, 0));
    if (ret < 0) {
        return ret;
    }
    return (n != len) ? -0xC : n;
}
