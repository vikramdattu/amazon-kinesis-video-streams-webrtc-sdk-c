/*******************************************
SessionDescription internal include file
*******************************************/
#ifndef __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_SESSIONDESCRIPTION__
#define __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_SESSIONDESCRIPTION__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "hash_table.h"
#include "double_linked_list.h"
#include "Sdp.h"
#include "PeerConnection.h"

#define SESSION_DESCRIPTION_INIT_LINE_ENDING            "\\r\\n"
#define SESSION_DESCRIPTION_INIT_LINE_ENDING_WITHOUT_CR "\\n"

#define SESSION_DESCRIPTION_INIT_TEMPLATE_HEAD "{\"type\": \"%s\", \"sdp\": \""
#define SESSION_DESCRIPTION_INIT_TEMPLATE_TAIL "\"}"

#define SDP_OFFER_VALUE  "offer"
#define SDP_ANSWER_VALUE "answer"

#define MEDIA_SECTION_AUDIO_VALUE "audio"
#define MEDIA_SECTION_VIDEO_VALUE "video"

#define SDP_TYPE_KEY  "type"
#define SDP_KEY       "sdp"
#define CANDIDATE_KEY "candidate"
#define SSRC_KEY      "ssrc"
#define BUNDLE_KEY    "BUNDLE"

#define H264_VALUE      "H264/90000"
#define OPUS_VALUE      "opus/48000"
#define VP8_VALUE       "VP8/90000"
#define MULAW_VALUE     "PCMU/8000"
#define ALAW_VALUE      "PCMA/8000"
#define RTX_VALUE       "rtx/90000"
#define RTX_CODEC_VALUE "apt="

#define DEFAULT_PAYLOAD_MULAW (UINT64) 0
#define DEFAULT_PAYLOAD_ALAW  (UINT64) 8
#define DEFAULT_PAYLOAD_OPUS  (UINT64) 111
#define DEFAULT_PAYLOAD_VP8   (UINT64) 96
#define DEFAULT_PAYLOAD_H264  (UINT64) 125
/**
 * a=rtpmap:0 PCMU/8000\r\n
 * a=rtpmap:8 PCMA/8000\r\n
 * a=rtpmap:111 opus/48000/2\r\n
 */
#define DEFAULT_PAYLOAD_MULAW_STR (PCHAR) "0"
#define DEFAULT_PAYLOAD_ALAW_STR  (PCHAR) "8"

#define DEFAULT_H264_FMTP (PCHAR) "level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=42e01f"
#define DEFAULT_OPUS_FMTP (PCHAR) "minptime=10;useinbandfec=1"

#define DTLS_ROLE_ACTPASS (PCHAR) "actpass"
#define DTLS_ROLE_ACTIVE  (PCHAR) "active"

#define VIDEO_CLOCKRATE (UINT64) 90000
#define OPUS_CLOCKRATE  (UINT64) 48000
#define PCM_CLOCKRATE   (UINT64) 8000

/**
 * @brief latch the value of rtp codec.
 *
 * @param[in] codecTable the codec table of transimission.
 * @param[in] rtxTable the codec table of retransmission.
 * @param[in] pSessionDescription the sdp of the offer.
 *
 * @return STATUS_SUCCESS
 */
STATUS sdp_setPayloadTypesFromOffer(PHashTable, PHashTable, PSessionDescription);
STATUS sdp_setPayloadTypesForOffer(PHashTable);

STATUS sdp_setTransceiverPayloadTypes(PHashTable, PHashTable, PDoubleList);
STATUS sdp_populateSessionDescription(PKvsPeerConnection, PSessionDescription, PSessionDescription);
STATUS sdp_reorderTransceiverByRemoteDescription(PKvsPeerConnection, PSessionDescription);
STATUS sdp_setReceiversSsrc(PSessionDescription, PDoubleList);
PCHAR sdp_fmtpForPayloadType(UINT64, PSessionDescription);

#ifdef __cplusplus
}
#endif
#endif /* __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_SESSIONDESCRIPTION__ */
