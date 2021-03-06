/* Rho API Android native bridge */

(function ($, rho, rhoPlatform, rhoUtil) {
    'use strict';

    if (window[rhoUtil.flag.NATIVE_BRIDGE_TYPE] && window[rhoUtil.flag.NATIVE_BRIDGE_TYPE] == rhoPlatform.id.AJAX) return;

    var RHO_API_CALL_TAG = '__rhoNativeApiCall';
    var RHO_API_TAG = '__rhoNativeApi';

    var nativeApi = {

        apiCall: function (cmdText, async, resultHandler) {
            //window.alert(cmdText);

            var nativeApiResult = {};

            if (window[RHO_API_TAG] && 'function' == typeof window[RHO_API_TAG]['apiCall']) {
                nativeApiResult = window[RHO_API_TAG].apiCall(cmdText, async);
            } else {
                nativeApiResult = prompt(cmdText, RHO_API_CALL_TAG + ':prompt');
            }

            //window.alert(nativeApiResult);
            resultHandler(JSON.parse(nativeApiResult));
        }
    };

    // TODO: uncomment as native handler will be implemented
    rhoPlatform.nativeApiCall = nativeApi.apiCall;

})(Rho.jQuery, Rho, Rho.platform, Rho.util);
