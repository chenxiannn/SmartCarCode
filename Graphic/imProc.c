/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : imProc.c
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - 
 * Website:http://www.mizhiquan.com
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     The Code is provided in source form for FREE evaluation and  educational 
 * use.
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2016-02-08     Xian.Chen    the first version
 * 2016-07-08     Xian.Chen    update
 *
 *******************************************************************************
 */

#include "imProc.h"
#include "imCom.h"
#include "ControlParam.h"
#ifndef MK60F15
   #include "mex.h"
#endif
extern EIT_PARAM gParam;
extern imUINT8  Image_Data[CAMERA_H][CAMERA_W];

imINT32  gDir_Near=0;
imINT32  gDir_Mid =0;
imINT32  gDir_Far =0;
imINT16  HBoundL[CAMERA_H];
imINT16  HBoundR[CAMERA_H];
imINT16  HBoundM[CAMERA_H];
imINT16  HBoundM_F[CAMERA_H];
imINT16  HBoundM_REAL[CAM_MAX_LENGTH_CM+1];
imINT32  H_Min=H_START;
imINT32  H_MaxL=H_END;
imINT32  H_MaxR=H_END;
imINT32  D_Max =CAM_MAX_LENGTH_CM;
int W_MID=W_MIDD;
int MaxWhite=0;
int Out=0;
int MaxStart=W_START;
int MaxEnd=W_START;

int Graph_JudgeOut(void)
{
    static int LeftOut=0;
    int WhiteCnt;
    int W;
    int wStart,wEnd;  
    MaxWhite=0;
    WhiteCnt=0;
    wStart=W_START;
    wEnd=W_START;
    
    for(W=W_START;W<W_END;W++)
    {
        if(Image_Data[H_END][W]==WHITE_VAL&&Image_Data[H_END][W+1]==WHITE_VAL)
          WhiteCnt++;
        else
        {
            if(WhiteCnt>MaxWhite)
            {
                wEnd=W;
                MaxWhite=WhiteCnt;
                MaxStart=wStart;
                MaxEnd=wEnd;
            }
            WhiteCnt=0;
            wStart=W;
        }
    }
    if(WhiteCnt>MaxWhite)
    {
        wEnd=W;
        MaxWhite=WhiteCnt;
        MaxStart=wStart;
        MaxEnd=wEnd;
     }
    switch(Out)
    {
       case 0:
          if(MaxWhite<=40)
          {
            if(MaxStart<=W_START)
            {
               Out=1;
               LeftOut=1;
            }
            else if (MaxEnd>=W_END)
            {
               Out=1;
               LeftOut=0;
            }
          }
          break;
       case 1:
       if(MaxWhite>=70)
       {
          if(LeftOut==1 && (MaxStart<=W_START))
             Out=0;
          if(LeftOut==0 && (MaxEnd>=W_END))
             Out=0;
       }
       break;
    }
    return Out;
}

void Graph_FindMidLine(void)
{
    int H,W;
    int dDir0,dDir1;
    int GetLineCntL=0;
    int GetLineCntR=0;
    int Mid;
    int H1,H2,H3,H4,H5,H6;
    
    H_Min = H_START;  
    if(Graph_JudgeOut())
    {
        return;
    }
    else
    {
      for (H=0;H<=CAMERA_H;H++)
      {
        HBoundL[H]=MaxStart;
        HBoundR[H]=MaxEnd;
        HBoundM[H]=(MaxStart+MaxEnd)/2;
      }
    }
    dDir0=0;
    dDir1=0;
    for(H=H_END;H>=H_START;H--)
    {
        H1=int_min(H+1,H_END);
        H2=int_min(H+2,H_END);
        H3=int_min(H+3,H_END);
        H4=int_min(H+4,H_END);
        H5=int_min(H+5,H_END);
        H6=int_min(H+6,H_END);
        
        Mid=HBoundM[H+1];
        if(Image_Data[H][Mid]!=WHITE_VAL || Image_Data[H][Mid-1]!=WHITE_VAL  || Image_Data[H][Mid+1]!=WHITE_VAL)
        {
             Mid = W_START+(W_END>>2);
             if(Image_Data[H][Mid]!=WHITE_VAL || Image_Data[H][Mid-1]!=WHITE_VAL  || Image_Data[H][Mid+1]!=WHITE_VAL)
             {
                  Mid = W_END-(W_END>>2);
                  if(Image_Data[H][Mid]!=WHITE_VAL|| Image_Data[H][Mid-1]!=WHITE_VAL  || Image_Data[H][Mid+1]!=WHITE_VAL)
                  {
                        Mid = W_START+(W_END>>4);
                        if(Image_Data[H][Mid]!=WHITE_VAL|| Image_Data[H][Mid-1]!=WHITE_VAL  || Image_Data[H][Mid+1]!=WHITE_VAL)
                        {
                             Mid = W_END-(W_END>>4);
                              if(Image_Data[H][Mid]!=WHITE_VAL|| Image_Data[H][Mid-1]!=WHITE_VAL  || Image_Data[H][Mid+1]!=WHITE_VAL)
                              {
                                   HBoundL[H] = HBoundL[H+1] ;
                                   HBoundR[H] = HBoundR[H+1] ;
                                   HBoundM[H] = HBoundM[H+1] ;
                                   continue;
                              }
                        }
                  }
             }
        }
        //Find Left Bound
        for(W=Mid;W>W_START;W--)
        {
            if (Image_Data[H][W]>Image_Data[H][W-1])
            {
                 HBoundL[H] = W;
                 GetLineCntL++;
                 break;
            }
        }
        if(W==W_START)
        {
             GetLineCntL=0;
        }
        //Find Right Bound
        for(W=Mid;W<W_END;W++)
        {
            if (Image_Data[H][W]>Image_Data[H][W+1])
            {
                 HBoundR[H] = W;
                 GetLineCntR++;
                 break;
            }
        }
        if(W==W_END)
        {
          GetLineCntR=0;
        }
        
        dDir0=HBoundR[H]-HBoundR[H2];
        dDir1=HBoundR[H2]-HBoundR[H6];
        if((dDir0*dDir1<-4 && dDir0>0) || (dDir0 > 10 && dDir1<=0) || (dDir0 < -8 && dDir1 >= -8))
        {
            HBoundR[H]=HBoundR[H3]+HBoundR[H3]-HBoundR[H6];
            HBoundR[H1]=HBoundR[H4]+HBoundR[H3]-HBoundR[H6];
        }

        //Cal Left
        dDir0=HBoundL[H]-HBoundL[H2];
        dDir1=HBoundL[H2]-HBoundL[H6];
        if((dDir0*dDir1<-4 && dDir0<0) || (dDir0 <-10  && dDir1>=0) || (dDir0 > 8 && dDir1 <= 8))
        {
            HBoundL[H]=HBoundL[H3]+HBoundL[H3]-HBoundL[H6];
            HBoundL[H1]=HBoundL[H4]+HBoundL[H3]-HBoundL[H6];
        }
        HBoundM[H]= (HBoundR[H]+ HBoundL[H])/2;
        if( HBoundR[H] < W_START+LINE_WIDTH || HBoundL[H] > W_END-LINE_WIDTH || (HBoundR[H]-HBoundL[H]) <LINE_WIDTH )
        {
             H_Min = H;
             break;
        }
   }
    for(H=int_min(H_MaxL,H_MaxR);H<=H_END;H++)
    {
         HBoundM[H]=(HBoundL[H]+HBoundR[H])/2;
    }
    
}

static void Graph_AverageMBound(void)
{
     int H;
     int i;
     int sum;
     for(H=H_END;H>H_Min;H--)
     {
         HBoundM_F[H]=HBoundM[H];
     }
     for(H=H_END-AVG_COUNT/2-1;H>H_Min+AVG_COUNT/2+1;H--)
     {
         sum=0;
         for(i=-AVG_COUNT/2;i<=AVG_COUNT/2;i++)
            sum+=HBoundM[H+i];
         HBoundM_F[H]=sum/AVG_COUNT;
     }
}

int Graph_Cam2Real(int H)
{
    int D;
    
    D=(int)(4188.0/(H+17.0)-10.0);
    D=int_max(0,D);
    D=int_min(CAM_MAX_LENGTH_CM,D);
    
    return D;
}

int Graph_Real2Cam(int D)
{
    int H;
    
    H = (int)(4188 / (D + 10.0) - 17.0);
    D=int_max(H_START,D);
    D=int_min(H_END,D);
    
    return H;
}
/*将纵向摄像头行转化为纵向厘米数*/
void Graph_Cam2Real_BoundM(void)
{
    int H;
    int D=0;
    int LastD;
    int d;
    
    for(H=H_END;H>=H_Min;H--)
    {
        LastD=D;
        D=Graph_Cam2Real(H);
        HBoundM_REAL[D]=HBoundM_F[H];
        for(d=LastD;d<D;d++)
        {
            HBoundM_REAL[d]=HBoundM_F[H+1]+(d-LastD)*(HBoundM_F[H]-HBoundM_F[H+1])/(D-LastD);
        }
    }
    D_Max=D;
    
    D=Graph_Cam2Real(H_END);
    for(d=D;d>=0;d--)
         HBoundM_REAL[d]=HBoundM_REAL[D];
}

void Graph_Calculate_Dir(int Speed)
{
    int D;
    int sum;
    int DStart;
    int DEnd;
    int Dir;
        
    Graph_AverageMBound();
    Graph_Cam2Real_BoundM();
    
    DStart = int_max(0,gParam.NearStart);
    DEnd   = int_min(gParam.NearStart+gParam.NearLen,D_Max);
    sum=0;
    for (D=DStart;D<=DEnd;D++)
    {
      sum+= HBoundM_REAL[D];
    }
    gDir_Near = sum/(DEnd-DStart+1)-W_MID;

    DStart = int_min((int)(gParam.MidDirSpeedK*Speed),D_Max-10);
    DEnd   = int_min(DStart+gParam.MidLen,D_Max);
    
    sum=0;
    for (D=DStart;D<=DEnd;D++)
    {
      sum+= HBoundM_REAL[D];
    }
    
    Dir= sum/(DEnd-DStart+1)-W_MID;
    gDir_Mid=int_min(Dir,W_MID);
    gDir_Mid=int_max(Dir,-W_MID);
    
    DStart = int_min(gParam.FarStart,D_Max-gParam.FarLen);
    DEnd =   int_min(DStart+gParam.FarLen,D_Max);
    
    sum=0;
    for (D=DStart;D<=DEnd;D++)
    {
      sum+= HBoundM_REAL[D];
    }
    gDir_Far = sum/(DEnd-DStart+1)-W_MID;
}






