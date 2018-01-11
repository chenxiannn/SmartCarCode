#include "CarDisplay.h"

static int  Mode=C_ALL;
volatile int  Display_flag=1;
volatile int  Mode_flag=0;
volatile int  Mode_flag_D1=0;
volatile int  Mode_flag_C16=0;
volatile int  Mode_flag_C17=0;
extern void  Infared_CountInc(void);
KEY_MSG_t keymsg;
//lcd显示
#define max_tab 9
uint8  i = 0; 
uint16 bkColor;
uint16 Color;
     //定义背景延时
#define SELECT_BG         YELLOW   //当前选中，而且没有改变
#define NO_SELECT_BG      BCOLOUR     //没有选中，而且没有改变（普通的就是这样）

    //定义文字颜色
#define SELECT_FC            BLUE    //当前选中，而且没有改变
#define NO_SELECT_FC         FCOLOUR   //没有选中，而且改变了

key_info_t task_key_info[max_tab] =
    {
    #define X_OFF   0
    #define Y_OFF   0
        {{X_OFF+0*15,Y_OFF+0*14},"H_MAX:",0},
        {{X_OFF+0*15,Y_OFF+1*14},"C_MAX:",0},
        {{X_OFF+0*15,Y_OFF+2*14},"C_MIN:",0},
        {{X_OFF+0*15,Y_OFF+3*14},"S_KLR:",0},
        {{X_OFF+0*15,Y_OFF+4*14},"S_DEC:",0},
    #undef X_OFF
    #undef Y_OFF
    };


key_num_info_t task_num_key_info[max_tab] =
    {
    #define X_OFF   0
    #define Y_OFF   0
        {{X_OFF+4*15,Y_OFF+0*14},0},
        {{X_OFF+4*15,Y_OFF+1*14},0},
        {{X_OFF+4*15,Y_OFF+2*14},0},
        {{X_OFF+4*15,Y_OFF+3*14},0},
        {{X_OFF+4*15,Y_OFF+4*14},0},

    #undef X_OFF
    #undef Y_OFF
    };
void UPdate(void);
void DisplayKey_Init(void)
{
    LCD_init();
    key_init(KEY_MAX); 
      
    port_init (MODE_EN, IRQ_EITHER | PF | ALT1 | PULLUP );
    port_init (MODE_EN_D1, IRQ_EITHER | PF | ALT1 | PULLUP );
    port_init (MODE_EN_C16, IRQ_EITHER | PF | ALT1 | PULLUP );
    port_init (MODE_EN_C17, IRQ_EITHER | PF | ALT1 | PULLUP );
       
    
    UPdate();
    
    LCD_str(task_key_info[H_MAX].site,task_key_info[H_MAX].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str(task_key_info[C_MAX].site,task_key_info[C_MAX].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str (task_key_info[C_MIN].site,task_key_info[C_MIN].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str (task_key_info[S_KLR].site,task_key_info[S_KLR].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str (task_key_info[S_DEC].site,task_key_info[S_DEC].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str (task_key_info[BendDec].site,task_key_info[BendDec].keystr,NO_SELECT_FC,NO_SELECT_BG);
    LCD_str (task_key_info[StrMid].site,task_key_info[StrMid].keystr,NO_SELECT_FC,NO_SELECT_BG);

}

void Param_Display_Task(void)
{
     i = max_tab - 1; 
    // LCD_clear(BCOLOUR); 
    do
    {
      if(Mode==C_ALL)
      {  
        Color   =  SELECT_FC;
        bkColor =  SELECT_BG;
      }
      else
      {
        if(i==Mode)
        {

            Color   =  SELECT_FC;
            bkColor =  SELECT_BG;

        }
        else
        {
            Color   =  NO_SELECT_FC;
            bkColor =  NO_SELECT_BG;
        }
      }

        //显示文字
        LCD_str(task_key_info[i].site,task_key_info[i].keystr,Color,bkColor);
        LCD_num(task_num_key_info[i].site, task_num_key_info[i].number,Color,bkColor);

        
    }
    while(i--);         //tab != VAR_MAX 的时候，执行一次就跳出
    
    
}
void UPdate(void)
{
   task_num_key_info[0].number=(uint32)gParam.StrightMaxSpeed;
   task_num_key_info[1].number=(uint32)gParam.MaxSpeed;
   task_num_key_info[2].number=(uint32) gParam.MinSpeed;
   task_num_key_info[3].number=(uint32) (gParam.LRSpeedK*10);
   task_num_key_info[4].number=(uint32) (gParam.DecSpeedK*10);
} 
void Inc_Speed_Param(void)
{
   switch(Mode)
   {
       case H_MAX:
       gParam.StrightMaxSpeed+=MIN_STEP;
      task_num_key_info[0].number=(uint32)gParam.StrightMaxSpeed;
       break;
       
       case C_MAX:
         gParam.MaxSpeed+=MIN_STEP;
       task_num_key_info[1].number=(uint32)gParam.MaxSpeed;
       break;
       
       case C_MIN:
         gParam.MinSpeed+=MIN_STEP;
        task_num_key_info[2].number=(uint32) gParam.MinSpeed;
       break;
       
       case S_KLR:
         gParam.LRSpeedK+=0.1;
          task_num_key_info[3].number=(uint32)( gParam.LRSpeedK*10);
       break;
      case S_DEC:
         gParam.DecSpeedK+=0.1;
          task_num_key_info[4].number=(uint32) (gParam.DecSpeedK*10);
       break;
      case C_ALL:
       gParam.StrightMaxSpeed+=MIN_STEP;
        task_num_key_info[0].number=(uint32)gParam.StrightMaxSpeed;
       gParam.MaxSpeed+=MIN_STEP;
        task_num_key_info[1].number=(uint32)gParam.MaxSpeed;
       gParam.MinSpeed+=MIN_STEP;
       task_num_key_info[2].number=(uint32) gParam.MinSpeed;
       break;

   default:
       break;
   }
}

void Dec_Speed_Param(void)
{

   switch(Mode)
   {
       case H_MAX:
       gParam.StrightMaxSpeed-=MIN_STEP;
       task_num_key_info[0].number=(uint32)gParam.StrightMaxSpeed;
       break;
       
       case C_MAX:
         gParam.MaxSpeed-=MIN_STEP;
          task_num_key_info[1].number=(uint32)gParam.MaxSpeed;
       break;
       
       case C_MIN:
         gParam.MinSpeed-=MIN_STEP;
         task_num_key_info[2].number=(uint32) gParam.MinSpeed;
       break;
       case S_KLR:
         gParam.LRSpeedK-=0.1;
         task_num_key_info[3].number=(uint32) (gParam.LRSpeedK*10);
       break;
       
       case S_DEC:
         gParam.DecSpeedK-=0.1;
           task_num_key_info[4].number=(uint32) (gParam.DecSpeedK*10);
       break;
        case BendDec:
         gParam.Stright2BendDecSpeedK-=1;
          task_num_key_info[5].number=(uint32) (gParam.Stright2BendDecSpeedK);
       break;
        case StrMid:
         gParam.SteerMid-=1;
          task_num_key_info[6].number=(uint32) (gParam.SteerMid);
       break;

       case C_ALL:
       gParam.StrightMaxSpeed-=MIN_STEP;
       task_num_key_info[0].number=(uint32)gParam.StrightMaxSpeed;
       gParam.MaxSpeed-=MIN_STEP;
        task_num_key_info[1].number=(uint32)gParam.MaxSpeed;
       gParam.MinSpeed-=MIN_STEP;
      task_num_key_info[2].number=(uint32) gParam.MinSpeed;
       break;

   default:
       break;
   }
}
void ChangeModeADD(void)
{
   Mode++;
   if(Mode > C_ALL)
     Mode = H_MAX;
}

void ChangeModeDEC(void)
{
   Mode--;
   if(Mode < H_MAX)
     Mode = C_ALL;
}

void param_kay(void)
{
        if(get_key_msg(&keymsg) == 1)
        {
            if(keymsg.status == KEY_DOWN)
            {
                switch(keymsg.key)
                {
                case KEY_U:
                  {
                    Inc_Speed_Param(); 
                    break;
                  }
                case KEY_D:
                  {
                    Dec_Speed_Param();
                    break;
                  }
                case KEY_L:
                  {
                    ChangeModeADD();
                    break;
                  }
                case KEY_R:
                  {
                    ChangeModeDEC();
                    break;
                  }
                case KEY_B:

                default:
                    break;

                }
            }
        }
}

