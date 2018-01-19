//
//  st8583.c
//  8583Demo
//
//  Created by newPosTech on 13-8-12.
//  Copyright (c) 2013年 com.Mysoft. All rights reserved.
//

#include <stdio.h>
#include "pack8583.h"
#include "st8583.h"

STISO8583	glSendPack, glRecvPack;

FIELD_ATTR glMsg0[2]={
    {Attr_n, Attr_fix, LEN_MSG_CODE},			// message code
    {Attr_Over, 0, 0},
};

FIELD_ATTR glData0[64+1] = {
    {Attr_b, Attr_fix,  LEN_BITMAP},			/* 1 -- Bit Map, Extended */
    {Attr_n, Attr_var1, LEN_PAN},				/* 2 -- Primary Account Number */
    {Attr_n, Attr_fix,  LEN_PROC_CODE},			/* 3 -- Processing Number */
    {Attr_n, Attr_fix,  LEN_TRAN_AMT},			/* 4 -- Amount, Transaction */
    {Attr_UnUsed, Attr_fix, 0},					/* 5 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 6 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 7 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 8 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 9 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 10 -- not used */
    {Attr_n, Attr_fix,  LEN_POS_STAN},			/* 11 -- System Trace Audit Number */
    {Attr_n, Attr_fix,  LEN_LOCAL_TIME},		/* 12 -- Time, Local Transaction */
    {Attr_n, Attr_fix,  LEN_LOCAL_DATE},		/* 13 -- Date, Local Transaction */
    {Attr_n, Attr_fix,  LEN_EXP_DATE},			/* 14 -- Date, Expiration */
    {Attr_n, Attr_fix,  LEN_SETTLE_DATE},		/* 15 -- Date, Settlement */
    {Attr_UnUsed, Attr_fix, 0},					/* 16 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 17 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 18 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 19 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 20 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 21 -- not used */
    {Attr_n, Attr_fix,  LEN_ENTRY_MODE},		/* 22 -- Point of Service Entry Mode */
    {Attr_n, Attr_fix,  LEN_PAN_SEQ_NO},		/* 23 -- Card Sequence Number */
    {Attr_UnUsed, Attr_fix, 0},					/* 24 -- NII(not used) */
    {Attr_n, Attr_fix,  LEN_SVR_CODE},			/* 25 -- Point of Service Condition Code */
    {Attr_n, Attr_fix,  LEN_CAPTURE_CODE},		/* 26 -- Point of Service PIN Capture Code */
    {Attr_UnUsed, Attr_fix, 0},					/* 27 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 28 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 29 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 30 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 31 -- not used */
    {Attr_n, Attr_var1, LEN_ACQUIRER_ID},		/* 32 -- Acquiring Institution Identification Code??? */
    {Attr_UnUsed, Attr_fix, 0},					/* 33 -- Attr_UnUsed */
    {Attr_UnUsed, Attr_fix, 0},					/* 34 -- Attr_UnUsed */
    {Attr_z, Attr_var1, LEN_TRACK2},			/* 35 -- Track 2 Data */
    {Attr_z, Attr_var2, LEN_TRACK3},			/* 36 -- Track 3 Data */
    {Attr_a, Attr_fix, LEN_RRN},				/* 37 -- Retrieval Reference Number */
    {Attr_a, Attr_fix, LEN_AUTH_CODE},			/* 38 -- Authorization Identification Response */
    {Attr_a, Attr_fix, LEN_RSP_CODE},			/* 39 -- Response Code */
    {Attr_UnUsed, Attr_fix,  0},				/* 40 -- not used */
    {Attr_a, Attr_fix,  LEN_TERM_ID},			/* 41 -- Card Acceptor Terminal Identification */
    {Attr_a, Attr_fix,  LEN_MERCHANT_ID},		/* 42 -- Card Acceptor Identification Code */
    {Attr_UnUsed, Attr_fix,  0},				/* 43 -- Card Acceptor Name/Location */
    {Attr_a, Attr_var1, LEN_ADD_RSP_DATA},		/* 44 -- Additional Response Data */
    {Attr_UnUsed, Attr_fix, 0},					/* 45 -- Track 1 Data(not used) */
    {Attr_UnUsed, Attr_fix, 0},					/* 46 -- not used */
    {Attr_UnUsed, Attr_fix, 0},					/* 47 -- not used */
    {Attr_n, Attr_var2, LEN_FIELD48},			/* 48 -- Additional Data - Private */
    {Attr_a, Attr_fix,  LEN_CURRENCY_CODE},		/* 49 -- Currency Code, Transaction */
    {Attr_UnUsed, Attr_fix,  0},				/* 50 -- not used */
    {Attr_51, Attr_var2,  LEN_FIELD51},		    /* 51 -- not used */
    {Attr_b, Attr_fix,  LEN_PIN_DATA},			/* 52 -- Personal Identification Number (PIN) Data */
    {Attr_n, Attr_fix,  LEN_SECURITY_INFO},		/* 53 -- Security Related Control Information */
    {Attr_a, Attr_var2, LEN_EXT_AMOUNT},		/* 54 -- Additional Amounts */	// max 20
    //{Attr_b, Attr_var2, LEN_ICC_DATA},		/* 55 -- Chip Data for PBOC */
    {Attr_ic, Attr_var2, LEN_ICC_DATA},			/* 55 -- Chip Data for PBOC */
    {Attr_ic, Attr_var2, 100},					/* 56 -- Reserved ISO */
    {Attr_a, Attr_var2, LEN_FIELD57},			/* 57 -- Reserved National */
    {Attr_b, Attr_var2, LEN_EP_DATA},			/* 58 -- Reserved National */
    {Attr_51, Attr_var2, LEN_FIELD59},		    /* 59 -- Reserved National */
    {Attr_n, Attr_var2, LEN_FIELD60},			/* 60 -- Reserved Private */	// max 13
    {Attr_n, Attr_var2, LEN_ORIGINAL_MSG},		/* 61 -- Reserved Private */	// max 29
    {Attr_t, Attr_var2, LEN_FIELD62},			/* 62 -- Reserved Private */
    {Attr_a, Attr_var2, LEN_FIELD63},			/* 63 -- Reserved Private */	// max 163
    {Attr_b, Attr_fix,  LEN_MAC_DATA},			/* 64 -- Message Authentication Code Field */
    {Attr_Over, 0, 0}
};
