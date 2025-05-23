/**
  ******************************************************************************
  * @file    stm32h7s78_discovery_lcd.h
  * @author  MCD Application Team
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm32h7s78_discovery_lcd.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H7S78_DISCOVERY_LCD_H
#define STM32H7S78_DISCOVERY_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7s78_discovery_conf.h"
#include "stm32h7s78_discovery_errno.h"


#ifndef USE_LCD_CTRL_RK050HR18
#define USE_LCD_CTRL_RK050HR18        1U
#endif

#if (USE_LCD_CTRL_RK050HR18 == 1)
/* Include RK050HR18 LCD Driver IC driver code */
#include "../Components/rk050hr18/rk050hr18.h"
#endif
#include "../Components/Common/lcd.h"
/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32H7S78_DK
  * @{
  */

/** @addtogroup STM32H7S78_DK_LCD
  * @{
  */

/** @defgroup STM32H7S78_DK_LCD_Exported_Constants STM32H7S78_DK LCD Exported Constants
  * @{
  */
#define LCD_INSTANCES_NBR                1U

#define LCD_ORIENTATION_LANDSCAPE        0x01U  /* Landscape orientation choice of LCD screen */

#define LCD_DEFAULT_WIDTH                800
#define LCD_DEFAULT_HEIGHT               480

#define BSP_LCD_RELOAD_NONE              0U                            /* No reload executed       */
#define BSP_LCD_RELOAD_IMMEDIATE         LTDC_RELOAD_IMMEDIATE         /* Immediate Reload         */
#define BSP_LCD_RELOAD_VERTICAL_BLANKING LTDC_RELOAD_VERTICAL_BLANKING /* Vertical Blanking Reload */
/**
  * @brief LCD special pins
  */
/* LCD display enable pin */
#define LCD_DISP_EN_PIN                       GPIO_PIN_15
#define LCD_DISP_EN_GPIO_PORT                 GPIOE
#define LCD_DISP_EN_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOE_CLK_ENABLE()
#define LCD_DISP_EN_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOE_CLK_DISABLE()

/* LCD BackLight control pin */
#define LCD_BL_CTRL_PIN                  GPIO_PIN_15
#define LCD_BL_CTRL_GPIO_PORT            GPIOG
#define LCD_BL_CTRL_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOG_CLK_ENABLE()
#define LCD_BL_CTRL_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOG_CLK_DISABLE()

/* LCD Brightness default value */
#define LCD_BRIGHTNESS_DEFAULT_VALUE   50U

/*LCD LPTimer brightness control parameters */
#define LCD_LPTIMx                     LPTIM1
#define LCD_LPTIMx_CLK_ENABLE()        __HAL_RCC_LPTIM1_CLK_ENABLE()
#define LCD_LPTIMx_CLK_DISABLE()       __HAL_RCC_LPTIM1_CLK_DISABLE()
#define LCD_LPTIMx_CHANNEL             TIM_CHANNEL_2
#define LCD_LPTIMx_CHANNEL_AF          GPIO_AF1_LPTIM1
#define LCD_LPTIMX_PERIOD_VALUE        ((uint32_t)10000) /* Period Value    */
#define LCD_LPTIMX_PULSE_VALUE         (((uint32_t)(LCD_LPTIMX_PERIOD_VALUE +1U)*LCD_BRIGHTNESS_DEFAULT_VALUE/100U)-1U)
#define LCD_LPTIMX_PRESCALER_VALUE     LPTIM_PRESCALER_DIV1  /* Prescaler divider Value */
#define LCD_LPTIMX_CLOCK_SOURCE        LPTIM_CLOCKSOURCE_APBCLOCK_LPOSC /* internal clock source */

/* RGB565 colors definitions */
#define LCD_COLOR_RGB565_BLUE                 0x001FU
#define LCD_COLOR_RGB565_GREEN                0x07E0U
#define LCD_COLOR_RGB565_RED                  0xF800U
#define LCD_COLOR_RGB565_CYAN                 0x07FFU
#define LCD_COLOR_RGB565_MAGENTA              0xF81FU
#define LCD_COLOR_RGB565_YELLOW               0xFFE0U
#define LCD_COLOR_RGB565_LIGHTBLUE            0x841FU
#define LCD_COLOR_RGB565_LIGHTGREEN           0x87F0U
#define LCD_COLOR_RGB565_LIGHTRED             0xFC10U
#define LCD_COLOR_RGB565_LIGHTCYAN            0x87FFU
#define LCD_COLOR_RGB565_LIGHTMAGENTA         0xFC1FU
#define LCD_COLOR_RGB565_LIGHTYELLOW          0xFFF0U
#define LCD_COLOR_RGB565_DARKBLUE             0x0010U
#define LCD_COLOR_RGB565_DARKGREEN            0x0400U
#define LCD_COLOR_RGB565_DARKRED              0x8000U
#define LCD_COLOR_RGB565_DARKCYAN             0x0410U
#define LCD_COLOR_RGB565_DARKMAGENTA          0x8010U
#define LCD_COLOR_RGB565_DARKYELLOW           0x8400U
#define LCD_COLOR_RGB565_WHITE                0xFFFFU
#define LCD_COLOR_RGB565_LIGHTGRAY            0xD69AU
#define LCD_COLOR_RGB565_GRAY                 0x8410U
#define LCD_COLOR_RGB565_DARKGRAY             0x4208U
#define LCD_COLOR_RGB565_BLACK                0x0000U
#define LCD_COLOR_RGB565_BROWN                0xA145U
#define LCD_COLOR_RGB565_ORANGE               0xFD20U
/* Definition of Official ST COLOR */
#define LCD_COLOR_RGB565_ST_BLUE_DARK         0x0001U
#define LCD_COLOR_RGB565_ST_BLUE              0x01EBU
#define LCD_COLOR_RGB565_ST_BLUE_LIGHT        0x06A7U
#define LCD_COLOR_RGB565_ST_GREEN_LIGHT       0x05ECU
#define LCD_COLOR_RGB565_ST_GREEN_DARK        0x001CU
#define LCD_COLOR_RGB565_ST_YELLOW            0x07F0U
#define LCD_COLOR_RGB565_ST_BROWN             0x02C8U
#define LCD_COLOR_RGB565_ST_PINK              0x0681U
#define LCD_COLOR_RGB565_ST_PURPLE            0x02CDU
#define LCD_COLOR_RGB565_ST_GRAY_DARK         0x0251U
#define LCD_COLOR_RGB565_ST_GRAY              0x04BAU
#define LCD_COLOR_RGB565_ST_GRAY_LIGHT        0x05E7U

/* ARGB8888 colors definitions */
#define LCD_COLOR_ARGB8888_BLUE               0xFF0000FFUL
#define LCD_COLOR_ARGB8888_GREEN              0xFF00FF00UL
#define LCD_COLOR_ARGB8888_RED                0xFFFF0000UL
#define LCD_COLOR_ARGB8888_CYAN               0xFF00FFFFUL
#define LCD_COLOR_ARGB8888_MAGENTA            0xFFFF00FFUL
#define LCD_COLOR_ARGB8888_YELLOW             0xFFFFFF00UL
#define LCD_COLOR_ARGB8888_LIGHTBLUE          0xFF8080FFUL
#define LCD_COLOR_ARGB8888_LIGHTGREEN         0xFF80FF80UL
#define LCD_COLOR_ARGB8888_LIGHTRED           0xFFFF8080UL
#define LCD_COLOR_ARGB8888_LIGHTCYAN          0xFF80FFFFUL
#define LCD_COLOR_ARGB8888_LIGHTMAGENTA       0xFFFF80FFUL
#define LCD_COLOR_ARGB8888_LIGHTYELLOW        0xFFFFFF80UL
#define LCD_COLOR_ARGB8888_DARKBLUE           0xFF000080UL
#define LCD_COLOR_ARGB8888_DARKGREEN          0xFF008000UL
#define LCD_COLOR_ARGB8888_DARKRED            0xFF800000UL
#define LCD_COLOR_ARGB8888_DARKCYAN           0xFF008080UL
#define LCD_COLOR_ARGB8888_DARKMAGENTA        0xFF800080UL
#define LCD_COLOR_ARGB8888_DARKYELLOW         0xFF808000UL
#define LCD_COLOR_ARGB8888_WHITE              0xFFFFFFFFUL
#define LCD_COLOR_ARGB8888_LIGHTGRAY          0xFFD3D3D3UL
#define LCD_COLOR_ARGB8888_GRAY               0xFF808080UL
#define LCD_COLOR_ARGB8888_DARKGRAY           0xFF404040UL
#define LCD_COLOR_ARGB8888_BLACK              0xFF000000UL
#define LCD_COLOR_ARGB8888_BROWN              0xFFA52A2AUL
#define LCD_COLOR_ARGB8888_ORANGE             0xFFFFA500UL
/* Definition of Official ST Colors */
#define LCD_COLOR_ARGB8888_ST_BLUE_DARK       0xFF002052UL
#define LCD_COLOR_ARGB8888_ST_BLUE            0xFF39A9DCUL
#define LCD_COLOR_ARGB8888_ST_BLUE_LIGHT      0xFFD1E4F3UL
#define LCD_COLOR_ARGB8888_ST_GREEN_LIGHT     0xFFBBCC01UL
#define LCD_COLOR_ARGB8888_ST_GREEN_DARK      0xFF003D14UL
#define LCD_COLOR_ARGB8888_ST_YELLOW          0xFFFFD300UL
#define LCD_COLOR_ARGB8888_ST_BROWN           0xFF5C0915UL
#define LCD_COLOR_ARGB8888_ST_PINK            0xFFD4007AUL
#define LCD_COLOR_ARGB8888_ST_PURPLE          0xFF590D58UL
#define LCD_COLOR_ARGB8888_ST_GRAY_DARK       0xFF4F5251UL
#define LCD_COLOR_ARGB8888_ST_GRAY            0xFF90989EUL
#define LCD_COLOR_ARGB8888_ST_GRAY_LIGHT      0xFFB9C4CAUL
/**
  * @}
  */
typedef enum
{

    TFT_FONT_12 = 0,         /* 12������ */
    TFT_FONT_16,             /* 16������ */
    TFT_FONT_24,             /* 24������ */
    TFT_FONT_32,             /* 32������ */

} tft_lcd_font_t;

#define TFT_FONT_12_CHAR_WIDTH   6
#define TFT_FONT_12_CHAR_HEIGHT  12
#define TFT_FONT_12_CHAR_SIZE    12
#define TFT_FONT_16_CHAR_WIDTH   8
#define TFT_FONT_16_CHAR_HEIGHT  16
#define TFT_FONT_16_CHAR_SIZE    16
#define TFT_FONT_24_CHAR_WIDTH   12
#define TFT_FONT_24_CHAR_HEIGHT  24
#define TFT_FONT_24_CHAR_SIZE    36
#define TFT_FONT_32_CHAR_WIDTH   16
#define TFT_FONT_32_CHAR_HEIGHT  32
#define TFT_FONT_32_CHAR_SIZE    64
/** @defgroup STM32H7S78_DK_LCD_Exported_Types STM32H7S78_DK LCD Exported Types
  * @{
  */
typedef struct
{
  uint32_t XSize;
  uint32_t YSize;
  uint32_t ActiveLayer;
  uint32_t PixelFormat;
  uint32_t BppFactor;
  uint32_t IsMspCallbacksValid;
  uint32_t ReloadEnable;
  uint32_t Brightness;
} BSP_LCD_Ctx_t;

typedef struct
{
  uint32_t X0;
  uint32_t X1;
  uint32_t Y0;
  uint32_t Y1;
  uint32_t PixelFormat;
  uint32_t Address;
} MX_LTDC_LayerConfig_t;

#define BSP_LCD_LayerConfig_t MX_LTDC_LayerConfig_t


#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
typedef struct
{
  pLTDC_CallbackTypeDef            pMspLtdcInitCb;
  pLTDC_CallbackTypeDef            pMspLtdcDeInitCb;
} BSP_LCD_Cb_t;
#endif /*(USE_HAL_LTDC_REGISTER_CALLBACKS == 1) */
/**
  * @}
  */

/** @addtogroup STM32H7S78_DK_LCD_Exported_Variables
  * @{
  */
extern DMA2D_HandleTypeDef   hlcd_dma2d;
extern LTDC_HandleTypeDef    hlcd_ltdc;
extern BSP_LCD_Ctx_t         Lcd_Ctx[LCD_INSTANCES_NBR];
extern const LCD_UTILS_Drv_t LCD_Driver;
/**
  * @}
  */

/** @addtogroup STM32H7S78_DK_LCD_Exported_Functions
  * @{
  */
/* Initialization APIs */
int32_t BSP_LCD_Init(uint32_t Instance, uint32_t Orientation);
int32_t BSP_LCD_InitEx(uint32_t Instance, uint32_t Orientation, uint32_t PixelFormat, uint32_t Width, uint32_t Height);
int32_t BSP_LCD_DeInit(uint32_t Instance);

/* Register Callbacks APIs */
#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
int32_t BSP_LCD_RegisterDefaultMspCallbacks(uint32_t Instance);
int32_t BSP_LCD_RegisterMspCallbacks(uint32_t Instance, BSP_LCD_Cb_t *CallBacks);
#endif /*(USE_HAL_LTDC_REGISTER_CALLBACKS == 1) */

/* LCD specific APIs: Layer control & LCD HW reset */
int32_t BSP_LCD_Reload(uint32_t Instance, uint32_t ReloadType);
int32_t BSP_LCD_ConfigLayer(uint32_t Instance, uint32_t LayerIndex, BSP_LCD_LayerConfig_t *Config);
int32_t BSP_LCD_SetLayerVisible(uint32_t Instance, uint32_t LayerIndex, FunctionalState State);
int32_t BSP_LCD_SetTransparency(uint32_t Instance, uint32_t LayerIndex, uint8_t Transparency);
int32_t BSP_LCD_SetLayerAddress(uint32_t Instance, uint32_t LayerIndex, uint32_t Address);
int32_t BSP_LCD_SetLayerWindow(uint32_t Instance, uint16_t LayerIndex, uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
int32_t BSP_LCD_SetColorKeying(uint32_t Instance, uint32_t LayerIndex, uint32_t Color);
int32_t BSP_LCD_ResetColorKeying(uint32_t Instance, uint32_t LayerIndex);

/* LCD generic APIs: Display control */
int32_t BSP_LCD_DisplayOn(uint32_t Instance);
int32_t BSP_LCD_DisplayOff(uint32_t Instance);
int32_t BSP_LCD_SetBrightness(uint32_t Instance, uint32_t Brightness);
int32_t BSP_LCD_GetBrightness(uint32_t Instance, uint32_t *Brightness);
int32_t BSP_LCD_GetXSize(uint32_t Instance, uint32_t *XSize);
int32_t BSP_LCD_GetYSize(uint32_t Instance, uint32_t *YSize);

/* LCD generic APIs: Draw operations. This list of APIs is required for
   lcd gfx utilities */
int32_t BSP_LCD_SetActiveLayer(uint32_t Instance, uint32_t LayerIndex);
int32_t BSP_LCD_GetPixelFormat(uint32_t Instance, uint32_t *PixelFormat);
int32_t BSP_LCD_DrawBitmap(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint8_t *pBmp);
int32_t BSP_LCD_DrawHLine(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t Length, uint32_t Color);
int32_t BSP_LCD_DrawVLine(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t Length, uint32_t Color);
int32_t BSP_LCD_FillRGBRect(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint8_t *pData, uint32_t Width, uint32_t Height);
int32_t BSP_LCD_FillRect(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height, uint32_t Color);
int32_t BSP_LCD_ReadPixel(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t *Color);
int32_t BSP_LCD_WritePixel(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t Color);

void LCD_Clear(uint32_t Color);
void LCD_show_char(uint16_t x, uint16_t y, char ch, tft_lcd_font_t font, uint32_t color);
/* LCD MX APIs */
HAL_StatusTypeDef MX_LTDC_ConfigLayer(LTDC_HandleTypeDef *hltdc, uint32_t LayerIndex, MX_LTDC_LayerConfig_t *Config);
HAL_StatusTypeDef MX_LTDC_ClockConfig(LTDC_HandleTypeDef *hltdc);
HAL_StatusTypeDef MX_LTDC_Init(LTDC_HandleTypeDef *hltdc, uint32_t Width, uint32_t Height);

/**
  * @}
  */

/* Private constants --------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32H7S78_DISCOVERY_LCD_H */
