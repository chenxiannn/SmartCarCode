#include "mex.h"
#include "imProc.h"
#include "imType.h"

imUINT8  Image_Data[CAMERA_H][CAMERA_W];
extern imUINT8  Image_DataF[CAMERA_H][CAMERA_W];
extern imINT32  gDir_Near;
extern imINT32  gDir_Mid;
extern imINT32  gDir_Far;
extern imINT16  HBoundL[CAMERA_H];
extern imINT16  HBoundR[CAMERA_H];
extern imINT16  HBoundM[CAMERA_H];
extern imINT16  HBoundM_F[CAMERA_H];
extern imINT16  HBoundM_REAL[CAM_MAX_LENGTH_CM+1];


void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
	imUINT8 *imIn;
    imUINT8 *imOut;
	int H,W;
    imINT16 *bound;
    imINT32 *dir;
    
    imINT32 CarSpeed;
    
    
    imIn=mxGetPr(prhs[0]);
	for(H=0;H<CAMERA_H;H++)
	{	for(W=0;W<CAMERA_W;W++)
		{
			Image_Data[H][W]=imIn[H*CAMERA_W+W];
		    //mexPrintf("%d ",Image_Data[H][W]);
		}
	}
    CarSpeed = *mxGetPr(prhs[1]);
    ControlParam_Init();
    Graph_FindMidLine();
    Graph_Calculate_Dir(CarSpeed);
    plhs[0]=mxCreateNumericMatrix(CAMERA_H,1,mxINT16_CLASS,mxREAL);
    plhs[1]=mxCreateNumericMatrix(CAMERA_H,1,mxINT16_CLASS,mxREAL);
    plhs[2]=mxCreateNumericMatrix(CAMERA_H,1,mxINT16_CLASS,mxREAL);
    plhs[3]=mxCreateNumericMatrix(3,1,mxINT32_CLASS,mxREAL);
    plhs[4]=mxCreateNumericMatrix(CAMERA_W,CAMERA_H,mxUINT8_CLASS,mxREAL);
    plhs[5]=mxCreateNumericMatrix(CAMERA_H,1,mxINT16_CLASS,mxREAL);
    plhs[6]=mxCreateNumericMatrix(CAM_MAX_LENGTH_CM+1,1,mxINT16_CLASS,mxREAL);
    
    bound=mxGetPr(plhs[0]);
	for(H=0;H<CAMERA_H;H++)
	{	
        bound[H]=HBoundL[H];
	}
    bound=mxGetPr(plhs[1]);
	for(H=0;H<CAMERA_H;H++)
	{	
        bound[H]=HBoundR[H];
	}
    bound=mxGetPr(plhs[2]);
	for(H=0;H<CAMERA_H;H++)
	{	
        bound[H]=HBoundM_F[H];
	}
    dir=mxGetPr(plhs[3]);
    dir[0]=gDir_Near;
    dir[1]=gDir_Mid;
    dir[2]=gDir_Far;
    imOut=mxGetPr(plhs[4]);
    for(H=0;H<CAMERA_H;H++)
	{	for(W=0;W<CAMERA_W;W++)
		{
			imOut[H*CAMERA_W+W]=Image_Data[H][W];
		}
	}
    
    bound=mxGetPr(plhs[5]);
	for(H=0;H<CAMERA_H;H++)
	{	
        bound[H]=HBoundM_F[H];
	}
    bound=mxGetPr(plhs[6]);
	for(H=0;H<CAM_MAX_LENGTH_CM;H++)
	{	
        bound[H]=HBoundM_REAL[H];
	}
}
