/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_comm_ive.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software (IVE) group
  Created       : 2014/11/15
  Description   : 
  History       :
  1.Date        : 2014/11/15
    Author      : c00211359
    Modification: Created file

  2.Date        : 2014/11/15
    Author      : c00211359
    Modification: move lpr function from mpi_ive.h to this file
******************************************************************************/

#ifndef _HI_MPI_IVE_LPR_H_
#define _HI_MPI_IVE_LPR_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */
#include "hi_ive_lpr.h"

/*****************************************************************************
*   Prototype    : HI_MPI_IVE_Bernsen
*   Description  : Image binaryzation using BERNSEN method or its extensional method.
*   Parameters   : IVE_HANDLE            *pIveHandle        Returned handle ID of a task
*                  IVE_SRC_IMAGE_S       *pstSrc            Input source. Only the U8C1 input format is supported.
*                  IVE_DST_IMAGE_S       *pstDst            Output result 
*				   IVE_BERNSEN_CTRL_S    *pstBernsenCtrl    Control parameter
*                  HI_BOOL                bInstant          For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         : The size of the input data ranges from 64x64 pixels to 1920x1024 pixels.
*                  The physical addresses of the input data and output data must be 16-byte-aligned.
*                  The stride must be 16-pixel-aligned.
*   History:
* 
*       1.  Date         : 2013-08-15
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_Bernsen(IVE_HANDLE *pIveHandle, IVE_SRC_IMAGE_S *pstSrc,
	IVE_DST_IMAGE_S *pstDst, IVE_BERNSEN_CTRL_S *pstBernsenCtrl, HI_BOOL bInstant);

/*****************************************************************************
*   Prototype    : HI_MPI_IVE_Radon
*   Description  :  
*   Parameters   : IVE_HANDLE			*pIveHandle       Returned handle ID of a task
*				   IVE_SRC_IMAGE_S		*pstSrc			  Input gray image
*				   IVE_DST_IMAGE_S		*pstDst			  Angle project image
*                  IVE_RADON_CTRL_S     *pstRadonCtrl	  Radon tranform parameters
*                  HI_BOOL				 bInstant         For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         : 
*   History:
* 
*       1.  Date         : 2013-10-29
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_Radon(IVE_HANDLE *pIveHandle, IVE_SRC_IMAGE_S *pstSrc, IVE_DST_IMAGE_S *pstDst, 
	IVE_RADON_CTRL_S *pstRadonCtrl, HI_BOOL bInstant);
/*****************************************************************************
*   Prototype    : HI_MPI_IVE_LineFilterHor
*   Description  :  
*   Parameters   : IVE_HANDLE                   *pIveHandle            Returned handle ID of a task
*				   IVE_IMAGE_S                  *pstSrcDst		           Input Binary image
*				   IVE_LINE_FILTER_HOR_CTRL_S   *pstLineFltHorCtrl     Horizontal Line Filter parameters
*                  HI_BOOL                       bInstant              For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         : 
*   History:
* 
*       1.  Date         : 2013-10-29
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_LineFilterHor(IVE_HANDLE *pIveHandle, IVE_IMAGE_S *pstSrcDst, 
	IVE_LINE_FILTER_HOR_CTRL_S *pstLineFltHorCtrl, HI_BOOL bInstant);

/*****************************************************************************
*   Prototype    : HI_MPI_IVE_AdpThresh
*   Description  :  
*   Parameters   : IVE_HANDLE			      *pIveHandle         Returned handle ID of a task
*				   IVE_SRC_IMAGE_S		      *pstSrc			  Gray image
*				   IVE_SRC_IMAGE_S		      *pstInteg		      Integer image
*				   IVE_DST_IMAGE_S		      *pstDst			  Binary image
*				   IVE_ADP_THRESH_CTRL_S      *pstAdpThrCtrl      Adaptive threshold parameters
*                  HI_BOOL				       bInstant           For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         : 
*   History:
* 
*       1.  Date         : 2013-10-29
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_AdpThresh(IVE_HANDLE *pIveHandle, IVE_SRC_IMAGE_S *pstSrc, IVE_SRC_IMAGE_S *pstInteg,
	IVE_DST_IMAGE_S *pstDst, IVE_ADP_THRESH_CTRL_S *pstAdpThrCtrl, HI_BOOL bInstant);

/*****************************************************************************
*   Prototype    : HI_MPI_IVE_NoiseRemoveHor
*   Description  :  
*   Parameters   : IVE_HANDLE                 *pIveHandle              Returned handle ID of a task
*				   IVE_IMAGE_S	              *pstSrcDst               Binary image
*				   IVE_NOISE_REMOVE_CTRL_S    *pstNoiseRemoveHorCtrl   Remove image noise parameters
*                  HI_BOOL                     bInstant                For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success; Error codes: Failure.
*   Spec         : 
*   History:
* 
*       1.  Date         : 2013-10-29
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_NoiseRemoveHor(IVE_HANDLE *pIveHandle, IVE_IMAGE_S *pstSrcDst,
	IVE_NOISE_REMOVE_HOR_CTRL_S *pstNoiseRemoveHorCtrl, HI_BOOL bInstant);
/*****************************************************************************
*   Prototype    : HI_MPI_IVE_PlateCharPos
*   Description  :  
*   Parameters   : IVE_HANDLE			       *pIveHandle              Returned handle ID of a task
*				   IVE_SRC_IMAGE_S		       *pstEnegyHist	        Energy Hist image														
*				   IVE_SRC_MEM_INFO_S	       *pstPlateInfo	        Plate model information
*				   IVE_DST_MEM_INFO_S          *pstCharPos              Output of characters information
*                  IVE_PLATE_CHAR_POS_CTRL_S   *pstPlateCharPosCtrl     Plate char position parameters
*                  HI_BOOL				        bInstant                For details, see HI_MPI_IVE_DMA.
*   Return Value : HI_SUCCESS: Success; Error codes: Failure.
*   Spec         : 
*   History:
* 
*       1.  Date         : 2013-10-29
*           Author       : 
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_MPI_IVE_PlateCharPos(IVE_HANDLE *pIveHandle, IVE_SRC_IMAGE_S *pstEnegyHist, IVE_SRC_MEM_INFO_S *pstPlateInfo,
	IVE_DST_MEM_INFO_S *pstCharPos, IVE_PLATE_CHAR_POS_CTRL_S *pstPlateCharPosCtrl, HI_BOOL bInstant);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif



