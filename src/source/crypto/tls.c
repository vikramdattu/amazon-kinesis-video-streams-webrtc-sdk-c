#define LOG_CLASS "TLS"

#include "tls.h"

STATUS tls_session_changeState(PTlsSession pTlsSession, TLS_SESSION_STATE newState)
{
    ENTERS();
    STATUS retStatus = STATUS_SUCCESS;

    CHK(pTlsSession != NULL, STATUS_TLS_NULL_ARG);
    CHK(pTlsSession->state != newState, retStatus);

    pTlsSession->state = newState;
    if (pTlsSession->callbacks.stateChangeFn != NULL) {
        pTlsSession->callbacks.stateChangeFn(pTlsSession->callbacks.stateChangeFnCustomData, newState);
    }

CleanUp:

    LEAVES();
    return retStatus;
}
