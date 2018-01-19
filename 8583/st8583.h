//
//  st8583.h
//  8583Demo
//
//  Created by newPosTech on 13-8-12.
//  Copyright (c) 2013年 com.Mysoft. All rights reserved.
//

#ifndef _583Demo_st8583_h
#define _583Demo_st8583_h

//#include "posapi.h"
#include "pack8583.h"

#define LEN_MSG_CODE			4
#define LEN_BITMAP				8
#define LEN_PAN					19
#define LEN_PROC_CODE			6
#define LEN_TRAN_AMT			12
#define LEN_POS_STAN			6
#define LEN_LOCAL_TIME			6
#define LEN_LOCAL_DATE			4
#define LEN_EXP_DATE			4
#define LEN_SETTLE_DATE			4
#define LEN_ENTRY_MODE			4	// Œ™¡À¥¶¿Ì◊Û∂‘∆Î∑Ω Ω
#define LEN_PAN_SEQ_NO			3
#define LEN_SVR_CODE			2
#define LEN_CAPTURE_CODE		2
#define LEN_ACQUIRER_ID			11
#define LEN_TRACK2				37
#define LEN_TRACK3				104
#define LEN_RRN					12
#define LEN_AUTH_CODE			6
#define LEN_RSP_CODE			2
#define LEN_TERM_ID				8
#define LEN_MERCHANT_ID			15
#define LEN_ADD_RSP_DATA		25
#define LEN_FIELD48				322
#define LEN_CURRENCY_CODE		3
#define LEN_PIN_DATA			8
#define LEN_SECURITY_INFO		16
#define LEN_EXT_AMOUNT			20
#define LEN_FIELD51             500
#define LEN_FIELD59             999
#define LEN_ICC_DATA			701
#define LEN_FIELD57				30
#define LEN_EP_DATA				100
#define LEN_FIELD60				30
#define LEN_ORIGINAL_MSG		29
#define LEN_FIELD62				2000
#define LEN_FIELD63				63
#define LEN_MAC_DATA			8

// Àµ√˜£∫
// 1. ∂‘Binary¿‡–Õµƒ”Ú£¨Ω·ππ≥…‘±±‰¡øµƒ«∞√Ê2∏ˆ◊÷Ω⁄Œ™ ˝æ›≥§∂», ∏Ò ΩŒ™∏ﬂ”––ßŒ™‘⁄«∞µƒÕ¯¬Á◊÷Ω⁄À≥–Ú
// 2. ∂‘∑«Binary¿‡–Õ”Ú£¨÷±Ω” π”√Cµƒ◊÷∑˚¥Æ≤Ÿ◊˜/∏Ò ΩªØ∫Ø ˝Ω¯––∏≥÷µº¥ø…;
//    ∂‡”‡µƒ2∏ˆ◊÷Ω⁄ «Œ™¡À¥Ê¥¢'\0'◊÷∑˚(Œ™∑Ω±„¥¶¿Ì»ﬂ”‡¡À“ª∏ˆ◊÷∑˚)
typedef struct _tagSTISO8583{
    char	szMsgCode[LEN_MSG_CODE+2];
    char	sBitMap[2*LEN_BITMAP];
    char	szPan[LEN_PAN+2];
    char	szProcCode[LEN_PROC_CODE+2];
    char	szTranAmt[LEN_TRAN_AMT+2];
    char	szSTAN[LEN_POS_STAN+2];
    char	szLocalTime[LEN_LOCAL_TIME+2];
    char	szLocalDate[LEN_LOCAL_DATE+2];
    char	szExpDate[LEN_EXP_DATE+2];
    char	szSettleDate[LEN_SETTLE_DATE+2];
    char	szEntryMode[LEN_ENTRY_MODE+2];
    char	szPanSeqNo[LEN_PAN_SEQ_NO+2];
    char	szSvrCode[LEN_SVR_CODE+2];
    char	szCaptureCode[LEN_CAPTURE_CODE+2];
    char	szAcquirerID[LEN_ACQUIRER_ID+2];
    char	szTrack2[LEN_TRACK2+2];
    char	szTrack3[LEN_TRACK3+2];
    char	szRRN[LEN_RRN+2];
    char	szAuthCode[LEN_AUTH_CODE+2];
    char	szRspCode[LEN_RSP_CODE+2];
    char	szTermID[LEN_TERM_ID+2];
    char	szMerchantID[LEN_MERCHANT_ID+2];
    char	szAddRspData[LEN_ADD_RSP_DATA+2];
    char	szField48[LEN_FIELD48+2];
    char	szCurrencyCode[LEN_CURRENCY_CODE+2];
    char    szField51[LEN_FIELD51+2];
    char	sPINData[LEN_PIN_DATA+2];
    char	szSecurityInfo[LEN_SECURITY_INFO+2];
    char	szExtAmount[LEN_EXT_AMOUNT+2];
    unsigned	char	sICCData[LEN_ICC_DATA+2];
    char     szField56[102];
    char	szField57[LEN_FIELD57+2];
    char	szEPData[LEN_EP_DATA+2];
    char    szField59[LEN_FIELD59+2];
    char	szField60[LEN_FIELD60+2];
    char	szOrginalMsg[LEN_ORIGINAL_MSG+2];
    char	sField62[LEN_FIELD62+2];
    char	szField63[LEN_FIELD63+2];
    char	sMacData[LEN_MAC_DATA+2];
}STISO8583;

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
    
    extern FIELD_ATTR	glMsg0[];
    extern FIELD_ATTR	glData0[];
    extern STISO8583	glSendPack, glRecvPack;
    
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
