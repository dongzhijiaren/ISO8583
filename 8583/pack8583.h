//
//  pack8583.h
//  8583Demo
//
//  Created by newPosTech on 13-8-12.
//  Copyright (c) 2013年 com.Mysoft. All rights reserved.
//

#ifndef _583Demo_pack8583_h
#define _583Demo_pack8583_h

#define  ERR_UNPACK_LEN     -1000

#define Attr_a			0
#define Attr_b			1
#define Attr_n			2
#define Attr_z			3
#define Attr_UnUsed		4
#define Attr_Over		5
#define Attr_t			6   //图片数据
#define Attr_ic			7   //ic
#define Attr_51			8   //对51域单独处理


#define Attr_var1		0
#define Attr_var2		1
#define Attr_fix		2

typedef struct _tagFIELD_ATTR{
    unsigned char	eElementAttr;
    unsigned char	eLengthAttr;
    unsigned short	uiLength;
}FIELD_ATTR;


#ifdef __cplusplus
extern "C" {
#endif
    
    int iPack8583(FIELD_ATTR *pMsgAttr, FIELD_ATTR *pDataAttr, void *pSt8583, unsigned char *pusOut, unsigned short *puiOutLen);
    
    int iUnPack8583(FIELD_ATTR *pMsgAttr, FIELD_ATTR *pDataAttr, unsigned char *pusIn, unsigned short uiInLen, void *pSt8583);
    
#ifdef __cplusplus
}
#endif

#endif
