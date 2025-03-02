/*
 * Copyright 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
#ifndef __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_RTCP__
#define __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_RTCP__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 * HEADERS
 ******************************************************************************/
#include "PeerConnection.h"
#include "RtcpPacket.h"

/******************************************************************************
 * DEFINITIONS
 ******************************************************************************/
/******************************************************************************
 * FUNCTIONS
 ******************************************************************************/
STATUS rtcp_onInboundPacket(PKvsPeerConnection pKvsPeerConnection, PBYTE pBuff, UINT32 buffLen);
STATUS rtcp_onInboundRembPacket(PRtcpPacket, PKvsPeerConnection);
STATUS rtcp_onPLIPacket(PRtcpPacket, PKvsPeerConnection);

#ifdef __cplusplus
}
#endif
#endif /* __KINESIS_VIDEO_WEBRTC_CLIENT_PEERCONNECTION_RTCP__ */
